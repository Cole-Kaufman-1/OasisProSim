#include "sessionmngr.h"

const QString sessionMngr::DATABASE_PATH = "/database/OasisPro.db";


sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{
      batteryLifeTimer = new QTimer();
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
           temp->print();
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
    if (!query.next()) {
        return nullptr;
    }
    else{
        const QString type = query.value(0).toString();
        const QString user = query.value(1).toString();
        int dur = query.value(2).toInt();
        int intense = query.value(3).toInt();
        session* ret = new session(type,dur,intense);
        return ret;
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
//TODO: add duration timer
void sessionMngr::startSession(const QString &type, int duration, int intensity){

    if(connectionTest()){
        qInfo("connection test worked");
        emit sessionStart();
        batteryLifeTimer->start(1000); //the battery will decrease .01% every 1 seconds by default

        //creating session record at the start:
        session *currSession = new session(type, duration,intensity);

        //TODO: carry out session effect on UI
    }
}

// does not currently work need to change timer being used to a duration timer
void sessionMngr::pauseSession() {
    remainingTime = batteryLifeTimer->remainingTime();
    batteryLifeTimer->stop();
    qInfo() << "Session paused with " << remainingTime << " left";
    sessionPaused = true;
}

void sessionMngr::unpauseSession() {
    qInfo("Session unpaused");
    emit sessionStart();
    batteryLifeTimer->start(1000);
}

bool sessionMngr::connectionTest(){
    //need to expand on this later
    if(this->connected==true){
        qInfo("we are connected");
        return true;
    }else{
        qInfo("not connected, try again");
        return false;
    }
}

void sessionMngr::setConnected(bool connection){
    connected = connection;
}

bool sessionMngr::isSessionPaused(){
    return sessionPaused;
}

int sessionMngr::getRemainingTime() {
    return remainingTime;
}

