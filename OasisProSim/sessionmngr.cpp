#include "sessionmngr.h"

sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{

}


void sessionMngr::startSession(int type, int duration, int intensity){

    if(connectionTest()){
        qInfo("connection test worked");
    }

}

bool sessionMngr::connectionTest(){
    //need to expand on this later

    if(this->connected){
        return true;
    }else{
        return false;
    }
}

void sessionMngr::setConnected(bool connection){
    connected = connection;
}
