#include "Attacker.h"

void Attacker::draw(QPainter &painter, int startX, int startY, int cellWidth, int cellHeight, int& rowIndex) const{
    QStringList rowData;
    rowData << QString::fromLocal8Bit(name)
            << QString::number(height)
            << QString::number(weight)
            << QString::number(age)
            << QString::number(power)
            << QString::number(jump);

    for (int i = 0; i < 6; ++i) {
        QRect cellRect(startX + i * cellWidth, startY + rowIndex * cellHeight, cellWidth, cellHeight);
        painter.drawRect(cellRect);
        painter.drawText(cellRect, Qt::AlignCenter, rowData[i]);
    }
    rowIndex++;
}
