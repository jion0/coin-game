#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QMainWindow>
#include "selectscene.h"

namespace Ui {
class MainSence;
}

class MainSence : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSence(QWidget *parent = 0);
    ~MainSence();
    //背景图
    void paintEvent(QPaintEvent *event);
    SelectScene *select=NULL;


private:
    Ui::MainSence *ui;
};

#endif // MAINSENCE_H
