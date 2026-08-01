#include<iostream>
#include"Game.hpp"
#include"DEFINITIONS.hpp"


int main()
{
	Flappy::Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
	return EXIT_SUCCESS;
}