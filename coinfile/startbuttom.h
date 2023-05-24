#ifndef STARTBUTTOM_H
#define STARTBUTTOM_H

#include <QWidget>
#include <QPushButton>

class StartButtom : public QPushButton
{
    Q_OBJECT
public:
    //explicit StartButtom(QWidget *parent = nullptr);
    StartButtom(QString normalImg,QString pressImg = "");
    void zoom1();
    void zoom2();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


    QString normalImgPath;
    QString pressImgPath;

signals:

public slots:
};

#endif // STARTBUTTOM_H
