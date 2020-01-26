/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *IMLOpenButton;
    QPushButton *IMLWriteButton;
    QLineEdit *IMLFileEdit;
    QLabel *labelInfo;
    QProgressBar *progressBar;
    QLineEdit *IpAddressIMLEdit;
    QLineEdit *BINFileEdit;
    QLineEdit *IpAddressBINEdit;
    QPushButton *BINOpenButton;
    QPushButton *BINWriteButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *BINUserEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *BINPasswordEdit;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 280);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(740, 280));
        MainWindow->setMaximumSize(QSize(740, 280));
        QIcon icon;
        icon.addFile(QString::fromUtf8("IMLEthernetLoader.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        IMLOpenButton = new QPushButton(centralwidget);
        IMLOpenButton->setObjectName(QString::fromUtf8("IMLOpenButton"));
        IMLOpenButton->setGeometry(QRect(480, 20, 111, 25));
        IMLWriteButton = new QPushButton(centralwidget);
        IMLWriteButton->setObjectName(QString::fromUtf8("IMLWriteButton"));
        IMLWriteButton->setGeometry(QRect(610, 20, 111, 25));
        IMLFileEdit = new QLineEdit(centralwidget);
        IMLFileEdit->setObjectName(QString::fromUtf8("IMLFileEdit"));
        IMLFileEdit->setGeometry(QRect(50, 20, 421, 25));
        labelInfo = new QLabel(centralwidget);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(10, 210, 721, 20));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(10, 230, 721, 23));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        IpAddressIMLEdit = new QLineEdit(centralwidget);
        IpAddressIMLEdit->setObjectName(QString::fromUtf8("IpAddressIMLEdit"));
        IpAddressIMLEdit->setGeometry(QRect(50, 55, 271, 25));
        BINFileEdit = new QLineEdit(centralwidget);
        BINFileEdit->setObjectName(QString::fromUtf8("BINFileEdit"));
        BINFileEdit->setGeometry(QRect(50, 100, 421, 25));
        IpAddressBINEdit = new QLineEdit(centralwidget);
        IpAddressBINEdit->setObjectName(QString::fromUtf8("IpAddressBINEdit"));
        IpAddressBINEdit->setGeometry(QRect(50, 135, 271, 25));
        BINOpenButton = new QPushButton(centralwidget);
        BINOpenButton->setObjectName(QString::fromUtf8("BINOpenButton"));
        BINOpenButton->setGeometry(QRect(480, 100, 111, 25));
        BINWriteButton = new QPushButton(centralwidget);
        BINWriteButton->setObjectName(QString::fromUtf8("BINWriteButton"));
        BINWriteButton->setGeometry(QRect(610, 100, 111, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 16, 67, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 56, 67, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 136, 67, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 98, 67, 31));
        BINUserEdit = new QLineEdit(centralwidget);
        BINUserEdit->setObjectName(QString::fromUtf8("BINUserEdit"));
        BINUserEdit->setGeometry(QRect(50, 170, 131, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 166, 67, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(240, 166, 67, 31));
        BINPasswordEdit = new QLineEdit(centralwidget);
        BINPasswordEdit->setObjectName(QString::fromUtf8("BINPasswordEdit"));
        BINPasswordEdit->setGeometry(QRect(320, 170, 151, 25));
        BINPasswordEdit->setEchoMode(QLineEdit::Password);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 740, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IML Ethernet Loader", nullptr));
        IMLOpenButton->setText(QCoreApplication::translate("MainWindow", "Open .iml", nullptr));
        IMLWriteButton->setText(QCoreApplication::translate("MainWindow", "Write .iml", nullptr));
        labelInfo->setText(QString());
        IpAddressIMLEdit->setInputMask(QString());
        IpAddressBINEdit->setInputMask(QString());
        BINOpenButton->setText(QCoreApplication::translate("MainWindow", "Open .bin", nullptr));
        BINWriteButton->setText(QCoreApplication::translate("MainWindow", "Write .bin", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Addr:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Addr:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        BINUserEdit->setText(QCoreApplication::translate("MainWindow", "user", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "User:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        BINPasswordEdit->setText(QCoreApplication::translate("MainWindow", "passw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
