#pragma once

template<class T> inline T operator~ (T a) { return (T)~(int)a; }
template<class T> inline T operator| (T a, T b) { return (T)((int)a | (int)b); }
template<class T> inline T operator& (T a, T b) { return (T)((int)a & (int)b); }
template<class T> inline T operator^ (T a, T b) { return (T)((int)a ^ (int)b); }
template<class T> inline T& operator|= (T& a, T b) { return (T&)((int&)a |= (int)b); }
template<class T> inline T& operator&= (T& a, T b) { return (T&)((int&)a &= (int)b); }
template<class T> inline T& operator^= (T& a, T b) { return (T&)((int&)a ^= (int)b); }

enum class InventoryItems
{
	Knife		= 1,	// 0000 0001
	Lantern		= 2,	// 0000 0010
	Pistol		= 4,	// 0000 0100
	MagicCube	= 8,	// 0000 1000
	Hammer		= 16,	// 0001 0000
};

class Inventory
{
private:
	InventoryItems items;

public:
	Inventory();

	bool has_item(InventoryItems item);
	void add_item(InventoryItems item);
	void del_item(InventoryItems item);
};
