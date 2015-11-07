#include <stdio.h>
#include <stdlib.h>

int *initializeWorld(int arraySize, int randSeed){
  srand(randSeed);
  int world[arraySize][arraySize];
  world[][]  = {0};
  for (int i = (arraySize/4); i<(arraySize*3/4) ; i++){
    for (int j = (arraySize/4); j<(arraySize*3/4) ; j++){
      if (rand() % 2 == 0){
        world[i][j] = 1;
      }
    }
  }
  return world[][];
}

int main(int argc, char const *argv[]) {
  int *world = initializeWorld(argv[1], argv[2]);
  return 0;
}
