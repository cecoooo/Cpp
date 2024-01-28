#pragma once
#include "Hero.h"

class Animal : public Hero
{
public:
	void Move() override;
	void Rotate() override;
};