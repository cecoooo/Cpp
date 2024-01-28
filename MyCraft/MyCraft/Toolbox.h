#pragma once
#include <vector>
#include "Item.h"

using std::vector;

class Toolbox
{
private:
	vector<Item*> items;
public:
	~Toolbox();
	vector<Item*> getItems();
	void setItems(vector<Item*> itms);
	void addItem(Item* itm);
};

