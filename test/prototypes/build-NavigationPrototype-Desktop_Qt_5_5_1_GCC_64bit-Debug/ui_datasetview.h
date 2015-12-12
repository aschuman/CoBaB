/********************************************************************************
** Form generated from reading UI file 'datasetview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASETVIEW_H
#define UI_DATASETVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatasetView
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *lblDataset;

    void setupUi(QWidget *DatasetView)
    {
        if (DatasetView->objectName().isEmpty())
            DatasetView->setObjectName(QStringLiteral("DatasetView"));
        DatasetView->resize(400, 300);
        label = new QLabel(DatasetView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 271, 141));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(DatasetView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 160, 95, 31));
        lblDataset = new QLabel(DatasetView);
        lblDataset->setObjectName(QStringLiteral("lblDataset"));
        lblDataset->setGeometry(QRect(70, 120, 241, 21));
        QFont font1;
        font1.setPointSize(8);
        lblDataset->setFont(font1);
        lblDataset->setAlignment(Qt::AlignCenter);

        retranslateUi(DatasetView);

        QMetaObject::connectSlotsByName(DatasetView);
    } // setupUi

    void retranslateUi(QWidget *DatasetView)
    {
        DatasetView->setWindowTitle(QApplication::translate("DatasetView", "Form", 0));
        label->setText(QApplication::translate("DatasetView", "DatasetView", 0));
        pushButton->setText(QApplication::translate("DatasetView", "PushButton", 0));
        lblDataset->setText(QApplication::translate("DatasetView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class DatasetView: public Ui_DatasetView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASETVIEW_H
