#include "game_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define WORLD_BORDER 2

void initialize_world(int randomflag, world *ptr){
	(*ptr).world = (cell*)calloc((*ptr).worldSize*(*ptr).worldSize,sizeof(cell));
	if(randomflag){
		srand(time(NULL));
		for(int i = WORLD_BORDER; i < (*ptr).worldSize - WORLD_BORDER; i++){
			for(int j = WORLD_BORDER; j < (*ptr).worldSize - WORLD_BORDER; j++){
				if((*ptr).worldType == 0){
					if (rand() % 2 == 0){
						(*((*ptr).world + i*(*ptr).worldSize + j)).discrete = 1;
					}
				}
				else{
				(*((*ptr).world + i*(*ptr).worldSize + j)).continuous = rand()/RAND_MAX;
				}
			}
		}
	}
}

void rulecheck_world(world *ptr){

}

int change_size_check(world *ptr){

	return 0;
}

void change_world_size(world *ptr){

}

void update_world(world *worldptr){
	rulecheck_world(worldptr);
	if (change_size_check(worldptr)){
		change_world_size(worldptr);
	}
}

void print_world(world *ptr, int clock){
  //print out world
  printf("Clock: %d\n", clock);
  for (int i = 0; i<(*ptr).worldSize ; i++){
    for (int j = 0; j<(*ptr).worldSize ; j++){
			if((*ptr).worldType == 0){
				printf("%d", (*((*ptr).world + i*(*ptr).worldSize + j)).discrete);
			}
			else{
				printf("%f", (*((*ptr).world + i*(*ptr).worldSize + j)).continuous);
			}
    }
    printf("\n" );
  }
  system("clear");
}
