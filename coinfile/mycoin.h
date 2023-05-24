#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString btnImg);



    //金币的属性
    int posX;
    int posY;
    bool flag;
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    int min=1;
    int max=8;
    //是否胜利

signals:

public slots:
};

#endif // MYCOIN_H
