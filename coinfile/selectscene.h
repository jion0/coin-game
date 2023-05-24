#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QMainWindow>

namespace Ui {
class SelectScene;
}

class SelectScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectScene(QWidget *parent = 0);
    ~SelectScene();
    void paintEvent(QPaintEvent *event);


signals:
    void chooseSceneBack();


private:
    Ui::SelectScene *ui;
};

#endif // SELECTSCENE_H
