#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMenu>
#include <QString>
#include <QList>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Student {
public:
    QString surname;
    qint64 course;
    qint32 phone;

    Student(const QString &surname, qint64 course, qint32 phone)
        : surname(surname), course(course), phone(phone) {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void handleExit();
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_ListOdd_clicked();
    void on_pushButton_TableAdd_clicked();
    void on_pushButton_TableOdd_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_LoadImage_clicked();

private:
    Ui::MainWindow *ui;
    QList<Student> students;

    void addStudent(const Student &student);
    void removeStudent(int index);
    void syncWidgets();
    void sortStandard();
    void sortBubble();
};

#endif // MAINWINDOW_H
