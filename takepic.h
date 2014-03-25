#ifndef TAKEPIC_H
#define TAKEPIC_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QVariant>

class takePic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString qmlQRcode READ getQRCode NOTIFY qRCodeUpdated)
    Q_PROPERTY(QString qmlQRimg READ getQRImg NOTIFY qRImgUpdated)

public:
    explicit takePic(QObject *parent = 0);
    QString cplusplus_qrcode;
    QString getQRCode();
    QString cplusplus_qrimg;
    QString getQRImg();

public slots:
    void takePicture();
    void errorString(QString);

    void doStuff(){


        //definicao de um timer associado ao contador "count"
        QTimer *timer = new QTimer(this);

        //definicao do fluxo de actividade: mediante signal de fim do timer, o metodo counting do contador e activado

        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(takePicture()));
        //o timer e iniciado, com intervalo recorrente de 1 segundo
        //quando o timer termina, o contador itera e o timer corre de novo

        timer->start(1000);
    }

signals:
    void finished();
    void error(QString err);
    QVariant qRCodeUpdated(QVariant signal_qrcode);
    QVariant qRImgUpdated(QVariant signal_qrimg);
};

#endif // TAKEPIC_H
