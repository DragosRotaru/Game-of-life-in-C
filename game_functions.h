#ifndef GAME_FUNCTIONS_
#define GAME_FUNCTIONS_

typedef union _cell_{
	int discrete;
	float continuous;
}cell;

typedef struct _world_{
	int worldSize, worldType;
	cell* world;
}world;

void initialize_world(int randomflag, world *ptr);

void update_world(world *worldptr);

void print_world(world *ptr, int clock);

#endif
