#include <iostream>
#include "Game.h"
#include "Inventory.h"

int main(void)
{
    //Game* game = new Game;
    //game -> gameLoop();
    //delete game;

    Inventory i;
    cout << "Pistol? " << (i.has_item(InventoryItems::Pistol) ? "Yes" : "No") << endl;
    i.add_item(InventoryItems::Pistol);
    cout << "Pistol? " << (i.has_item(InventoryItems::Pistol) ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}
