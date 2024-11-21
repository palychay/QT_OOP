#pragma once
#include "VolleyPlayer.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/access.hpp>
#include <QPainter>


using namespace std;


class Attacker : public VolleyPlayer
{
    int power;
    double jump;

public:
    Attacker() : VolleyPlayer(), power(0), jump(0.0) {}

    void draw(QPainter &painter, int startX, int startY, int cellWidth, int cellHeight, int& rowIndex) const override;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& boost::serialization::base_object<VolleyPlayer>(*this);
        ar& power;
        ar& jump;
    }
};
