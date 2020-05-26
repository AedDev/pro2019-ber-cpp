#include "Inventory.h"

Inventory::Inventory()
{
	this->items = static_cast<InventoryItems>(0);
}

bool Inventory::has_item(InventoryItems item)
{
	return (bool)((int)(this->items & item) != 0);
}

void Inventory::add_item(InventoryItems item)
{
	this->items |= item;
}

void Inventory::del_item(InventoryItems item)
{
	this->items &= ~item;
}
