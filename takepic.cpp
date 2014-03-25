#include "takepic.h"
#include <QDebug>
#include <QQmlContext>
#include <QProcess>
#include <QObject>
#include <QTimer>
#include <qzxing.h>
#include <QThread>
#include <QtGui/QGuiApplication>
#include <QFile>

takePic::takePic(QObject *parent) :
    QObject(parent)
{
}

void takePic::takePicture() {

    //qDebug("Thread id inside run %d",(int)QThread::currentThreadId());

       QFile file("/sys/class/gpio/gpio17/value");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
       QTextStream in(&file);
       QString irSensorState=in.readLine();

       qDebug() << "Estado do IR Sensor: " + irSensorState;

       if(irSensorState == "1"){
       cplusplus_qrimg = "/opt/QRCode/qml/QRCode/resources/qrfree.kaywa.com.jpg";

        QImage *QRCode = new QImage;
        QRCode->load(cplusplus_qrimg);

        QZXing *QRprocessor = new QZXing;
        cplusplus_qrcode = QRprocessor->decodeImage(*QRCode);

       }

       else{

           qDebug() << "Estado do IR Sensor: " + irSensorState;

           cplusplus_qrimg = "/tmp/moved.jpeg";

           QString pictureCommand = "streamer -c /dev/video0 -b 16 -r 640x480  -o /tmp/moved.jpeg";

           QProcess *picNewProc = new QProcess;
           picNewProc->start(pictureCommand);

           QImage *QRCode = new QImage;
           QRCode->load(cplusplus_qrimg);

           //QRCode->load("/tmp/qrcode.17529617.png");

           QZXing *QRprocessor = new QZXing;
           cplusplus_qrcode = QRprocessor->decodeImage(*QRCode);

           qDebug() << "QR: " + cplusplus_qrcode;
          }

        //if (!picNewProc->waitForFinished())
         //   qDebug() << "snapshot failed:" << picNewProc->errorString();

        //else{
            //qDebug() << "snapshot succeeded: " + QRreturn;

            if(cplusplus_qrcode != ""){
                //qDebug() << "C++ : " + cplusplus_qrcode;
                emit qRCodeUpdated(cplusplus_qrcode);
                emit qRImgUpdated(cplusplus_qrimg);

            }
    }

//leitura do valor do QRCode
QString takePic::getQRCode()
{
    //devolve o valor actual do contador
    return cplusplus_qrcode;
    emit finished();
}

QString takePic::getQRImg()
{

    return cplusplus_qrimg;
    emit finished();
}

void takePic::errorString(QString){
    qDebug() << "Foi-se";
}

