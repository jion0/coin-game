#include "mycoin.h"
#include <QDebug>
#include <QLabel>
//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}
MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret=pix.load(btnImg);
    pix=pix.scaled(75,75);
    if(!ret)
    {
        qDebug()<<"图片加载错误";
        return;
    }

    //设置固定照片
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        //设置固定照片
        this->setFixedSize(75,75);
        //设置不规则
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(75,110));

        //判断是否翻完
        if(this->min>this->max)
        {
            this->min=1;
            timer1->stop();
        }
    });
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix1;
        QString str1 = QString(":/res/Coin000%1.png").arg(this->max--);
        pix1 .load(str1);
        //设置固定照片
        this->setFixedSize(75,75);
        //设置不规则
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix1);
        //设置图标大小
        this->setIconSize(QSize(75,110));

        //判断是否翻完
        if(this->min>this->max)
        {
            this->max=8;
            timer2->stop();
        }
    });

}
//反转
void MyCoin::changeFlag()
{
    if(this->flag)
    {
        timer1->start(30);
        this->flag=false;

    }
    else
    {
        timer2->start(30);
        this->flag=true;

    }

}
