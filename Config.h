#ifndef CONFIG_H
#define CONFIG_H

#define TICK_PER_SEC 100.0
#define GAME_WIDTH 1000
#define GAME_HEIGHT 600
#define BLOCK_SIZE 50
#define MAX_SPEED 100
#define ACCELERATION 50
#define FRICTION_COEFFICIENT 30
#define TICK_PER_ANIMATION 15

enum class Blocks{Box, Broken, Floor, Normal, Stone, Pipe};
enum class Entity{};
enum class Facing{Left, Right};

#endif // CONFIG_H
