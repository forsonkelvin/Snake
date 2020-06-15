#include <ge211.hxx>
#include "geometry.hxx"

using Block = ge211::Rectangle ;

///Initializes the snake struct with specified properties and member functions.

struct Snake{
    Snake(Geometry const& geometry, ge211::Position center_snake);

    ge211:: Position center;

    ge211::Position top_left(Geometry geometry);

    ge211::Position center_right(Geometry geometry);

    ge211::Position center_up(Geometry geometry);

    ge211::Position center_left(Geometry geometry);

    ge211::Position center_bottom(Geometry geometry);

    bool moving;
};
