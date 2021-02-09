/********************************************************************************
** Form generated from reading UI file 'csrs485_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSRS485_CALIB_H
#define UI_CSRS485_CALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CSRS485_Calib
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *CalibZ;
    QPushButton *CalibV;
    QPushButton *Write;
    QPushButton *Cancel;
    QSpinBox *value;
    QLineEdit *passw;
    QLabel *label_3;

    void setupUi(QDialog *CSRS485_Calib)
    {
        if (CSRS485_Calib->objectName().isEmpty())
            CSRS485_Calib->setObjectName(QString::fromUtf8("CSRS485_Calib"));
        CSRS485_Calib->resize(372, 133);
        CSRS485_Calib->setMinimumSize(QSize(372, 133));
        CSRS485_Calib->setMaximumSize(QSize(372, 133));
        label = new QLabel(CSRS485_Calib);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 281, 26));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label_2 = new QLabel(CSRS485_Calib);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 42, 171, 22));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        CalibZ = new QPushButton(CSRS485_Calib);
        CalibZ->setObjectName(QString::fromUtf8("CalibZ"));
        CalibZ->setGeometry(QRect(275, 10, 90, 26));
        sizePolicy.setHeightForWidth(CalibZ->sizePolicy().hasHeightForWidth());
        CalibZ->setSizePolicy(sizePolicy);
        CalibV = new QPushButton(CSRS485_Calib);
        CalibV->setObjectName(QString::fromUtf8("CalibV"));
        CalibV->setGeometry(QRect(275, 40, 90, 26));
        sizePolicy.setHeightForWidth(CalibV->sizePolicy().hasHeightForWidth());
        CalibV->setSizePolicy(sizePolicy);
        Write = new QPushButton(CSRS485_Calib);
        Write->setObjectName(QString::fromUtf8("Write"));
        Write->setGeometry(QRect(275, 70, 90, 26));
        sizePolicy.setHeightForWidth(Write->sizePolicy().hasHeightForWidth());
        Write->setSizePolicy(sizePolicy);
        Cancel = new QPushButton(CSRS485_Calib);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(275, 100, 90, 26));
        sizePolicy.setHeightForWidth(Cancel->sizePolicy().hasHeightForWidth());
        Cancel->setSizePolicy(sizePolicy);
        value = new QSpinBox(CSRS485_Calib);
        value->setObjectName(QString::fromUtf8("value"));
        value->setGeometry(QRect(135, 42, 80, 22));
        sizePolicy.setHeightForWidth(value->sizePolicy().hasHeightForWidth());
        value->setSizePolicy(sizePolicy);
        value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        value->setMaximum(10000);
        passw = new QLineEdit(CSRS485_Calib);
        passw->setObjectName(QString::fromUtf8("passw"));
        passw->setGeometry(QRect(135, 74, 130, 18));
        sizePolicy.setHeightForWidth(passw->sizePolicy().hasHeightForWidth());
        passw->setSizePolicy(sizePolicy);
        passw->setMaxLength(32);
        label_3 = new QLabel(CSRS485_Calib);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 74, 141, 18));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        retranslateUi(CSRS485_Calib);

        QMetaObject::connectSlotsByName(CSRS485_Calib);
    } // setupUi

    void retranslateUi(QDialog *CSRS485_Calib)
    {
        CSRS485_Calib->setWindowTitle(QCoreApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 CS-RS485", nullptr));
        label->setText(QCoreApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\321\203\320\273\321\217 (<400ppm@60\320\274\320\270\320\275)", nullptr));
        label_2->setText(QCoreApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        CalibZ->setText(QCoreApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        CalibV->setText(QCoreApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        Write->setText(QCoreApplication::translate("CSRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        Cancel->setText(QCoreApplication::translate("CSRS485_Calib", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("CSRS485_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSRS485_Calib: public Ui_CSRS485_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSRS485_CALIB_H
