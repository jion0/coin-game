#include "selectscene.h"
#include "ui_selectscene.h"
#include <QPainter>
#include "startbuttom.h"
#include <QLabel>
#include <QDebug>
#include "playscene.h"
SelectScene::SelectScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectScene)
{
    ui->setupUi(this);
    //设置固定大小
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("选择关卡");
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
        emit this->chooseSceneBack();

    });
    //返回按钮的实现


    //创建选择关卡的按钮
    for(int i=0;i<20;i++)
    {
        StartButtom *level=new StartButtom(":/res/LevelIcon.png");
        level->setParent(this);
        level->move(25 + i%4 * 70 , 130 + i/4 * 70);

        QLabel *label = new QLabel();
        label->setParent(level);
        label->setFixedSize(level->width(),level->height());
        label->setText(QString::number(i+1));
        //label->move(25 + i%4 * 70 , 130 + i/4 * 70);

        //设置水平垂直居中
        label->setAlignment(Qt::AlignCenter);

        //按下关卡后显示关卡场景
        connect(level,&StartButtom::clicked,[=](){
            qDebug()<<"你选择的是"<<i+1;
            PlayScene *play = new PlayScene();
            play->setGeometry(this->geometry());
            this->hide();
            play->denji(i+1);
            play->show();
            //按下游戏场景中的back返回到选择关卡场景

            connect(play,PlayScene::playSceneBack,this,[=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
            });



        });




    }
}

void SelectScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/jinbibeijin.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
//    pix.load(":/res/Title.png");
//    pix=pix.scaled(pix.width(),pix.height());
//    painter.drawPixmap(30,30,pix);
}

SelectScene::~SelectScene()
{
    delete ui;
}
