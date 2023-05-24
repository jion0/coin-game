#include "mainsence.h"
#include "ui_mainsence.h"
#include <QPainter>
#include "startbuttom.h"
#include <QDebug>
#include <QTimer>

MainSence::MainSence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSence)
{
    ui->setupUi(this);
    //设置固定大小
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("翻初八");
    //退出按钮实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });

    StartButtom *start=new StartButtom(":/res/MenuSceneStartButton.png");
    start->setParent(this);
    start->move(this->width()*0.5-start->width()*0.5,this->height()*0.7);

    select=new SelectScene;
    //0.00.0.000.0.0.00乱了
    connect(select,SelectScene::chooseSceneBack,this,[=](){
        this->setGeometry(select->geometry());
        select->hide();
        this->show();
    });
    connect(start,&StartButtom::clicked,[=](){
        start->zoom1();
        start->zoom2();        //开始按钮弹跳动画实现
        //点击开始按钮后延迟出现选择关卡场景

        QTimer::singleShot(500,this,[=](){
            select->setGeometry(this->geometry());
            this->hide();
            select->show();

        });

    });




}



void MainSence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/Coin0001.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //设置图标
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}


MainSence::~MainSence()
{
    delete ui;
}
