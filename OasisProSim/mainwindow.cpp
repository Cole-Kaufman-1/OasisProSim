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
    sesnMngr = new sessionMngr();

    //connect slots
    connect(ui->powerButton, SIGNAL(released()), this, SLOT (togglePwr()));
    connect(idleTimer, SIGNAL(timeout()),this,SLOT (idleTimerExpired()));
    connect(batteryLifeTimer, SIGNAL(timeout()),this,SLOT (batteryLifeTimerTick()));

    connect(ui->adminConnectedComboBox, SIGNAL(currentIndexChanged(int)),this,SLOT (on_adminConnectedComboBox_currentIndexChanged(int index)));
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

void MainWindow::on_adminConnectedComboBox_currentIndexChanged(int index)
{
    if(index == 0)
        sesnMngr->setConnected(true);
    else
        sesnMngr->setConnected(false);
}
