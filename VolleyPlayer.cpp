#include "VolleyPlayer.h"

VolleyPlayer::VolleyPlayer() : name(""), height(0), weight(0), age(0) {}

VolleyPlayer::VolleyPlayer(const string& name, int height, double weight, int age):
	name(name), height(height), weight(weight), age(age) {}

void VolleyPlayer::draw(QPainter &painter, int startX, int startY, int cellWidth, int cellHeight, int& rowIndex) const{
    QStringList rowData;
    rowData << QString::fromLocal8Bit(name)
            << QString::number(height)
            << QString::number(weight)
            << QString::number(age);

    for (int i = 0; i < 6; ++i) {
        QRect cellRect(startX + i * cellWidth, startY + rowIndex * cellHeight, cellWidth, cellHeight);
        painter.drawRect(cellRect);
        if (i < 4) {
            painter.drawText(cellRect, Qt::AlignCenter, rowData[i]);
        }
    }
    rowIndex++;
}
