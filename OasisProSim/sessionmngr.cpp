#include "sessionmngr.h"

sessionMngr::sessionMngr(QObject *parent) : QObject(parent)
{

}


void sessionMngr::startSession(int type, int duration, int intensity){

    if(connectionTest()){

    }

}

bool sessionMngr::connectionTest(){
    return true;
    //need to expand on this later

    //link up to the true or false attribute of the
}
