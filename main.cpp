#include <iostream>
#include "Game.h"

int main()
{
	BlackJack::Game game;
	game.AddUser(BlackJack::User("CopyCat", 5000));
	game.Start();
}