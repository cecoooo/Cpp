#include "Toolbox.h"

Toolbox::~Toolbox() 
{
	for (size_t i = 0; i < items.size(); i++)
		delete items[i];
}

vector<Item*> Toolbox::getItems() 
{
	return this->items;
}

void Toolbox::setItems(vector<Item*> itms) 
{
	this->items = itms;
}

void Toolbox::addItem(Item* itm)
{
	this->items.push_back(itm);
}