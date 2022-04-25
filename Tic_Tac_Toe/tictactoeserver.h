#ifndef TICTACTOESERVER_H
#define TICTACTOESERVER_H

#include <QTcpServer>
#include <QObject>

class MainWindow;
class TicTacToeServer : public QTcpServer
{
    Q_OBJECT
public:
    TicTacToeServer(MainWindow* pHelloServer,QObject *parent=0);
   MainWindow* m_pMainWindow;

   TicTacToeServer * m_pServer;
    void StopServer();
private:
           QSet<QTcpSocket*> clients;

private slots:
    void readyRead();
    void disconnected();

protected:
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;
};

#endif // TICTACTOESERVER_H
