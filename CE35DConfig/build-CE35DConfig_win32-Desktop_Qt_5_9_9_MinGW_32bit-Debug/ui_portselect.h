/********************************************************************************
** Form generated from reading UI file 'portselect.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTSELECT_H
#define UI_PORTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PortSelect
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *Submit;
    QPushButton *Cancel;

    void setupUi(QDialog *PortSelect)
    {
        if (PortSelect->objectName().isEmpty())
            PortSelect->setObjectName(QStringLiteral("PortSelect"));
        PortSelect->setWindowModality(Qt::WindowModal);
        PortSelect->resize(220, 120);
        PortSelect->setContextMenuPolicy(Qt::NoContextMenu);
        PortSelect->setModal(true);
        label = new QLabel(PortSelect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 71, 26));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        comboBox = new QComboBox(PortSelect);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 20, 110, 26));
        Submit = new QPushButton(PortSelect);
        Submit->setObjectName(QStringLiteral("Submit"));
        Submit->setGeometry(QRect(120, 80, 90, 28));
        Submit->setFont(font);
        Cancel = new QPushButton(PortSelect);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(10, 80, 90, 28));
        Cancel->setFont(font);

        retranslateUi(PortSelect);

        QMetaObject::connectSlotsByName(PortSelect);
    } // setupUi

    void retranslateUi(QDialog *PortSelect)
    {
        PortSelect->setWindowTitle(QApplication::translate("PortSelect", "\320\222\321\213\320\261\320\276\321\200 COM-\320\277\320\276\321\200\321\202\320\260", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        PortSelect->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("PortSelect", "COM-\320\277\320\276\321\200\321\202", Q_NULLPTR));
        Submit->setText(QApplication::translate("PortSelect", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        Cancel->setText(QApplication::translate("PortSelect", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PortSelect: public Ui_PortSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTSELECT_H
