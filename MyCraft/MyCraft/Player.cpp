#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

Player::~Player() 
{
	if(toolbox != NULL)
		delete toolbox;
}

void Player::Move()
{
	cout << "Player moves." << endl;
}

void Player::Rotate()
{
	cout << "Player rotates." << endl;
}

Toolbox* Player::getToolbox()
{
	return this->toolbox;
}