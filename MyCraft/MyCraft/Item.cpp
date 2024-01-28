#include "Item.h"

int Item::getCurrentLevel() 
{
	return currentLevel;
}

void Item::increaseCurrentLevel(int value)
{
	this->currentLevel += value;
}

void Item::decreaseCurrentLevel(int value)
{
	this->currentLevel -= value;
}