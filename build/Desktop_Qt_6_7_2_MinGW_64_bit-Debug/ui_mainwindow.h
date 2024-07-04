/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_ListOdd;
    QPushButton *pushButton_TableAdd;
    QPushButton *pushButton_TableOdd;
    QPushButton *pushButton_LoadImage;
    QLabel *imageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 180, 101, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(430, 180, 101, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(340, 320, 131, 85));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(300, 17, 191, 31));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 280, 301, 192));
        tableWidget->setColumnCount(3);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(480, 280, 291, 192));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 250, 161, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 250, 161, 20));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_ListOdd = new QPushButton(centralwidget);
        pushButton_ListOdd->setObjectName("pushButton_ListOdd");
        pushButton_ListOdd->setGeometry(QRect(660, 490, 83, 29));
        pushButton_TableAdd = new QPushButton(centralwidget);
        pushButton_TableAdd->setObjectName("pushButton_TableAdd");
        pushButton_TableAdd->setGeometry(QRect(60, 490, 83, 29));
        pushButton_TableOdd = new QPushButton(centralwidget);
        pushButton_TableOdd->setObjectName("pushButton_TableOdd");
        pushButton_TableOdd->setGeometry(QRect(200, 490, 83, 29));
        pushButton_LoadImage = new QPushButton(centralwidget);
        pushButton_LoadImage->setObjectName("pushButton_LoadImage");
        pushButton_LoadImage->setGeometry(QRect(342, 90, 101, 29));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(550, 20, 221, 211));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "std::sort", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Bubble sort", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\201\321\221 \321\202\321\203\321\202", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\235\320\270\321\207\320\265\320\263\320\276 \320\275\320\265\321\202", nullptr));

        tableWidget->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("MainWindow", "Surname", nullptr),
            QCoreApplication::translate("MainWindow", "Course", nullptr),
            QCoreApplication::translate("MainWindow", "Phone", nullptr)}));
        label->setText(QCoreApplication::translate("MainWindow", "Table Widget", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "List Widget", nullptr));
        pushButton_ListOdd->setText(QCoreApplication::translate("MainWindow", "odd List", nullptr));
        pushButton_TableAdd->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        pushButton_TableOdd->setText(QCoreApplication::translate("MainWindow", "odd Table", nullptr));
        pushButton_LoadImage->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
