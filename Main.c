#include "Graphics.h"
#include <stdio.h>

int main()
{   
    InitWindow("Computer Graphics", 800, 600);

    putpixel(100, 200);
    Draw();

    while (QuitWindow())
    {

    }

    return -1;
}
