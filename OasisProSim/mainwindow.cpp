#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup timers
    idleTimer = new QTimer();
    batteryLifeTimer = new QTimer();

    //create manager
    mngr = new sessionMngr(this);

    //connect slots
    connect(ui->powerButton, SIGNAL(released()), this, SLOT (togglePwr()));
    connect(idleTimer, SIGNAL(timeout()),this,SLOT (idleTimerExpired()));
    connect(batteryLifeTimer, SIGNAL(timeout()),this,SLOT (batteryLifeTimerTick()));
    connect(ui->adminConnectedComboBox, SIGNAL(currentIndexChanged(int)),this,SLOT (updateConnection()));
    connect(ui->checkButton, SIGNAL(released()),this,SLOT (checkButtonPress()));
    connect(ui->upIntButton, SIGNAL(released()),this,SLOT (changeInstensity()));
    connect(ui->downIntButton, SIGNAL(released()),this,SLOT (changeInstensity()));

    //connect siganls from sessionMngr to slots
    connect(mngr,SIGNAL(sessionStart()),this,SLOT (displaySessionStart()));

    //init buttons / displays / battery
    isOn=false;
    batteryLife=100;
    ui->batteryLifeBar->setValue(batteryLife);
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
            batteryLifeTimer->start(10000); //the battery will decrease 1% every 10 seconds
            ui->batteryLifeBar->setValue(batteryLife);
        }
    }else {
        //if a session is in progress, end it properly before turning off
        if (sessionInProgress==true){
            //endSession();
            //saveReplay(); //not sure if these are going to be two separate functions
        } else {
            qInfo("Turning off");
            isOn=false;
            ui->powrButtonLight->setStyleSheet("background-color:white");
            idleTimer->stop();
            batteryLifeTimer->stop();
        }
    }
}


void MainWindow::idleTimerExpired(){
    //we will impliment such that when a session is started, this timer is stopped so this function will not be called
    qInfo("Idle timer expired");
    togglePwr();
}

void MainWindow::batteryLifeTimerTick(){
    if (sessionInProgress==true){
        //i will need to add more code here as battery decrease depends on the current current output
        //we could also stop the battery timer and start it again with a faster interval depending on the current output, so basically
        //  we could have it just lose 1% every 5 seconds instead of 1% every 10 seconds
        batteryLife-=3;
    } else{
        batteryLife-=1;
    }
    //update the ui and handel dead battery behaviour
    ui->batteryLifeBar->setValue(batteryLife);
    if (batteryLife==0){
        qInfo("Battery has died");
        togglePwr();
    }

}

void MainWindow::updateConnection(){
    if(ui->adminConnectedComboBox->currentIndex() == 0)
        mngr->setConnected(true);
    else
        mngr->setConnected(false);
}


void MainWindow::displaySessionStart(){
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
    mngr->startSession(dur,ui->sessionSelectionComboBox->currentIndex(),5);

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
