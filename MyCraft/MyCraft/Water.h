#pragma once
#include "Material.h"

class Water : public Material
{
public:
	string materialType() override;
};