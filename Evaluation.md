//Evaluation guide for Snake Game

//Describing Onscreen Objects
// Snake - white squares with a blue circular head.
//
// Thorn - red squares 
// 
// Fruit - green squares
//
// Bullet - grey circular objects

//Functional Requirements Hints

//1. Placing Fruits and Thorns
//When the game is launched, the snake's position doesn't interfere with the 
//positions of any of the fruits and thorns on screen.  

//2. Releasing circular shots(bullets)
// The space bar key is used to shoot a shot from the snake to hit obstacle(
// fruit or thorn) in its direction.

//3. Shot travelling(bullets)
// The released shot travels in the direction of the snake with an addition of a
// constant velocity to every UI on frame update call. 

//4. Snake hitting either sides of the screen.
// The head of the snake(blue circular object) is used for collision with side 
// detection. 
// Collision with side happens when the total head of the snake exits the side 
// the screen. This leaves the snake's body hanging in the screen. The game is 
// over.

//5. Snake Colliding with Thorn(Red square objects)
//   When the snake hits a thorn element on screen, the thorn element should 
//   disappear and the snake would not move afterwards. 

//6. Eating Fruit on Screen
// Move the snake in the direction of the fruit(green square objects) to be 
// eaten and collide head on with it. 
// The snake's length should increase by one square and the fruit should 
// disappear from screen. 

//7. Snake firing bullets(grey circular objects)
//  The space bar key should be use by the snake player to fire shots.
//      When the bullet hits a fruit, a thorn, snake itself, sides of screen,
//       i) the fruit and the bullet both disappears from screen.
//       ii) both the thorn and bullet disappears
//       iii) the game is over
//       iv) the bullets exits the screen.

//8 Moving Snake
//When the game launches, the sanke would start moving from left to right. 
// The snakes moves by continuously changing the positions of the squares 
// forwards in the direction of movement. 

//9. Changing the direction of the snake's movement.
// When snake is moving vertically, use 'left arrow key' and 'right arrow key'
//    for turning left and right respectively.
//    - When snake is moving horizontally, use 'left arrow key' and 'right arrow
//     key' to up and down respectively.


//10. This has been changed from what was originally in the proposal. 
// 


    
    