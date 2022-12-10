#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup timers
    idleTimer = new QTimer();
    softOffTimer = new QTimer();
    softOnTimer = new QTimer();

    //create manager
    mngr = new sessionMngr(this);

    //connect slots
    connect(ui->powerButton, SIGNAL(released()), this, SLOT (togglePwr()));
    connect(idleTimer, SIGNAL(timeout()),this,SLOT (idleTimerExpired()));
    connect(mngr->batteryLifeTimer, SIGNAL(timeout()),this,SLOT (batteryLifeTimerTick()));
    connect(ui->adminConnectedComboBox, SIGNAL(currentIndexChanged(int)),this,SLOT (updateConnection()));
    connect(ui->connectElectrodeButton, SIGNAL(released()), this, SLOT(toggleElectrodes()));
    connect(ui->checkButton, SIGNAL(released()),this,SLOT (checkButtonPress()));
    connect(ui->upIntButton, SIGNAL(released()),this,SLOT (changeInstensity()));
    connect(ui->downIntButton, SIGNAL(released()),this,SLOT (changeInstensity()));
    connect(ui->adminIntensityLevelspinBox, SIGNAL(valueChanged(int)), SLOT(changeInstensityAdmin(int)));
    connect(ui->setDefaultIntensityButton, SIGNAL(released()),this,SLOT (setDefaultIntensity()));
    connect(softOffTimer, SIGNAL(timeout()),this,SLOT (softOff()));
    connect(softOnTimer, SIGNAL(timeout()),this,SLOT (softOn()));

    //connect siganls from sessionMngr to slots
    connect(mngr,SIGNAL(sessionStart()),this,SLOT (onSessionStart()));
    connect(mngr,SIGNAL(sessionEnd()),this,SLOT (onSessionEnd()));

    //init buttons / displays / battery
    isOn = false;
    sessionInProgress = false;
    isConnected = false;
    batteryLife = 99.99;
    currIntensity = 0;
    defaultIntensity = 1; //all sessions will set their intenstiy to this value unless changed manually
    ui->adminBatterySpinBox->setValue(batteryLife);
    //init with start session button and increase intensity spin box off
    ui->checkButton->setDisabled(true);
    ui->adminIntensityLevelspinBox->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::togglePwr(){
    //if the device is off and has power remaining, activate the power button light and set "isOn" true, start the idle timer and battery progress
    if (!isOn){
        if (batteryLife<=0){
            qInfo("Battery dead, Please charge");
        }else{
            qInfo("Turning on");
            //enable start session button and increase intensity spin box since device turned on
            ui->checkButton->setEnabled(true);
            ui->adminIntensityLevelspinBox->setEnabled(true);
            isOn=true;
            ui->powrButtonLight->setStyleSheet("background-color:green");
            idleTimer->start(120000); //this will be set to 2 minutes
        }
    }else {
        //disable start session button and intensity spin box since device turned off
        ui->checkButton->setDisabled(true);
        ui->adminIntensityLevelspinBox->setDisabled(true);
        //if a session is in progress, end it properly before turning off
        if (sessionInProgress){
            mngr->endSession(); //will need to turn battery tick timer off in this function

        } else {
            qInfo("Turning off");
            isOn=false;
            changeInstensity();
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
    batteryLife -= (0.01 + (0.01 * currIntensity));
    //update the ui and handle dead battery behaviour
    ui->adminBatterySpinBox->setValue(batteryLife);

    if (batteryLife<=0){
        qInfo("Battery has died");
        togglePwr();
        mngr->batteryLifeTimer->stop(); //replace once endSession() is done, should probably be done in sessionmngr
        return;
    }
}

void MainWindow::toggleElectrodes() {
    if (isConnected) {
        ui->adminConnectedComboBox->setCurrentIndex(1);
    }
    else {
        ui->adminConnectedComboBox->setCurrentIndex(0);
    }
}

void MainWindow::updateConnection(){
    if(ui->adminConnectedComboBox->currentIndex() == 0) {
        isConnected = true;
    }
    //session is running and user disconnects ear clips
    else if (sessionInProgress && ui->adminConnectedComboBox->currentIndex() == 1){
        isConnected = false;
        mngr->pauseSession();
    }
    //reconnect ear clips from paused session
    else if (mngr->isSessionPaused() && ui->adminConnectedComboBox->currentIndex() == 0) {
        isConnected = true;;
        mngr->unpauseSession();
    }
    else{
        isConnected = false;
    }
}

void MainWindow::onSessionStart(){
    //the signal from session manager has informed the main window of session start, so update the members and stop the idleTimer
    sessionInProgress=true;
    idleTimer->stop();
    currIntensity=0;
    softOnTimer->start(500);
}

void MainWindow::softOn(){
    if (currIntensity==defaultIntensity){
        changeInstensity();
        softOnTimer->stop();
        qInfo("soft on complete, enjoy the session");
    }else{
        changeInstensity();
        currIntensity++;
    }
}


void MainWindow::onSessionEnd(){
    //update the recording intensity to match the current user selected intensity
    session* currSess = mngr->getCurrentSession();
    currSess->setIntensity(currIntensity);

    //add the record to the database if the user choses to
    if (ui->adminRecordReplayCheckBox->isChecked()){
        mngr->addSessionRecord(ui->adminSelectUserComboBox->currentText(),currSess->getType(),currSess->getDuration(),currSess->getIntensity());
        ui->replaysDropdown->addItem("newReplay");
    }

    //finally start the soft off process
    currIntensity=8; //the intensity associated with the session will have already been saved, this is soley to visually show the soft off process
    softOffTimer->start(500);
}

void MainWindow::softOff(){
    if (currIntensity==0){
        qInfo("soft off complete, powering off");
        changeInstensity();
        softOffTimer->stop();
        sessionInProgress=false;
        isOn=false;
        ui->powrButtonLight->setStyleSheet("background-color:white");
    } else {
        changeInstensity();
        currIntensity--;
    }
}

void MainWindow::checkButtonPress(){
    //TO DO: we need to actually adjust the values here to pass

    int dur;
    if (ui->timeSelectionComboBox->currentIndex()==0){
        dur=20;
    }
    ui->adminBatterySpinBox->setValue(batteryLife);

    if (connectionTest()) {
        mngr->startSession("tempTreatment", ui->sessionSelectionComboBox->currentIndex(), 5); //passing temporary value must change this
    }
}

bool MainWindow::connectionTest(){
    //need to expand on this later by displaying according to the manual

    //inform console of connection state
    QString connectionResult = isConnected ? "device probes are connected" : "not connected, try again";
    qInfo() << connectionResult;
    return isConnected;
}

void MainWindow::changeInstensity(){
    if (isOn){
        if (sender()==ui->upIntButton){
            if (currIntensity<8){
                currIntensity++;
            }
        }
        else if (sender()==ui->downIntButton){
            if (currIntensity>0){
                currIntensity--;
            }
        }
        //now set the three graphs on the UI to match the intensity
        changeInstensityDisplay();

        //block signal temporarily while setting new intensity value (prevents intensity setting loop between spin box and buttons)
        ui->adminIntensityLevelspinBox->blockSignals(true);
        ui->adminIntensityLevelspinBox->setValue(currIntensity);
        ui->adminIntensityLevelspinBox->blockSignals(false);
    }
    else { //this segment will reset the graphs to 0 when someone turns off the device suddenly and a session is NOT active
        currIntensity=0;
        ui->adminIntensityLevelspinBox->setValue(currIntensity);
        ui->bottom3Graphs->setValue(0);
        ui->middle3Graphs->setValue(0);
        ui->top2Graphs->setValue(0);
    }
}

void MainWindow::changeInstensityDisplay() {
    if (currIntensity<4){
        ui->top2Graphs->setValue(0);
        ui->middle3Graphs->setValue(0);
        ui->bottom3Graphs->setValue(currIntensity);
    }
    else if (currIntensity<7){
        ui->bottom3Graphs->setValue(3);
        ui->middle3Graphs->setValue(currIntensity-3);
        ui->top2Graphs->setValue(0);
    }
    else {
        ui->bottom3Graphs->setValue(3);
        ui->middle3Graphs->setValue(3);
        ui->top2Graphs->setValue(currIntensity-6);
    }
}

void MainWindow::changeInstensityAdmin(int newVal) {
    if (newVal > currIntensity){
        currIntensity++;
    }
    else {
        currIntensity--;
    }
    changeInstensityDisplay();
}

void MainWindow::setDefaultIntensity(){
    defaultIntensity = currIntensity;
    qInfo("Default intensity updated to current intensity");
}
