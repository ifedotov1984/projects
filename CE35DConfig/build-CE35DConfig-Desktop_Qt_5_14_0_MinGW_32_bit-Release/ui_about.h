/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(330, 132);
        label_2 = new QLabel(about);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 13, 331, 41));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        label_4 = new QLabel(about);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 47, 141, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        label_5 = new QLabel(about);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 88, 231, 31));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5->setWordWrap(true);
        pushButton = new QPushButton(about);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 90, 90, 30));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("about", "\320\232\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\202\320\276\321\200 \320\274\320\276\320\264\321\203\320\273\320\265\320\271 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\321\217 \321\201\320\265\321\200\320\270\320\270 35D \"35D Config\"", nullptr));
        label_4->setText(QCoreApplication::translate("about", "version 4.01", nullptr));
        label_5->setText(QCoreApplication::translate("about", "\320\236\320\236\320\236 \"\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202 \320\274\320\276\320\264\321\203\320\273\321\214\" www.intellect-module.ru", nullptr));
        pushButton->setText(QCoreApplication::translate("about", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
