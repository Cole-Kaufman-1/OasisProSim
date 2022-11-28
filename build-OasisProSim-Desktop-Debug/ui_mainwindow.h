/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainWindowCentralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *oasisProWidget;
    QPushButton *powerButton;
    QPushButton *downIntButton;
    QPushButton *upIntButton;
    QLabel *intLabel;
    QPushButton *checkButton;
    QProgressBar *bottom3Graphs;
    QLabel *canadaLabel;
    QLabel *ProLabel;
    QLabel *oasisLabel;
    QLabel *mindAliveLabel;
    QLabel *graphLabel1;
    QPushButton *powrButtonLight;
    QLabel *graphLabel2;
    QLabel *graphLabel3;
    QLabel *graphLabel4;
    QLabel *graphLabel5;
    QProgressBar *middle3Graphs;
    QLabel *graphLabel6;
    QLabel *graphLabel7;
    QLabel *graphLabel8;
    QProgressBar *top2Graphs;
    QPushButton *toggleElectrodes;
    QComboBox *comboBox;
    QLabel *timeSelectionLabel;
    QLabel *SessionSelectionLabel;
    QComboBox *comboBox_2;
    QLabel *connectElectrodeLabel;
    QPushButton *downIntButton_2;
    QPushButton *shortPulseButtonLight;
    QSpinBox *userDesignatedspinBox;
    QLabel *timeSelectionLabel_2;
    QTabWidget *tabWidget;
    QWidget *adminTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *adminTabVlLayout;
    QGridLayout *adminTabGridLayout;
    QLabel *adminBatteryLevelLabel;
    QLabel *adminPowerLevelLabel;
    QLabel *adminConnectedLabel;
    QComboBox *adminConnectedComboBox;
    QDoubleSpinBox *adminBatteryLevelSpinBox;
    QSpinBox *adminPowerLevelspinBox;
    QProgressBar *batteryLifeBar;
    QSpacerItem *adminTabSpacer;
    QWidget *replayTab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *replayTabLayout;
    QScrollArea *replayTabScrollArea;
    QWidget *replayTabScrollAreaWidgetContents;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *replayTabVLayout;
    QLabel *exampleReplayLabel;
    QSpacerItem *replayTabSpacer;
    QPushButton *selectReplayButton;
    QFrame *line;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(798, 600);
        mainWindowCentralWidget = new QWidget(MainWindow);
        mainWindowCentralWidget->setObjectName(QString::fromUtf8("mainWindowCentralWidget"));
        verticalLayout = new QVBoxLayout(mainWindowCentralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        oasisProWidget = new QWidget(mainWindowCentralWidget);
        oasisProWidget->setObjectName(QString::fromUtf8("oasisProWidget"));
        powerButton = new QPushButton(oasisProWidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(570, 300, 80, 25));
        downIntButton = new QPushButton(oasisProWidget);
        downIntButton->setObjectName(QString::fromUtf8("downIntButton"));
        downIntButton->setGeometry(QRect(480, 300, 80, 25));
        upIntButton = new QPushButton(oasisProWidget);
        upIntButton->setObjectName(QString::fromUtf8("upIntButton"));
        upIntButton->setGeometry(QRect(480, 270, 80, 25));
        intLabel = new QLabel(oasisProWidget);
        intLabel->setObjectName(QString::fromUtf8("intLabel"));
        intLabel->setGeometry(QRect(483, 250, 71, 20));
        QFont font;
        font.setPointSize(14);
        intLabel->setFont(font);
        intLabel->setStyleSheet(QString::fromUtf8("color: rgb(196, 160, 0);"));
        intLabel->setAlignment(Qt::AlignCenter);
        checkButton = new QPushButton(oasisProWidget);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(20, 280, 61, 41));
        QFont font1;
        font1.setPointSize(18);
        checkButton->setFont(font1);
        bottom3Graphs = new QProgressBar(oasisProWidget);
        bottom3Graphs->setObjectName(QString::fromUtf8("bottom3Graphs"));
        bottom3Graphs->setGeometry(QRect(190, 280, 51, 51));
        bottom3Graphs->setMaximum(3);
        bottom3Graphs->setValue(0);
        bottom3Graphs->setTextVisible(false);
        bottom3Graphs->setOrientation(Qt::Vertical);
        canadaLabel = new QLabel(oasisProWidget);
        canadaLabel->setObjectName(QString::fromUtf8("canadaLabel"));
        canadaLabel->setGeometry(QRect(680, 300, 91, 20));
        canadaLabel->setFont(font);
        canadaLabel->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);"));
        canadaLabel->setAlignment(Qt::AlignCenter);
        ProLabel = new QLabel(oasisProWidget);
        ProLabel->setObjectName(QString::fromUtf8("ProLabel"));
        ProLabel->setGeometry(QRect(630, 120, 91, 20));
        ProLabel->setFont(font);
        ProLabel->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);"));
        ProLabel->setAlignment(Qt::AlignCenter);
        oasisLabel = new QLabel(oasisProWidget);
        oasisLabel->setObjectName(QString::fromUtf8("oasisLabel"));
        oasisLabel->setGeometry(QRect(660, 140, 91, 20));
        oasisLabel->setFont(font);
        oasisLabel->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);"));
        oasisLabel->setAlignment(Qt::AlignCenter);
        mindAliveLabel = new QLabel(oasisProWidget);
        mindAliveLabel->setObjectName(QString::fromUtf8("mindAliveLabel"));
        mindAliveLabel->setGeometry(QRect(680, 10, 91, 20));
        mindAliveLabel->setFont(font);
        mindAliveLabel->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);"));
        mindAliveLabel->setAlignment(Qt::AlignCenter);
        graphLabel1 = new QLabel(oasisProWidget);
        graphLabel1->setObjectName(QString::fromUtf8("graphLabel1"));
        graphLabel1->setGeometry(QRect(180, 310, 71, 20));
        QFont font2;
        font2.setPointSize(9);
        graphLabel1->setFont(font2);
        graphLabel1->setAlignment(Qt::AlignCenter);
        powrButtonLight = new QPushButton(oasisProWidget);
        powrButtonLight->setObjectName(QString::fromUtf8("powrButtonLight"));
        powrButtonLight->setEnabled(false);
        powrButtonLight->setGeometry(QRect(600, 270, 21, 25));
        powrButtonLight->setStyleSheet(QString::fromUtf8(""));
        powrButtonLight->setCheckable(false);
        powrButtonLight->setFlat(false);
        graphLabel2 = new QLabel(oasisProWidget);
        graphLabel2->setObjectName(QString::fromUtf8("graphLabel2"));
        graphLabel2->setGeometry(QRect(180, 295, 71, 20));
        graphLabel2->setFont(font2);
        graphLabel2->setAlignment(Qt::AlignCenter);
        graphLabel3 = new QLabel(oasisProWidget);
        graphLabel3->setObjectName(QString::fromUtf8("graphLabel3"));
        graphLabel3->setGeometry(QRect(180, 280, 71, 20));
        graphLabel3->setFont(font2);
        graphLabel3->setAlignment(Qt::AlignCenter);
        graphLabel4 = new QLabel(oasisProWidget);
        graphLabel4->setObjectName(QString::fromUtf8("graphLabel4"));
        graphLabel4->setGeometry(QRect(180, 260, 71, 20));
        graphLabel4->setFont(font2);
        graphLabel4->setAlignment(Qt::AlignCenter);
        graphLabel5 = new QLabel(oasisProWidget);
        graphLabel5->setObjectName(QString::fromUtf8("graphLabel5"));
        graphLabel5->setGeometry(QRect(180, 245, 71, 20));
        graphLabel5->setFont(font2);
        graphLabel5->setAlignment(Qt::AlignCenter);
        middle3Graphs = new QProgressBar(oasisProWidget);
        middle3Graphs->setObjectName(QString::fromUtf8("middle3Graphs"));
        middle3Graphs->setGeometry(QRect(190, 230, 51, 51));
        middle3Graphs->setMaximum(3);
        middle3Graphs->setValue(0);
        middle3Graphs->setTextVisible(false);
        middle3Graphs->setOrientation(Qt::Vertical);
        graphLabel6 = new QLabel(oasisProWidget);
        graphLabel6->setObjectName(QString::fromUtf8("graphLabel6"));
        graphLabel6->setGeometry(QRect(180, 230, 71, 20));
        graphLabel6->setFont(font2);
        graphLabel6->setAlignment(Qt::AlignCenter);
        graphLabel7 = new QLabel(oasisProWidget);
        graphLabel7->setObjectName(QString::fromUtf8("graphLabel7"));
        graphLabel7->setGeometry(QRect(180, 205, 71, 20));
        graphLabel7->setFont(font2);
        graphLabel7->setAlignment(Qt::AlignCenter);
        graphLabel8 = new QLabel(oasisProWidget);
        graphLabel8->setObjectName(QString::fromUtf8("graphLabel8"));
        graphLabel8->setGeometry(QRect(180, 190, 71, 20));
        graphLabel8->setFont(font2);
        graphLabel8->setAlignment(Qt::AlignCenter);
        top2Graphs = new QProgressBar(oasisProWidget);
        top2Graphs->setObjectName(QString::fromUtf8("top2Graphs"));
        top2Graphs->setGeometry(QRect(190, 190, 51, 41));
        top2Graphs->setMaximum(2);
        top2Graphs->setValue(-1);
        top2Graphs->setTextVisible(false);
        top2Graphs->setOrientation(Qt::Vertical);
        toggleElectrodes = new QPushButton(oasisProWidget);
        toggleElectrodes->setObjectName(QString::fromUtf8("toggleElectrodes"));
        toggleElectrodes->setEnabled(false);
        toggleElectrodes->setGeometry(QRect(0, 0, 781, 341));
        toggleElectrodes->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 11, 11);"));
        toggleElectrodes->setFlat(false);
        comboBox = new QComboBox(oasisProWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 50, 121, 25));
        timeSelectionLabel = new QLabel(oasisProWidget);
        timeSelectionLabel->setObjectName(QString::fromUtf8("timeSelectionLabel"));
        timeSelectionLabel->setGeometry(QRect(130, 20, 131, 20));
        timeSelectionLabel->setFont(font);
        timeSelectionLabel->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        timeSelectionLabel->setAlignment(Qt::AlignCenter);
        SessionSelectionLabel = new QLabel(oasisProWidget);
        SessionSelectionLabel->setObjectName(QString::fromUtf8("SessionSelectionLabel"));
        SessionSelectionLabel->setGeometry(QRect(270, 20, 161, 20));
        SessionSelectionLabel->setFont(font);
        SessionSelectionLabel->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        SessionSelectionLabel->setAlignment(Qt::AlignCenter);
        comboBox_2 = new QComboBox(oasisProWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(290, 50, 111, 25));
        connectElectrodeLabel = new QLabel(oasisProWidget);
        connectElectrodeLabel->setObjectName(QString::fromUtf8("connectElectrodeLabel"));
        connectElectrodeLabel->setGeometry(QRect(260, 270, 191, 20));
        connectElectrodeLabel->setFont(font);
        connectElectrodeLabel->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        connectElectrodeLabel->setAlignment(Qt::AlignCenter);
        downIntButton_2 = new QPushButton(oasisProWidget);
        downIntButton_2->setObjectName(QString::fromUtf8("downIntButton_2"));
        downIntButton_2->setGeometry(QRect(270, 300, 171, 25));
        shortPulseButtonLight = new QPushButton(oasisProWidget);
        shortPulseButtonLight->setObjectName(QString::fromUtf8("shortPulseButtonLight"));
        shortPulseButtonLight->setEnabled(false);
        shortPulseButtonLight->setGeometry(QRect(490, 10, 71, 25));
        shortPulseButtonLight->setStyleSheet(QString::fromUtf8(""));
        shortPulseButtonLight->setCheckable(false);
        shortPulseButtonLight->setFlat(false);
        userDesignatedspinBox = new QSpinBox(oasisProWidget);
        userDesignatedspinBox->setObjectName(QString::fromUtf8("userDesignatedspinBox"));
        userDesignatedspinBox->setGeometry(QRect(220, 90, 45, 26));
        userDesignatedspinBox->setMinimum(1);
        userDesignatedspinBox->setMaximum(60);
        timeSelectionLabel_2 = new QLabel(oasisProWidget);
        timeSelectionLabel_2->setObjectName(QString::fromUtf8("timeSelectionLabel_2"));
        timeSelectionLabel_2->setGeometry(QRect(10, 80, 201, 41));
        timeSelectionLabel_2->setFont(font);
        timeSelectionLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        timeSelectionLabel_2->setAlignment(Qt::AlignCenter);
        toggleElectrodes->raise();
        top2Graphs->raise();
        middle3Graphs->raise();
        powerButton->raise();
        downIntButton->raise();
        upIntButton->raise();
        intLabel->raise();
        checkButton->raise();
        bottom3Graphs->raise();
        canadaLabel->raise();
        ProLabel->raise();
        oasisLabel->raise();
        mindAliveLabel->raise();
        graphLabel1->raise();
        powrButtonLight->raise();
        graphLabel2->raise();
        graphLabel3->raise();
        graphLabel4->raise();
        graphLabel5->raise();
        graphLabel6->raise();
        graphLabel7->raise();
        graphLabel8->raise();
        comboBox->raise();
        timeSelectionLabel->raise();
        SessionSelectionLabel->raise();
        comboBox_2->raise();
        connectElectrodeLabel->raise();
        downIntButton_2->raise();
        shortPulseButtonLight->raise();
        userDesignatedspinBox->raise();
        timeSelectionLabel_2->raise();

        verticalLayout->addWidget(oasisProWidget);

        tabWidget = new QTabWidget(mainWindowCentralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        adminTab = new QWidget();
        adminTab->setObjectName(QString::fromUtf8("adminTab"));
        verticalLayoutWidget = new QWidget(adminTab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 781, 201));
        adminTabVlLayout = new QVBoxLayout(verticalLayoutWidget);
        adminTabVlLayout->setObjectName(QString::fromUtf8("adminTabVlLayout"));
        adminTabVlLayout->setContentsMargins(5, 5, 5, 5);
        adminTabGridLayout = new QGridLayout();
        adminTabGridLayout->setObjectName(QString::fromUtf8("adminTabGridLayout"));
        adminBatteryLevelLabel = new QLabel(verticalLayoutWidget);
        adminBatteryLevelLabel->setObjectName(QString::fromUtf8("adminBatteryLevelLabel"));

        adminTabGridLayout->addWidget(adminBatteryLevelLabel, 0, 0, 1, 1);

        adminPowerLevelLabel = new QLabel(verticalLayoutWidget);
        adminPowerLevelLabel->setObjectName(QString::fromUtf8("adminPowerLevelLabel"));

        adminTabGridLayout->addWidget(adminPowerLevelLabel, 1, 0, 1, 1);

        adminConnectedLabel = new QLabel(verticalLayoutWidget);
        adminConnectedLabel->setObjectName(QString::fromUtf8("adminConnectedLabel"));

        adminTabGridLayout->addWidget(adminConnectedLabel, 2, 0, 1, 1);

        adminConnectedComboBox = new QComboBox(verticalLayoutWidget);
        adminConnectedComboBox->addItem(QString());
        adminConnectedComboBox->addItem(QString());
        adminConnectedComboBox->setObjectName(QString::fromUtf8("adminConnectedComboBox"));

        adminTabGridLayout->addWidget(adminConnectedComboBox, 2, 2, 1, 1);

        adminBatteryLevelSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        adminBatteryLevelSpinBox->setObjectName(QString::fromUtf8("adminBatteryLevelSpinBox"));

        adminTabGridLayout->addWidget(adminBatteryLevelSpinBox, 0, 2, 1, 1);

        adminPowerLevelspinBox = new QSpinBox(verticalLayoutWidget);
        adminPowerLevelspinBox->setObjectName(QString::fromUtf8("adminPowerLevelspinBox"));
        adminPowerLevelspinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adminPowerLevelspinBox->setMinimum(1);
        adminPowerLevelspinBox->setMaximum(8);

        adminTabGridLayout->addWidget(adminPowerLevelspinBox, 1, 2, 1, 1);

        batteryLifeBar = new QProgressBar(verticalLayoutWidget);
        batteryLifeBar->setObjectName(QString::fromUtf8("batteryLifeBar"));
        batteryLifeBar->setValue(24);

        adminTabGridLayout->addWidget(batteryLifeBar, 0, 1, 1, 1);

        adminTabGridLayout->setColumnStretch(0, 1);

        adminTabVlLayout->addLayout(adminTabGridLayout);

        adminTabSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        adminTabVlLayout->addItem(adminTabSpacer);

        tabWidget->addTab(adminTab, QString());
        replayTab = new QWidget();
        replayTab->setObjectName(QString::fromUtf8("replayTab"));
        horizontalLayoutWidget = new QWidget(replayTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 781, 201));
        replayTabLayout = new QHBoxLayout(horizontalLayoutWidget);
        replayTabLayout->setObjectName(QString::fromUtf8("replayTabLayout"));
        replayTabLayout->setContentsMargins(0, 0, 0, 0);
        replayTabScrollArea = new QScrollArea(horizontalLayoutWidget);
        replayTabScrollArea->setObjectName(QString::fromUtf8("replayTabScrollArea"));
        replayTabScrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        replayTabScrollArea->setLineWidth(2);
        replayTabScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        replayTabScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        replayTabScrollArea->setWidgetResizable(true);
        replayTabScrollAreaWidgetContents = new QWidget();
        replayTabScrollAreaWidgetContents->setObjectName(QString::fromUtf8("replayTabScrollAreaWidgetContents"));
        replayTabScrollAreaWidgetContents->setGeometry(QRect(0, 0, 763, 197));
        verticalLayoutWidget_2 = new QWidget(replayTabScrollAreaWidgetContents);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 641, 201));
        replayTabVLayout = new QVBoxLayout(verticalLayoutWidget_2);
        replayTabVLayout->setObjectName(QString::fromUtf8("replayTabVLayout"));
        replayTabVLayout->setContentsMargins(5, 5, 5, 5);
        exampleReplayLabel = new QLabel(verticalLayoutWidget_2);
        exampleReplayLabel->setObjectName(QString::fromUtf8("exampleReplayLabel"));
        QFont font3;
        font3.setPointSize(11);
        exampleReplayLabel->setFont(font3);
        exampleReplayLabel->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        exampleReplayLabel->setWordWrap(true);

        replayTabVLayout->addWidget(exampleReplayLabel);

        replayTabSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        replayTabVLayout->addItem(replayTabSpacer);

        selectReplayButton = new QPushButton(replayTabScrollAreaWidgetContents);
        selectReplayButton->setObjectName(QString::fromUtf8("selectReplayButton"));
        selectReplayButton->setGeometry(QRect(650, 60, 101, 71));
        selectReplayButton->setFont(font);
        selectReplayButton->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        line = new QFrame(replayTabScrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(637, 0, 20, 201));
        line->setFont(font2);
        line->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(5);
        line->setFrameShape(QFrame::VLine);
        replayTabScrollArea->setWidget(replayTabScrollAreaWidgetContents);

        replayTabLayout->addWidget(replayTabScrollArea);

        tabWidget->addTab(replayTab, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 4);
        MainWindow->setCentralWidget(mainWindowCentralWidget);

        retranslateUi(MainWindow);

        powrButtonLight->setDefault(false);
        toggleElectrodes->setDefault(false);
        shortPulseButtonLight->setDefault(false);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        powerButton->setText(QApplication::translate("MainWindow", "Power", nullptr));
        downIntButton->setText(QApplication::translate("MainWindow", "Down", nullptr));
        upIntButton->setText(QApplication::translate("MainWindow", "Up", nullptr));
        intLabel->setText(QApplication::translate("MainWindow", "INT", nullptr));
        checkButton->setText(QApplication::translate("MainWindow", "\342\234\223", nullptr));
        canadaLabel->setText(QApplication::translate("MainWindow", "canada", nullptr));
        ProLabel->setText(QApplication::translate("MainWindow", "Oasis", nullptr));
        oasisLabel->setText(QApplication::translate("MainWindow", "Pro", nullptr));
        mindAliveLabel->setText(QApplication::translate("MainWindow", "mind alive", nullptr));
        graphLabel1->setText(QApplication::translate("MainWindow", "|1|", nullptr));
        powrButtonLight->setText(QString());
        graphLabel2->setText(QApplication::translate("MainWindow", "|2|", nullptr));
        graphLabel3->setText(QApplication::translate("MainWindow", "|3|", nullptr));
        graphLabel4->setText(QApplication::translate("MainWindow", "|4|", nullptr));
        graphLabel5->setText(QApplication::translate("MainWindow", "|5|", nullptr));
        graphLabel6->setText(QApplication::translate("MainWindow", "|6|", nullptr));
        graphLabel7->setText(QApplication::translate("MainWindow", "|7|", nullptr));
        graphLabel8->setText(QApplication::translate("MainWindow", "|8|", nullptr));
        toggleElectrodes->setText(QString());
        comboBox->setItemText(0, QApplication::translate("MainWindow", "20 Minutes", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "45 Minutes", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "User Designated", nullptr));

        timeSelectionLabel->setText(QApplication::translate("MainWindow", "Time Selection", nullptr));
        SessionSelectionLabel->setText(QApplication::translate("MainWindow", "Session Selection", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "Delta", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "Theta", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", "Alpha", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MainWindow", "Beta 1", nullptr));

        connectElectrodeLabel->setText(QApplication::translate("MainWindow", "Connect Electrodes", nullptr));
        downIntButton_2->setText(QString());
        shortPulseButtonLight->setText(QApplication::translate("MainWindow", "Short Pulse", nullptr));
        timeSelectionLabel_2->setText(QApplication::translate("MainWindow", "User Designated Time", nullptr));
        adminBatteryLevelLabel->setText(QApplication::translate("MainWindow", "Battery Level", nullptr));
        adminPowerLevelLabel->setText(QApplication::translate("MainWindow", "Power Level", nullptr));
        adminConnectedLabel->setText(QApplication::translate("MainWindow", "Connected", nullptr));
        adminConnectedComboBox->setItemText(0, QApplication::translate("MainWindow", "TRUE", nullptr));
        adminConnectedComboBox->setItemText(1, QApplication::translate("MainWindow", "FALSE", nullptr));

        adminConnectedComboBox->setCurrentText(QApplication::translate("MainWindow", "TRUE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(adminTab), QApplication::translate("MainWindow", "Admin", nullptr));
        exampleReplayLabel->setText(QApplication::translate("MainWindow", "1 - Session Type: Delta  Duration: 20 Minutes, Intensity: 8 (example while working)", nullptr));
        selectReplayButton->setText(QApplication::translate("MainWindow", "Select \n"
" Recording", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(replayTab), QApplication::translate("MainWindow", "Replays", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
