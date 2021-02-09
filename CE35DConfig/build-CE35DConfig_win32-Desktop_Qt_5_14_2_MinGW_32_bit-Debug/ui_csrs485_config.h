/********************************************************************************
** Form generated from reading UI file 'csrs485_config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSRS485_CONFIG_H
#define UI_CSRS485_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CSRS485_Config
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *diap;
    QPushButton *dWrite;
    QCheckBox *correct;
    QPushButton *dWrite_2;
    QPushButton *Cancel;

    void setupUi(QDialog *CSRS485_Config)
    {
        if (CSRS485_Config->objectName().isEmpty())
            CSRS485_Config->setObjectName(QString::fromUtf8("CSRS485_Config"));
        CSRS485_Config->resize(375, 103);
        CSRS485_Config->setMinimumSize(QSize(375, 103));
        CSRS485_Config->setMaximumSize(QSize(375, 103));
        label = new QLabel(CSRS485_Config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 13, 191, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label_2 = new QLabel(CSRS485_Config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 45, 191, 20));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        diap = new QComboBox(CSRS485_Config);
        diap->addItem(QString());
        diap->addItem(QString());
        diap->setObjectName(QString::fromUtf8("diap"));
        diap->setGeometry(QRect(170, 13, 90, 20));
        sizePolicy.setHeightForWidth(diap->sizePolicy().hasHeightForWidth());
        diap->setSizePolicy(sizePolicy);
        dWrite = new QPushButton(CSRS485_Config);
        dWrite->setObjectName(QString::fromUtf8("dWrite"));
        dWrite->setGeometry(QRect(275, 10, 90, 26));
        sizePolicy.setHeightForWidth(dWrite->sizePolicy().hasHeightForWidth());
        dWrite->setSizePolicy(sizePolicy);
        correct = new QCheckBox(CSRS485_Config);
        correct->setObjectName(QString::fromUtf8("correct"));
        correct->setGeometry(QRect(247, 45, 15, 15));
        sizePolicy.setHeightForWidth(correct->sizePolicy().hasHeightForWidth());
        correct->setSizePolicy(sizePolicy);
        dWrite_2 = new QPushButton(CSRS485_Config);
        dWrite_2->setObjectName(QString::fromUtf8("dWrite_2"));
        dWrite_2->setGeometry(QRect(275, 40, 90, 26));
        sizePolicy.setHeightForWidth(dWrite_2->sizePolicy().hasHeightForWidth());
        dWrite_2->setSizePolicy(sizePolicy);
        Cancel = new QPushButton(CSRS485_Config);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(275, 70, 90, 26));
        sizePolicy.setHeightForWidth(Cancel->sizePolicy().hasHeightForWidth());
        Cancel->setSizePolicy(sizePolicy);

        retranslateUi(CSRS485_Config);

        QMetaObject::connectSlotsByName(CSRS485_Config);
    } // setupUi

    void retranslateUi(QDialog *CSRS485_Config)
    {
        CSRS485_Config->setWindowTitle(QCoreApplication::translate("CSRS485_Config", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 CS-RS485", nullptr));
        label->setText(QCoreApplication::translate("CSRS485_Config", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217, ppm", nullptr));
        label_2->setText(QCoreApplication::translate("CSRS485_Config", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", nullptr));
        diap->setItemText(0, QCoreApplication::translate("CSRS485_Config", "400-5000", nullptr));
        diap->setItemText(1, QCoreApplication::translate("CSRS485_Config", "400-10000", nullptr));

        dWrite->setText(QCoreApplication::translate("CSRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        correct->setText(QString());
        dWrite_2->setText(QCoreApplication::translate("CSRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        Cancel->setText(QCoreApplication::translate("CSRS485_Config", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSRS485_Config: public Ui_CSRS485_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSRS485_CONFIG_H
