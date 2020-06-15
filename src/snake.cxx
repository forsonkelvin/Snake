#include "snake.hxx"

Snake::Snake(const Geometry &geometry, ge211::Position center_snake)
    : center(center_snake)
{

}



ge211::Position Snake::center_right(Geometry geometry){
    return {center.x + geometry.snake_radius, center.y};
}

ge211::Position Snake::center_left(Geometry geometry) {
    return {center.x - geometry.snake_radius, center.y};
}

ge211::Position Snake::center_up(Geometry geometry) {
    return {center.x, center.y - geometry.snake_radius};
}

ge211::Position Snake::center_bottom(Geometry geometry) {
    return {center.x , center.y+ geometry.snake_radius};
}


ge211::Position Snake::top_left(Geometry geometry) {
    return {center.x - geometry.snake_radius, center.y - geometry
    .snake_radius };
}

