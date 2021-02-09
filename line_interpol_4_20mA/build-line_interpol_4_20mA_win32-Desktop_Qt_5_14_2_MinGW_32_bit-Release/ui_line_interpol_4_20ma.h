/********************************************************************************
** Form generated from reading UI file 'line_interpol_4_20ma.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINE_INTERPOL_4_20MA_H
#define UI_LINE_INTERPOL_4_20MA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_line_interpol_4_20mA
{
public:
    QAction *actiononData_Changed;
    QWidget *centralwidget;
    QLineEdit *Y0Edit;
    QLineEdit *Y1Edit;
    QLineEdit *X0Edit;
    QLineEdit *X1Edit;
    QLineEdit *Z0Edit;
    QLineEdit *Z1Edit;
    QSpinBox *I0Box;
    QSpinBox *I1Box;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *Y0Box_X;
    QLabel *label_5;
    QSpinBox *Y1Box_X;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *X0Box_X;
    QSpinBox *X1Box_X;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *ZBox_X;
    QLabel *label_12;
    QMenuBar *menubar;

    void setupUi(QMainWindow *line_interpol_4_20mA)
    {
        if (line_interpol_4_20mA->objectName().isEmpty())
            line_interpol_4_20mA->setObjectName(QString::fromUtf8("line_interpol_4_20mA"));
        line_interpol_4_20mA->resize(350, 180);
        line_interpol_4_20mA->setMinimumSize(QSize(350, 180));
        line_interpol_4_20mA->setMaximumSize(QSize(350, 180));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMLEthernetLoader.svg"), QSize(), QIcon::Normal, QIcon::Off);
        line_interpol_4_20mA->setWindowIcon(icon);
        actiononData_Changed = new QAction(line_interpol_4_20mA);
        actiononData_Changed->setObjectName(QString::fromUtf8("actiononData_Changed"));
        centralwidget = new QWidget(line_interpol_4_20mA);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Y0Edit = new QLineEdit(centralwidget);
        Y0Edit->setObjectName(QString::fromUtf8("Y0Edit"));
        Y0Edit->setGeometry(QRect(20, 26, 75, 18));
        Y0Edit->setMaxLength(10);
        Y1Edit = new QLineEdit(centralwidget);
        Y1Edit->setObjectName(QString::fromUtf8("Y1Edit"));
        Y1Edit->setGeometry(QRect(20, 55, 75, 18));
        Y1Edit->setMaxLength(10);
        X0Edit = new QLineEdit(centralwidget);
        X0Edit->setObjectName(QString::fromUtf8("X0Edit"));
        X0Edit->setGeometry(QRect(185, 26, 75, 18));
        X0Edit->setMaxLength(10);
        X1Edit = new QLineEdit(centralwidget);
        X1Edit->setObjectName(QString::fromUtf8("X1Edit"));
        X1Edit->setGeometry(QRect(185, 55, 75, 18));
        X1Edit->setMaxLength(10);
        Z0Edit = new QLineEdit(centralwidget);
        Z0Edit->setObjectName(QString::fromUtf8("Z0Edit"));
        Z0Edit->setGeometry(QRect(20, 151, 75, 18));
        Z0Edit->setMaxLength(10);
        Z0Edit->setReadOnly(true);
        Z1Edit = new QLineEdit(centralwidget);
        Z1Edit->setObjectName(QString::fromUtf8("Z1Edit"));
        Z1Edit->setGeometry(QRect(185, 151, 75, 18));
        Z1Edit->setMaxLength(10);
        Z1Edit->setReadOnly(true);
        I0Box = new QSpinBox(centralwidget);
        I0Box->setObjectName(QString::fromUtf8("I0Box"));
        I0Box->setGeometry(QRect(85, 105, 75, 20));
        I0Box->setValue(4);
        I1Box = new QSpinBox(centralwidget);
        I1Box->setObjectName(QString::fromUtf8("I1Box"));
        I1Box->setGeometry(QRect(185, 105, 75, 20));
        I1Box->setValue(20);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 5, 121, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 25, 21, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 55, 21, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 5, 121, 15));
        Y0Box_X = new QSpinBox(centralwidget);
        Y0Box_X->setObjectName(QString::fromUtf8("Y0Box_X"));
        Y0Box_X->setGeometry(QRect(110, 25, 50, 20));
        Y0Box_X->setMaximum(1000);
        Y0Box_X->setValue(10);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 25, 15, 20));
        Y1Box_X = new QSpinBox(centralwidget);
        Y1Box_X->setObjectName(QString::fromUtf8("Y1Box_X"));
        Y1Box_X->setGeometry(QRect(110, 55, 50, 20));
        Y1Box_X->setMaximum(1000);
        Y1Box_X->setValue(10);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 55, 15, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(265, 55, 15, 20));
        X0Box_X = new QSpinBox(centralwidget);
        X0Box_X->setObjectName(QString::fromUtf8("X0Box_X"));
        X0Box_X->setGeometry(QRect(275, 25, 50, 20));
        X0Box_X->setMaximum(1000);
        X0Box_X->setValue(10);
        X1Box_X = new QSpinBox(centralwidget);
        X1Box_X->setObjectName(QString::fromUtf8("X1Box_X"));
        X1Box_X->setGeometry(QRect(275, 55, 50, 20));
        X1Box_X->setMaximum(1000);
        X1Box_X->setValue(10);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(265, 25, 15, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(38, 85, 270, 15));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 130, 250, 15));
        label_11->setAlignment(Qt::AlignCenter);
        ZBox_X = new QSpinBox(centralwidget);
        ZBox_X->setObjectName(QString::fromUtf8("ZBox_X"));
        ZBox_X->setGeometry(QRect(275, 150, 65, 20));
        ZBox_X->setMinimum(1);
        ZBox_X->setMaximum(1000000);
        ZBox_X->setSingleStep(1);
        ZBox_X->setValue(1);
        ZBox_X->setDisplayIntegerBase(10);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(265, 150, 15, 20));
        line_interpol_4_20mA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(line_interpol_4_20mA);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 350, 26));
        line_interpol_4_20mA->setMenuBar(menubar);
        QWidget::setTabOrder(Y0Edit, Y1Edit);
        QWidget::setTabOrder(Y1Edit, Y0Box_X);
        QWidget::setTabOrder(Y0Box_X, Y1Box_X);
        QWidget::setTabOrder(Y1Box_X, X0Edit);
        QWidget::setTabOrder(X0Edit, X1Edit);
        QWidget::setTabOrder(X1Edit, X0Box_X);
        QWidget::setTabOrder(X0Box_X, X1Box_X);
        QWidget::setTabOrder(X1Box_X, I0Box);
        QWidget::setTabOrder(I0Box, I1Box);
        QWidget::setTabOrder(I1Box, Z0Edit);
        QWidget::setTabOrder(Z0Edit, Z1Edit);

        retranslateUi(line_interpol_4_20mA);

        QMetaObject::connectSlotsByName(line_interpol_4_20mA);
    } // setupUi

    void retranslateUi(QMainWindow *line_interpol_4_20mA)
    {
        line_interpol_4_20mA->setWindowTitle(QCoreApplication::translate("line_interpol_4_20mA", "line_interpol_4_20mA", nullptr));
        actiononData_Changed->setText(QCoreApplication::translate("line_interpol_4_20mA", "onData_Changed", nullptr));
        label->setText(QCoreApplication::translate("line_interpol_4_20mA", "\320\230\320\267\320\274\320\265\321\200\321\217\320\265\320\274\321\213\320\271 \321\202\320\276\320\272, \320\220", nullptr));
        label_2->setText(QCoreApplication::translate("line_interpol_4_20mA", "1", nullptr));
        label_3->setText(QCoreApplication::translate("line_interpol_4_20mA", "2", nullptr));
        label_4->setText(QCoreApplication::translate("line_interpol_4_20mA", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271 \321\202\320\276\320\272, m\320\220", nullptr));
        label_5->setText(QCoreApplication::translate("line_interpol_4_20mA", "x", nullptr));
        label_7->setText(QCoreApplication::translate("line_interpol_4_20mA", "x", nullptr));
        label_8->setText(QCoreApplication::translate("line_interpol_4_20mA", "x", nullptr));
        label_9->setText(QCoreApplication::translate("line_interpol_4_20mA", "x", nullptr));
        label_10->setText(QCoreApplication::translate("line_interpol_4_20mA", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\202\320\276\320\272\320\260 \320\264\320\273\321\217 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217, \320\274\320\220", nullptr));
        label_11->setText(QCoreApplication::translate("line_interpol_4_20mA", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213 \320\264\320\273\321\217 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_12->setText(QCoreApplication::translate("line_interpol_4_20mA", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class line_interpol_4_20mA: public Ui_line_interpol_4_20mA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINE_INTERPOL_4_20MA_H
