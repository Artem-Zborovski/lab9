#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QVBoxLayout *mainLayout = new QVBoxLayout(ui->centralwidget);
    QHBoxLayout *buttonLayout1 = new QHBoxLayout();
    QHBoxLayout *buttonLayout2 = new QHBoxLayout();
    QHBoxLayout *tableListLayout = new QHBoxLayout();

    mainLayout->addWidget(ui->comboBox);
    buttonLayout1->addWidget(ui->pushButton_TableOdd);
    buttonLayout1->addWidget(ui->pushButton_TableAdd);
    buttonLayout1->addWidget(ui->pushButton_ListOdd);
    mainLayout->addLayout(buttonLayout1);

    buttonLayout2->addWidget(ui->pushButton);
    buttonLayout2->addWidget(ui->pushButton_2);
    buttonLayout2->addWidget(ui->pushButton_LoadImage);
    mainLayout->addLayout(buttonLayout2);

    mainLayout->addWidget(ui->textEdit);

    tableListLayout->addWidget(ui->tableWidget);
    tableListLayout->addWidget(ui->listWidget);
    mainLayout->addLayout(tableListLayout);

    mainLayout->addWidget(ui->imageLabel);

    setLayout(mainLayout);
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
    close();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        close();
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


void MainWindow::on_pushButton_ListOdd_clicked() {
    int listRow = ui->listWidget->currentRow();
    if (listRow >= 0) {
        removeStudent(listRow);
    }
}

void MainWindow::on_pushButton_TableAdd_clicked() {
    QString surname = ui->textEdit->toPlainText();
    qint64 course = 1;
    qint32 phone = +375;

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
    ui->listWidget->clear();
    ui->tableWidget->setRowCount(0);


    for (const Student &student : qAsConst(students)) {
        ui->listWidget->addItem(student.surname);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(student.surname));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(student.course)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(student.phone)));
    }
}

void MainWindow::on_pushButton_clicked() {
    sortStandard();
}

void MainWindow::on_pushButton_2_clicked() {
    sortBubble();
}

void MainWindow::sortStandard() {

    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.surname < b.surname;
    });
    syncWidgets();
}

void MainWindow::sortBubble() {

    bool swapped;
    int n = students.size();
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (students[i-1].surname > students[i].surname) {
                std::swap(students[i-1], students[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
    syncWidgets();
}

void MainWindow::on_pushButton_LoadImage_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image File", "", "Images (*.png *.xpm *.jpg)");
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, "Image Viewer", "Cannot load " + fileName);
            return;
        }

        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(100,100), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->imageLabel->setPixmap(pixmap);
    }
}
