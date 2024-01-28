#pragma once
#include "Item.h"

class Instrument : public Item
{
public:
	virtual ~Instrument() = 0;
	virtual string instrumentType();
	string itemType() override;
};