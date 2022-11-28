#include "sessionmngr.h"

sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{
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


