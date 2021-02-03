/********************************************************************************
** Form generated from reading UI file 'sr_control.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SR_CONTROL_H
#define UI_SR_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SR_Control
{
public:
    QPushButton *Cancel;
    QPushButton *Write;

    void setupUi(QDialog *SR_Control)
    {
        if (SR_Control->objectName().isEmpty())
            SR_Control->setObjectName(QStringLiteral("SR_Control"));
        SR_Control->resize(790, 520);
        SR_Control->setMinimumSize(QSize(790, 520));
        SR_Control->setMaximumSize(QSize(790, 520));
        Cancel = new QPushButton(SR_Control);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(675, 480, 100, 30));
        Write = new QPushButton(SR_Control);
        Write->setObjectName(QStringLiteral("Write"));
        Write->setGeometry(QRect(560, 480, 100, 30));

        retranslateUi(SR_Control);

        QMetaObject::connectSlotsByName(SR_Control);
    } // setupUi

    void retranslateUi(QDialog *SR_Control)
    {
        SR_Control->setWindowTitle(QApplication::translate("SR_Control", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \321\200\320\265\320\273\320\265\320\271\320\275\321\213\320\274\320\270 \320\262\321\213\321\205\320\276\320\264\320\260\320\274\320\270", Q_NULLPTR));
        Cancel->setText(QApplication::translate("SR_Control", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        Write->setText(QApplication::translate("SR_Control", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SR_Control: public Ui_SR_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SR_CONTROL_H
