/********************************************************************************
** Form generated from reading UI file 'line_interpol_4_20ma.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINE_INTERPOL_4_20MA_H
#define UI_LINE_INTERPOL_4_20MA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *line_interpol_4_20mA)
    {
        if (line_interpol_4_20mA->objectName().isEmpty())
            line_interpol_4_20mA->setObjectName(QStringLiteral("line_interpol_4_20mA"));
        line_interpol_4_20mA->resize(480, 310);
        line_interpol_4_20mA->setMinimumSize(QSize(480, 310));
        line_interpol_4_20mA->setMaximumSize(QSize(480, 310));
        actiononData_Changed = new QAction(line_interpol_4_20mA);
        actiononData_Changed->setObjectName(QStringLiteral("actiononData_Changed"));
        centralwidget = new QWidget(line_interpol_4_20mA);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Y0Edit = new QLineEdit(centralwidget);
        Y0Edit->setObjectName(QStringLiteral("Y0Edit"));
        Y0Edit->setGeometry(QRect(30, 30, 113, 22));
        Y0Edit->setMaxLength(10);
        Y1Edit = new QLineEdit(centralwidget);
        Y1Edit->setObjectName(QStringLiteral("Y1Edit"));
        Y1Edit->setGeometry(QRect(30, 70, 113, 22));
        Y1Edit->setMaxLength(10);
        X0Edit = new QLineEdit(centralwidget);
        X0Edit->setObjectName(QStringLiteral("X0Edit"));
        X0Edit->setGeometry(QRect(260, 30, 113, 22));
        X0Edit->setMaxLength(10);
        X1Edit = new QLineEdit(centralwidget);
        X1Edit->setObjectName(QStringLiteral("X1Edit"));
        X1Edit->setGeometry(QRect(260, 70, 113, 22));
        X1Edit->setMaxLength(10);
        Z0Edit = new QLineEdit(centralwidget);
        Z0Edit->setObjectName(QStringLiteral("Z0Edit"));
        Z0Edit->setGeometry(QRect(30, 230, 81, 22));
        Z0Edit->setMaxLength(10);
        Z0Edit->setReadOnly(true);
        Z1Edit = new QLineEdit(centralwidget);
        Z1Edit->setObjectName(QStringLiteral("Z1Edit"));
        Z1Edit->setGeometry(QRect(180, 230, 81, 22));
        Z1Edit->setMaxLength(10);
        Z1Edit->setReadOnly(true);
        I0Box = new QSpinBox(centralwidget);
        I0Box->setObjectName(QStringLiteral("I0Box"));
        I0Box->setGeometry(QRect(30, 170, 81, 22));
        I0Box->setValue(4);
        I1Box = new QSpinBox(centralwidget);
        I1Box->setObjectName(QStringLiteral("I1Box"));
        I1Box->setGeometry(QRect(180, 170, 81, 22));
        I1Box->setValue(20);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 121, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 21, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 21, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 10, 121, 16));
        Y0Box_X = new QSpinBox(centralwidget);
        Y0Box_X->setObjectName(QStringLiteral("Y0Box_X"));
        Y0Box_X->setGeometry(QRect(170, 30, 71, 22));
        Y0Box_X->setValue(10);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 30, 21, 21));
        Y1Box_X = new QSpinBox(centralwidget);
        Y1Box_X->setObjectName(QStringLiteral("Y1Box_X"));
        Y1Box_X->setGeometry(QRect(170, 70, 71, 22));
        Y1Box_X->setValue(10);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 70, 21, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(380, 70, 21, 21));
        X0Box_X = new QSpinBox(centralwidget);
        X0Box_X->setObjectName(QStringLiteral("X0Box_X"));
        X0Box_X->setGeometry(QRect(400, 30, 71, 22));
        X0Box_X->setValue(10);
        X1Box_X = new QSpinBox(centralwidget);
        X1Box_X->setObjectName(QStringLiteral("X1Box_X"));
        X1Box_X->setGeometry(QRect(400, 70, 71, 22));
        X1Box_X->setValue(10);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(380, 30, 21, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 150, 241, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 210, 241, 16));
        ZBox_X = new QSpinBox(centralwidget);
        ZBox_X->setObjectName(QStringLiteral("ZBox_X"));
        ZBox_X->setGeometry(QRect(290, 230, 81, 22));
        ZBox_X->setMinimum(1);
        ZBox_X->setMaximum(1000000);
        ZBox_X->setSingleStep(1);
        ZBox_X->setValue(1);
        ZBox_X->setDisplayIntegerBase(10);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(270, 230, 21, 21));
        line_interpol_4_20mA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(line_interpol_4_20mA);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 26));
        line_interpol_4_20mA->setMenuBar(menubar);
        statusbar = new QStatusBar(line_interpol_4_20mA);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        line_interpol_4_20mA->setStatusBar(statusbar);
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
        line_interpol_4_20mA->setWindowTitle(QApplication::translate("line_interpol_4_20mA", "line_interpol_4_20mA", Q_NULLPTR));
        actiononData_Changed->setText(QApplication::translate("line_interpol_4_20mA", "onData_Changed", Q_NULLPTR));
        label->setText(QApplication::translate("line_interpol_4_20mA", "\320\230\320\267\320\274\320\265\321\200\321\217\320\265\320\274\321\213\320\271 \321\202\320\276\320\272, \320\220", Q_NULLPTR));
        label_2->setText(QApplication::translate("line_interpol_4_20mA", "1", Q_NULLPTR));
        label_3->setText(QApplication::translate("line_interpol_4_20mA", "2", Q_NULLPTR));
        label_4->setText(QApplication::translate("line_interpol_4_20mA", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271 \321\202\320\276\320\272, m\320\220", Q_NULLPTR));
        label_5->setText(QApplication::translate("line_interpol_4_20mA", "x", Q_NULLPTR));
        label_7->setText(QApplication::translate("line_interpol_4_20mA", "x", Q_NULLPTR));
        label_8->setText(QApplication::translate("line_interpol_4_20mA", "x", Q_NULLPTR));
        label_9->setText(QApplication::translate("line_interpol_4_20mA", "x", Q_NULLPTR));
        label_10->setText(QApplication::translate("line_interpol_4_20mA", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\202\320\276\320\272\320\260 \320\264\320\273\321\217 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217, \320\274\320\220", Q_NULLPTR));
        label_11->setText(QApplication::translate("line_interpol_4_20mA", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213 \320\264\320\273\321\217 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        label_12->setText(QApplication::translate("line_interpol_4_20mA", "x", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class line_interpol_4_20mA: public Ui_line_interpol_4_20mA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINE_INTERPOL_4_20MA_H
