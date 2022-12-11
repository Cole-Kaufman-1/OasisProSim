#ifndef SESSIONMNGR_H
#define SESSIONMNGR_H

#include <QObject>
#include "session.h"
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>
#include <QTimer>
#include <QtDebug>

class sessionMngr : public QObject
{
    Q_OBJECT
public:
    QTimer* batteryLifeTimer;
    QTimer* sessionTimer;
    static const QString DATABASE_PATH;
    explicit sessionMngr(QObject *parent = nullptr);
    bool isSessionPaused();
    int getRemainingTime();
    void startSession(QString user,int sessionType, int duration, int intensity);
    void addSessionRecord(int currIntensity);
    void addUserRecord(const QString &user);
    QStringList getUserSessions(QString user);
    void pauseSession();
    void unpauseSession();
    void endSession();
    Session* getCurrentSession();
    Session* getSession(int sessionNum);

    bool deleteRecords();
    void displayRecords();
private:
    bool DBInit();
    QSqlDatabase db;
    bool runningSession;
    bool sessionPaused;
    const QString tempUser = "tempUser"; //use this for testing purposes
    int remainingTime;
    Session *currSession;

public slots:
    void sessionTimerExpired();

signals:
    void sessionStart();
    void sessionEnd();
};

#endif // SESSIONMNGR_H
