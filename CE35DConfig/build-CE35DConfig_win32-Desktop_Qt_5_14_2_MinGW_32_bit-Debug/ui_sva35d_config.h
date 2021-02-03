/********************************************************************************
** Form generated from reading UI file 'sva35d_config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SVA35D_CONFIG_H
#define UI_SVA35D_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SVA35D_Config
{
public:
    QLabel *label_5;
    QPushButton *vWrite;
    QSpinBox *v_coeff;
    QPushButton *iWrite;
    QLabel *label_6;
    QSpinBox *i_coeff;
    QPushButton *Cancel;

    void setupUi(QDialog *SVA35D_Config)
    {
        if (SVA35D_Config->objectName().isEmpty())
            SVA35D_Config->setObjectName(QString::fromUtf8("SVA35D_Config"));
        SVA35D_Config->resize(520, 155);
        label_5 = new QLabel(SVA35D_Config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 12, 291, 26));
        QFont font;
        font.setPointSize(9);
        label_5->setFont(font);
        vWrite = new QPushButton(SVA35D_Config);
        vWrite->setObjectName(QString::fromUtf8("vWrite"));
        vWrite->setGeometry(QRect(420, 10, 90, 30));
        vWrite->setFont(font);
        v_coeff = new QSpinBox(SVA35D_Config);
        v_coeff->setObjectName(QString::fromUtf8("v_coeff"));
        v_coeff->setGeometry(QRect(300, 12, 100, 26));
        v_coeff->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        v_coeff->setMinimum(0);
        v_coeff->setMaximum(1000000000);
        iWrite = new QPushButton(SVA35D_Config);
        iWrite->setObjectName(QString::fromUtf8("iWrite"));
        iWrite->setGeometry(QRect(420, 60, 90, 30));
        iWrite->setFont(font);
        label_6 = new QLabel(SVA35D_Config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 62, 291, 26));
        label_6->setFont(font);
        i_coeff = new QSpinBox(SVA35D_Config);
        i_coeff->setObjectName(QString::fromUtf8("i_coeff"));
        i_coeff->setGeometry(QRect(300, 62, 100, 26));
        i_coeff->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        i_coeff->setMinimum(0);
        i_coeff->setMaximum(1000000000);
        Cancel = new QPushButton(SVA35D_Config);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(420, 110, 90, 30));
        Cancel->setFont(font);

        retranslateUi(SVA35D_Config);

        QMetaObject::connectSlotsByName(SVA35D_Config);
    } // setupUi

    void retranslateUi(QDialog *SVA35D_Config)
    {
        SVA35D_Config->setWindowTitle(QCoreApplication::translate("SVA35D_Config", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("SVA35D_Config", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\270 \320\277\320\276 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\216", nullptr));
        vWrite->setText(QCoreApplication::translate("SVA35D_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        iWrite->setText(QCoreApplication::translate("SVA35D_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("SVA35D_Config", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\270 \320\277\320\276 \321\202\320\276\320\272\321\203", nullptr));
        Cancel->setText(QCoreApplication::translate("SVA35D_Config", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SVA35D_Config: public Ui_SVA35D_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SVA35D_CONFIG_H
