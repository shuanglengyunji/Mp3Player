#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMediaPlayer>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    //私有变量
    QString runPath;        //程序运行目录
    QString absDir;         //音乐所在目录
    QStringList arguments;  //命令行输入参数

    QMediaPlayer musicPlayer;    //音乐播放器对象
};

#endif // MAINWINDOW_H
