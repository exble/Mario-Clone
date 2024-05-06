#ifndef CONFIG_H
#define CONFIG_H

#define TICK_PER_SEC 100
#define GAME_WIDTH 7000
#define GAME_HEIGHT 700
#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 700
#define TITLE_WIDTH 1080
#define TITLE_HEIGHT 619
#define BLOCK_SIZE 50
#define MAX_SPEED 5
#define WALKING_ACCELERATION_PER_SEC 10
#define JUMP_HOLDING_MAX_MILISEC 300
#define GRAVITATIONAL_ACCELERATION_PER_SEC 9.8
#define FRICTION_ACCELERATION_PER_SEC 6
#define ANIMATION_PER_SEC 6
#define BULLET_SPEED 7
#define TICK_PER_ANIMATION (TICK_PER_SEC / ANIMATION_PER_SEC)
#define SEC_TO_TICK(x) ((float)x / TICK_PER_SEC)
#define EPSILON 1e-1
#define DEBUG_PLAYER 0
#define DEBUG_REMOVE 1
#define DEBUG_HITBOX 1

enum class Blocks{Box, Broken, Floor, Normal, Stone, Pipe};
enum class State{Jumping, Falling, Stop, Running, Dying};
enum class Direction{Up, Down, Left, Right};
enum class Facing{Left, Right};


#endif // CONFIG_H
