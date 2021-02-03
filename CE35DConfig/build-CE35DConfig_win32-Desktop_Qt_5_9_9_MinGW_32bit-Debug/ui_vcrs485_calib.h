/********************************************************************************
** Form generated from reading UI file 'vcrs485_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCRS485_CALIB_H
#define UI_VCRS485_CALIB_H

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
            VCRS485_Calib->setObjectName(QStringLiteral("VCRS485_Calib"));
        VCRS485_Calib->resize(510, 340);
        groupBox = new QGroupBox(VCRS485_Calib);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 491, 211));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 181, 20));
        QFont font;
        font.setPointSize(9);
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
        up = new QSpinBox(groupBox);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(270, 92, 100, 26));
        up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        up->setMinimum(-800000);
        up->setMaximum(800000);
        dwn = new QSpinBox(groupBox);
        dwn->setObjectName(QStringLiteral("dwn"));
        dwn->setGeometry(QRect(270, 132, 100, 26));
        dwn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dwn->setMinimum(-800000);
        dwn->setMaximum(800000);
        diaWrite = new QPushButton(groupBox);
        diaWrite->setObjectName(QStringLiteral("diaWrite"));
        diaWrite->setGeometry(QRect(390, 50, 90, 30));
        diaWrite->setFont(font);
        upWrite = new QPushButton(groupBox);
        upWrite->setObjectName(QStringLiteral("upWrite"));
        upWrite->setGeometry(QRect(390, 90, 90, 30));
        upWrite->setFont(font);
        dwnWrite = new QPushButton(groupBox);
        dwnWrite->setObjectName(QStringLiteral("dwnWrite"));
        dwnWrite->setGeometry(QRect(390, 130, 90, 30));
        dwnWrite->setFont(font);
        Calibrate = new QPushButton(groupBox);
        Calibrate->setObjectName(QStringLiteral("Calibrate"));
        Calibrate->setGeometry(QRect(269, 170, 211, 30));
        Calibrate->setFont(font);
        dia_label = new QLabel(groupBox);
        dia_label->setObjectName(QStringLiteral("dia_label"));
        dia_label->setGeometry(QRect(190, 50, 71, 26));
        dia_label->setFont(font);
        dia_label->setTextFormat(Qt::AutoText);
        dia_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(VCRS485_Calib);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 222, 265, 26));
        label_7->setFont(font);
        avgWrite = new QPushButton(VCRS485_Calib);
        avgWrite->setObjectName(QStringLiteral("avgWrite"));
        avgWrite->setGeometry(QRect(400, 220, 90, 30));
        avgWrite->setFont(font);
        avg = new QDoubleSpinBox(VCRS485_Calib);
        avg->setObjectName(QStringLiteral("avg"));
        avg->setGeometry(QRect(329, 222, 51, 26));
        avg->setFont(font);
        avg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg->setDecimals(1);
        avg->setMinimum(0.1);
        avg->setMaximum(10);
        avg->setSingleStep(0.1);
        passw = new QLineEdit(VCRS485_Calib);
        passw->setObjectName(QStringLiteral("passw"));
        passw->setGeometry(QRect(160, 262, 220, 26));
        passw->setMaxLength(32);
        pswWrite = new QPushButton(VCRS485_Calib);
        pswWrite->setObjectName(QStringLiteral("pswWrite"));
        pswWrite->setGeometry(QRect(400, 260, 90, 30));
        pswWrite->setFont(font);
        Cancel = new QPushButton(VCRS485_Calib);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(400, 300, 90, 30));
        label_8 = new QLabel(VCRS485_Calib);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 260, 141, 26));
        label_8->setFont(font);

        retranslateUi(VCRS485_Calib);

        QMetaObject::connectSlotsByName(VCRS485_Calib);
    } // setupUi

    void retranslateUi(QDialog *VCRS485_Calib)
    {
        VCRS485_Calib->setWindowTitle(QApplication::translate("VCRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("VCRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\262 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("VCRS485_Calib", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", Q_NULLPTR));
        Volt_1->setText(QString());
        Volt_2->setText(QString());
        label_2->setText(QApplication::translate("VCRS485_Calib", "\342\204\2261", Q_NULLPTR));
        label_3->setText(QApplication::translate("VCRS485_Calib", "\342\204\2262", Q_NULLPTR));
        label_4->setText(QApplication::translate("VCRS485_Calib", "\320\250\320\272\320\260\320\273\320\260 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("VCRS485_Calib", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", Q_NULLPTR));
        label_6->setText(QApplication::translate("VCRS485_Calib", "\320\235\320\270\320\266\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217, \320\222*10000", Q_NULLPTR));
        Dia->clear();
        Dia->insertItems(0, QStringList()
         << QApplication::translate("VCRS485_Calib", "\320\260\320\262\321\202\320\276", Q_NULLPTR)
         << QApplication::translate("VCRS485_Calib", "\320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274", Q_NULLPTR)
         << QApplication::translate("VCRS485_Calib", "\320\274\320\270\320\275\320\270\320\274\321\203\320\274", Q_NULLPTR)
        );
        diaWrite->setText(QApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        upWrite->setText(QApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        dwnWrite->setText(QApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        Calibrate->setText(QApplication::translate("VCRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        dia_label->setText(QApplication::translate("VCRS485_Calib", "\342\204\2261, \342\204\2262", Q_NULLPTR));
        label_7->setText(QApplication::translate("VCRS485_Calib", "\320\222\321\200\320\265\320\274\321\217 \321\203\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\321\217, \321\201\320\265\320\272\321\203\320\275\320\264", Q_NULLPTR));
        avgWrite->setText(QApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        pswWrite->setText(QApplication::translate("VCRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        Cancel->setText(QApplication::translate("VCRS485_Calib", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        label_8->setText(QApplication::translate("VCRS485_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VCRS485_Calib: public Ui_VCRS485_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCRS485_CALIB_H
