#ifndef GAME_FUNCTIONS_
#define GAME_FUNCTIONS_

typedef union _cell_{
	int discrete;
	float continuous;
}cell;

typedef struct _world_{
	int ticks, randflag, worldSize, worldType;
	cell* world;
}world;

void initialize_world(world *ptr, int randFlag, int worldSize, int worldType);

void update_world(world *ptr);

void print_world(world *ptr);

#endif
