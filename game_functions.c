#include "game_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define WORLD_BORDER 2

void initialize_world(world *ptr, int randFlag, int worldSize, int worldType){
	(*ptr).ticks = 0;
	(*ptr).randflag = randFlag;
	(*ptr).worldSize = worldSize;
	(*ptr).worldType = worldType;
	(*ptr).world = (cell*)calloc((*ptr).worldSize*(*ptr).worldSize,sizeof(cell));

	if((*ptr).randflag){
		srand(time(NULL));
		for(int i = WORLD_BORDER; i < (*ptr).worldSize - WORLD_BORDER; i++){
			for(int j = WORLD_BORDER; j < (*ptr).worldSize - WORLD_BORDER; j++){
				if((*ptr).worldType == 0){
					if (rand() % 2 == 0){
						(*((*ptr).world + i*(*ptr).worldSize + j)).discrete = 1;
					}
				}
				else{
				(*((*ptr).world + i*(*ptr).worldSize + j)).continuous = ((float)rand() / (RAND_MAX));
				}
			}
		}
	}
}

void rulecheck_world(world *ptr){

}

int change_size_check(world *ptr){
	for(int i = 0; i < (*ptr).worldSize; i++){
		if ((*ptr).worldType == 0){
      if((*((*ptr).world + (*ptr).worldSize + i)).continuous > 0 || (*((*ptr).world + (*ptr).worldSize*((*ptr).worldSize - 2) + i)).continuous > 0 || (*((*ptr).world + (*ptr).worldSize*i + 1)).continuous > 0 || (*((*ptr).world + (*ptr).worldSize*i - 2)).continuous > 0 ){
        return 1;
      }
		}
		else{
			if((*((*ptr).world + (*ptr).worldSize + i)).discrete || (*((*ptr).world + (*ptr).worldSize*((*ptr).worldSize - 2) + i)).discrete || (*((*ptr).world + (*ptr).worldSize*i + 1)).discrete || (*((*ptr).world + (*ptr).worldSize*i - 2)).discrete ){
        return 1;
      }
    }
	}
	return 0;
}

cell *change_world_size(world *ptr){
	(*ptr).worldSize += 2;
	cell *new;
	new = (cell*)calloc((*ptr).worldSize*(*ptr).worldSize,sizeof(cell));
	for (int i = 1; i < (*ptr).worldSize - 1; i++){
    for (int j = 1; j< (*ptr).worldSize - 1; j++){
			if ((*ptr).worldType == 0){
			 (*(new + i*(*ptr).worldSize + j)).discrete = (*((*ptr).world + (i - 1)*((*ptr).worldSize - 2) + (j - 1))).discrete;
		  }
      else{
			 (*(new + i*(*ptr).worldSize + j)).continuous = (*((*ptr).world + (i - 1)*((*ptr).worldSize - 2) + (j - 1))).continuous;
			}
    }
  }
	return new;
}

void update_world(world *ptr){
	rulecheck_world(ptr);
	if (change_size_check(ptr)){
		((*ptr).world) = change_world_size(ptr);
	}
	(*ptr).ticks++;
}

void print_world(world *ptr){
  //print out world
  printf("Clock: %d\n", (*ptr).ticks);
  for (int i = 0; i<(*ptr).worldSize ; i++){
    for (int j = 0; j<(*ptr).worldSize ; j++){
			if((*ptr).worldType == 0){
				printf("%d", (*((*ptr).world + i*(*ptr).worldSize + j)).discrete);
			}
			else{
				printf("%f ", (*((*ptr).world + i*(*ptr).worldSize + j)).continuous);
			}
    }
    printf("\n" );
  }
  system("clear");
}
