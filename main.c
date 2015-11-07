#include <stdio.h>
#include <stdlib.h>

int main(void) {

  const unsigned int RANDOM_SEED = 0;
  unsigned int worldSize = 0, changeInWidth = 0, changeInLength = 0; changeSizeFlagLeft = 0, changeSizeFlagRight = 0, changeSizeFlagTop = 0, changeSizeFlagBottom = 0;

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

  for(;;){
    printf("Please provide two integer values in the format 123:456 \n");
    printf("The first number specifies a seed for the world, the second indicates initial world size \n" );
    scanf("%d:%d", &RANDOM_SEED, &worldSize );
    if (RANDOM_SEED > 0 && worldSize > 0){
      break;
    }
  }

//initialize the game
  srand(RANDOM_SEED);
  int world[worldSize][worldSize];
  for (int i = 0; i < worldSize; i++){
    for (int j = 0; j< worldSize; j++){
      if (i > 1 && i < worldSize - 2 && j > 1 && j < worldSize - 2 && rand() % 2 == 0){
        world[i][j] = 1;
      }
      else world[i][j] = 0;
    }
  }

  for(int i = 1;;i++){
//init new world
    for(int i = 0;j< worldSize;i++){
      if(world[i][0] == 1){
        changeSizeFlagLeft = 1;
      }
      if (world[i][worldSize - 1] == 1){
        changeSizeFlagRight = 1;
      }
      if (world[0][i] == 1){
        changeSizeFlagTop = 1;
      }
      if (world[worldSize - 1][i] == 1){
        changeSizeFlagBottom = 1;
      }
    }
    changeInWidth += (changeSizeFlagRight + changeSizeFlagLeft);
    changeInLength += (changeSizeFlagTop + changeSizeFlagBottom);
    int newWorld[worldSize + changeInLength][worldSize + changeInWidth];
    for (int i = 0; i < worldSize + changeInLength; i++){
      for (int j = 0; j< worldSize + changeInWidth; j++){
        newWorld[i][j] = 0;
      }
    }
//check for rules
    for(int j = 1;j< worldSize - 1 + changeInLength;j++){
      for(int k = 1;k< worldSize - 1 + changeInWidth;k++){
        if (world[j][k]){
          switch (world[j-1][k-1] + world[j-1][k] + world[j-1][k+1] + world[j][k-1] + world[j][k+1] + world[j+1][k-1] + world[j+1][k] + world[j+1][k-1]){
            case 0: case 1: newWorld[j + changeSizeFlagTop][k + changeSizeFlagLeft] = 0; break;
            case 2: case 3: newWorld[j + changeSizeFlagTop][k + changeSizeFlagLeft] = 1; break;
            case 4: case 5: case 6: case 7: case 8: newWorld[j + changeSizeFlagTop][k + changeSizeFlagLeft] = 0; break;
          }
        }
        else if (world[j-1][k-1] + world[j-1][k] + world[j-1][k+1] + world[j][k-1] + world[j][k+1] + world[j+1][k-1] + world[j+1][k] + world[j+1][k-1] == 3){
          newWorld[j + changeSizeFlagTop][k + changeSizeFlagLeft]=1;
        }
      }
    }

    changeSizeFlagTop = 0;
    changeSizeFlagBottom = 0;
    changeSizeFlagLeft = 0;
    changeSizeFlagRight = 0;

//copy new world elements over to original world array
    for (int i = 0; i < worldSize; i++){
      for (int j = 0; j< worldSize; j++){
        world[i][j] = newWorld[i][j];
      }
    }

//print out world
    printf("Clock: %d\n", i);
    for (int i = 0; i<worldSize ; i++){
      for (int j = 0; j<worldSize ; j++){
          printf("%d", newWorld[i][j]);
        }
      printf("\n" );
    }
    printf("\n\n\n" );
    system("clear");
  }
}
