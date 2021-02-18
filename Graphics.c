#include "Graphics.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;
int w, h;

void InitWindow(const char*title, int width, int height)
{
    w =  width;
    h = height;
    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow(title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    renderer = SDL_CreateRenderer(window, -1, render_flags);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
}

void putpixel(int x, int y)
{
    SDL_RenderDrawPoint(renderer, x, h - y);
}

void Draw()
{
    SDL_RenderPresent(renderer);
}

int QuitWindow()
{
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        return 0;
    }

    return 1;
}

void CloseWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
