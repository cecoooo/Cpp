#pragma once
#include "Item.h"

class Material : public Item
{
public:
	virtual ~Material() = 0;
	virtual string materialType();
	string itemType() override;
};