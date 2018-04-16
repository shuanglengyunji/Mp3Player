#include <QCoreApplication>
#include <QDebug>
#include <QMediaPlayer>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*1.获取绝对路径absDir*/
    QString runPath = QCoreApplication::applicationDirPath();   //获取当前exe所在路径
    QString absDir = runPath + "/1.mp3";

    qDebug() << "Path:" << absDir;      //显示文件目录

    /*2.创建QMediaPlayer对象指针，通过指针设置文件路径、音量、播放*/
    QMediaPlayer *musicPlayer = new QMediaPlayer();
    musicPlayer->setMedia(QUrl::fromLocalFile(absDir));
    musicPlayer->setVolume(80);
    musicPlayer->play();

    return a.exec();
}
