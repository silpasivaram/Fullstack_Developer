#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QtGui>
#include <QPalette>
#include<QDebug>
#include<QMessageBox>


    const int  m_width=100;
    const int  m_Height=100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Initialize();
    m_pClientSocket=new QTcpSocket(this);

        m_gameturn=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *pEvent)
{
   const int  m_width=100;
   const int  m_Height=100;

    X=75;
    Y=100;

QWidget::paintEvent(pEvent);
QPainter obj(this);
obj.setRenderHint(QPainter::Antialiasing);
obj.setPen(QPen(Qt::blue, 3));

obj.setFont(QFont("X",22));
for (int j = 0; j <NoOfCols;j++)
          {
                obj.drawLine(X, Y,X,Y+300);
               X =X +OFFSET;

          }
   X=75;
   Y=100;
for (int i = 0; i <NoOfRows; i++)
          {
                obj.drawLine(X, Y,X+300,Y);
                Y = Y +OFFSET;

          }

for (int i = 0; i< NoOfRows-1;i++)
{
   for (int j = 0; j< NoOfCols-1; j++)
{


        if(m_CellArray[i][j].m_strText!="i")
                    {

                        obj.drawText(m_CellArray[i][j].m_CellRect.left()-11-m_Height/2,
                                     m_CellArray[i][j].m_CellRect.top()+11-m_width/2,
                                               m_CellArray[i][j].m_strText);
                    }


}
}

}

