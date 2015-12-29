//#include "SDL2/SDL.h"
#include "game_functions.h"
#include <stdio.h>
/*
int processMenuEvents(SDL_Window *window, int *windowW, int *windowH){
  SDL_Event event;
  int done = 0;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_WINDOWEVENT:  {
            switch (event.window.event)  {

              case SDL_WINDOWEVENT_SIZE_CHANGED:  {
                *windowW = event.window.data1;
                *windowH = event.window.data2;
                break;
              }

              case SDL_WINDOWEVENT_CLOSE:  {
                event.type = SDL_QUIT;
                SDL_PushEvent(&event);
                break;
              }

            }
          break;
        }
      case SDL_KEYDOWN:
      {
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            done = 1;
          break;
        }
      }
      break;
      case SDL_QUIT:
        //quit out of the game
        done = 1;
      break;
    }
  }

  return done;
}

void renderMenu(SDL_Renderer *renderer, int *windowW, int *windowH)
{
  //set the drawing color to blue
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

  //Clear the screen (to blue)
  SDL_RenderClear(renderer);

  //set the drawing color to white
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_Rect startbutton = { *windowW - 100, *windowH - 100, 100, 50 };
  SDL_RenderFillRect(renderer, &startbutton);
  SDL_Rect randomflagbutton = { 50, *windowH - 100, 100, 50 };
  SDL_RenderFillRect(renderer, &randomflagbutton);
  SDL_Rect exitbutton = { *windowW - 50, 20, 25, 25 };
  SDL_RenderFillRect(renderer, &exitbutton);
  SDL_Rect titlebar = { 100, 150, 400, 200 };
  SDL_RenderFillRect(renderer, &titlebar);

  //We are done drawing, "present" or show to the screen what we've drawn
  SDL_RenderPresent(renderer);
}
*/

int main(void){

/*  if (SDL_Init(SDL_INIT_VIDEO||SDL_INIT_TIMER) != 0){
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

*/
  int randomflag = 0, ticks = 0;
	world worldObject, *ptr;
  scanf("%d:%d:%d:%d",&randomflag,&ticks,&worldObject.worldSize, &worldObject.worldType );
	ptr = &worldObject;

	initialize_world(randomflag, ptr);
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

  for(int i = 1;i<ticks;i++){
    update_world(ptr);
    print_world(ptr, i);
  }
}
