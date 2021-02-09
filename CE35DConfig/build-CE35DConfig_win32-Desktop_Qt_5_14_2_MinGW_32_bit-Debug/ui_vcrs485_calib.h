/********************************************************************************
** Form generated from reading UI file 'vcrs485_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCRS485_CALIB_H
#define UI_VCRS485_CALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_VCRS485_Calib
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QCheckBox *Volt_1;
    QCheckBox *Volt_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *Dia;
    QSpinBox *up;
    QSpinBox *dwn;
    QPushButton *diaWrite;
    QPushButton *upWrite;
    QPushButton *dwnWrite;
    QPushButton *Calibrate;
    QLabel *dia_label;
    QLabel *label_7;
    QPushButton *avgWrite;
    QDoubleSpinBox *avg;
    QLineEdit *passw;
    QPushButton *pswWrite;
    QPushButton *Cancel;
    QLabel *label_8;

    void setupUi(QDialog *VCRS485_Calib)
    {
        if (VCRS485_Calib->objectName().isEmpty())
            VCRS485_Calib->setObjectName(QString::fromUtf8("VCRS485_Calib"));
        VCRS485_Calib->resize(400, 260);
        VCRS485_Calib->setMinimumSize(QSize(400, 260));
        VCRS485_Calib->setMaximumSize(QSize(400, 260));
        groupBox = new QGroupBox(VCRS485_Calib);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(5, 0, 390, 160));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 15, 181, 15));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        Volt_1 = new QCheckBox(groupBox);
        Volt_1->setObjectName(QString::fromUtf8("Volt_1"));
        Volt_1->setGeometry(QRect(220, 15, 15, 15));
        sizePolicy.setHeightForWidth(Volt_1->sizePolicy().hasHeightForWidth());
        Volt_1->setSizePolicy(sizePolicy);
        Volt_2 = new QCheckBox(groupBox);
        Volt_2->setObjectName(QString::fromUtf8("Volt_2"));
        Volt_2->setGeometry(QRect(267, 15, 15, 15));
        sizePolicy.setHeightForWidth(Volt_2->sizePolicy().hasHeightForWidth());
        Volt_2->setSizePolicy(sizePolicy);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 15, 31, 15));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(247, 15, 21, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 35, 121, 26));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 64, 221, 22));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 94, 221, 22));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        Dia = new QComboBox(groupBox);
        Dia->addItem(QString());
        Dia->addItem(QString());
        Dia->addItem(QString());
        Dia->setObjectName(QString::fromUtf8("Dia"));
        Dia->setGeometry(QRect(200, 35, 80, 20));
        sizePolicy.setHeightForWidth(Dia->sizePolicy().hasHeightForWidth());
        Dia->setSizePolicy(sizePolicy);
        up = new QSpinBox(groupBox);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(200, 64, 80, 22));
        sizePolicy.setHeightForWidth(up->sizePolicy().hasHeightForWidth());
        up->setSizePolicy(sizePolicy);
        up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        up->setMinimum(-800000);
        up->setMaximum(800000);
        dwn = new QSpinBox(groupBox);
        dwn->setObjectName(QString::fromUtf8("dwn"));
        dwn->setGeometry(QRect(200, 94, 80, 22));
        sizePolicy.setHeightForWidth(dwn->sizePolicy().hasHeightForWidth());
        dwn->setSizePolicy(sizePolicy);
        dwn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dwn->setMinimum(-800000);
        dwn->setMaximum(800000);
        diaWrite = new QPushButton(groupBox);
        diaWrite->setObjectName(QString::fromUtf8("diaWrite"));
        diaWrite->setGeometry(QRect(290, 32, 90, 26));
        sizePolicy.setHeightForWidth(diaWrite->sizePolicy().hasHeightForWidth());
        diaWrite->setSizePolicy(sizePolicy);
        upWrite = new QPushButton(groupBox);
        upWrite->setObjectName(QString::fromUtf8("upWrite"));
        upWrite->setGeometry(QRect(290, 62, 90, 26));
        sizePolicy.setHeightForWidth(upWrite->sizePolicy().hasHeightForWidth());
        upWrite->setSizePolicy(sizePolicy);
        dwnWrite = new QPushButton(groupBox);
        dwnWrite->setObjectName(QString::fromUtf8("dwnWrite"));
        dwnWrite->setGeometry(QRect(290, 92, 90, 26));
        sizePolicy.setHeightForWidth(dwnWrite->sizePolicy().hasHeightForWidth());
        dwnWrite->setSizePolicy(sizePolicy);
        Calibrate = new QPushButton(groupBox);
        Calibrate->setObjectName(QString::fromUtf8("Calibrate"));
        Calibrate->setGeometry(QRect(200, 125, 180, 26));
        sizePolicy.setHeightForWidth(Calibrate->sizePolicy().hasHeightForWidth());
        Calibrate->setSizePolicy(sizePolicy);
        dia_label = new QLabel(groupBox);
        dia_label->setObjectName(QString::fromUtf8("dia_label"));
        dia_label->setGeometry(QRect(128, 35, 71, 20));
        sizePolicy.setHeightForWidth(dia_label->sizePolicy().hasHeightForWidth());
        dia_label->setSizePolicy(sizePolicy);
        dia_label->setTextFormat(Qt::AutoText);
        dia_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(VCRS485_Calib);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 169, 175, 22));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        avgWrite = new QPushButton(VCRS485_Calib);
        avgWrite->setObjectName(QString::fromUtf8("avgWrite"));
        avgWrite->setGeometry(QRect(295, 167, 90, 26));
        sizePolicy.setHeightForWidth(avgWrite->sizePolicy().hasHeightForWidth());
        avgWrite->setSizePolicy(sizePolicy);
        avg = new QDoubleSpinBox(VCRS485_Calib);
        avg->setObjectName(QString::fromUtf8("avg"));
        avg->setGeometry(QRect(235, 169, 50, 22));
        sizePolicy.setHeightForWidth(avg->sizePolicy().hasHeightForWidth());
        avg->setSizePolicy(sizePolicy);
        avg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg->setDecimals(1);
        avg->setMinimum(0.100000000000000);
        avg->setMaximum(10.000000000000000);
        avg->setSingleStep(0.100000000000000);
        passw = new QLineEdit(VCRS485_Calib);
        passw->setObjectName(QString::fromUtf8("passw"));
        passw->setGeometry(QRect(130, 201, 155, 18));
        sizePolicy.setHeightForWidth(passw->sizePolicy().hasHeightForWidth());
        passw->setSizePolicy(sizePolicy);
        passw->setMaxLength(32);
        pswWrite = new QPushButton(VCRS485_Calib);
        pswWrite->setObjectName(QString::fromUtf8("pswWrite"));
        pswWrite->setGeometry(QRect(295, 197, 90, 26));
        sizePolicy.setHeightForWidth(pswWrite->sizePolicy().hasHeightForWidth());
        pswWrite->setSizePolicy(sizePolicy);
        Cancel = new QPushButton(VCRS485_Calib);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(295, 227, 90, 26));
        sizePolicy.setHeightForWidth(Cancel->sizePolicy().hasHeightForWidth());
        Cancel->setSizePolicy(sizePolicy);
        label_8 = new QLabel(VCRS485_Calib);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 201, 121, 18));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        retranslateUi(VCRS485_Calib);

        QMetaObject::connectSlotsByName(VCRS485_Calib);
    } // setupUi

    void retranslateUi(QDialog *VCRS485_Calib)
    {
        VCRS485_Calib->setWindowTitle(QCoreApplication::translate("VCRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 VC-RS485", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VCRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("VCRS485_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", nullptr));
        Volt_1->setText(QString());
        Volt_2->setText(QString());
        label_2->setText(QCoreApplication::translate("VCRS485_Calib", "\342\204\2261", nullptr));
        label_3->setText(QCoreApplication::translate("VCRS485_Calib", "\342\204\2262", nullptr));
        label_4->setText(QCoreApplication::translate("VCRS485_Calib", "\320\250\320\272\320\260\320\273\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("VCRS485_Calib", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", nullptr));
        label_6->setText(QCoreApplication::translate("VCRS485_Calib", "\320\235\320\270\320\266\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", nullptr));
        Dia->setItemText(0, QCoreApplication::translate("VCRS485_Calib", "\320\260\320\262\321\202\320\276", nullptr));
        Dia->setItemText(1, QCoreApplication::translate("VCRS485_Calib", "\320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274", nullptr));
        Dia->setItemText(2, QCoreApplication::translate("VCRS485_Calib", "\320\274\320\270\320\275\320\270\320\274\321\203\320\274", nullptr));

        diaWrite->setText(QCoreApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        upWrite->setText(QCoreApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        dwnWrite->setText(QCoreApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        Calibrate->setText(QCoreApplication::translate("VCRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        dia_label->setText(QCoreApplication::translate("VCRS485_Calib", "\342\204\2261, \342\204\2262", nullptr));
        label_7->setText(QCoreApplication::translate("VCRS485_Calib", "\320\222\321\200\320\265\320\274\321\217 \321\203\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\321\217, \321\201\320\265\320\272\321\203\320\275\320\264", nullptr));
        avgWrite->setText(QCoreApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pswWrite->setText(QCoreApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        Cancel->setText(QCoreApplication::translate("VCRS485_Calib", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_8->setText(QCoreApplication::translate("VCRS485_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VCRS485_Calib: public Ui_VCRS485_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCRS485_CALIB_H
