#include "ge211.hxx"
#include "geometry.hxx"



struct bullet{

    bullet(Geometry const& geometry, ge211::Position position);

    int shot_radius;

    ge211::Position top_left();

    void move_bullet(int snake_state);

    bool live;

    ge211::Position center;

    bool hit_object(ge211::Rectangle onscreen_item);

    bool out_of_screen(Geometry geometry);

    bool out_top();

    bool out_bottom(Geometry geometry);

    bool out_side(Geometry geometry);

    ge211::Dimensions vel;

    void now_moving();

};

