/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_2;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(635, 539);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 281, 411));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 430, 97, 33));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 430, 97, 33));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 20, 67, 21));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(480, 20, 121, 29));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 80, 67, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(540, 70, 52, 31));
        spinBox->setMaximum(500);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 130, 67, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(490, 120, 113, 33));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 200, 81, 21));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(530, 200, 76, 31));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 260, 121, 21));
        doubleSpinBox_2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(530, 260, 76, 31));
        doubleSpinBox_2->setMaximum(1);
        doubleSpinBox_2->setSingleStep(0.1);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 430, 391, 33));
        doubleSpinBox_3 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(320, 300, 76, 31));
        doubleSpinBox_3->setMinimum(-5000);
        doubleSpinBox_3->setMaximum(5000);
        doubleSpinBox_4 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(420, 300, 76, 31));
        doubleSpinBox_4->setMinimum(-5000);
        doubleSpinBox_4->setMaximum(5000);
        doubleSpinBox_5 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(520, 300, 76, 31));
        doubleSpinBox_5->setMinimum(-5000);
        doubleSpinBox_5->setMaximum(5000);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(310, 310, 67, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(410, 310, 67, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(510, 310, 67, 21));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 380, 97, 33));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 380, 97, 33));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 380, 97, 33));
        doubleSpinBox_6 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(320, 340, 76, 31));
        doubleSpinBox_6->setMinimum(-5000);
        doubleSpinBox_6->setMaximum(5000);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(410, 350, 67, 21));
        doubleSpinBox_7 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(420, 340, 76, 31));
        doubleSpinBox_7->setMinimum(-5000);
        doubleSpinBox_7->setMaximum(5000);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(510, 350, 67, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(310, 350, 67, 21));
        doubleSpinBox_8 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(520, 340, 76, 31));
        doubleSpinBox_8->setMinimum(-5000);
        doubleSpinBox_8->setMaximum(5000);
        MainWindow->setCentralWidget(centralWidget);
        listWidget->raise();
        pushButton->raise();
        pushButton_2->raise();
        label->raise();
        comboBox->raise();
        label_2->raise();
        spinBox->raise();
        label_3->raise();
        lineEdit->raise();
        label_4->raise();
        doubleSpinBox->raise();
        label_5->raise();
        doubleSpinBox_2->raise();
        lineEdit_2->raise();
        doubleSpinBox_3->raise();
        doubleSpinBox_4->raise();
        doubleSpinBox_5->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        doubleSpinBox_6->raise();
        doubleSpinBox_7->raise();
        label_12->raise();
        doubleSpinBox_8->raise();
        label_11->raise();
        label_10->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 635, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Editeur Rtracer", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Save", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Load", 0));
        label->setText(QApplication::translate("MainWindow", "Type :", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SPHERE", 0)
         << QApplication::translate("MainWindow", "PLAN", 0)
         << QApplication::translate("MainWindow", "CONNE", 0)
         << QApplication::translate("MainWindow", "CYLINDRE", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "Taille :", 0));
        label_3->setText(QApplication::translate("MainWindow", "Couleur :", 0));
        label_4->setText(QApplication::translate("MainWindow", "Reflexion : ", 0));
        label_5->setText(QApplication::translate("MainWindow", "Transparence : ", 0));
        label_7->setText(QApplication::translate("MainWindow", "x", 0));
        label_8->setText(QApplication::translate("MainWindow", " y", 0));
        label_9->setText(QApplication::translate("MainWindow", " z", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Ajouter", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Editer", 0));
        label_10->setText(QApplication::translate("MainWindow", "ry", 0));
        label_11->setText(QApplication::translate("MainWindow", "rz", 0));
        label_12->setText(QApplication::translate("MainWindow", "rx", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
