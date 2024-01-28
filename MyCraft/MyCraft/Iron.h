#pragma once
#include "Material.h"

class Iron : public Material
{
public:
	string materialType() override;
};