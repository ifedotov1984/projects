/********************************************************************************
** Form generated from reading UI file 'vcrs485_config.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCRS485_CONFIG_H
#define UI_VCRS485_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_VCRS485_Config
{
public:
    QPushButton *Cancel;
    QGroupBox *groupBox;
    QLabel *label;
    QSpinBox *koeff_K;
    QSpinBox *koeff_Z;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *dim;
    QLabel *label_4;
    QSpinBox *dec;
    QPushButton *dWrite;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QSpinBox *koeff_K_2;
    QSpinBox *koeff_Z_2;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *dim_2;
    QLabel *label_8;
    QSpinBox *dec_2;
    QPushButton *dWrite_2;

    void setupUi(QDialog *VCRS485_Config)
    {
        if (VCRS485_Config->objectName().isEmpty())
            VCRS485_Config->setObjectName(QStringLiteral("VCRS485_Config"));
        VCRS485_Config->resize(475, 380);
        Cancel = new QPushButton(VCRS485_Config);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(360, 335, 95, 30));
        groupBox = new QGroupBox(VCRS485_Config);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 455, 160));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 191, 25));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        koeff_K = new QSpinBox(groupBox);
        koeff_K->setObjectName(QStringLiteral("koeff_K"));
        koeff_K->setGeometry(QRect(210, 20, 120, 26));
        koeff_K->setFont(font);
        koeff_K->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_K->setMinimum(-1000000000);
        koeff_K->setMaximum(1000000000);
        koeff_K->setValue(0);
        koeff_Z = new QSpinBox(groupBox);
        koeff_Z->setObjectName(QStringLiteral("koeff_Z"));
        koeff_Z->setGeometry(QRect(210, 55, 120, 26));
        koeff_Z->setFont(font);
        koeff_Z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_Z->setMinimum(-1000000000);
        koeff_Z->setMaximum(1000000000);
        koeff_Z->setValue(0);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 55, 191, 25));
        label_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 191, 25));
        label_3->setFont(font);
        dim = new QLineEdit(groupBox);
        dim->setObjectName(QStringLiteral("dim"));
        dim->setGeometry(QRect(210, 90, 120, 26));
        dim->setMaxLength(10);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 122, 191, 25));
        label_4->setFont(font);
        dec = new QSpinBox(groupBox);
        dec->setObjectName(QStringLiteral("dec"));
        dec->setGeometry(QRect(290, 122, 40, 26));
        dec->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dec->setMaximum(3);
        dWrite = new QPushButton(groupBox);
        dWrite->setObjectName(QStringLiteral("dWrite"));
        dWrite->setGeometry(QRect(350, 120, 95, 30));
        groupBox_2 = new QGroupBox(VCRS485_Config);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 165, 455, 160));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 191, 25));
        label_5->setFont(font);
        koeff_K_2 = new QSpinBox(groupBox_2);
        koeff_K_2->setObjectName(QStringLiteral("koeff_K_2"));
        koeff_K_2->setGeometry(QRect(210, 20, 120, 26));
        koeff_K_2->setFont(font);
        koeff_K_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_K_2->setMinimum(-1000000000);
        koeff_K_2->setMaximum(1000000000);
        koeff_K_2->setValue(0);
        koeff_Z_2 = new QSpinBox(groupBox_2);
        koeff_Z_2->setObjectName(QStringLiteral("koeff_Z_2"));
        koeff_Z_2->setGeometry(QRect(210, 55, 120, 26));
        koeff_Z_2->setFont(font);
        koeff_Z_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_Z_2->setMinimum(-1000000000);
        koeff_Z_2->setMaximum(1000000000);
        koeff_Z_2->setValue(0);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 55, 191, 25));
        label_6->setFont(font);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 90, 191, 25));
        label_7->setFont(font);
        dim_2 = new QLineEdit(groupBox_2);
        dim_2->setObjectName(QStringLiteral("dim_2"));
        dim_2->setGeometry(QRect(210, 90, 120, 26));
        dim_2->setMaxLength(10);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 122, 191, 25));
        label_8->setFont(font);
        dec_2 = new QSpinBox(groupBox_2);
        dec_2->setObjectName(QStringLiteral("dec_2"));
        dec_2->setGeometry(QRect(290, 122, 40, 26));
        dec_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dec_2->setMaximum(3);
        dWrite_2 = new QPushButton(groupBox_2);
        dWrite_2->setObjectName(QStringLiteral("dWrite_2"));
        dWrite_2->setGeometry(QRect(350, 120, 95, 30));

        retranslateUi(VCRS485_Config);

        QMetaObject::connectSlotsByName(VCRS485_Config);
    } // setupUi

    void retranslateUi(QDialog *VCRS485_Config)
    {
        VCRS485_Config->setWindowTitle(QApplication::translate("VCRS485_Config", "\320\232\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\321\217 \320\264\320\260\321\202\321\207\320\270\320\272\320\260 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217", Q_NULLPTR));
        Cancel->setText(QApplication::translate("VCRS485_Config", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("VCRS485_Config", "\320\224\320\260\321\202\321\207\320\270\320\272 AnK \342\204\2261", Q_NULLPTR));
        label->setText(QApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 K", Q_NULLPTR));
        label_2->setText(QApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 Z", Q_NULLPTR));
        label_3->setText(QApplication::translate("VCRS485_Config", "\320\240\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("VCRS485_Config", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\321\213\320\271 \320\267\320\275\320\260\320\272", Q_NULLPTR));
        dWrite->setText(QApplication::translate("VCRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("VCRS485_Config", "\320\224\320\260\321\202\321\207\320\270\320\272 AnK \342\204\2262", Q_NULLPTR));
        label_5->setText(QApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 K", Q_NULLPTR));
        label_6->setText(QApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 Z", Q_NULLPTR));
        label_7->setText(QApplication::translate("VCRS485_Config", "\320\240\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("VCRS485_Config", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\321\213\320\271 \320\267\320\275\320\260\320\272", Q_NULLPTR));
        dWrite_2->setText(QApplication::translate("VCRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VCRS485_Config: public Ui_VCRS485_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCRS485_CONFIG_H
