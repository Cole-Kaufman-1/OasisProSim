#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtGlobal>
#include "sessionmngr.h"
#include <string>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //member var
    bool isOn;
    bool isConnected;
    double batteryLife;
    bool sessionInProgress;
    int currIntensity;
    int defaultIntensity;
    QString currUser;

    //members
    sessionMngr* mngr;
    QTimer* idleTimer;
    QTimer* softOffTimer;
    QTimer* softOnTimer;

    //member methods
    bool connectionTest();
    void changeInstensityDisplay();
    int getTimeSelection();
    void setUserSessions();

private slots:
    void togglePwr(); //turns device on and off

public slots:
    void toggleElectrodes();
    void idleTimerExpired(); //shuts device off if no session is started for 2 minutes after power on
    void batteryLifeTimerTick(); //gradually decreases the remaining battery life
    void updateConnection();
    void onSessionStart();
    void softOn();
    void onSessionEnd();
    void softOff();
    void checkButtonPress();
    void changeInstensity();
    void changeInstensityAdmin(int);
    void setDefaultIntensity();
    void rechargeBattery();
    void changeUser(QString user);
    void setReplayValues();


};
#endif // MAINWINDOW_H
