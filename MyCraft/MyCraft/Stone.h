#pragma once
#include "Material.h"

class Stone : public Material
{
public:
	string materialType() override;
};

