#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);       //窗口总在最前+取消关闭按钮
    setWindowFlags(windowFlags() | Qt::CustomizeWindowHint);        //允许自定义标题栏
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint    //取消最大、最小、关闭按钮
                                 & ~Qt::WindowMaximizeButtonHint
                                 & ~Qt::WindowCloseButtonHint
                  );

    ////////////////////////////////////////////////////////////////////////////////////
    //运行程序时自动开始播放音乐

    /*1.获取音乐目录absDir*/
    runPath = QCoreApplication::applicationDirPath();   //获取当前exe所在路径
    absDir = runPath;

    //检测命令行参数
    QStringList arguments = QCoreApplication::arguments();
    qDebug() << "The whole Arguments: " << arguments << endl;

    //生成文件目录
    if(arguments.count() < 2)   //这个参数至少也是1，程序会自动传入一个参数，内容是程序所在目录地址
    {
        absDir = absDir + "/musics/1.mp3";      //没有传入参数，使用默认参数
    }
    else
    {
        absDir = absDir + "/musics/" + arguments.at(1);    //使用传入音乐名称作为参数
    }

    qDebug() << "Path:" << absDir << endl;      //显示文件目录

    ui->Text->setText(absDir);

    /*2.创建QMediaPlayer对象指针，通过指针设置文件路径、音量、播放*/
    musicPlayer.setMedia(QUrl::fromLocalFile(absDir));
    musicPlayer.setVolume(80);
    musicPlayer.play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << musicPlayer.state();

    int tmp_state = musicPlayer.state();
    if(tmp_state != 0)
        musicPlayer.stop();

    //关闭程序
    this->close();
}
