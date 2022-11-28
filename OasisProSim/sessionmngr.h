#ifndef SESSIONMNGR_H
#define SESSIONMNGR_H

#include <QObject>
#include "session.h"


class sessionMngr : public QObject
{
    Q_OBJECT
public:
    explicit sessionMngr(QObject *parent = nullptr);
    void startSession(int type, int duration, int intensity);

private:
    bool connectionTest();

signals:

};

#endif // SESSIONMNGR_H
