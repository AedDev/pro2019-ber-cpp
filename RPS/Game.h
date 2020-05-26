#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include "Choice.h"
#include "LoopChoice.h"
#include "Util.h"

using namespace std;

class Game
{
private:
	bool running;
	int matchesWon;
	int matchesLost;

public:
	Game();

	void gameLoop();
	LoopChoice showMenu();
	void runGame();
	Choice makeAiChoice();
	int compareChoice(Choice a, Choice b);
	string* choiceToStr(Choice c);
};