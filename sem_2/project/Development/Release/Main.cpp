#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	mt::Game game;

	game.SetResolution(840, 650);
	game.SetCaption("Road");
	game.Setup();

	game.Run();

	return 0;
}