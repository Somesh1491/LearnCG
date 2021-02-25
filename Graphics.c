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

void MidPointLine_Alogrithm(int x1, int y1, int x2, int y2, int octant);
void Line(int x1, int y1, int x2, int y2)
{
    int dy = y2 - y1;
    int dx = x2 - x1;

    int octant = 0;
    float slope = (float)dy / dx;
    
    if (slope >= 0) //1st 2nd 5th 6th octant
    {
        if (abs(dy) <= abs(dx)) //1st 5th octant
        {
            if (x2 >= x1)   //1st octant
                MidPointLine_Alogrithm(x1, y1, x2, y2, 1);
            else
                MidPointLine_Alogrithm(-x1, -y1, -x2, -y2, 5); //5th octant
        }

        else //2nd 6th octant
        {
            if (y2 >= y1) //2nd octant
                MidPointLine_Alogrithm(y1, x1, y2, x2, 2);
            else
                MidPointLine_Alogrithm(-y1, -x1, -y2, -x2, 6); //6th octant
        }
    }

    else   //3rd 4th 7th 8th octant
    {
        if (abs(dy) <= abs(dx)) //4th 8th octant
        {
            if (x2 <= x1) //4th octant
                MidPointLine_Alogrithm(-x1, y1, -x2, y2, 4);
            else
                MidPointLine_Alogrithm(x1, -y1, x2, -y2, 8); //8th octant
        }

        else //3rd 7th octant
        {
            if (y2 >= y1)
                MidPointLine_Alogrithm(y1, -x1, y2, -x2, 3); //3rd octant
            else
                MidPointLine_Alogrithm(-y1, x1, -y2, x2, 7); //7th octant
        }
    }
    
}

void MidPointLine_Alogrithm(int x1, int y1, int x2, int y2, int octant)
{
    int x = x1;
    int y = y1;
    int dy = y2 - y1;
    int dx = x2 - x1;

    int d = 2 * dy - dx;
    int d_E = 2 * dy;  // For east
    int d_NE = 2 * (dy - dx); //For north east

    switch (octant)
    {
    case 1:
        putpixel(x, y);
        break;
    case 2:
        putpixel(y, x);
        break;
    case 3:
        putpixel(y, -x);
        break;
    case 4:
        putpixel(-x, y);
        break;
    case 5:
        putpixel(-x, -y);
        break;
    case 6:
        putpixel(-y, -x);
        break;
    case 7:
        putpixel(-y, x);
        break;
    case 8:
        putpixel(x, -y);
        break;
    default:
        break;
    }

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

        switch (octant)
        {
        case 1:
            putpixel(x, y);
            break;
        case 2:
            putpixel(y, x);
            break;
        case 3:
            putpixel(-y, x);
            break;
        case 4:
            putpixel(-x, y);
            break;
        case 5:
            putpixel(-x, -y);
            break;
        case 6:
            putpixel(-y, -x);
            break;
        case 7:
            putpixel(y, -x);
            break;
        case 8:
            putpixel(x, -y);
            break;
        default:
            break;
        }
    }
}
