#include "shot.hxx"

shot::shot(const Geometry &geometry, ge211::Position position)
        :live(false)
        ,center(position)
        ,shot_radius(geometry.shot_radius)
{

}

void shot:: move_shot(ge211:: Dimensions velocity){
    center.x += velocity.width;
    center.y += velocity.height;
}


ge211::Position shot::top_left(){
    return {center.x  - shot_radius, center.y -
    shot_radius};
}

bool shot::python_hits_top(){
    return center.y  < 0;
}

bool shot::python_hits_bottom(Geometry geometry) {
    return center.y + geometry.shot_radius  > geometry.scene_dims.height;
}

bool shot::python_hits_side(Geometry geometry)  {
    return center.x - geometry.shot_radius < 0 ||
           center.x + geometry.shot_radius > geometry.scene_dims.width;
}

bool shot::python_eats_fruit(ge211::Rectangle fruit) {
    int x = abs(center.x - fruit.center().x);
    int y = abs(center.y - fruit.center().y);
    int k =  x*x +y*y;
    int z = shot_radius + 25;
    return k < z*z;
}