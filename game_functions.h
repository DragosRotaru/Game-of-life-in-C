#ifndef GAME_FUNCTIONS_
#define GAME_FUNCTIONS_

typedef union _unit_{
	int discrete;
	float continuous;
}unit;

typedef struct _world_{
	int worldSize, worldType;
	unit* world;
}world;

void initialize_world(int randomflag, world *ptr);

void update_world(world *worldptr);

void print_world(world *ptr, int clock);

#endif
