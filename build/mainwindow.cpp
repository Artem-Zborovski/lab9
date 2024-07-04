#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_ListAdd, &QPushButton::clicked, this, &MainWindow::on_pushButton_ListAdd_clicked);
    connect(ui->pushButton_ListOdd, &QPushButton::clicked, this, &MainWindow::on_pushButton_ListOdd_clicked);
    connect(ui->pushButton_TableAdd, &QPushButton::clicked, this, &MainWindow::on_pushButton_TableAdd_clicked);
    connect(ui->pushButton_TableOdd, &QPushButton::clicked, this, &MainWindow::on_pushButton_TableOdd_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QMenu contextMenu;
        QAction *exitAction = contextMenu.addAction("exit");
        connect(exitAction, &QAction::triggered, this, &MainWindow::handleExit);
        contextMenu.exec(event->globalPos());
    }
}

void MainWindow::handleExit() {
    close(); // Closes the main window
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        close(); // Close the application
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) {
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->textEdit->show();
    } else if (index == 1) {
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->textEdit->hide();
    }
}

void MainWindow::on_pushButton_ListAdd_clicked() {
    QString surname = ui->textEdit->toPlainText();
    qint64 course = 1;  // Example value, replace with actual input
    qint32 phone = 123456;  // Example value, replace with actual input

    Student student(surname, course, phone);
    addStudent(student);
}

void MainWindow::on_pushButton_ListOdd_clicked() {
    int listRow = ui->listWidget->currentRow();
    if (listRow >= 0) {
        removeStudent(listRow);
    }
}

void MainWindow::on_pushButton_TableAdd_clicked() {
    QString surname = ui->textEdit->toPlainText();
    qint64 course = 1;  // Example value, replace with actual input
    qint32 phone = 123456;  // Example value, replace with actual input

    Student student(surname, course, phone);
    addStudent(student);
}

void MainWindow::on_pushButton_TableOdd_clicked() {
    int tableRow = ui->tableWidget->currentRow();
    if (tableRow >= 0) {
        removeStudent(tableRow);
    }
}

void MainWindow::addStudent(const Student &student) {
    students.append(student);
    syncWidgets();
}

void MainWindow::removeStudent(int index) {
    if (index >= 0 && index < students.size()) {
        students.removeAt(index);
        syncWidgets();
    }
}

void MainWindow::syncWidgets() {
    // Clear both widgets
    ui->listWidget->clear();
    ui->tableWidget->setRowCount(0);

    // Populate both widgets with updated student list
    for (const Student &student : qAsConst(students)) {
        ui->listWidget->addItem(student.surname);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(student.surname));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(student.course)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(student.phone)));
    }
}
