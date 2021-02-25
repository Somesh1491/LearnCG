#pragma once

#include "SDL.h"
#include <stdio.h>
#include <math.h>

void InitWindow(const char* title, int width, int height);
void Draw();
int QuitWindow();
void CloseWindow();

//Drawing Function
void putpixel(int x, int y);
void Line(int x1, int y1, int x2, int y2);
