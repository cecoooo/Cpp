#pragma once
#include <string>
using std::string;

class Item
{
private:
	int currentLevel = 0;
public:
	virtual ~Item();
	virtual string itemType();
	int getCurrentLevel();
	void increaseCurrentLevel(int value);
	void decreaseCurrentLevel(int value);
};