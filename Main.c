#include <stdio.h> 
#include <stdlib.h> 
#include "Graphics.h"

int main()
{
	InitWindow("LearnCG", 800, 600);

	Line(0, 0, 300, 200);
	Draw();

	while (!QuitWindow())
	{

	}

	CloseWindow();
}
