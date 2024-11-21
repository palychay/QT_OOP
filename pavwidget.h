#ifndef PAVWIDGET_H
#define PAVWIDGET_H

#include <QWidget>
#include "Team.h"

class PavWidget : public QWidget
{
    Q_OBJECT
    Team team;
public:
    explicit PavWidget(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    void paintEvent(QPaintEvent *event) override;
    void load(const QString path);
    void save(const QString path);
signals:

};

#endif // PAVWIDGET_H
