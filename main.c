#include "render_functions.h"
#include "game_functions.h"
#include <stdio.h>
#include "SDL2/SDL.h"

int main(void){

 if (SDL_Init(SDL_INIT_VIDEO||SDL_INIT_TIMER) != 0){
    fprintf(stderr, "\nunable to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }
  atexit(SDL_Quit);

  SDL_Window *window;
  SDL_Renderer *renderer;
  int *windowH, *windowW;
  *windowW = 480;
  *windowH = 640;
  window = SDL_CreateWindow("Game of Life in C", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *windowW, *windowH, SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int maxTicks, randomFlag, worldSize, worldType;
	world worldObject, *ptr;

  scanf("%d:%d:%d:%d",&randomFlag,&maxTicks,&worldSize, &worldType);
	ptr = &worldObject;

	initialize_world(ptr, randomFlag, worldSize, worldType);

	while((*ptr).ticks < maxTicks){
		update_world(ptr);
		print_world(ptr);

  /*
  //Menu loop
  while(!start)
  {
    //Check for events
    start = processMenuEvents(window, windowW, windowH);

    //Render display
    renderMenu(renderer, windowW, windowH);

    //don't burn up the CPU
    SDL_Delay(100);
  }
*/
  }
}