void MainWindow ::Initialize()
{

    X=75,Y=100;

     //Initialize the Rectangle

    for (int i = 0; i<NoOfRows-1; i++)
    {
        for (int j = 0; j<NoOfCols-1; j++)
        {
             m_CellArray[i][j].m_CellRect.setSize(QSize(m_width, m_Height));
             m_CellArray[i][j].m_CellRect.setTopLeft(QPoint(X + (m_width*(j+1)), Y + (m_Height*(i+1))));

        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QWidget::mousePressEvent(event);


        if (event->button() == Qt::LeftButton)
            for(int i=0;i<NoOfRows-1;i++)
                  {
                      for(int j=0;j<NoOfCols-1;j++)
                      {
                          QRect widgetRect = m_CellArray[i][j].m_CellRect;
                                          widgetRect.moveTopLeft(this->parentWidget()->mapToGlobal(widgetRect.topLeft()));
                                          QPoint CurretPoint=event->pos();
                                          if(widgetRect.contains(CurretPoint))
                                          {
                                              if(m_gameturn)
                                              {
                                                  if(m_CellArray[i][j].m_strText=="i")
                                                  {

                                              m_CellArray[i][j].m_strText="X";

                                              QString Message=CreateMessage();
                                                                DisplayStatusMessage(Message);

                                                                this->repaint();
                                                                    CheckWinnings();
                                                                SendMovesToRemotePC(Message);
                                                                m_gameturn=false;
                                                               // CheckWinnings();



                                                  }
                                                  else
                                                  {
                                                      QMessageBox::information(this, tr("Tic-Tac-Toe"),
                                                                               tr("this cell is occupied ,please try again"));
                                                  }
                                                }
                                              else
                                              {
                                                  QMessageBox::information(this, tr("Tic-Tac-Toe"),
                                                                           tr("This is not your turn"));
                                              }

                                              return;


                                          }
                      }
            }

}

void MainWindow::onExitMenuClicked()
{
    this->close();
}

void MainWindow::OnNewGameClicked()
{
 m_gameturn=true;
    for (int i = 0; i< NoOfRows-1;i++)
    {
       for (int j = 0; j< NoOfCols-1; j++)
        {



                           m_CellArray[i][j].m_strText="i";

        }
    }
     this->repaint();

}
QString MainWindow ::CreateMessage()
{
    m_Message="";
    for(int i=0;i<NoOfRows-1;i++)
    {
        for(int j=0;j<NoOfCols-1;j++)
        {
            m_Message+=m_CellArray[i][j].m_strText;
        }
    }
    return m_Message;
}




void MainWindow::on_btn_server_start_clicked()
{


    if(ui->btn_server_start->text()=="Start")
      {
          m_pServer= new TicTacToeServer(this);
          bool success = m_pServer->listen(QHostAddress::Any, quint16(ui->lEportno->text().toUShort()));
          if(!success)
          {
              DisplayStatusMessage("Server failed...");
          }
          else
          {
              DisplayStatusMessage("Server Started...");
              this->setWindowTitle(this->windowTitle()+"  Port  "+ui->lEportno->text());
              ui->btn_server_start->setText("Stop");
          }

      }
      else
      {
          m_pServer->close();
          DisplayStatusMessage("Server Stopped...");
          ui->btn_server_start->setText("Start");
      }
}
    void MainWindow::DisplayStatusMessage(QString Message)
    {
        ui->label_Result->setText(Message);
    }




void MainWindow::on_pushButton_connect_clicked()
{
    try
        {
            if(ui->pushButton_connect ->text()=="Connect")
            {
                m_pClientSocket->connectToHost(ui->LeRemoteIP->text(),quint16(ui->LeRemotePort->text().toInt()) );
                    connect(m_pClientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

                ui->pushButton_connect->setText("Disconnect");
                //QMessageBox::information(this, tr(" Tic-Tac-Toe"),  tr("Connected"));
                DisplayStatusMessage("Connected to Host =>" + ui->LeRemoteIP->text() + "Port =>" + ui->LeRemotePort->text());
            }
            else
            {
                m_pClientSocket->disconnectFromHost();
                m_pClientSocket->close();
                ui->pushButton_connect->setText("Connect");
               // QMessageBox::information(this, tr(" Tic-Tac-Toe"), tr("Disconnected"));

                DisplayStatusMessage("Disconnected from Host =>" + ui->LeRemoteIP->text());
            }
        }
        catch(QException* ex)
        {
            DisplayStatusMessage(QString("Error in Connection=>") + QString(ex->what()));
        }
}
void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
            case QAbstractSocket::RemoteHostClosedError:
                break;
            case QAbstractSocket::HostNotFoundError:
                QMessageBox::information(this, tr("Fortune Client"),
                                         tr("The host was not found. Please check the "
                                            "host name and port settings."));
                break;
            case QAbstractSocket::ConnectionRefusedError:
                QMessageBox::information(this, tr("Fortune Client"),
                                         tr("The connection was refused by the peer. "
                                            "Make sure the fortune server is running, "
                                            "and check that the host name and port "
                                            "settings are correct."));
                break;
            default:
                QMessageBox::information(this, tr("Fortune Client"),
                                         tr("The following error occurred: %1.")
                                         .arg(m_pClientSocket->errorString()));
            }

}
void MainWindow::CheckWinnings()
{

    for(int i=0;i<NoOfRows-1;i++)
    {
        if(( m_CellArray[i][0].m_strText== m_CellArray[i][1].m_strText)&&
                (m_CellArray[i][1].m_strText== m_CellArray[i][2].m_strText)&&(m_CellArray[i][0].m_strText==m_CellArray[i][2].m_strText))
        {
            if(( m_CellArray[i][0].m_strText== "X")&&( m_CellArray[i][1].m_strText!="i"))
            {
                QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("You are the winner"));
                cleargame();
                return;
            }

            else if(( m_CellArray[i][0].m_strText=="O")&&( m_CellArray[i][1].m_strText!="i"))
            {
                QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("Your Opponent is the winner"));
                cleargame();
                return;
            }
        }
    }
    for(int j=0;j<NoOfCols-1;j++)
    {
        if(( m_CellArray[0][j].m_strText== m_CellArray[1][j].m_strText)&&
                (m_CellArray[1][j].m_strText== m_CellArray[2][j].m_strText)&&(m_CellArray[0][j].m_strText==m_CellArray[2][j].m_strText))
        {
            if(( m_CellArray[0][j].m_strText== "X")&&( m_CellArray[0][j].m_strText!="i"))
            {
                QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("You are the winner"));
                cleargame();
                return;
            }

            else if(( m_CellArray[0][j].m_strText=="O")&&( m_CellArray[1][j].m_strText!="i"))
            {
                QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("Your Opponent is the winner"));
                cleargame();
                return;
            }
        }
    }
     if(( m_CellArray[0][0].m_strText== m_CellArray[1][1].m_strText) &&
                (m_CellArray[1][1].m_strText== m_CellArray[2][2].m_strText) &&
             (m_CellArray[0][0].m_strText==m_CellArray[2][2].m_strText))
        {
            if(( m_CellArray[0][0].m_strText== "X")&&( m_CellArray[1][1].m_strText!="i"))
            {
                QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("You are the winner"));
                cleargame();
                return;

            }

            else if(( m_CellArray[0][0].m_strText=="O")&&( m_CellArray[1][1].m_strText!="i"))
            {
                QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("Your Opponent is the winner"));
                cleargame();
            return;
            }
        }
     else
     {
         int count=0;
         for(int i=0;i<NoOfRows-1;i++)
         {

             for(int j=0;j<NoOfCols-1;j++)
             {
                 if(m_CellArray[i][j].m_strText!='i')
                 {
                        count=count+1;

                 }
             }
         }
         if(count==9)
         {
             QMessageBox::information(this, tr("Tic-Tac-Toe"),tr("Tie in Game"));
             cleargame();

             return;
         }
     }



}

void MainWindow::cleargame()
{
    m_gameturn=true;

       for (int i = 0; i< NoOfRows-1;i++)
       {
          for (int j = 0; j< NoOfCols-1; j++)
           {



                              m_CellArray[i][j].m_strText="i";

           }
       }

        this->repaint();

}



void MainWindow::DisplayRemotePCMessage(QString Message)
{

    int index=0;
    for(int i=0;i<NoOfRows-1;i++)
    {
        for(int j=0;j<NoOfCols-1;j++)
        {
            if(m_CellArray[i][j].m_strText=="i")
                 if(Message[index]=="X")
                        m_CellArray[i][j].m_strText="O";

            index=index+1;
        }
    }


   if(Message.length()>=NoOfRows-1*NoOfCols-1)
    {
       QString msg=CreateMessage();
        DisplayStatusMessage(msg);
    }
    else
    {
        DisplayStatusMessage("Message Length Small");
        return;
    }
    m_gameturn=true;

   this->repaint();
   CheckWinnings();
}

void MainWindow::SendMovesToRemotePC(QString Message)
{

    m_pClientSocket->write(QString(Message + "\n").toUtf8());
}
