#include <QCoreApplication>
#include <QDebug>
#include <QMediaPlayer>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*1.获取绝对路径absDir*/
    QString runPath = QCoreApplication::applicationDirPath();   //获取当前exe所在路径
    QString absDir = runPath;

    //检测命令行参数
    QStringList arguments = QCoreApplication::arguments();
    qDebug() << "The whole Arguments: " << arguments << endl;

    if(arguments.count() < 2)   //这个参数至少也是1，程序会自动传入一个参数，内容是程序所在目录地址
    {
        absDir = absDir + "/music/1.mp3";      //没有传入参数，使用默认参数
    }
    else
    {
        absDir = absDir + "/music/" + arguments.at(1);    //使用传入音乐名称作为参数
    }

    qDebug() << "Path:" << absDir << endl;      //显示文件目录

    /*2.创建QMediaPlayer对象指针，通过指针设置文件路径、音量、播放*/
    QMediaPlayer *musicPlayer = new QMediaPlayer();
    musicPlayer->setMedia(QUrl::fromLocalFile(absDir));
    musicPlayer->setVolume(80);
    musicPlayer->play();

    return a.exec();
}

//    absDir.replace(QString("/"), QString("\\"));/*替换为windown的目录格式*/
