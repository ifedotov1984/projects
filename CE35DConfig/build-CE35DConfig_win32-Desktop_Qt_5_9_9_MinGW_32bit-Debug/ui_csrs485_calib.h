/********************************************************************************
** Form generated from reading UI file 'csrs485_calib.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSRS485_CALIB_H
#define UI_CSRS485_CALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
            CSRS485_Calib->setObjectName(QStringLiteral("CSRS485_Calib"));
        CSRS485_Calib->resize(450, 194);
        label = new QLabel(CSRS485_Calib);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 15, 281, 30));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label_2 = new QLabel(CSRS485_Calib);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 171, 30));
        label_2->setFont(font);
        CalibZ = new QPushButton(CSRS485_Calib);
        CalibZ->setObjectName(QStringLiteral("CalibZ"));
        CalibZ->setGeometry(QRect(325, 15, 110, 30));
        CalibV = new QPushButton(CSRS485_Calib);
        CalibV->setObjectName(QStringLiteral("CalibV"));
        CalibV->setGeometry(QRect(325, 60, 110, 30));
        Write = new QPushButton(CSRS485_Calib);
        Write->setObjectName(QStringLiteral("Write"));
        Write->setGeometry(QRect(325, 105, 110, 30));
        Cancel = new QPushButton(CSRS485_Calib);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(325, 150, 110, 30));
        value = new QSpinBox(CSRS485_Calib);
        value->setObjectName(QStringLiteral("value"));
        value->setGeometry(QRect(220, 62, 80, 26));
        value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        value->setMaximum(10000);
        passw = new QLineEdit(CSRS485_Calib);
        passw->setObjectName(QStringLiteral("passw"));
        passw->setGeometry(QRect(150, 107, 151, 26));
        passw->setMaxLength(32);
        label_3 = new QLabel(CSRS485_Calib);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 106, 141, 26));
        label_3->setFont(font);

        retranslateUi(CSRS485_Calib);

        QMetaObject::connectSlotsByName(CSRS485_Calib);
    } // setupUi

    void retranslateUi(QDialog *CSRS485_Calib)
    {
        CSRS485_Calib->setWindowTitle(QApplication::translate("CSRS485_Calib", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\321\203\320\273\321\217 (<400ppm@60\320\274\320\270\320\275)", Q_NULLPTR));
        label_2->setText(QApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", Q_NULLPTR));
        CalibZ->setText(QApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        CalibV->setText(QApplication::translate("CSRS485_Calib", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        Write->setText(QApplication::translate("CSRS485_Calib", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        Cancel->setText(QApplication::translate("CSRS485_Calib", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("CSRS485_Calib", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSRS485_Calib: public Ui_CSRS485_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSRS485_CALIB_H
