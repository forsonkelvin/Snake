#pragma once

#include <ge211.hxx>

struct Geometry
{
    // Constructs an instance with the default parameters.
    Geometry() noexcept;

    // The dimensions of the whole window:
    ge211::Dimensions scene_dims;

    int snake_radius;

    // Number of thorns:
    int thorns_num;

    // Number of fruits:
    int fruits_num;

    // The radius of the shot:
    int shot_radius;

    // Number of shots:
    int shots_num;

    //The length of the snake
    int snake_length;

    // Score of the length of the snake:
    int score;

    // The shot's vertical velocity {width, height}:
    ge211::Dimensions shot_vel;

    // The snake's velocity
    ge211::Dimensions snake_vel;


    // Number of pixels from top of screen to initial position of snake:
    int top_margin;

    // Number of pixels from sides of screen to initial position of snake:
    int side_margin;


    // The dimensions of each thorn, fruit, and snake. Also computed from the
    // other
    // properties.
    //
    ge211::Dimensions thorn_dims;

    ge211::Dimensions fruit_dims;

    ge211::Dimensions snake_dims;

};

