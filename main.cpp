#include <SDL.h>
#include <string>

const int screen_x = 640;
const int screen_y = 480;
const std::string window_title = "SDL2 Window";

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_x, screen_y, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game loop
    bool running = true;
    float color = 0.;
    int dcolor; // Dynamically updating int version of color

    SDL_Event event;
    while (running) {
        // Slowly change the background color from black to white
        dcolor = (int)color; // Cast float to int
        SDL_SetRenderDrawColor(renderer, dcolor, dcolor, dcolor, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        color += 0.01;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
