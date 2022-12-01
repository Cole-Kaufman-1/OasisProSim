#include "sessionmngr.h"

const QString sessionMngr::DATABASE_PATH = "/database/OasisPro.db";


sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{
      runningSession = false;
      db = QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName("OasisPro.db");

      if(!db.open())
          throw "Errow: Could not open database";

       if(!DBInit())
           throw "Error: Database has not been initialized";
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

bool sessionMngr::isValidRecord(const QString &user, const QString &sessionType, int duration, int intensityLevel){

    //TODO: add verification for records
    return false;

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
void sessionMngr::startSession(int type, int duration, int intensity){

    if(connectionTest()){
        qInfo("connection test worked");
        emit sessionStart();


        //creating session record at the start:
        session *currSession = new session(type, duration,intensity);

        //TODO: carry out session effect on UI
    }




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


