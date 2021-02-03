/********************************************************************************
** Form generated from reading UI file 'asc35d_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASC35D_CALIB_H
#define UI_ASC35D_CALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
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
            ASC35D_Calib->setObjectName(QStringLiteral("ASC35D_Calib"));
        ASC35D_Calib->resize(510, 690);
        Cancel = new QPushButton(ASC35D_Calib);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(400, 648, 90, 30));
        avg = new QDoubleSpinBox(ASC35D_Calib);
        avg->setObjectName(QStringLiteral("avg"));
        avg->setGeometry(QRect(329, 570, 51, 26));
        QFont font;
        font.setPointSize(9);
        avg->setFont(font);
        avg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg->setDecimals(1);
        avg->setMinimum(0.1);
        avg->setMaximum(10);
        avg->setSingleStep(0.1);
        label_8 = new QLabel(ASC35D_Calib);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 608, 141, 26));
        label_8->setFont(font);
        avgWrite = new QPushButton(ASC35D_Calib);
        avgWrite->setObjectName(QStringLiteral("avgWrite"));
        avgWrite->setGeometry(QRect(400, 568, 90, 30));
        avgWrite->setFont(font);
        pswWrite = new QPushButton(ASC35D_Calib);
        pswWrite->setObjectName(QStringLiteral("pswWrite"));
        pswWrite->setGeometry(QRect(400, 608, 90, 30));
        pswWrite->setFont(font);
        label_7 = new QLabel(ASC35D_Calib);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 570, 265, 26));
        label_7->setFont(font);
        groupBox = new QGroupBox(ASC35D_Calib);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 490, 210));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 181, 20));
        label->setFont(font);
        Volt_1 = new QCheckBox(groupBox);
        Volt_1->setObjectName(QStringLiteral("Volt_1"));
        Volt_1->setGeometry(QRect(352, 20, 18, 20));
        Volt_2 = new QCheckBox(groupBox);
        Volt_2->setObjectName(QStringLiteral("Volt_2"));
        Volt_2->setGeometry(QRect(461, 20, 18, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(322, 20, 31, 20));
        label_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 20, 31, 20));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 52, 121, 26));
        label_4->setFont(font);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 92, 265, 26));
        label_5->setFont(font);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 132, 271, 26));
        label_6->setFont(font);
        Dia = new QComboBox(groupBox);
        Dia->setObjectName(QStringLiteral("Dia"));
        Dia->setGeometry(QRect(270, 52, 100, 26));
        v_up = new QSpinBox(groupBox);
        v_up->setObjectName(QStringLiteral("v_up"));
        v_up->setGeometry(QRect(270, 92, 100, 26));
        v_up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        v_up->setMinimum(-800000);
        v_up->setMaximum(800000);
        v_dwn = new QSpinBox(groupBox);
        v_dwn->setObjectName(QStringLiteral("v_dwn"));
        v_dwn->setGeometry(QRect(270, 132, 100, 26));
        v_dwn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        v_dwn->setMinimum(-800000);
        v_dwn->setMaximum(800000);
        v_diaWrite = new QPushButton(groupBox);
        v_diaWrite->setObjectName(QStringLiteral("v_diaWrite"));
        v_diaWrite->setGeometry(QRect(390, 50, 90, 30));
        v_diaWrite->setFont(font);
        v_upWrite = new QPushButton(groupBox);
        v_upWrite->setObjectName(QStringLiteral("v_upWrite"));
        v_upWrite->setGeometry(QRect(390, 90, 90, 30));
        v_upWrite->setFont(font);
        v_dwnWrite = new QPushButton(groupBox);
        v_dwnWrite->setObjectName(QStringLiteral("v_dwnWrite"));
        v_dwnWrite->setGeometry(QRect(390, 130, 90, 30));
        v_dwnWrite->setFont(font);
        v_Calibrate = new QPushButton(groupBox);
        v_Calibrate->setObjectName(QStringLiteral("v_Calibrate"));
        v_Calibrate->setGeometry(QRect(269, 170, 211, 30));
        v_Calibrate->setFont(font);
        v_dia_label = new QLabel(groupBox);
        v_dia_label->setObjectName(QStringLiteral("v_dia_label"));
        v_dia_label->setGeometry(QRect(190, 50, 71, 26));
        v_dia_label->setFont(font);
        v_dia_label->setTextFormat(Qt::AutoText);
        v_dia_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passw = new QLineEdit(ASC35D_Calib);
        passw->setObjectName(QStringLiteral("passw"));
        passw->setGeometry(QRect(160, 610, 220, 26));
        passw->setMaxLength(32);
        groupBox_2 = new QGroupBox(ASC35D_Calib);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 215, 490, 170));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 20, 181, 20));
        label_9->setFont(font);
        Curr_1 = new QCheckBox(groupBox_2);
        Curr_1->setObjectName(QStringLiteral("Curr_1"));
        Curr_1->setGeometry(QRect(352, 20, 18, 20));
        Curr_2 = new QCheckBox(groupBox_2);
        Curr_2->setObjectName(QStringLiteral("Curr_2"));
        Curr_2->setGeometry(QRect(461, 20, 18, 20));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(322, 20, 31, 20));
        label_10->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(430, 20, 31, 20));
        label_11->setFont(font);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 52, 121, 26));
        label_12->setFont(font);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 92, 211, 26));
        label_13->setFont(font);
        i_val = new QSpinBox(groupBox_2);
        i_val->setObjectName(QStringLiteral("i_val"));
        i_val->setGeometry(QRect(270, 92, 100, 26));
        i_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        i_val->setMinimum(-800000);
        i_val->setMaximum(800000);
        i_zWrite = new QPushButton(groupBox_2);
        i_zWrite->setObjectName(QStringLiteral("i_zWrite"));
        i_zWrite->setGeometry(QRect(269, 50, 211, 30));
        i_zWrite->setFont(font);
        i_Write = new QPushButton(groupBox_2);
        i_Write->setObjectName(QStringLiteral("i_Write"));
        i_Write->setGeometry(QRect(390, 90, 90, 30));
        i_Write->setFont(font);
        i_Calibrate = new QPushButton(groupBox_2);
        i_Calibrate->setObjectName(QStringLiteral("i_Calibrate"));
        i_Calibrate->setGeometry(QRect(270, 130, 211, 30));
        i_Calibrate->setFont(font);
        groupBox_3 = new QGroupBox(ASC35D_Calib);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 390, 490, 171));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 20, 181, 20));
        label_14->setFont(font);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(250, 20, 31, 20));
        label_15->setFont(font);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(310, 20, 31, 20));
        label_16->setFont(font);
        c_Calibrate = new QPushButton(groupBox_3);
        c_Calibrate->setObjectName(QStringLiteral("c_Calibrate"));
        c_Calibrate->setGeometry(QRect(270, 130, 211, 30));
        c_Calibrate->setFont(font);
        Cloop_1 = new QRadioButton(groupBox_3);
        Cloop_1->setObjectName(QStringLiteral("Cloop_1"));
        Cloop_1->setGeometry(QRect(280, 20, 20, 20));
        Cloop_1->setChecked(true);
        Cloop_2 = new QRadioButton(groupBox_3);
        Cloop_2->setObjectName(QStringLiteral("Cloop_2"));
        Cloop_2->setGeometry(QRect(340, 20, 20, 20));
        Cloop_3 = new QRadioButton(groupBox_3);
        Cloop_3->setObjectName(QStringLiteral("Cloop_3"));
        Cloop_3->setGeometry(QRect(400, 20, 20, 20));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(370, 20, 31, 20));
        label_17->setFont(font);
        Cloop_4 = new QRadioButton(groupBox_3);
        Cloop_4->setObjectName(QStringLiteral("Cloop_4"));
        Cloop_4->setGeometry(QRect(460, 20, 20, 20));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(430, 20, 31, 20));
        label_18->setFont(font);
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 50, 265, 26));
        label_19->setFont(font);
        c_dwn = new QSpinBox(groupBox_3);
        c_dwn->setObjectName(QStringLiteral("c_dwn"));
        c_dwn->setGeometry(QRect(270, 90, 100, 26));
        c_dwn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        c_dwn->setMinimum(-800000);
        c_dwn->setMaximum(800000);
        c_dwnWrite = new QPushButton(groupBox_3);
        c_dwnWrite->setObjectName(QStringLiteral("c_dwnWrite"));
        c_dwnWrite->setGeometry(QRect(390, 88, 90, 30));
        c_dwnWrite->setFont(font);
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 90, 271, 26));
        label_20->setFont(font);
        c_upWrite = new QPushButton(groupBox_3);
        c_upWrite->setObjectName(QStringLiteral("c_upWrite"));
        c_upWrite->setGeometry(QRect(390, 48, 90, 30));
        c_upWrite->setFont(font);
        c_up = new QSpinBox(groupBox_3);
        c_up->setObjectName(QStringLiteral("c_up"));
        c_up->setGeometry(QRect(270, 50, 100, 26));
        c_up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        c_up->setMinimum(-800000);
        c_up->setMaximum(800000);

        retranslateUi(ASC35D_Calib);

        QMetaObject::connectSlotsByName(ASC35D_Calib);
    } // setupUi

    void retranslateUi(QDialog *ASC35D_Calib)
    {
        ASC35D_Calib->setWindowTitle(QApplication::translate("ASC35D_Calib", "Dialog", Q_NULLPTR));
        Cancel->setText(QApplication::translate("ASC35D_Calib", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        label_8->setText(QApplication::translate("ASC35D_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", Q_NULLPTR));
        avgWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        pswWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        label_7->setText(QApplication::translate("ASC35D_Calib", "\320\222\321\200\320\265\320\274\321\217 \321\203\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\321\217, \321\201\320\265\320\272\321\203\320\275\320\264", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("ASC35D_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", Q_NULLPTR));
        Volt_1->setText(QString());
        Volt_2->setText(QString());
        label_2->setText(QApplication::translate("ASC35D_Calib", "\342\204\2261", Q_NULLPTR));
        label_3->setText(QApplication::translate("ASC35D_Calib", "\342\204\2262", Q_NULLPTR));
        label_4->setText(QApplication::translate("ASC35D_Calib", "\320\250\320\272\320\260\320\273\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("ASC35D_Calib", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", Q_NULLPTR));
        label_6->setText(QApplication::translate("ASC35D_Calib", "\320\235\320\270\320\266\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", Q_NULLPTR));
        Dia->clear();
        Dia->insertItems(0, QStringList()
         << QApplication::translate("ASC35D_Calib", "\320\260\320\262\321\202\320\276", Q_NULLPTR)
         << QApplication::translate("ASC35D_Calib", "\320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274", Q_NULLPTR)
         << QApplication::translate("ASC35D_Calib", "\320\274\320\270\320\275\320\270\320\274\321\203\320\274", Q_NULLPTR)
        );
        v_diaWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        v_upWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        v_dwnWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        v_Calibrate->setText(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        v_dia_label->setText(QApplication::translate("ASC35D_Calib", "\342\204\2261, \342\204\2262", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 \321\202\320\276\320\272\320\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("ASC35D_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", Q_NULLPTR));
        Curr_1->setText(QString());
        Curr_2->setText(QString());
        label_10->setText(QApplication::translate("ASC35D_Calib", "\342\204\2261", Q_NULLPTR));
        label_11->setText(QApplication::translate("ASC35D_Calib", "\342\204\2262", Q_NULLPTR));
        label_12->setText(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\321\203\320\273\321\217", Q_NULLPTR));
        label_13->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\202\320\276\320\272\320\260, \320\220*1000", Q_NULLPTR));
        i_zWrite->setText(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        i_Write->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        i_Calibrate->setText(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 4/20 \320\274\320\220", Q_NULLPTR));
        label_14->setText(QApplication::translate("ASC35D_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", Q_NULLPTR));
        label_15->setText(QApplication::translate("ASC35D_Calib", "\342\204\2261", Q_NULLPTR));
        label_16->setText(QApplication::translate("ASC35D_Calib", "\342\204\2262", Q_NULLPTR));
        c_Calibrate->setText(QApplication::translate("ASC35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        Cloop_1->setText(QString());
        Cloop_2->setText(QString());
        Cloop_3->setText(QString());
        label_17->setText(QApplication::translate("ASC35D_Calib", "\342\204\2263", Q_NULLPTR));
        Cloop_4->setText(QString());
        label_18->setText(QApplication::translate("ASC35D_Calib", "\342\204\2264", Q_NULLPTR));
        label_19->setText(QApplication::translate("ASC35D_Calib", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", Q_NULLPTR));
        c_dwnWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        label_20->setText(QApplication::translate("ASC35D_Calib", "\320\235\320\270\320\266\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", Q_NULLPTR));
        c_upWrite->setText(QApplication::translate("ASC35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ASC35D_Calib: public Ui_ASC35D_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASC35D_CALIB_H
