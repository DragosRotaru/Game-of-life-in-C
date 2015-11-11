//gcc `sdl-config --cflags --libs` -o main main.c
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

int main(void) {

  unsigned int randomSeed = 0, worldSize = 0, shitDistance =0, changeSizeFlag = 0, ticks = 0;
  int *ptr, *ptrNew;

  //Start SDL
  SDL_Init( SDL_INIT_EVERYTHING );

   //Set up screen
   screen = SDL_SetVideoMode( 1024, 1024, 32, SDL_SWSURFACE );

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
    scanf("%d:%d:%d:%d", &randomSeed, &worldSize, &shitDistance, &ticks );

//initialize the world (create array, zero out and assign random)
  srand(randomSeed);
  ptr=(int*)calloc(worldSize*worldSize,sizeof(int));
  for (int i = shitDistance; i < worldSize - shitDistance; i++){
    for(int j = shitDistance; j < worldSize - shitDistance; j++){
      if (rand() % 2 == 0){
         *(ptr + i*worldSize + j) = 1;
      }
    }
  }


  for(int i = 1;i<ticks;i++){

    //create new world
    ptrNew=(int*)calloc(worldSize*worldSize,sizeof(int));

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
    ptr = ptrNew;

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

    //print out world
    printf("Clock: %d\n", i);
    for (int i = 0; i<worldSize ; i++){
      for (int j = 0; j<worldSize ; j++){
        printf("%d", (int)*(ptr + i*worldSize + j));
      }
      printf("\n" );
    }
    printf("\n\n\n" );
    system("clear");

  }
}
