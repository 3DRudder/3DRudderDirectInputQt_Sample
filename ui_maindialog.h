/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *Pitch;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *UpDown;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *Yaw;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Roll;
    QGroupBox *groupBox_2;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *Sensor1;
    QLabel *label_7;
    QLineEdit *Sensor2;
    QLabel *label_8;
    QLineEdit *Sensor3;
    QLabel *label_9;
    QLineEdit *Sensor4;
    QLabel *label_10;
    QLineEdit *Sensor5;
    QLabel *label_11;
    QLineEdit *Sensor6;
    QLabel *Status;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(512, 242);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainDialog->sizePolicy().hasHeightForWidth());
        MainDialog->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(MainDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 221, 161));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 201, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        Pitch = new QLineEdit(layoutWidget);
        Pitch->setObjectName(QStringLiteral("Pitch"));
        Pitch->setReadOnly(true);

        horizontalLayout_3->addWidget(Pitch);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 90, 201, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        UpDown = new QLineEdit(layoutWidget_2);
        UpDown->setObjectName(QStringLiteral("UpDown"));
        UpDown->setReadOnly(true);

        horizontalLayout_4->addWidget(UpDown);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 120, 201, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setBaseSize(QSize(0, 0));

        horizontalLayout_5->addWidget(label_5);

        Yaw = new QLineEdit(layoutWidget_3);
        Yaw->setObjectName(QStringLiteral("Yaw"));
        Yaw->setReadOnly(true);

        horizontalLayout_5->addWidget(Yaw);

        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 201, 24));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Roll = new QLineEdit(widget);
        Roll->setObjectName(QStringLiteral("Roll"));
        Roll->setReadOnly(true);

        horizontalLayout_2->addWidget(Roll);

        groupBox_2 = new QGroupBox(MainDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(250, 0, 231, 161));
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 40, 214, 80));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        Sensor1 = new QLineEdit(widget1);
        Sensor1->setObjectName(QStringLiteral("Sensor1"));

        gridLayout->addWidget(Sensor1, 0, 1, 1, 1);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        Sensor2 = new QLineEdit(widget1);
        Sensor2->setObjectName(QStringLiteral("Sensor2"));

        gridLayout->addWidget(Sensor2, 0, 3, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        Sensor3 = new QLineEdit(widget1);
        Sensor3->setObjectName(QStringLiteral("Sensor3"));

        gridLayout->addWidget(Sensor3, 1, 1, 1, 1);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        Sensor4 = new QLineEdit(widget1);
        Sensor4->setObjectName(QStringLiteral("Sensor4"));

        gridLayout->addWidget(Sensor4, 1, 3, 1, 1);

        label_10 = new QLabel(widget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        Sensor5 = new QLineEdit(widget1);
        Sensor5->setObjectName(QStringLiteral("Sensor5"));

        gridLayout->addWidget(Sensor5, 2, 1, 1, 1);

        label_11 = new QLabel(widget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        Sensor6 = new QLineEdit(widget1);
        Sensor6->setObjectName(QStringLiteral("Sensor6"));

        gridLayout->addWidget(Sensor6, 2, 3, 1, 1);

        Status = new QLabel(MainDialog);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setGeometry(QRect(20, 170, 471, 16));
        widget2 = new QWidget(MainDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(20, 200, 471, 24));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(MainDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), MainDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "MainDialog", 0));
        groupBox->setTitle(QApplication::translate("MainDialog", "MainAxis", 0));
        label_3->setText(QApplication::translate("MainDialog", "Pitch (YAxis)     ", 0));
        label_4->setText(QApplication::translate("MainDialog", "UpDown (ZAxis)", 0));
        label_5->setText(QApplication::translate("MainDialog", "Yaw (ZRotation)", 0));
        label_2->setText(QApplication::translate("MainDialog", "Roll (XAxis)       ", 0));
        groupBox_2->setTitle(QApplication::translate("MainDialog", "Force Sensor", 0));
        label_6->setText(QApplication::translate("MainDialog", "1", 0));
        label_7->setText(QApplication::translate("MainDialog", "2", 0));
        label_8->setText(QApplication::translate("MainDialog", "3", 0));
        label_9->setText(QApplication::translate("MainDialog", "4", 0));
        label_10->setText(QApplication::translate("MainDialog", "5", 0));
        label_11->setText(QApplication::translate("MainDialog", "6", 0));
        Status->setText(QApplication::translate("MainDialog", "Status", 0));
        pushButton->setText(QApplication::translate("MainDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
