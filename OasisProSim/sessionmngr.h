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
    static const QString DATABASE_PATH;
    explicit sessionMngr(QObject *parent = nullptr);
    bool connectionTest();
    bool isSessionPaused();
    int getRemainingTime();
    void startSession(const QString &type, int duration, int intensity);
    void setConnected(bool connection);
    void addSessionRecord(const QString& user, const QString& sessionType, int duration, int intensityLevel);
    void addUserRecord(const QString &user);
    void pauseSession();
    void unpauseSession();


    bool deleteRecords();
    void displayRecords();
private:

    bool DBInit();
    bool connected;
    QSqlDatabase db;
    bool runningSession;
    bool sessionPaused;
    session* getSession(const QString& user, const QString& sessionType, int duration, int intensityLevel);
    session* loadSession(const QString& user, const QString& sessionType, int duration, int intensityLevel);
    QString sessionTypes[3] = { "Basic", "Middle", "Advanced" };
    const QString tempUser = "tempUser"; //use this for testing purposes
    int remainingTime;

public slots:

signals:
    void sessionStart();
};

#endif // SESSIONMNGR_H
