#include "Game.h"

Game::Game()
{
	this->running = true;
	this->matchesWon = 0;
	this->matchesLost = 0;
}

void Game::gameLoop()
{
	while (this->running)
	{
		LoopChoice choice = this->showMenu();
		switch (choice)
		{
		case LoopChoice::NewGame:
			this->runGame();
			break;

		case LoopChoice::QuitGame:
			this->running = false;

			cout << endl;
			cout << "You won " << this->matchesWon << " and lost " << this->matchesLost << " matches" << endl;
			
			break;
		}
	}
}

void Game::runGame()
{
	int maxPoints = Util::readInt("How many turns (min turns: 3)? ", 3);
	int playerPoints = 0;
	int aiPoints = 0;

	while (playerPoints < maxPoints && aiPoints < maxPoints)
	{
		Choice playerChoice;
		Choice aiChoice;
		
		cout << endl;
		cout << "Rock, Paper or Scissors?" << endl;
		
		playerChoice = Util::readEnum<Choice>("Make your choice [1-3]: ", Choice::Rock, Choice::Scissors, -1);
		aiChoice = this->makeAiChoice();

		string* sPlayerChoice = this->choiceToStr(playerChoice);
		string* sAiChoice = this->choiceToStr(aiChoice);

		int comparison = this->compareChoice(playerChoice, aiChoice);

		if (comparison < 0)
		{
			playerPoints++;

			cout << "Player wins! (Player Points: " << playerPoints << "; AI Points: " << aiPoints << ")" << endl;
			cout << *sPlayerChoice << " beats " << *sAiChoice << endl;
		}
		else if (comparison > 0)
		{
			aiPoints++;

			cout << "AI wins! (Player Points: " << playerPoints << "; AI Points: " << aiPoints << ")" << endl;
			cout << *sAiChoice << " beats " << *sPlayerChoice << endl;
		}
		else
		{
			cout << "Draw! (Player Points: " << playerPoints << "; AI Points: " << aiPoints << ")" << endl;
			continue;
		}

		delete sPlayerChoice;
		delete sAiChoice;
	}

	if (playerPoints >= 3)
		this->matchesWon++;
	else if (aiPoints >= 3)
		this->matchesLost++;
}

LoopChoice Game::showMenu()
{
	cout << "[ Menu ]" << endl;
	cout << "1) New Game" << endl;
	cout << "2) Quit Game" << endl;
	
	return Util::readEnum<LoopChoice>("Select [1-2]: ", LoopChoice::NewGame, LoopChoice::QuitGame, -1);
}

Choice Game::makeAiChoice()
{
	int random = rand() % 3;
	Choice c = static_cast<Choice>(random);

	return c;
}

int Game::compareChoice(Choice a, Choice b)
{
	// Paper
	if (a == Choice::Paper && b == Choice::Paper)
		return 0;
	else if (a == Choice::Paper && b == Choice::Rock)
		return -1;
	else if (a == Choice::Paper && b == Choice::Scissors)
		return 1;

	// Rock
	else if (a == Choice::Rock && b == Choice::Paper)
		return 1;
	else if (a == Choice::Rock && b == Choice::Rock)
		return 0;
	else if (a == Choice::Rock && b == Choice::Scissors)
		return -1;

	// Scissors
	else if (a == Choice::Scissors && b == Choice::Paper)
		return -1;
	else if (a == Choice::Scissors && b == Choice::Rock)
		return 1;
	else if (a == Choice::Scissors && b == Choice::Scissors)
		return 0;
	else
		return 0;
}

string* Game::choiceToStr(Choice c)
{
	switch (c)
	{
	case Choice::Rock:
		return new string("Rock");
		break;

	case Choice::Paper:
		return new string("Paper");
		break;

	case Choice::Scissors:
		return new string("Scissors");
		break;

	default:
		return new string("Florian");
		break;
	}
}
