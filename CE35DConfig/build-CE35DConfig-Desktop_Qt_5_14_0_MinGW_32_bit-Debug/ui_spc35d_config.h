/********************************************************************************
** Form generated from reading UI file 'spc35d_config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPC35D_CONFIG_H
#define UI_SPC35D_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SPC35D_Config
{
public:
    QPushButton *addrWrite;
    QLabel *label_5;
    QPushButton *Cancel;
    QLineEdit *addr;
    QLabel *label_6;
    QLineEdit *passw;
    QPushButton *passwWrite;

    void setupUi(QDialog *SPC35D_Config)
    {
        if (SPC35D_Config->objectName().isEmpty())
            SPC35D_Config->setObjectName(QString::fromUtf8("SPC35D_Config"));
        SPC35D_Config->resize(440, 155);
        addrWrite = new QPushButton(SPC35D_Config);
        addrWrite->setObjectName(QString::fromUtf8("addrWrite"));
        addrWrite->setGeometry(QRect(340, 10, 90, 30));
        QFont font;
        font.setPointSize(9);
        addrWrite->setFont(font);
        label_5 = new QLabel(SPC35D_Config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 12, 121, 26));
        label_5->setFont(font);
        Cancel = new QPushButton(SPC35D_Config);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(340, 110, 90, 30));
        Cancel->setFont(font);
        addr = new QLineEdit(SPC35D_Config);
        addr->setObjectName(QString::fromUtf8("addr"));
        addr->setGeometry(QRect(140, 12, 180, 26));
        addr->setFont(font);
        addr->setMaxLength(20);
        label_6 = new QLabel(SPC35D_Config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 62, 121, 26));
        label_6->setFont(font);
        passw = new QLineEdit(SPC35D_Config);
        passw->setObjectName(QString::fromUtf8("passw"));
        passw->setGeometry(QRect(140, 62, 180, 26));
        passw->setMaxLength(20);
        passwWrite = new QPushButton(SPC35D_Config);
        passwWrite->setObjectName(QString::fromUtf8("passwWrite"));
        passwWrite->setGeometry(QRect(340, 60, 90, 30));
        passwWrite->setFont(font);

        retranslateUi(SPC35D_Config);

        QMetaObject::connectSlotsByName(SPC35D_Config);
    } // setupUi

    void retranslateUi(QDialog *SPC35D_Config)
    {
        SPC35D_Config->setWindowTitle(QCoreApplication::translate("SPC35D_Config", "Dialog", nullptr));
        addrWrite->setText(QCoreApplication::translate("SPC35D_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("SPC35D_Config", "\320\220\320\264\321\200\320\265\321\201 \321\201\321\207\320\265\321\202\321\207\320\270\320\272\320\260", nullptr));
        Cancel->setText(QCoreApplication::translate("SPC35D_Config", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        addr->setText(QString());
        label_6->setText(QCoreApplication::translate("SPC35D_Config", "\320\237\320\260\321\200\320\276\320\273\321\214 \321\201\321\207\320\265\321\202\321\207\320\270\320\272\320\260", nullptr));
        passwWrite->setText(QCoreApplication::translate("SPC35D_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SPC35D_Config: public Ui_SPC35D_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPC35D_CONFIG_H
