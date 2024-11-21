#include "Team.h"
#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/export.hpp>
#include <algorithm>
#include <functional>
#include <iostream>

BOOST_CLASS_EXPORT(Attacker)
BOOST_CLASS_EXPORT(VolleyPlayer)


void Team::readFromFile(const string& filename) {
    ifstream inFile(filename);
    boost::archive::text_iarchive ia(inFile);
    ia >> team;
}

void Team::writeToFile(const string& filename) const {
    ofstream outFile(filename);
    boost::archive::text_oarchive oa(outFile);
    oa << team;
}

bool Team::IsEmpty() const {
    return team.empty();
}

void Team::clearPlayers() {
    team.clear();
}

QSize Team::calculTableSize() const{
    int widthTable = 6 * 150 + 2 * 30;
    int heightTable = (team.size() + 1) * 30 + 2 * 20;
    return QSize(widthTable, heightTable);
}

void Team::drawCell(QPainter &painter, int x, int y, int width, int height, const QString &text) {
    QRect cellRect(x, y, width, height);
    painter.drawRect(cellRect);
    painter.drawText(cellRect, Qt::AlignCenter, text);
}

void Team::draw(QPainter &painter) {
    int startX = 30;       // Начальная позиция по оси X
    int startY = 20;       // Начальная позиция по оси Y
    int cellWidth = 150;   // Ширина ячейки
    int cellHeight = 30;   // Высота ячейки

    // Заголовки столбцов
    QStringList headers = {"Name", "Height", "Weight", "Age", "Power", "Jump"};

    // Отрисовка заголовков с использованием for_each и bind
    int headerY = startY;
    for(int colIndex = 0; colIndex < 6; ++colIndex) {
        int x = startX + colIndex * cellWidth;
        drawCell(painter, x, headerY, cellWidth, cellHeight, headers[colIndex]);
    }

    // Рисуем строки данных с использованием for_each и bind
    int rowIndex = 1; // Начинаем с 1, так как первая строка — это заголовки
    // Используем for_each для перебора элементов класса Team
    std::for_each(team.begin(), team.end(),
                  std::bind(&VolleyPlayer::draw,
                            std::placeholders::_1,  // Это будет объект типа VolleyPlayer* или Attacker*
                            std::ref(painter),
                            startX, startY, cellWidth, cellHeight, std::ref(rowIndex)));
}

Team::~Team() {
    clearPlayers();
}
