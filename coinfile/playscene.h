#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScene(QWidget *parent = 0);
    void denji(int num);
    void paintEvent(QPaintEvent *event);
    MyCoin *coinBtn[4][4];
    ~PlayScene();

    int levelnum;
    int gameArray[4][4];  //维护每一关
    bool isWin;
signals:
    void playSceneBack();

private:
    Ui::PlayScene *ui;
};

#endif // PLAYSCENE_H
