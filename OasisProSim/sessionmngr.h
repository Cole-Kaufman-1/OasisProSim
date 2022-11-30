#ifndef SESSIONMNGR_H
#define SESSIONMNGR_H

#include <QObject>
#include "session.h"
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>

class sessionMngr : public QObject
{
    Q_OBJECT
public:
    static const QString DATABASE_PATH;
    explicit sessionMngr(QObject *parent = nullptr);
    void startSession(int type, int duration, int intensity);
    void setConnected(bool connection);
    bool addSessionRecord(const QString& user, const QString& sessionType, int duration, int intensityLevel);
    bool addUserRecord(const QString &user);

    bool deleteRecords();
    void displayRecords();
private:
    bool connectionTest();
    bool DBInit();
    bool connected;
    QSqlDatabase db;
    bool isValidRecord(const QString& user, const QString& sessionType, int duration, int intensityLevel);




public slots:

signals:
    void sessionStart();
};

#endif // SESSIONMNGR_H
