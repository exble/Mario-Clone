#ifndef CONFIG_H
#define CONFIG_H

#define TICK_PER_SEC 100
#define GAME_WIDTH 1000
#define GAME_HEIGHT 600
#define BLOCK_SIZE 50
#define MAX_SPEED 3
#define GRAVITATIONAL_ACCELERATION_PER_SEC 3
#define FRICTION_COEFFICIENT 30
#define ANIMATION_PER_SEC 6
#define TICK_PER_ANIMATION (TICK_PER_SEC / ANIMATION_PER_SEC)
#define SEC_TO_TICK(x) (x / TICK_PER_SEC)

enum class Blocks{Box, Broken, Floor, Normal, Stone, Pipe};

enum class Subhitbox{Top, Bottom, Left, Right};


#endif // CONFIG_H
