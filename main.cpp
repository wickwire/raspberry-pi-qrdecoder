#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QQmlContext>
#include <QtQuick>
#include <qzxing.h>
#include <takepic.h>
#include <QTimer>
#include <QObject>
#include <QThread>
#include <tcpserver.h>
#include <QTcpServer>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    QZXing decoder;

    QThread* thread = new QThread;
    takePic* snapp = new takePic();

    //modelo que move para a thread, mas depois perde o resultado
    snapp->moveToThread(thread);

    QObject::connect(thread, SIGNAL(started()), snapp, SLOT(doStuff()),Qt::QueuedConnection);


    //qDebug() << QGuiApplication::instance()->thread();
    thread->start();

    qmlRegisterType<QZXing>("QZXing", 1, 2, "QZXing");

    viewer.rootContext()->setContextProperty("decoder", &decoder);


    viewer.setMainQmlFile(QStringLiteral("qml/QRCode/main.qml"));
    viewer.showExpanded();

    QObject *rootObject = qobject_cast<QObject *>(viewer.rootObject());

    // find element by name
    QObject *textBox = rootObject->findChild<QObject *>(QString("TextBox"));
    QObject::connect(snapp, SIGNAL(qRCodeUpdated(QVariant)), textBox, SLOT(updateTextBox(QVariant)));


    QObject *qrFrame = rootObject->findChild<QObject *>(QString("QRFrame"));
    QObject::connect(snapp, SIGNAL(qRImgUpdated(QVariant)), qrFrame, SLOT(updateQRFrame(QVariant)));


    tcpServer server;


    return app.exec();
}
