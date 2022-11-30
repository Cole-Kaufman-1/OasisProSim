#include "sessionmngr.h"

const QString sessionMngr::DATABASE_PATH = "/database/OasisPro.db";

sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{
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
    query.exec("CREATE TABLE IF NOT EXISTS treatmentHistory (user TEXT NOT NULL UNIQUE PRIMARY KEY, sessionType TEXT NOT NULL, duration INTEGER NOT NULL, intensityLevel INTEGER NOT NULL);");
    query.exec("CREATE TABLE IF NOT EXISTS users (name TEXT NOT NULL UNIQUE PRIMARY KEY, treatmentAmount INTEGER NOT NULL);");
    return db.commit();

}


bool sessionMngr::addSessionRecord(const QString &user, const QString &sessionType, int duration, int intensityLevel){


}


bool sessionMngr::isValidRecord(const QString &user, const QString &sessionType, int duration, int intensityLevel){


}

bool sessionMngr::addRecord(const QString &user, const QString &sessionType, int duration, int intensityLevel){

}

bool sessionMngr::deleteRecords(){
    QSqlQuery query;
    query.prepare("DELETE FROM treatmentHistory");
    query.exec();
    query.prepare("DELETE FROM users");
    query.exec();
    return query.exec();
}


void sessionMngr::startSession(int type, int duration, int intensity){

    if(connectionTest()){
        qInfo("connection test worked");
        emit sessionStart();
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


