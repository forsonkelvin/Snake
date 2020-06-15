#include "bullets.hxx"

bullet::bullet(const Geometry &geometry, ge211::Position position)
        :live(false)
        ,center(position)
        ,shot_radius(geometry.shot_radius)
        ,vel{0,0}
{

}


void bullet:: move_bullet(int  snake_state){
    if(snake_state == 1){
        vel += {5, 0};
    }
    if(snake_state == -1){
        vel += {-5, 0};
    }
    if(snake_state == 2){
        vel += {0, 5};
    }
    if(snake_state == -2){
        vel += {0,-5};
    }
}

void bullet::now_moving() {
    center.x += vel.width;
    center.y += vel.height;
}




ge211::Position bullet::top_left(){
    return {center.x  - shot_radius, center.y -
                                     shot_radius};
}




bool bullet::hit_object(ge211::Rectangle fruit) {
    int x = center.x - fruit.center().x;
    int y = center.y - fruit.center().y;
    int k =  x*x +y*y;
    int z = shot_radius + 25;
    return k < z*z;
}



/*
bool bullet::hit_object(ge211::Rectangle onscreen_item){
    int x = center.x - onscreen_item.center().x;
    int y = center.y - onscreen_item.center().y;
    return x^2 + y^2 < (onscreen_item.width/2 + shot_radius)^2;
}

*/






bool bullet::out_of_screen(Geometry geometry) {
    return out_top() ||
    out_bottom(geometry) || out_side(geometry);
}

bool bullet::out_top(){
    return center.y - shot_radius < 0;
}

bool bullet::out_bottom(Geometry geometry){
    return center.y + shot_radius > geometry.scene_dims.height ;
}

bool bullet::out_side(Geometry geometry){
    return center.x + shot_radius > geometry.scene_dims.width
    || center.x - shot_radius < 0;
}
