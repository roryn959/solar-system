#include <SDL2/SDL.h>
#include <iostream>

#include "Drawer.h"
#include "Universe.h"


bool startup(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return false;
    }

    window = SDL_CreateWindow("Template", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
    if (NULL == window)
        return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer)
        return false;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    return true;
}

void draw_background(SDL_Renderer*& renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void mainloop(SDL_Window*& window, SDL_Renderer*& renderer) {
    Universe universe;
    Drawer drawer(renderer);

	double lastTime = SDL_GetTicks() / 1000.0;
	double timeAccumulator{ 0.0 };

    bool running = true;
    while (running) {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

		double time = SDL_GetTicks() / 1000.0;
		timeAccumulator += (time - lastTime);

		while (timeAccumulator > TICK_SIZE) {
			universe.ProcessTick();
			timeAccumulator -= TICK_SIZE;
		}

		lastTime = time;

        draw_background(renderer);

        drawer.Render(universe);

        SDL_RenderPresent(renderer);
    }
}

void teardown(SDL_Window*& window, SDL_Renderer*& renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;

    if (!startup(window, renderer))
        return 1;

    mainloop(window, renderer);

    teardown(window, renderer);

    return 0;
}
