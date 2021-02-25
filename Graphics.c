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

void Draw()
{
    SDL_RenderPresent(renderer);
}

int QuitWindow()
{
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        return 1;
    }

    return 0;
}

void CloseWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void putpixel(int x, int y)
{
    SDL_RenderDrawPoint(renderer, x, h - y);
}

void Line(int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dy = y2 - y1;
    int dx = x2 - x1;

    int d = 2 * dy - dx;
    int d_E = 2 * dy;  // For east
    int d_NE = 2 * (dy - dx);

    putpixel(x, y);
    while (x < x2)
    {
        if (d <= 0)
            d = d + d_E;

        else
        {
            d = d + d_NE;
            y++;
        }

        x++;

        putpixel(x, y);
    }
}