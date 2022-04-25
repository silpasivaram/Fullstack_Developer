#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define OFFSET 100;
#include <QTcpSocket>
#include <QMainWindow>
#include "tictactoeserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int  NoOfRows=4;
const int  NoOfCols=4;
class TicTacToeServer;
class Cell
{
public:
    QRect           m_CellRect;
    QString         m_strText;

    Cell()
    {

        m_strText="i";

    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    TicTacToeServer * m_pServer;
    QTcpSocket *m_pClientSocket;
public:
    bool     m_gameturn;
    int X,Y;
    Cell            m_CellArray[NoOfRows][NoOfCols];
    QString         m_Message;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DisplayStatusMessage(QString Message);
    void CheckWinnings();
    void cleargame();
    void DisplayRemotePCMessage(QString Message);
    void SendMovesToRemotePC(QString Message);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* ev);
    void Initialize();
    QString CreateMessage();

public slots:
    void onExitMenuClicked();
    void displayError(QAbstractSocket::SocketError socketError);
    void OnNewGameClicked();
private slots:
    void on_btn_server_start_clicked();

    void on_pushButton_connect_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
