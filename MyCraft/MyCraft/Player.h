#pragma once
#include "Hero.h"
#include "Toolbox.h"

class Player : public Hero
{
private:
	Toolbox *toolbox;
public:
	~Player();
	void Move() override;
	void Rotate() override;
	Toolbox* getToolbox();
};