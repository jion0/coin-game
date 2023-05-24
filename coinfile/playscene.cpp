#include "playscene.h"
#include "ui_playscene.h"
#include <QPainter>
#include "startbuttom.h"
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QDebug>
#include "win.h"
PlayScene::PlayScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayScene)
{
    ui->setupUi(this);
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("游戏中");
    //退出按钮实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });

    //返回按钮
    StartButtom *backbtn=new StartButtom(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());

    connect(backbtn,&StartButtom::clicked,[=](){
        //发送信号
        emit this->playSceneBack();
    });
    //创建背景图片
//    for(int i=0;i<4;i++)
//    {
//        for(int j=0;j<4;j++)
//        {
//            QLabel *label=new QLabel;
//            label->setGeometry(0,0,75,75);
//            label->setPixmap(QPixmap(":/res/BoardNode.png"));
//            label->setParent(this);
//            label->move(10+i * 75,150+j*75);
//            //创建金币
//            MyCoin *coin=new MyCoin(":/res/chuba.png");
//            coin->setParent(this);
//            coin->move(10+i*75,150+j*75);
//        }

//    }
}

void PlayScene::denji(int num)
{
    this->levelnum=num;
    QLabel *label=new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1=QString("Level:%1").arg(this->levelnum);
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30,this->height()-50,120,50);
    dataConfig data;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=data.mData[this->levelnum][i][j];
        }
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QLabel *label=new QLabel;
            label->setGeometry(0,0,75,75);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(10+i * 75,140+j*75);
            //创建金币
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str=":/res/Coin0001.png";
            }
            else
            {
                str=":/res/Coin0008.png";
            }
            MyCoin *coin=new MyCoin(str);
            coin->setParent(this);
            coin->move(10+i*75,150+j*75);


            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];
            //二维数组存各个按钮
            coinBtn[i][j]=coin;
            //点击金币翻转
            connect(coin,&MyCoin::clicked,[=](){
                coin->changeFlag();
                if(i+1<=3)
                {
                    coinBtn[i+1][j]->changeFlag();
                }
                if(i-1>=0)
                {
                    coinBtn[i-1][j]->changeFlag();
                }
                if(j+1<=3)
                {
                    coinBtn[i][j+1]->changeFlag();
                }
                if(j-1>=0)
                {
                    coinBtn[i][j-1]->changeFlag();
                }

                this->isWin = true;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        if(coinBtn[i][j]->flag == false)
                        {
                            this->isWin = false;
                            break;
                        }
                    }
                }
                if(this->isWin)
                {
                    win w;
                    //w.show();
                    w.exec();
                }


            });
        }

    }

}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width() * 0.5,pix.height() * 0.5);
    painter.drawPixmap(10,30,pix);
}

PlayScene::~PlayScene()
{
    delete ui;
}
