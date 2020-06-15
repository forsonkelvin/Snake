#include "ge211.hxx"
#include "ui.hxx"

ge211::Color const shot_color    {0, 0, 255};
ge211::Color const fruit_color  {0, 255, 0};
ge211::Color const snake_color   {255, 255, 255};
ge211::Color const thorn_color {255,0,0};
ge211::Color const bullet_color {150,150,150};


Ui::Ui(Model& model)
        : model(model)
{ }

ge211::Dimensions Ui::initial_window_dimensions() const
{
    return model.geometry_.scene_dims;
}


void Ui::draw(ge211::Sprite_set& sprites){
    for(Segment& thorn: model.thorn_){
        sprites.add_sprite(thorn_sprite_, thorn.top_left());}
    for(bullet& bull: model.ammo){
        sprites.add_sprite(bullet_sprite_, bull .top_left());}
    for(Segment& fruit: model.fruits_){
        sprites.add_sprite(fruit_sprite_, fruit.top_left());
    }
    for(Snake& python_atom : model.python){
        sprites.add_sprite(snake_sprite_, python_atom.top_left(model.geometry_));
    }
    sprites.add_sprite(shot_sprite_, model.Shot.top_left());
}


void Ui::on_key(ge211::Key key) {
    if (key == ge211::Key::code(' ')){
        model.moving = true;
        model.fireShot();
    }

    if (key == ge211::Key::right()) {
        model.moving = true;
        model.modify_snake_state(1);
    }
    if (key == ge211::Key::left()) {
        model.moving = true;
        model.modify_snake_state(-1);
    }


}

void Ui::on_frame(double dt) {
    model.update();
}
