#include "sessionmngr.h"

const QString sessionMngr::DATABASE_PATH = "/database/OasisPro.db";


sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{
      batteryLifeTimer = new QTimer();
      sessionTimer = new QTimer();
      runningSession = false;
      sessionPaused = false;
      db = QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName("OasisPro.db");

      if(!db.open())
          throw "Errow: Could not open database";

       if(!DBInit())
           throw "Error: Database has not been initialized";
     
       addSessionRecord("big","basicTreatment",10,5);
             session *temp = getSession("big","basicTreatment",10,5);
             if(temp == nullptr)
                 qInfo("get record does not work");
             else
                 if(temp->type.compare("basicTreatment")==0)
                     qInfo("inner working works well..\n");

      //connections
      connect(sessionTimer, SIGNAL(timeout()),this,SLOT (sessionTimerExpired()));
}

session* sessionMngr::getCurrentSession(){
    return currSession;
}

//DB Initialization. Creates a couple of tables to utlise later. Specifically a table for treatment history and a table to track users
bool sessionMngr::DBInit(){

    db.transaction();
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS treatmentHistory (user TEXT NOT NULL PRIMARY KEY, sessionType TEXT NOT NULL, duration INTEGER NOT NULL, intensityLevel INTEGER NOT NULL);");
    query.exec("CREATE TABLE IF NOT EXISTS users (name TEXT NOT NULL UNIQUE PRIMARY KEY, treatmentAmount INTEGER NOT NULL);");
    return db.commit();

}

//TODO: this function needs some updating - the display is not functioning as expected - we can see properly in terminal but not in output...
void sessionMngr::displayRecords() {

    QList<QString>* records = new QList<QString>;

    QSqlQuery query;
    query.exec("SELECT * FROM treatmentHistory");
    while (query.next()) {
        qInfo("%s",query.value(0).toString().toStdString());
    }

    QSqlQuery userQuery;

    userQuery.exec("SELECT * FROM users");
    while (query.next()) {
        qInfo("%s",userQuery.value(0).toString());
    }

}


void sessionMngr::addSessionRecord(const QString &user, const QString &sessionType, int duration, int intensityLevel){

    db.transaction();
    QSqlQuery query;
    query.prepare("INSERT INTO treatmentHistory (user, sessionType, duration, intensityLevel) VALUES (:user, :sessionType, :duration, :intensityLevel);");
    query.bindValue(":user",user);
    query.bindValue(":sessionType",sessionType);
    query.bindValue(":duration", duration);
    query.bindValue(":intensityLevel", intensityLevel);
    query.exec();
    db.commit();

}

void sessionMngr::addUserRecord(const QString &user){
    db.transaction();
    QSqlQuery query;
    query.prepare("INSERT INTO users (user, treatmentAmount) VALUES (:user, :treatmentAmount);");
    query.bindValue(":user",user);
    query.bindValue(":treatmentAmount",0);
    query.exec();
    db.commit();
}
session* sessionMngr::getSession(const QString &user, const QString &sessionType, int duration, int intensityLevel){

    db.transaction();
       QSqlQuery query;
       query.prepare("SELECT * FROM treatmentHistory WHERE user LIKE :user AND sessionType LIKE :sessionType AND duration=:duration AND intensityLevel=:intensityLevel");

      query.bindValue(":user", user);
      query.bindValue(":sessionType",sessionType);
      query.bindValue(":duration", duration);
      query.bindValue(":intensityLevel", intensityLevel);
      query.exec();

       if (!db.commit()) {
           qInfo("querry did not work");
       }
       // profile does not exist
       if (query.next()) {
           const QString u = query.value(0).toString(); //not used in return since user info
           const QString t = query.value(1).toString();
           int d = query.value(2).toInt();
           int i = query.value(3).toInt();
           session* ret = new session(t,d,i);
           return ret;
       }
       //no result
       else{
           return nullptr;

       }
}

bool sessionMngr::deleteRecords(){
    QSqlQuery query;
    query.prepare("DELETE FROM treatmentHistory");
    query.exec();
    query.prepare("DELETE FROM users");
    query.exec();
    return query.exec();
}


//TODO: we are mapping the type here as an int over to an array of chars. This makes it easier to work with FOR NOW...doesn't require string to int conversion. Will need to change later
void sessionMngr::startSession(const QString &type, int duration, int intensity){

    qInfo("connection test worked");
    emit sessionStart();
    batteryLifeTimer->start(1000); //the battery will decrease .01% every 1 seconds by default

    //creating session record at the start:
    currSession = new session(type, duration,intensity);

    //starting session timer
    if (duration==0){
        sessionTimer->start(20000); //simulating 20 minutes as 20 seconds
    } else if (duration==1){
        sessionTimer->start(45000);
    } //TODO: need to add the last else here for user designated time
}

// does not currently work need to change timer being used to a duration timer
void sessionMngr::pauseSession() {
    batteryLifeTimer->stop();
    remainingTime = sessionTimer->remainingTime();
    sessionTimer->stop();
    qInfo() << "Session paused with " << remainingTime << " left";
    sessionPaused = true;
}

void sessionMngr::unpauseSession() {
    qInfo("Session unpaused");
    batteryLifeTimer->start(1000);
    sessionTimer->start(remainingTime);
    sessionPaused = false;

}

bool sessionMngr::isSessionPaused(){
    return sessionPaused;
}

int sessionMngr::getRemainingTime() {
    return remainingTime;
}

void sessionMngr::sessionTimerExpired(){
    endSession();
}

//will be called when the session timer ends, or when the user pressed the power button during a session
void sessionMngr::endSession(){
    qInfo("ending session");
    emit sessionEnd();
    if (sender()==sessionTimer){
        currSession->setDuration(sessionTimer->interval());
    } else { //if the sender was not the session timer, it means the session was ended early, thus we must substract remaining time
        currSession->setDuration(sessionTimer->interval()-sessionTimer->remainingTime());
    }
    sessionTimer->stop();
    batteryLifeTimer->stop();

}
