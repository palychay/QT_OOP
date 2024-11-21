#pragma once

#include <vector>
#include "VolleyPlayer.h"
#include "Attacker.h"
#include <boost/serialization/vector.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <QPainter>

using namespace std;

class Team
{
    vector<shared_ptr<VolleyPlayer>> team;

public:

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& team;
    }
    void readFromFile(const string& filename);
    void writeToFile(const string& filename) const;

    bool IsEmpty() const;

    QSize calculTableSize() const;
    void draw(QPainter& painter);
    void drawCell(QPainter &painter, int x, int y, int width, int height, const QString &text);

    void clearPlayers();

    ~Team();
};

