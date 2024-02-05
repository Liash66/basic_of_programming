#include "Game.h"
#include "Planet.h"

int main()
{
	mt::Game game;

	game.SetResolution(1000, 700);
	game.SetCaption("Planetary system");
	game.Setup();

	game.Run();

	return 0;
}