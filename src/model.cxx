#include <iostream>
#include "model.hxx"


//Constructs the model to be able to use member variables and functions.
Model:: Model(Geometry const& geometry)
        : geometry_(geometry)
        , Shot(geometry, {50,50})
        ,on_snake(true)
        ,moving(false)
        ,head(0)
        ,tail(2)
        ,space(2)
        ,snakeFinder(geometry, 0)
        ,python{}
        ,snake_state(1)
        ,count(0)
        ,python_alive(true)

{
    python.push_back(Snake(geometry, {200,200}));
    python.push_back(Snake(geometry, {178,200}));
    python.push_back(Snake(geometry, {156,200}));
    snakeFinder.addToQueue(1);
    Shot.center = {python[0].center_right(geometry).right_by
            (geometry_.shot_radius)};



    std::vector<ge211::Position> thorn_pos = {{100,100}, {150,400},
                                              {300,300},{400,560},
                                              {700, 200}, {800,560},
                                              {900,500}};

    for(int i = 0; i < thorn_pos.size(); i++){
        thorn_.push_back(ge211::Rectangle {thorn_pos[i].x, thorn_pos[i].y});
    }

    std::vector<ge211::Position> fruit_pos = {{700,100}, {200,150},
                                              {200,300},{560,400},
                                              {200, 700}, {960,240},
                                              {500,640}};

    for(int i = 0; i < fruit_pos.size(); i++){
        fruits_.push_back(ge211::Rectangle {fruit_pos[i].x, fruit_pos[i].y});
    }






}




void  Model::launch() {
}

void Model::update()
{
    eat_food();
    eat_thorn();
if(python_alive) {
    if (Shot.live) {
        Shot.move_shot(geometry_.shot_vel);
    }
    if (count == 50) {
        python_move();
        count = 0;
    }
    count++;
    if (ammo.size() != 0) {
        for (bullet& bull: ammo) {
            bull.now_moving();
        }
    }
    modify_ammo_state();
    bullet_destroy_others();
    destroy_python();
    eat_food();
    eat_thorn();
}
}
void Model::bullet_destroy_others() {
    for(bullet& bull: ammo){
        if (bullet_hit_thorn(bull) || bullet_hit_fruit(bull)){
            std::swap(bull, ammo.back());
            ammo.pop_back();
        }
    }
}


bool Model::bullet_hit_fruit(bullet bull)
{
    for (Segment& fruit: fruits_) {
        if (bull.hit_object(fruit)) {
            std::swap(fruit, fruits_.back());
            fruits_.pop_back();
            return  true;
        }
    }
    return false;
}

bool Model::bullet_hit_thorn(bullet bull) {
    for(Segment& thorn: thorn_) {
        if (bull.hit_object(thorn)) {
            std::swap(thorn, thorn_.back());
            thorn_.pop_back();
            return true;
        }
    }
    return false;
}
void Model::modify_snake_state(int snake_dir) {
    if(snake_state == 1 && snake_dir == 1){
        snake_state = 2;
    }
    else if (snake_state == 1 && snake_dir == -1){
        snake_state = -2;
    }
    else if (snake_state == -1 && snake_dir == 1){
        snake_state = -2;
    }
    else if (snake_state == -1 && snake_dir == -1){
        snake_state = 2;
    }
    else if (snake_state == -2 && snake_dir == 1){
        snake_state = 1;
    }
    else if (snake_state == -2 && snake_dir == -1){
        snake_state = -1;
    }
    else if (snake_state == 2 && snake_dir == 1){
        snake_state = -1;
    }
    else if (snake_state == 2 && snake_dir == -1){
        snake_state = 1;
    }

}

void Model::update_shot_on_snake() {
    if(on_snake && snake_state == 1){
        Shot.center = python[head].center_right(geometry_).right_by(geometry_
                .shot_radius);
    }
    if(on_snake && snake_state == -1){
        Shot.center = python[head].center_left(geometry_).left_by(geometry_
                .shot_radius);
    }
    if(on_snake && snake_state == -2){
        Shot.center = python[head].center_up(geometry_).up_by(geometry_
                .shot_radius);
    }
    if(on_snake && snake_state == 2){
        Shot.center = python[head].center_bottom(geometry_).down_by(geometry_
                .shot_radius);
    }

}


void Model::update_shot_position() {

    if(on_snake && snake_state == 1){
        Shot.center = python[head].center_right(geometry_).right_by(geometry_
                .shot_radius);
    }
    if(on_snake && snake_state == -1){
        Shot.center = python[head].center_left(geometry_).left_by(geometry_
                                                                   .shot_radius);
    }
    if(on_snake && snake_state == -2){
        Shot.center = python[head].center_up(geometry_).up_by(geometry_
                                                               .shot_radius);
    }
    if(on_snake && snake_state == 2){
        Shot.center = python[head].center_bottom(geometry_).down_by(geometry_
                                                                     .shot_radius);
    }
}

/*
int Model::snake_length() {
    return python.size();
}
*/
void Model::python_move(){
    int temp = head;
    head = tail;
    snakeFinder.addToQueue(head);
    tail = snakeFinder.getLastItemIndex();
    python_move_head_forward(temp);
    update_shot_position();

}

void Model:: python_move_head_forward(int temp){
    python[head].center = find_next_position(temp);
}


ge211:: Position Model::find_next_position(int temp){
    ge211::Dimensions add{geometry_.snake_radius + space, geometry_
    .snake_radius + space };

    if(snake_state == 1)
        return {python[temp].center_right(geometry_).x + add.width,
                python[temp].center_right(geometry_).y};
    if(snake_state == -1)
        return {python[temp].center_left(geometry_).x - add.width,
                python[temp].center_left(geometry_).y};
    if(snake_state == 2)
        return {python[temp].center_bottom(geometry_).x ,
                python[temp].center_bottom(geometry_).y + add.width};
    if(snake_state == -2)
        return {python[temp].center_up(geometry_).x,
                python[temp].center_up(geometry_).y - add.width};
    else{
        return ge211::Position {0,0};
    }

}


void Model::growSnake() {
    ge211::Position tail_center = {python[tail].center};
    python.push_back(Snake(geometry_, tail_center));
    snakeMove2();
}

void Model::snakeMove2(){
    int temp = head;
    head = tail;
    snakeFinder.addToQueue(head);
    tail = python.size() -1;
    python_move_head_forward(temp);
    update_shot_position();
}




void Model::fireShot() {
    bullet Bullet(geometry_, Shot.center);
    Bullet.move_bullet(snake_state);
    ammo.push_back(Bullet);

}

void Model::modify_ammo_state() {
    for(bullet& bull: ammo){
        if(bull.out_of_screen(geometry_)){
            std::swap(bull, ammo.back());
            ammo.pop_back();
        }
    }
}

void Model::destroy_python()
{
    if (
    Shot.python_hits_top() || Shot.python_hits_side(geometry_) || Shot
    .python_hits_bottom(geometry_)
        )
    {
        python_alive = false;
    }
}

void Model::eat_food() {
    for(ge211::Rectangle& food: fruits_){
        if(Shot.python_eats_fruit(food)){
            std::swap(food, fruits_.back());
            fruits_.pop_back();
            growSnake();
        }
    }
}


void Model::eat_thorn() {
    for(ge211::Rectangle& thorn: thorn_){
        if(Shot.python_eats_fruit(thorn)){
            std::swap(thorn, thorn_.back());
            thorn_.pop_back();
            python_alive = false;
        }
    }
}