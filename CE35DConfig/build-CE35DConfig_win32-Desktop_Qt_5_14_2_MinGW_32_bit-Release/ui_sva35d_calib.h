/********************************************************************************
** Form generated from reading UI file 'sva35d_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SVA35D_CALIB_H
#define UI_SVA35D_CALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SVA35D_Calib
{
public:
    QLabel *label;
    QSpinBox *Temp;
    QPushButton *TempWrite;
    QLabel *label_2;
    QLineEdit *dTemp;
    QGroupBox *groupBox;
    QCheckBox *phase_1;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *phase_2;
    QLabel *label_5;
    QCheckBox *phase_3;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *offsetWrite;
    QPushButton *vWrite;
    QPushButton *cWrite;
    QLabel *label_8;
    QSpinBox *volt;
    QSpinBox *curr;
    QSpinBox *mult;
    QPushButton *checkWrite;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QLabel *label_13;
    QPushButton *aWrite_2;
    QPushButton *aWrite_3;
    QSpinBox *angle_2;
    QSpinBox *angle_3;
    QLabel *label_15;
    QSpinBox *angle_1;
    QPushButton *aWrite_1;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *kvar_1;
    QLineEdit *kvar_2;
    QLineEdit *kvar_3;
    QPushButton *Write;
    QLineEdit *passw;
    QLabel *label_10;
    QPushButton *Save;
    QPushButton *Cancel;

    void setupUi(QDialog *SVA35D_Calib)
    {
        if (SVA35D_Calib->objectName().isEmpty())
            SVA35D_Calib->setObjectName(QString::fromUtf8("SVA35D_Calib"));
        SVA35D_Calib->resize(395, 473);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SVA35D_Calib->sizePolicy().hasHeightForWidth());
        SVA35D_Calib->setSizePolicy(sizePolicy);
        SVA35D_Calib->setMinimumSize(QSize(395, 473));
        SVA35D_Calib->setMaximumSize(QSize(395, 473));
        label = new QLabel(SVA35D_Calib);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 14, 181, 22));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        Temp = new QSpinBox(SVA35D_Calib);
        Temp->setObjectName(QString::fromUtf8("Temp"));
        Temp->setGeometry(QRect(200, 14, 60, 22));
        sizePolicy.setHeightForWidth(Temp->sizePolicy().hasHeightForWidth());
        Temp->setSizePolicy(sizePolicy);
        Temp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Temp->setMinimum(-1000);
        Temp->setMaximum(1000);
        TempWrite = new QPushButton(SVA35D_Calib);
        TempWrite->setObjectName(QString::fromUtf8("TempWrite"));
        TempWrite->setGeometry(QRect(290, 10, 90, 26));
        sizePolicy.setHeightForWidth(TempWrite->sizePolicy().hasHeightForWidth());
        TempWrite->setSizePolicy(sizePolicy);
        label_2 = new QLabel(SVA35D_Calib);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 45, 201, 18));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        dTemp = new QLineEdit(SVA35D_Calib);
        dTemp->setObjectName(QString::fromUtf8("dTemp"));
        dTemp->setGeometry(QRect(200, 45, 60, 18));
        sizePolicy.setHeightForWidth(dTemp->sizePolicy().hasHeightForWidth());
        dTemp->setSizePolicy(sizePolicy);
        dTemp->setReadOnly(true);
        groupBox = new QGroupBox(SVA35D_Calib);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(5, 60, 385, 179));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        phase_1 = new QCheckBox(groupBox);
        phase_1->setObjectName(QString::fromUtf8("phase_1"));
        phase_1->setGeometry(QRect(195, 25, 15, 15));
        sizePolicy.setHeightForWidth(phase_1->sizePolicy().hasHeightForWidth());
        phase_1->setSizePolicy(sizePolicy);
        phase_1->setChecked(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 25, 161, 15));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(198, 10, 15, 15));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        phase_2 = new QCheckBox(groupBox);
        phase_2->setObjectName(QString::fromUtf8("phase_2"));
        phase_2->setGeometry(QRect(225, 25, 15, 15));
        sizePolicy.setHeightForWidth(phase_2->sizePolicy().hasHeightForWidth());
        phase_2->setSizePolicy(sizePolicy);
        phase_2->setChecked(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(228, 10, 15, 15));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        phase_3 = new QCheckBox(groupBox);
        phase_3->setObjectName(QString::fromUtf8("phase_3"));
        phase_3->setGeometry(QRect(255, 25, 15, 15));
        sizePolicy.setHeightForWidth(phase_3->sizePolicy().hasHeightForWidth());
        phase_3->setSizePolicy(sizePolicy);
        phase_3->setChecked(true);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(258, 10, 15, 15));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 84, 191, 22));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        offsetWrite = new QPushButton(groupBox);
        offsetWrite->setObjectName(QString::fromUtf8("offsetWrite"));
        offsetWrite->setGeometry(QRect(195, 50, 180, 26));
        sizePolicy.setHeightForWidth(offsetWrite->sizePolicy().hasHeightForWidth());
        offsetWrite->setSizePolicy(sizePolicy);
        vWrite = new QPushButton(groupBox);
        vWrite->setObjectName(QString::fromUtf8("vWrite"));
        vWrite->setGeometry(QRect(285, 82, 90, 26));
        sizePolicy.setHeightForWidth(vWrite->sizePolicy().hasHeightForWidth());
        vWrite->setSizePolicy(sizePolicy);
        cWrite = new QPushButton(groupBox);
        cWrite->setObjectName(QString::fromUtf8("cWrite"));
        cWrite->setGeometry(QRect(285, 112, 90, 26));
        sizePolicy.setHeightForWidth(cWrite->sizePolicy().hasHeightForWidth());
        cWrite->setSizePolicy(sizePolicy);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 114, 161, 22));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        volt = new QSpinBox(groupBox);
        volt->setObjectName(QString::fromUtf8("volt"));
        volt->setGeometry(QRect(195, 84, 80, 22));
        sizePolicy.setHeightForWidth(volt->sizePolicy().hasHeightForWidth());
        volt->setSizePolicy(sizePolicy);
        volt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        volt->setMaximum(10000000);
        volt->setValue(0);
        curr = new QSpinBox(groupBox);
        curr->setObjectName(QString::fromUtf8("curr"));
        curr->setGeometry(QRect(195, 114, 80, 22));
        sizePolicy.setHeightForWidth(curr->sizePolicy().hasHeightForWidth());
        curr->setSizePolicy(sizePolicy);
        curr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        curr->setMaximum(10000000);
        curr->setValue(0);
        mult = new QSpinBox(groupBox);
        mult->setObjectName(QString::fromUtf8("mult"));
        mult->setGeometry(QRect(140, 114, 45, 22));
        sizePolicy.setHeightForWidth(mult->sizePolicy().hasHeightForWidth());
        mult->setSizePolicy(sizePolicy);
        mult->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mult->setMaximum(50);
        mult->setValue(1);
        checkWrite = new QPushButton(groupBox);
        checkWrite->setObjectName(QString::fromUtf8("checkWrite"));
        checkWrite->setGeometry(QRect(10, 143, 365, 26));
        sizePolicy.setHeightForWidth(checkWrite->sizePolicy().hasHeightForWidth());
        checkWrite->setSizePolicy(sizePolicy);
        groupBox_2 = new QGroupBox(SVA35D_Calib);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(5, 239, 385, 132));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(12, 15, 161, 18));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 41, 41, 18));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        aWrite_2 = new QPushButton(groupBox_2);
        aWrite_2->setObjectName(QString::fromUtf8("aWrite_2"));
        aWrite_2->setGeometry(QRect(285, 67, 90, 26));
        sizePolicy.setHeightForWidth(aWrite_2->sizePolicy().hasHeightForWidth());
        aWrite_2->setSizePolicy(sizePolicy);
        aWrite_3 = new QPushButton(groupBox_2);
        aWrite_3->setObjectName(QString::fromUtf8("aWrite_3"));
        aWrite_3->setGeometry(QRect(285, 97, 90, 26));
        sizePolicy.setHeightForWidth(aWrite_3->sizePolicy().hasHeightForWidth());
        aWrite_3->setSizePolicy(sizePolicy);
        angle_2 = new QSpinBox(groupBox_2);
        angle_2->setObjectName(QString::fromUtf8("angle_2"));
        angle_2->setGeometry(QRect(195, 69, 80, 22));
        sizePolicy.setHeightForWidth(angle_2->sizePolicy().hasHeightForWidth());
        angle_2->setSizePolicy(sizePolicy);
        angle_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        angle_2->setMinimum(-10000);
        angle_2->setMaximum(10000);
        angle_2->setValue(0);
        angle_3 = new QSpinBox(groupBox_2);
        angle_3->setObjectName(QString::fromUtf8("angle_3"));
        angle_3->setGeometry(QRect(195, 99, 80, 22));
        sizePolicy.setHeightForWidth(angle_3->sizePolicy().hasHeightForWidth());
        angle_3->setSizePolicy(sizePolicy);
        angle_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        angle_3->setMinimum(-10000);
        angle_3->setMaximum(10000);
        angle_3->setValue(0);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 15, 141, 18));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setAlignment(Qt::AlignCenter);
        angle_1 = new QSpinBox(groupBox_2);
        angle_1->setObjectName(QString::fromUtf8("angle_1"));
        angle_1->setGeometry(QRect(195, 39, 80, 22));
        sizePolicy.setHeightForWidth(angle_1->sizePolicy().hasHeightForWidth());
        angle_1->setSizePolicy(sizePolicy);
        angle_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        angle_1->setMinimum(-10000);
        angle_1->setMaximum(10000);
        angle_1->setValue(0);
        aWrite_1 = new QPushButton(groupBox_2);
        aWrite_1->setObjectName(QString::fromUtf8("aWrite_1"));
        aWrite_1->setGeometry(QRect(285, 37, 90, 26));
        sizePolicy.setHeightForWidth(aWrite_1->sizePolicy().hasHeightForWidth());
        aWrite_1->setSizePolicy(sizePolicy);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 71, 41, 18));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 101, 41, 18));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        kvar_1 = new QLineEdit(groupBox_2);
        kvar_1->setObjectName(QString::fromUtf8("kvar_1"));
        kvar_1->setGeometry(QRect(60, 41, 80, 18));
        sizePolicy.setHeightForWidth(kvar_1->sizePolicy().hasHeightForWidth());
        kvar_1->setSizePolicy(sizePolicy);
        kvar_1->setReadOnly(true);
        kvar_2 = new QLineEdit(groupBox_2);
        kvar_2->setObjectName(QString::fromUtf8("kvar_2"));
        kvar_2->setGeometry(QRect(60, 71, 80, 18));
        sizePolicy.setHeightForWidth(kvar_2->sizePolicy().hasHeightForWidth());
        kvar_2->setSizePolicy(sizePolicy);
        kvar_2->setReadOnly(true);
        kvar_3 = new QLineEdit(groupBox_2);
        kvar_3->setObjectName(QString::fromUtf8("kvar_3"));
        kvar_3->setGeometry(QRect(60, 101, 80, 18));
        sizePolicy.setHeightForWidth(kvar_3->sizePolicy().hasHeightForWidth());
        kvar_3->setSizePolicy(sizePolicy);
        kvar_3->setReadOnly(true);
        Write = new QPushButton(SVA35D_Calib);
        Write->setObjectName(QString::fromUtf8("Write"));
        Write->setGeometry(QRect(290, 410, 90, 26));
        sizePolicy.setHeightForWidth(Write->sizePolicy().hasHeightForWidth());
        Write->setSizePolicy(sizePolicy);
        passw = new QLineEdit(SVA35D_Calib);
        passw->setObjectName(QString::fromUtf8("passw"));
        passw->setGeometry(QRect(130, 444, 150, 18));
        sizePolicy.setHeightForWidth(passw->sizePolicy().hasHeightForWidth());
        passw->setSizePolicy(sizePolicy);
        passw->setMaxLength(32);
        label_10 = new QLabel(SVA35D_Calib);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 444, 120, 18));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        Save = new QPushButton(SVA35D_Calib);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(290, 380, 90, 26));
        sizePolicy.setHeightForWidth(Save->sizePolicy().hasHeightForWidth());
        Save->setSizePolicy(sizePolicy);
        Cancel = new QPushButton(SVA35D_Calib);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(290, 440, 90, 26));
        sizePolicy.setHeightForWidth(Cancel->sizePolicy().hasHeightForWidth());
        Cancel->setSizePolicy(sizePolicy);

        retranslateUi(SVA35D_Calib);

        QMetaObject::connectSlotsByName(SVA35D_Calib);
    } // setupUi

    void retranslateUi(QDialog *SVA35D_Calib)
    {
        SVA35D_Calib->setWindowTitle(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 SVA-35D", nullptr));
        label->setText(QCoreApplication::translate("SVA35D_Calib", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260, \302\260\320\241*10", nullptr));
        TempWrite->setText(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("SVA35D_Calib", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\200\320\260\320\267\320\275\320\270\321\206\320\260 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200, \302\260\320\241", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262", nullptr));
        phase_1->setText(QString());
        label_3->setText(QCoreApplication::translate("SVA35D_Calib", "\320\244\320\260\320\267\321\213 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("SVA35D_Calib", "1", nullptr));
        phase_2->setText(QString());
        label_5->setText(QCoreApplication::translate("SVA35D_Calib", "2", nullptr));
        phase_3->setText(QString());
        label_6->setText(QCoreApplication::translate("SVA35D_Calib", "3", nullptr));
        label_7->setText(QCoreApplication::translate("SVA35D_Calib", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265, \320\222*1000", nullptr));
        offsetWrite->setText(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 Offset", nullptr));
        vWrite->setText(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        cWrite->setText(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("SVA35D_Calib", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\202\320\276\320\272, \320\220*1000", nullptr));
        checkWrite->setText(QCoreApplication::translate("SVA35D_Calib", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\321\203\321\201 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \321\201\320\264\320\262\320\270\320\263\320\260 \321\204\320\260\320\267", nullptr));
        label_9->setText(QCoreApplication::translate("SVA35D_Calib", "\320\240\320\265\320\260\320\272\321\202\320\270\320\262\320\275\320\260\321\217 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\321\214, \320\272\320\222\320\220\321\200", nullptr));
        label_13->setText(QCoreApplication::translate("SVA35D_Calib", "\320\244\320\260\320\267\320\260 1", nullptr));
        aWrite_2->setText(QCoreApplication::translate("SVA35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        aWrite_3->setText(QCoreApplication::translate("SVA35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_15->setText(QCoreApplication::translate("SVA35D_Calib", "\320\232\320\276\320\274\320\277\320\265\320\275\321\201\320\260\321\206\320\270\321\217 \321\201\320\264\320\262\320\270\320\263\320\260 \321\204\320\260\320\267", nullptr));
        aWrite_1->setText(QCoreApplication::translate("SVA35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_16->setText(QCoreApplication::translate("SVA35D_Calib", "\320\244\320\260\320\267\320\260 2", nullptr));
        label_17->setText(QCoreApplication::translate("SVA35D_Calib", "\320\244\320\260\320\267\320\260 3", nullptr));
        Write->setText(QCoreApplication::translate("SVA35D_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_10->setText(QCoreApplication::translate("SVA35D_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        Save->setText(QCoreApplication::translate("SVA35D_Calib", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        Cancel->setText(QCoreApplication::translate("SVA35D_Calib", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SVA35D_Calib: public Ui_SVA35D_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SVA35D_CALIB_H
