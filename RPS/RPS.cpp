#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include "Inventory.h"

using namespace std;

void fileInputOutputTest()
{
    ofstream fileOut;
    fileOut.open("test.txt", ios::out);

    if (fileOut.is_open())
    {
        fileOut << "Hello World!" << endl;
        fileOut.close();
    }
    else
    {
        cerr << "Failed to open file!";
    }

    ifstream fileIn;
    fileIn.open("test.txt", ios::in);

    if (fileIn.is_open())
    {
        string line;
        while (getline(fileIn, line))
        {
            cout << line;
        }
    }
    else
    {
        cerr << "Failed to open file!";
    }
}

int main(void)
{
    Game* game = new Game;
    game -> gameLoop();
    delete game;

    return EXIT_SUCCESS;
}
