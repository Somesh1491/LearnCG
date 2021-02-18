#pragma once

#include "SDL.h"
#include <stdio.h>

void InitWindow(const char* title, int width, int height);
void putpixel(int x, int y);
void Draw();
int QuitWindow();
void CloseWindow();
