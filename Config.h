#ifndef CONFIG_H
#define CONFIG_H

#define TICK_PER_SEC 100.0
#define GAME_WIDTH 7000
#define GAME_HEIGHT 700
#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 620
#define TITLE_WIDTH 1080
#define TITLE_HEIGHT 619
#define END_WIDTH 400
#define END_HEIGHT 400
#define BLOCK_SIZE 50
#define MAX_SPEED_PER_SEC 300.0
#define MAX_SPEED MAX_SPEED_PER_SEC/TICK_PER_SEC
#define WALKING_ACCELERATION_PER_SEC 10
#define JUMP_ACCELERATION_PER_SEC 155
#define JUMP_ACCELERATION_PER_TICK JUMP_ACCELERATION_PER_SEC/TICK_PER_SEC
#define JUMP_HOLDING_MAX_MILISEC 300
#define GRAVITATIONAL_ACCELERATION_PER_SEC 9.8
#define FRICTION_ACCELERATION_PER_SEC 6
#define ANIMATION_PER_SEC 6
#define BULLET_SPEED 7
#define TICK_PER_ANIMATION (int)(TICK_PER_SEC / ANIMATION_PER_SEC)
#define SEC_TO_TICK(x) ((float)x / TICK_PER_SEC)
#define EPSILON 1e-1
#define DEBUG_PLAYER 1
#define DEBUG_REMOVE 0
#define DEBUG_HITBOX 0
#define PI 3.14159265358979323846

enum class Blocks{Box, Broken, Floor, Normal, Stone, Pipe};
enum class State{Jumping, Falling, Stop, Running, Dying};
enum class Direction{Up, Down, Left, Right};
enum class Facing{Left, Right};
enum class Items{None, Coin, FireFlower, SuperMushroom};
enum class FlagPart{Flag, Pole};

#endif // CONFIG_H
