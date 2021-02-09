/********************************************************************************
** Form generated from reading UI file 'asc35d_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASC35D_CALIB_H
#define UI_ASC35D_CALIB_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ASC35D_Calib
{
public:
    QPushButton *Cancel;
    QDoubleSpinBox *avg;
    QLabel *label_8;
    QPushButton *avgWrite;
    QPushButton *pswWrite;
    QLabel *label_7;
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
    QSpinBox *v_up;
    QSpinBox *v_dwn;
    QPushButton *v_diaWrite;
    QPushButton *v_upWrite;
    QPushButton *v_dwnWrite;
    QPushButton *v_Calibrate;
    QLabel *v_dia_label;
    QLineEdit *passw;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QCheckBox *Curr_1;
    QCheckBox *Curr_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QSpinBox *i_val;
    QPushButton *i_zWrite;
    QPushButton *i_Write;
    QPushButton *i_Calibrate;
    QGroupBox *groupBox_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *c_Calibrate;
    QRadioButton *Cloop_1;
    QRadioButton *Cloop_2;
    QRadioButton *Cloop_3;
    QLabel *label_17;
    QRadioButton *Cloop_4;
    QLabel *label_18;
    QLabel *label_19;
    QSpinBox *c_dwn;
    QPushButton *c_dwnWrite;
    QLabel *label_20;
    QPushButton *c_upWrite;
    QSpinBox *c_up;

    void setupUi(QDialog *ASC35D_Calib)
    {
        if (ASC35D_Calib->objectName().isEmpty())
            ASC35D_Calib->setObjectName(QString::fromUtf8("ASC35D_Calib"));
        ASC35D_Calib->resize(400, 513);
        ASC35D_Calib->setMinimumSize(QSize(400, 513));
        ASC35D_Calib->setMaximumSize(QSize(400, 513));
        Cancel = new QPushButton(ASC35D_Calib);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(295, 480, 90, 26));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cancel->sizePolicy().hasHeightForWidth());
        Cancel->setSizePolicy(sizePolicy);
        avg = new QDoubleSpinBox(ASC35D_Calib);
        avg->setObjectName(QString::fromUtf8("avg"));
        avg->setGeometry(QRect(235, 422, 50, 22));
        sizePolicy.setHeightForWidth(avg->sizePolicy().hasHeightForWidth());
        avg->setSizePolicy(sizePolicy);
        avg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg->setDecimals(1);
        avg->setMinimum(0.100000000000000);
        avg->setMaximum(10.000000000000000);
        avg->setSingleStep(0.100000000000000);
        label_8 = new QLabel(ASC35D_Calib);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 454, 121, 18));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        avgWrite = new QPushButton(ASC35D_Calib);
        avgWrite->setObjectName(QString::fromUtf8("avgWrite"));
        avgWrite->setGeometry(QRect(295, 420, 90, 26));
        sizePolicy.setHeightForWidth(avgWrite->sizePolicy().hasHeightForWidth());
        avgWrite->setSizePolicy(sizePolicy);
        pswWrite = new QPushButton(ASC35D_Calib);
        pswWrite->setObjectName(QString::fromUtf8("pswWrite"));
        pswWrite->setGeometry(QRect(295, 450, 90, 26));
        sizePolicy.setHeightForWidth(pswWrite->sizePolicy().hasHeightForWidth());
        pswWrite->setSizePolicy(sizePolicy);
        label_7 = new QLabel(ASC35D_Calib);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 422, 211, 22));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(ASC35D_Calib);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(5, 0, 390, 155));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 15, 180, 15));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        Volt_1 = new QCheckBox(groupBox);
        Volt_1->setObjectName(QString::fromUtf8("Volt_1"));
        Volt_1->setGeometry(QRect(220, 15, 15, 15));
        sizePolicy.setHeightForWidth(Volt_1->sizePolicy().hasHeightForWidth());
        Volt_1->setSizePolicy(sizePolicy);
        Volt_2 = new QCheckBox(groupBox);
        Volt_2->setObjectName(QString::fromUtf8("Volt_2"));
        Volt_2->setGeometry(QRect(267, 15, 25, 15));
        sizePolicy.setHeightForWidth(Volt_2->sizePolicy().hasHeightForWidth());
        Volt_2->setSizePolicy(sizePolicy);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 15, 20, 15));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(247, 15, 25, 15));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 35, 121, 20));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 64, 265, 22));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 94, 271, 26));
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
        v_up = new QSpinBox(groupBox);
        v_up->setObjectName(QString::fromUtf8("v_up"));
        v_up->setGeometry(QRect(200, 64, 80, 22));
        sizePolicy.setHeightForWidth(v_up->sizePolicy().hasHeightForWidth());
        v_up->setSizePolicy(sizePolicy);
        v_up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        v_up->setMinimum(-800000);
        v_up->setMaximum(800000);
        v_dwn = new QSpinBox(groupBox);
        v_dwn->setObjectName(QString::fromUtf8("v_dwn"));
        v_dwn->setGeometry(QRect(200, 94, 80, 22));
        sizePolicy.setHeightForWidth(v_dwn->sizePolicy().hasHeightForWidth());
        v_dwn->setSizePolicy(sizePolicy);
        v_dwn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        v_dwn->setMinimum(-800000);
        v_dwn->setMaximum(800000);
        v_diaWrite = new QPushButton(groupBox);
        v_diaWrite->setObjectName(QString::fromUtf8("v_diaWrite"));
        v_diaWrite->setGeometry(QRect(290, 32, 90, 26));
        sizePolicy.setHeightForWidth(v_diaWrite->sizePolicy().hasHeightForWidth());
        v_diaWrite->setSizePolicy(sizePolicy);
        v_upWrite = new QPushButton(groupBox);
        v_upWrite->setObjectName(QString::fromUtf8("v_upWrite"));
        v_upWrite->setGeometry(QRect(290, 62, 90, 26));
        sizePolicy.setHeightForWidth(v_upWrite->sizePolicy().hasHeightForWidth());
        v_upWrite->setSizePolicy(sizePolicy);
        v_dwnWrite = new QPushButton(groupBox);
        v_dwnWrite->setObjectName(QString::fromUtf8("v_dwnWrite"));
        v_dwnWrite->setGeometry(QRect(290, 92, 90, 26));
        sizePolicy.setHeightForWidth(v_dwnWrite->sizePolicy().hasHeightForWidth());
        v_dwnWrite->setSizePolicy(sizePolicy);
        v_Calibrate = new QPushButton(groupBox);
        v_Calibrate->setObjectName(QString::fromUtf8("v_Calibrate"));
        v_Calibrate->setGeometry(QRect(200, 122, 180, 26));
        sizePolicy.setHeightForWidth(v_Calibrate->sizePolicy().hasHeightForWidth());
        v_Calibrate->setSizePolicy(sizePolicy);
        v_dia_label = new QLabel(groupBox);
        v_dia_label->setObjectName(QString::fromUtf8("v_dia_label"));
        v_dia_label->setGeometry(QRect(128, 35, 71, 20));
        sizePolicy.setHeightForWidth(v_dia_label->sizePolicy().hasHeightForWidth());
        v_dia_label->setSizePolicy(sizePolicy);
        v_dia_label->setTextFormat(Qt::AutoText);
        v_dia_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passw = new QLineEdit(ASC35D_Calib);
        passw->setObjectName(QString::fromUtf8("passw"));
        passw->setGeometry(QRect(130, 454, 155, 18));
        sizePolicy.setHeightForWidth(passw->sizePolicy().hasHeightForWidth());
        passw->setSizePolicy(sizePolicy);
        passw->setMaxLength(32);
        groupBox_2 = new QGroupBox(ASC35D_Calib);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(5, 155, 390, 128));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 15, 181, 15));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        Curr_1 = new QCheckBox(groupBox_2);
        Curr_1->setObjectName(QString::fromUtf8("Curr_1"));
        Curr_1->setGeometry(QRect(220, 15, 15, 15));
        sizePolicy.setHeightForWidth(Curr_1->sizePolicy().hasHeightForWidth());
        Curr_1->setSizePolicy(sizePolicy);
        Curr_2 = new QCheckBox(groupBox_2);
        Curr_2->setObjectName(QString::fromUtf8("Curr_2"));
        Curr_2->setGeometry(QRect(267, 15, 15, 15));
        sizePolicy.setHeightForWidth(Curr_2->sizePolicy().hasHeightForWidth());
        Curr_2->setSizePolicy(sizePolicy);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 15, 20, 15));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(247, 15, 20, 15));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 35, 121, 26));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 65, 211, 22));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        i_val = new QSpinBox(groupBox_2);
        i_val->setObjectName(QString::fromUtf8("i_val"));
        i_val->setGeometry(QRect(200, 67, 80, 22));
        sizePolicy.setHeightForWidth(i_val->sizePolicy().hasHeightForWidth());
        i_val->setSizePolicy(sizePolicy);
        i_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        i_val->setMinimum(-800000);
        i_val->setMaximum(800000);
        i_zWrite = new QPushButton(groupBox_2);
        i_zWrite->setObjectName(QString::fromUtf8("i_zWrite"));
        i_zWrite->setGeometry(QRect(200, 35, 180, 26));
        sizePolicy.setHeightForWidth(i_zWrite->sizePolicy().hasHeightForWidth());
        i_zWrite->setSizePolicy(sizePolicy);
        i_Write = new QPushButton(groupBox_2);
        i_Write->setObjectName(QString::fromUtf8("i_Write"));
        i_Write->setGeometry(QRect(290, 65, 90, 26));
        sizePolicy.setHeightForWidth(i_Write->sizePolicy().hasHeightForWidth());
        i_Write->setSizePolicy(sizePolicy);
        i_Calibrate = new QPushButton(groupBox_2);
        i_Calibrate->setObjectName(QString::fromUtf8("i_Calibrate"));
        i_Calibrate->setGeometry(QRect(200, 95, 180, 26));
        sizePolicy.setHeightForWidth(i_Calibrate->sizePolicy().hasHeightForWidth());
        i_Calibrate->setSizePolicy(sizePolicy);
        groupBox_3 = new QGroupBox(ASC35D_Calib);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(5, 283, 390, 130));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 15, 181, 16));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(200, 15, 20, 16));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(250, 15, 20, 16));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        c_Calibrate = new QPushButton(groupBox_3);
        c_Calibrate->setObjectName(QString::fromUtf8("c_Calibrate"));
        c_Calibrate->setGeometry(QRect(200, 95, 180, 26));
        sizePolicy.setHeightForWidth(c_Calibrate->sizePolicy().hasHeightForWidth());
        c_Calibrate->setSizePolicy(sizePolicy);
        Cloop_1 = new QRadioButton(groupBox_3);
        Cloop_1->setObjectName(QString::fromUtf8("Cloop_1"));
        Cloop_1->setGeometry(QRect(220, 15, 16, 16));
        sizePolicy.setHeightForWidth(Cloop_1->sizePolicy().hasHeightForWidth());
        Cloop_1->setSizePolicy(sizePolicy);
        Cloop_1->setChecked(true);
        Cloop_2 = new QRadioButton(groupBox_3);
        Cloop_2->setObjectName(QString::fromUtf8("Cloop_2"));
        Cloop_2->setGeometry(QRect(270, 15, 16, 16));
        sizePolicy.setHeightForWidth(Cloop_2->sizePolicy().hasHeightForWidth());
        Cloop_2->setSizePolicy(sizePolicy);
        Cloop_3 = new QRadioButton(groupBox_3);
        Cloop_3->setObjectName(QString::fromUtf8("Cloop_3"));
        Cloop_3->setGeometry(QRect(320, 15, 16, 16));
        sizePolicy.setHeightForWidth(Cloop_3->sizePolicy().hasHeightForWidth());
        Cloop_3->setSizePolicy(sizePolicy);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(300, 15, 20, 16));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        Cloop_4 = new QRadioButton(groupBox_3);
        Cloop_4->setObjectName(QString::fromUtf8("Cloop_4"));
        Cloop_4->setGeometry(QRect(370, 15, 16, 16));
        sizePolicy.setHeightForWidth(Cloop_4->sizePolicy().hasHeightForWidth());
        Cloop_4->setSizePolicy(sizePolicy);
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(350, 15, 20, 16));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 36, 265, 22));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        c_dwn = new QSpinBox(groupBox_3);
        c_dwn->setObjectName(QString::fromUtf8("c_dwn"));
        c_dwn->setGeometry(QRect(200, 65, 80, 22));
        sizePolicy.setHeightForWidth(c_dwn->sizePolicy().hasHeightForWidth());
        c_dwn->setSizePolicy(sizePolicy);
        c_dwn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        c_dwn->setMinimum(-800000);
        c_dwn->setMaximum(800000);
        c_dwnWrite = new QPushButton(groupBox_3);
        c_dwnWrite->setObjectName(QString::fromUtf8("c_dwnWrite"));
        c_dwnWrite->setGeometry(QRect(290, 63, 90, 26));
        sizePolicy.setHeightForWidth(c_dwnWrite->sizePolicy().hasHeightForWidth());
        c_dwnWrite->setSizePolicy(sizePolicy);
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 65, 271, 22));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        c_upWrite = new QPushButton(groupBox_3);
        c_upWrite->setObjectName(QString::fromUtf8("c_upWrite"));
        c_upWrite->setGeometry(QRect(290, 33, 90, 26));
        sizePolicy.setHeightForWidth(c_upWrite->sizePolicy().hasHeightForWidth());
        c_upWrite->setSizePolicy(sizePolicy);
        c_up = new QSpinBox(groupBox_3);
        c_up->setObjectName(QString::fromUtf8("c_up"));
        c_up->setGeometry(QRect(200, 36, 80, 22));
        sizePolicy.setHeightForWidth(c_up->sizePolicy().hasHeightForWidth());
        c_up->setSizePolicy(sizePolicy);
        c_up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        c_up->setMinimum(-800000);
        c_up->setMaximum(800000);

        retranslateUi(ASC35D_Calib);

        QMetaObject::connectSlotsByName(ASC35D_Calib);
    } // setupUi

    void retranslateUi(QDialog *ASC35D_Calib)
    {
        ASC35D_Calib->setWindowTitle(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 ASC-35D", nullptr));
        Cancel->setText(QCoreApplication::translate("ASC35D_Calib", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_8->setText(QCoreApplication::translate("ASC35D_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        avgWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pswWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("ASC35D_Calib", "\320\222\321\200\320\265\320\274\321\217 \321\203\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\321\217, \321\201\320\265\320\272\321\203\320\275\320\264", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("ASC35D_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", nullptr));
        Volt_1->setText(QString());
        Volt_2->setText(QString());
        label_2->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2261", nullptr));
        label_3->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2262", nullptr));
        label_4->setText(QCoreApplication::translate("ASC35D_Calib", "\320\250\320\272\320\260\320\273\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("ASC35D_Calib", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", nullptr));
        label_6->setText(QCoreApplication::translate("ASC35D_Calib", "\320\235\320\270\320\266\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", nullptr));
        Dia->setItemText(0, QCoreApplication::translate("ASC35D_Calib", "\320\260\320\262\321\202\320\276", nullptr));
        Dia->setItemText(1, QCoreApplication::translate("ASC35D_Calib", "\320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274", nullptr));
        Dia->setItemText(2, QCoreApplication::translate("ASC35D_Calib", "\320\274\320\270\320\275\320\270\320\274\321\203\320\274", nullptr));

        v_diaWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        v_upWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        v_dwnWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        v_Calibrate->setText(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        v_dia_label->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2261, \342\204\2262", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 \321\202\320\276\320\272\320\260", nullptr));
        label_9->setText(QCoreApplication::translate("ASC35D_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", nullptr));
        Curr_1->setText(QString());
        Curr_2->setText(QString());
        label_10->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2261", nullptr));
        label_11->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2262", nullptr));
        label_12->setText(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\321\203\320\273\321\217", nullptr));
        label_13->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\202\320\276\320\272\320\260, \320\220*1000", nullptr));
        i_zWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        i_Write->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        i_Calibrate->setText(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 4/20 \320\274\320\220", nullptr));
        label_14->setText(QCoreApplication::translate("ASC35D_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", nullptr));
        label_15->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2261", nullptr));
        label_16->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2262", nullptr));
        c_Calibrate->setText(QCoreApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        Cloop_1->setText(QString());
        Cloop_2->setText(QString());
        Cloop_3->setText(QString());
        label_17->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2263", nullptr));
        Cloop_4->setText(QString());
        label_18->setText(QCoreApplication::translate("ASC35D_Calib", "\342\204\2264", nullptr));
        label_19->setText(QCoreApplication::translate("ASC35D_Calib", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", nullptr));
        c_dwnWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_20->setText(QCoreApplication::translate("ASC35D_Calib", "\320\235\320\270\320\266\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", nullptr));
        c_upWrite->setText(QCoreApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ASC35D_Calib: public Ui_ASC35D_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASC35D_CALIB_H
