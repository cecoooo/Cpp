#pragma once
class Hero
{
public:
	virtual ~Hero() = 0;
	virtual void Move() = 0;
	virtual void Rotate() = 0;
};

