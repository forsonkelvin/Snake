#include "ge211.hxx"
#include "geometry.hxx"



struct shot{

    shot(Geometry const& geometry, ge211::Position position);

    int shot_radius;

    ge211::Position top_left();

    void move_shot(ge211:: Dimensions velocity);

    bool python_hits_side(Geometry geometry);

    bool python_hits_top();

    bool python_hits_bottom(Geometry geometry);

    bool live;

    ge211::Position center;

    bool python_eats_fruit(ge211::Rectangle fruit);

};