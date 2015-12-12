/********************************************************************************
** Form generated from reading UI file 'libraryview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYVIEW_H
#define UI_LIBRARYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibraryView
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *LibraryView)
    {
        if (LibraryView->objectName().isEmpty())
            LibraryView->setObjectName(QStringLiteral("LibraryView"));
        LibraryView->resize(400, 300);
        label = new QLabel(LibraryView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 251, 101));
        QFont font;
        font.setPointSize(22);
        font.setKerning(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(LibraryView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 160, 95, 31));

        retranslateUi(LibraryView);

        QMetaObject::connectSlotsByName(LibraryView);
    } // setupUi

    void retranslateUi(QWidget *LibraryView)
    {
        LibraryView->setWindowTitle(QApplication::translate("LibraryView", "Form", 0));
        label->setText(QApplication::translate("LibraryView", "LibraryView", 0));
        pushButton->setText(QApplication::translate("LibraryView", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class LibraryView: public Ui_LibraryView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYVIEW_H
