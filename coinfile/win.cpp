#include "win.h"
#include "ui_win.h"

win::win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/res/Coin0001.png"));
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(15);
    ui->label->setFont(font);
}

win::~win()
{
    delete ui;
}
