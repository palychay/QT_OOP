#include "pavwidget.h"
#include <QPainter>

PavWidget::PavWidget(QWidget *parent)
    : QWidget{parent}
{}

QSize PavWidget::minimumSizeHint() const{
    return team.calculTableSize();
}

void PavWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (team.IsEmpty())
        return;
    team.draw(painter);
}

void PavWidget::load(const QString path){
    team.clearPlayers();
    team.readFromFile(path.toStdString());
    resize(minimumSizeHint());
    update();
}

void PavWidget::save(const QString path){
    team.writeToFile(path.toStdString());
}
