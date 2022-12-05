#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup timers
    idleTimer = new QTimer();

    //create manager
    mngr = new sessionMngr(this);

    //connect slots
    connect(ui->powerButton, SIGNAL(released()), this, SLOT (togglePwr()));
    connect(idleTimer, SIGNAL(timeout()),this,SLOT (idleTimerExpired()));
    connect(mngr->batteryLifeTimer, SIGNAL(timeout()),this,SLOT (batteryLifeTimerTick()));
    connect(ui->adminConnectedComboBox, SIGNAL(currentIndexChanged(int)),this,SLOT (updateConnection()));
    connect(ui->checkButton, SIGNAL(released()),this,SLOT (checkButtonPress()));
    connect(ui->upIntButton, SIGNAL(released()),this,SLOT (changeInstensity()));
    connect(ui->downIntButton, SIGNAL(released()),this,SLOT (changeInstensity()));

    //connect siganls from sessionMngr to slots
    connect(mngr,SIGNAL(sessionStart()),this,SLOT (onSessionStart()));

    //init buttons / displays / battery
    isOn=false;
    sessionInProgress = false;
    batteryLife=99.99;
    currIntensity = 0;
    ui->adminBatterySpinBox->setValue(batteryLife);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::togglePwr(){
    //if the device is off and has power remaining, activate the power button light and set "isOn" true, start the idle timer and battery progress
    if (isOn==false){
        if (batteryLife<=0){
            qInfo("Battery dead, Please charge");
        }else{
            qInfo("Turning on");
            isOn=true;
            ui->powrButtonLight->setStyleSheet("background-color:green");
            idleTimer->start(120000); //this will be set to 2 minutes
        }
    }else {
        //if a session is in progress, end it properly before turning off
        if (sessionInProgress==true){
            //endSession(); //will need to turn battery tick timer off in this function
            //saveReplay(); //not sure if these are going to be two separate functions
        } else {
            qInfo("Turning off");
            isOn=false;
            ui->powrButtonLight->setStyleSheet("background-color:white");
            idleTimer->stop();
        }
    }
}

void MainWindow::idleTimerExpired(){
    //we will impliment such that when a session is started, this timer is stopped so this function will not be called
    qInfo("Idle timer expired");
    togglePwr();
}

void MainWindow::batteryLifeTimerTick(){
    //i will need to add more code here as battery decrease depends on the current current output
    //we could also stop the battery timer and start it again with a faster interval depending on the current output, so basically
    //we could have it just lose .01% every 1 seconds instead of 1% every 1 seconds
    batteryLife -= (0.01 + (0.01 * currIntensity));
    //update the ui and handel dead battery behaviour
    ui->adminBatterySpinBox->setValue(batteryLife);

    if (batteryLife<=0){
        qInfo("Battery has died");
        togglePwr();
        mngr->batteryLifeTimer->stop(); //replace one endSession() is done, should probably be done in sessionmngr
        return;
    }
}

void MainWindow::updateConnection(){
    if(ui->adminConnectedComboBox->currentIndex() == 0) {
        mngr->setConnected(true);
    }
    //session is running and user disconnects ear clips
    else if (sessionInProgress && ui->adminConnectedComboBox->currentIndex() == 1){
        mngr->setConnected(false);
        mngr->pauseSession();
    }
    //reconnect ear clips from paused session
    else if (mngr->isSessionPaused() && ui->adminConnectedComboBox->currentIndex() == 0) {
        mngr->setConnected(true);
        mngr->unpauseSession();
    }
    else{
        mngr->setConnected(false);
    }
}

void MainWindow::onSessionStart(){
    //the signal from session manager has informed the main window of session start, so update the members and stop the idleTimer
    sessionInProgress=true;
    idleTimer->stop();

}

void MainWindow::checkButtonPress(){
    //TO DO: we need to actually adjust the values here to pass

    int dur;
    if (ui->timeSelectionComboBox->currentIndex()==0){
        dur=20;
    }
    ui->adminBatterySpinBox->setValue(batteryLife);

    mngr->startSession(dur, ui->sessionSelectionComboBox->currentIndex(), 5); //passing temporary value must change this
}

void MainWindow::changeInstensity(){
    if (isOn==true){
        if (sender()==ui->upIntButton){
            if (currIntensity<8){
                currIntensity++;
            }
        } else
        if (sender()==ui->downIntButton){
            if (currIntensity>0){
                currIntensity--;
            }
        }
        //now set the three graphs on the UI to match the intensity
        //gonna be a lot of ifs
        if (currIntensity<4){
            ui->top2Graphs->setValue(0);
            ui->middle3Graphs->setValue(0);
            ui->bottom3Graphs->setValue(currIntensity);
        } else
        if (currIntensity<7){
            ui->bottom3Graphs->setValue(3);
            ui->middle3Graphs->setValue(currIntensity-3);
            ui->top2Graphs->setValue(0);
        } else {
            ui->bottom3Graphs->setValue(3);
            ui->middle3Graphs->setValue(3);
            ui->top2Graphs->setValue(currIntensity-6);
        }
    }
}
