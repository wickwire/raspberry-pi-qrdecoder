#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QNetworkSession>

class tcpServer : public QObject
{
    Q_OBJECT
public:
    explicit tcpServer(QObject *parent = 0);

private slots:
    void sessionOpened();
    void sendFortune();
    
signals:
    
public slots:

private:
//    QLabel *statusLabel;
//    QPushButton *quitButton;
    QTcpServer *tcpserver;
    QList<QString> fortunes;
    QNetworkSession *networkSession;
    
};

#endif // TCPSERVER_H
