#ifndef CONFIG_H
#define CONFIG_H

#define TICK_PER_SEC 100
#define GAME_WIDTH 1000
#define GAME_HEIGHT 600
#define BLOCK_SIZE 50
#define MAX_SPEED 5
#define WALKING_ACCELERATION_PER_SEC 10
#define GRAVITATIONAL_ACCELERATION_PER_SEC 9.8
#define FRICTION_ACCELERATION_PER_SEC 7
#define ANIMATION_PER_SEC 6
#define TICK_PER_ANIMATION (TICK_PER_SEC / ANIMATION_PER_SEC)
#define SEC_TO_TICK(x) ((float)x / TICK_PER_SEC)
#define EPSILON 1e-1

enum class Blocks{Box, Broken, Floor, Normal, Stone, Pipe};
enum class State{Jumping, Falling, Stop, Running};
enum class Direction{Up, Down, Left, Right};
enum class Facing{Left, Right};

#endif // CONFIG_H
