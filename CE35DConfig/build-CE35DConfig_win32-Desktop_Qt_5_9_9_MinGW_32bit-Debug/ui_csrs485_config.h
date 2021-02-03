/********************************************************************************
** Form generated from reading UI file 'csrs485_config.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSRS485_CONFIG_H
#define UI_CSRS485_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
            CSRS485_Config->setObjectName(QStringLiteral("CSRS485_Config"));
        CSRS485_Config->resize(450, 149);
        label = new QLabel(CSRS485_Config);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 15, 191, 30));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label_2 = new QLabel(CSRS485_Config);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 65, 191, 16));
        label_2->setFont(font);
        diap = new QComboBox(CSRS485_Config);
        diap->setObjectName(QStringLiteral("diap"));
        diap->setGeometry(QRect(210, 15, 111, 30));
        dWrite = new QPushButton(CSRS485_Config);
        dWrite->setObjectName(QStringLiteral("dWrite"));
        dWrite->setGeometry(QRect(340, 15, 95, 30));
        correct = new QCheckBox(CSRS485_Config);
        correct->setObjectName(QStringLiteral("correct"));
        correct->setGeometry(QRect(303, 65, 18, 20));
        dWrite_2 = new QPushButton(CSRS485_Config);
        dWrite_2->setObjectName(QStringLiteral("dWrite_2"));
        dWrite_2->setGeometry(QRect(340, 60, 95, 30));
        Cancel = new QPushButton(CSRS485_Config);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(340, 105, 95, 30));

        retranslateUi(CSRS485_Config);

        QMetaObject::connectSlotsByName(CSRS485_Config);
    } // setupUi

    void retranslateUi(QDialog *CSRS485_Config)
    {
        CSRS485_Config->setWindowTitle(QApplication::translate("CSRS485_Config", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CSRS485_Config", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217, ppm", Q_NULLPTR));
        label_2->setText(QApplication::translate("CSRS485_Config", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", Q_NULLPTR));
        diap->clear();
        diap->insertItems(0, QStringList()
         << QApplication::translate("CSRS485_Config", "400-5000", Q_NULLPTR)
         << QApplication::translate("CSRS485_Config", "400-10000", Q_NULLPTR)
        );
        dWrite->setText(QApplication::translate("CSRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        correct->setText(QString());
        dWrite_2->setText(QApplication::translate("CSRS485_Config", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        Cancel->setText(QApplication::translate("CSRS485_Config", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSRS485_Config: public Ui_CSRS485_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSRS485_CONFIG_H
