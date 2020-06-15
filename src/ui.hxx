#pragma once

#include "model.hxx"
#include <ge211.hxx>

extern ge211::Color const shot_color, fruit_color, snake_color,bullet_color,
thorn_color;


struct Ui : ge211::Abstract_game
{

    explicit Ui(Model&);


    ge211::Dimensions initial_window_dimensions() const override;

    void draw(ge211::Sprite_set&) override;

    void  on_frame(double dt) override;


    Model& model;

    void on_key(ge211::Key) override;

    ge211::Circle_sprite    const
            shot_sprite_    {model.geometry_.shot_radius, shot_color};
    ge211::Circle_sprite    const
            bullet_sprite_    {model.geometry_.shot_radius, bullet_color};

    ge211::Rectangle_sprite const
            fruit_sprite_  {model.geometry_.fruit_dims, fruit_color};
    ge211::Rectangle_sprite const
            snake_sprite_  {model.geometry_.snake_dims, snake_color};

    ge211::Rectangle_sprite const
            thorn_sprite_   {model.geometry_.thorn_dims, thorn_color};
};

