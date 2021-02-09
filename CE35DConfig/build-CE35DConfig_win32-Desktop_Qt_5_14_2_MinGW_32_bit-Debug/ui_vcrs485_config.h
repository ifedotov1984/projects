/********************************************************************************
** Form generated from reading UI file 'vcrs485_config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCRS485_CONFIG_H
#define UI_VCRS485_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
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
            VCRS485_Config->setObjectName(QString::fromUtf8("VCRS485_Config"));
        VCRS485_Config->resize(370, 298);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VCRS485_Config->sizePolicy().hasHeightForWidth());
        VCRS485_Config->setSizePolicy(sizePolicy);
        VCRS485_Config->setMinimumSize(QSize(370, 298));
        VCRS485_Config->setMaximumSize(QSize(370, 298));
        Cancel = new QPushButton(VCRS485_Config);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(265, 265, 90, 26));
        sizePolicy.setHeightForWidth(Cancel->sizePolicy().hasHeightForWidth());
        Cancel->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(VCRS485_Config);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(5, 0, 360, 130));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 14, 161, 22));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        koeff_K = new QSpinBox(groupBox);
        koeff_K->setObjectName(QString::fromUtf8("koeff_K"));
        koeff_K->setGeometry(QRect(170, 14, 80, 22));
        sizePolicy.setHeightForWidth(koeff_K->sizePolicy().hasHeightForWidth());
        koeff_K->setSizePolicy(sizePolicy);
        koeff_K->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_K->setMinimum(-1000000000);
        koeff_K->setMaximum(1000000000);
        koeff_K->setValue(0);
        koeff_Z = new QSpinBox(groupBox);
        koeff_Z->setObjectName(QString::fromUtf8("koeff_Z"));
        koeff_Z->setGeometry(QRect(170, 42, 80, 22));
        sizePolicy.setHeightForWidth(koeff_Z->sizePolicy().hasHeightForWidth());
        koeff_Z->setSizePolicy(sizePolicy);
        koeff_Z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_Z->setMinimum(-1000000000);
        koeff_Z->setMaximum(1000000000);
        koeff_Z->setValue(0);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 42, 161, 22));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 151, 18));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        dim = new QLineEdit(groupBox);
        dim->setObjectName(QString::fromUtf8("dim"));
        dim->setGeometry(QRect(170, 70, 80, 18));
        sizePolicy.setHeightForWidth(dim->sizePolicy().hasHeightForWidth());
        dim->setSizePolicy(sizePolicy);
        dim->setMaxLength(10);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 95, 151, 22));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        dec = new QSpinBox(groupBox);
        dec->setObjectName(QString::fromUtf8("dec"));
        dec->setGeometry(QRect(210, 95, 40, 22));
        sizePolicy.setHeightForWidth(dec->sizePolicy().hasHeightForWidth());
        dec->setSizePolicy(sizePolicy);
        dec->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dec->setMaximum(3);
        dWrite = new QPushButton(groupBox);
        dWrite->setObjectName(QString::fromUtf8("dWrite"));
        dWrite->setGeometry(QRect(260, 93, 90, 26));
        sizePolicy.setHeightForWidth(dWrite->sizePolicy().hasHeightForWidth());
        dWrite->setSizePolicy(sizePolicy);
        groupBox_2 = new QGroupBox(VCRS485_Config);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(5, 130, 360, 130));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 14, 160, 22));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        koeff_K_2 = new QSpinBox(groupBox_2);
        koeff_K_2->setObjectName(QString::fromUtf8("koeff_K_2"));
        koeff_K_2->setGeometry(QRect(170, 14, 80, 22));
        sizePolicy.setHeightForWidth(koeff_K_2->sizePolicy().hasHeightForWidth());
        koeff_K_2->setSizePolicy(sizePolicy);
        koeff_K_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_K_2->setMinimum(-1000000000);
        koeff_K_2->setMaximum(1000000000);
        koeff_K_2->setValue(0);
        koeff_Z_2 = new QSpinBox(groupBox_2);
        koeff_Z_2->setObjectName(QString::fromUtf8("koeff_Z_2"));
        koeff_Z_2->setGeometry(QRect(170, 42, 80, 22));
        sizePolicy.setHeightForWidth(koeff_Z_2->sizePolicy().hasHeightForWidth());
        koeff_Z_2->setSizePolicy(sizePolicy);
        koeff_Z_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        koeff_Z_2->setMinimum(-1000000000);
        koeff_Z_2->setMaximum(1000000000);
        koeff_Z_2->setValue(0);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 42, 161, 22));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 70, 151, 18));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        dim_2 = new QLineEdit(groupBox_2);
        dim_2->setObjectName(QString::fromUtf8("dim_2"));
        dim_2->setGeometry(QRect(170, 70, 80, 18));
        sizePolicy.setHeightForWidth(dim_2->sizePolicy().hasHeightForWidth());
        dim_2->setSizePolicy(sizePolicy);
        dim_2->setMaxLength(10);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 95, 150, 22));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        dec_2 = new QSpinBox(groupBox_2);
        dec_2->setObjectName(QString::fromUtf8("dec_2"));
        dec_2->setGeometry(QRect(210, 95, 40, 22));
        sizePolicy.setHeightForWidth(dec_2->sizePolicy().hasHeightForWidth());
        dec_2->setSizePolicy(sizePolicy);
        dec_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dec_2->setMaximum(3);
        dWrite_2 = new QPushButton(groupBox_2);
        dWrite_2->setObjectName(QString::fromUtf8("dWrite_2"));
        dWrite_2->setGeometry(QRect(260, 93, 90, 26));
        sizePolicy.setHeightForWidth(dWrite_2->sizePolicy().hasHeightForWidth());
        dWrite_2->setSizePolicy(sizePolicy);

        retranslateUi(VCRS485_Config);

        QMetaObject::connectSlotsByName(VCRS485_Config);
    } // setupUi

    void retranslateUi(QDialog *VCRS485_Config)
    {
        VCRS485_Config->setWindowTitle(QCoreApplication::translate("VCRS485_Config", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 VC-RS485", nullptr));
        Cancel->setText(QCoreApplication::translate("VCRS485_Config", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VCRS485_Config", "\320\224\320\260\321\202\321\207\320\270\320\272 AnK \342\204\2261", nullptr));
        label->setText(QCoreApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 K", nullptr));
        label_2->setText(QCoreApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 Z", nullptr));
        label_3->setText(QCoreApplication::translate("VCRS485_Config", "\320\240\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("VCRS485_Config", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\321\213\320\271 \320\267\320\275\320\260\320\272", nullptr));
        dWrite->setText(QCoreApplication::translate("VCRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("VCRS485_Config", "\320\224\320\260\321\202\321\207\320\270\320\272 AnK \342\204\2262", nullptr));
        label_5->setText(QCoreApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 K", nullptr));
        label_6->setText(QCoreApplication::translate("VCRS485_Config", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260 Z", nullptr));
        label_7->setText(QCoreApplication::translate("VCRS485_Config", "\320\240\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("VCRS485_Config", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\321\213\320\271 \320\267\320\275\320\260\320\272", nullptr));
        dWrite_2->setText(QCoreApplication::translate("VCRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VCRS485_Config: public Ui_VCRS485_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCRS485_CONFIG_H
