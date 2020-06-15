#pragma once

#include <ge211.hxx>
#include "geometry.hxx"
#include "snake.hxx"
#include "shot.hxx"
#include "queue.hxx"
#include "bullets.hxx"

using Segment = ge211:: Rectangle;

//
// Model classes
//

//The position of initial state of snake;

struct Model
{
    ///
    /// MEMBER VARIABLES
    ///

    explicit Model(Geometry const& geometry = Geometry());

    //
    // PRIVATE DATA MEMBERS
    //

    // The Thorns
    std::vector<Segment> thorn_;

    //The fruits
    std::vector<Segment> fruits_;

    Geometry const& geometry_;


    shot Shot;

    //The index of the current head of the snake
    int head;

    //The index of the current tail of the snake
    int tail;

    //The space between the body parts of the snake.
    int space;

    bool moving;

    //Finds the current snake part being used.
    queue snakeFinder;

    //Stores the snakes length;
    int  snake_length();

    int count;

    //Moves the whole snake's body;
    void python_move();

    int snake_state;

    //Moves the head of the current snake head forward;
    void python_move_head_forward(int temp);

    ge211:: Position find_next_position(int temp);

    //Stores the instances of the snake
    std::vector<Snake> python;

    //
    // PUBLIC FUNCTIONS
    //

    bool on_snake;
    bool python_alive;

    //Updates the model state
    //Check if fruit has been eaten-> increase Snake's length, then reduce
    // number of fruits.
    //Check how many thorns have been destroyed-> remove them from the thorns
    //vector.
    //Updates the score of the player.
    //Checks if the player dies, hence game over or updates its state.
    void update();

    void update_shot_on_snake();

    void modify_snake_state(int snake_dir);

    //updates the shot whenever the snake's body moves
    void update_shot_position();

    void growSnake();

    void snakeMove2();

    void fireShot();

    std::vector<bullet> ammo;

    void modify_ammo_state();

    void bullet_destroy_others();

    bool bullet_hit_thorn(bullet bull);

    bool bullet_hit_fruit(bullet bull);

    void destroy_python();

    void eat_food();

    void eat_thorn();

    //Launches the game.
    void launch();



    //
    // POSSIBLE HELPER FUNCTIONS
    //

    //Does the game over setup
    void game_over();

    //Determines whether the snake hits the top of the screen.
    bool snake_hits_top() const;

    //Determines whether the snake hits the bottom of the screen.
    bool snake_hits_bottom() const;

    //Determines whether the snake hits the left or right side of the screen.
    bool snake_hits_side() const;

    //Determines if the shot hits a thorn
    bool snake_hits_thorn() const;

    //Determines if the snake hits itself
    bool snake_hits_self() const;

    //Determines if the shot hits fruit.
    bool shot_hits_fruit(Segment&) const;

    //Determines if the shot hits thorn.
    bool shot_hits_thorn(Segment&) const;

    //Determines if the shot hits the screen.
    bool shot_hits_screen(Segment&) const;

    //Determines if the snake eats a fruit.
    bool snake_eats_fruit(Segment fruit) const;

    //Removes the fruit from the screen
    bool destroy_fruit(std::vector<Segment>& fruits);

    //Removes the snake if it hits any side of the screen or snake hits thorn.
    bool destroy_snake_hit();

    friend struct Test_access;
};



