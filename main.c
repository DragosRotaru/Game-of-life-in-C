#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include <time.h>

#define WORLD_BORDER 2

//initialize discrete world (create array, zero out and assign random if randomflag is set to true)
int* initialize_world(int randomflag, int worldSize) {
  int* ptr=(int*)calloc(worldSize*worldSize,sizeof(int));
  if (randomflag) {
    srand(time(NULL));
    for (int i = WORLD_BORDER; i < worldSize - WORLD_BORDER; i++){
      for(int j = WORLD_BORDER; j < worldSize - WORLD_BORDER; j++){
        if (rand() % 2 == 0){
           *(ptr + i*worldSize + j) = 1;
        }
      }
    }
  }
  return ptr;
}

int* update_world(int* ptr, int worldSize){
  //create new world
  int* ptrNew=(int*)calloc(worldSize*worldSize,sizeof(int));
  //check for rules
  for(int j = 1;j< worldSize - 1;j++){
    for(int k = 1;k< worldSize - 1;k++){
      if (*(ptr + j*worldSize + k)){
        switch (*(ptr + (j - 1)*worldSize + (k - 1)) + *(ptr + (j - 1)*worldSize + k) + *(ptr + (j - 1)*worldSize + (k + 1)) + *(ptr + j*worldSize + (k - 1)) + *(ptr + j*worldSize + (k + 1)) + *(ptr + (j + 1)*worldSize + (k - 1)) + *(ptr + (j + 1)*worldSize + k) + *(ptr + (j + 1)*worldSize + (k + 1))){
          case 0: case 1: *(ptrNew + j*worldSize + k) = 0; break;
          case 2: case 3: *(ptrNew + j*worldSize + k) = 1; break;
          case 4: case 5: case 6: case 7: case 8: *(ptrNew + j*worldSize + k) = 0; break;
        }
      }
      else if (*(ptr + (j - 1)*worldSize + (k - 1)) + *(ptr + (j - 1)*worldSize + k) + *(ptr + (j - 1)*worldSize + (k + 1)) + *(ptr + j*worldSize + (k - 1)) + *(ptr + j*worldSize + (k + 1)) + *(ptr + (j + 1)*worldSize + (k - 1)) + *(ptr + (j + 1)*worldSize + k) + *(ptr + (j + 1)*worldSize + (k + 1)) == 3){
        *(ptrNew + j*worldSize + k) = 1;
      }
    }
  }
  free(ptr);
  return ptrNew;
}

void print_world(int* ptr, int worldSize, int clock){
  //print out world
  printf("Clock: %d\n", clock);
  for (int i = 0; i<worldSize ; i++){
    for (int j = 0; j<worldSize ; j++){
      printf("%d", (int)*(ptr + i*worldSize + j));
    }
    printf("\n" );
  }
  system("clear");
}

int main(void){

  if (SDL_Init(SDL_INIT_VIDEO||SDL_INIT_TIMER) != 0){
    fprintf(stderr, "\nunable to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }
  atexit(SDL_Quit); //if error take out () from SDL_quit


  SDL_Window *window;
  SDL_Renderer *renderer;
  window = SDL_CreateWindow("Game of Life in C", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


  unsigned int randomflag = 0, worldSize = 0, changeSizeFlag = 0, ticks = 0, start = 0;
  int* ptrNew;

  scanf("%d:%d:%d", &randomflag, &worldSize, &ticks );
  int *ptr = initialize_world(randomflag, worldSize);

  while(!start){
  }

  for(int i = 1;i<ticks;i++){

    ptr = update_world(ptr, worldSize);
    //check if worldSize should increase
    for(int i = 0;i< worldSize;i++){
      if(*(ptr + worldSize + i) || *(ptr + worldSize*(worldSize - 2) + i) || *(ptr + worldSize*i + 1) || *(ptr + worldSize*i - 2)){
        changeSizeFlag = 1;
      }
    }
    //increase world size if necessary
    if(changeSizeFlag){
      worldSize += 2;
      ptrNew = ptr;
      ptr=(int*)calloc(worldSize*worldSize,sizeof(int));
      for (int i = 1; i < worldSize - 1; i++){
        for (int j = 1; j< worldSize - 1; j++){
          *(ptr + i*(worldSize) + j) = *(ptrNew + (i - 1)*(worldSize - 2 ) + (j -1));
        }
      }
      free(ptrNew);
      changeSizeFlag = 0;
    }

    print_world(ptr, worldSize, i);
  }
}

/*
printf("[]\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/[]\n");
printf("[]                                                                                          []\n");
printf("[]        H H EEE L   L   OO          W       w EEE L    CC  OO    M   M   EEE              []\n");
printf("[]        HHH EE  L   L  O  O          W  W  W  EE  L   C   O  O  M  M  M  EE               []\n");
printf("[]        H H EEE LLL LLL OO            W   W   EEE LLL  CC  OO  M       M EEE              []\n");
printf("[]                                                                                          []\n");
printf("[]        TTT OO        TTT H H EEE     GG     A     M M   EEE      OO   FFF                []\n");
printf("[]         T O  O        T  HHH E      G  GG  A A   M M M  EE      O  O  FF                 []\n");
printf("[]         T  OO         T  H H EEE     GGGG A   A M     M EEE      OO   F                  []\n");
printf("[]                                                                                          []\n");
printf("[]                          LL     IIIIII  FFFFFF EEEEEEE     !!                            []\n");
printf("[]                          LL       II    FF     EE          !!                            []\n");
printf("[]                          LL       II    FFFFF  EEEEEEE     !!                            []\n");
printf("[]                          LL       II    FF     EE                                        []\n");
printf("[]                          LLLLLL IIIIII  FF     EEEEEEE     !!                            []\n");
printf("[]                                                                                          []\n");
printf("[]                                                                                          []\n");
printf("[]    The Universe of the Game of Life is an infinite two-dimensional orthogonal grid of    []\n");
printf("[]    square cells, each of which is in one of two possible states, alive or dead.          []\n");
printf("[]    Every cell interacts with its eight neighbours, which are the cells that are          []\n");
printf("[]    horizontally, vertically, or diagonally adjacent. At each step in time, the           []\n");
printf("[]    following transitions occur:                                                          []\n");
printf("[]                                                                                          []\n");
printf("[]    1. Any live cell with fewer than two live neighbours dies.                            []\n");
printf("[]    2. Any live cell with two or three live neighbours lives on to the next generation.   []\n");
printf("[]    3. Any live cell with more than three live neighbours dies.                           []\n");
printf("[]    4. Any dead cell with exactly three live neighbours becomes a live cell.              []\n");
printf("[]                                                                                          []\n");
printf("[]    The initial pattern constitutes the seed of the system. The first generation          []\n");
printf("[]    is created by applying the above rules simultaneously to every cell in the            []\n");
printf("[]    seed; births and deaths occur simultaneously. The rules continue to be                []\n");
printf("[]    applied repeatedly at each step in time to create further generations.                []\n");
printf("[]                                                                                          []\n");
printf("[]    Enjoy!                                                                                []\n");
printf("[]                                                                                          []\n");
printf("[]/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\[]\n\n\n\n");


//get user input
  printf("Please provide two integer values in the format 123:456 \n");
  printf("The first number specifies a seed for the world, the second indicates initial world size, the third indicates the distance from the edge of the initial world where a shit may spawn, minimum 2 \n" );
*/
