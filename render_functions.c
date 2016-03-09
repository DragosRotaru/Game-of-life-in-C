#include "SDL2/SDL.h"


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

void renderMenu(SDL_Renderer *renderer, int *windowW, int *windowH){
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
