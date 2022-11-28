#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "session.h"

class sessionManager
{
public:
    sessionManager();
    void startSession(int type, int duration, int intensity);
    void updateWindo

private:
    bool connectionTest();


};

#endif // SESSIONMANAGER_H
