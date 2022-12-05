#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QtGlobal"
#include "sessionmngr.h"
#include <string>
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
    int batteryLife;
    bool sessionInProgress;
    int currIntensity;

    //members
    sessionMngr* mngr;
    QTimer* idleTimer;
    QTimer* batteryLifeTimer;


private slots:
    void togglePwr(); //turns device on and off

public slots:
    void idleTimerExpired(); //shuts device off if no session is started for 2 minutes after power on
    void batteryLifeTimerTick(); //gradually decreases the remaining battery life
    void updateConnection();
    void displaySessionStart();
    void checkButtonPress();
    void changeInstensity();


};
#endif // MAINWINDOW_H
