#include "SDL.h"

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "SDL2Test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640,
    480,
    0
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  bool running = true;
    SDL_Event event;
    while (running) {
        // Set background color to gray
        SDL_RenderClear(renderer);
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          running = false;
        }
      }
    }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
