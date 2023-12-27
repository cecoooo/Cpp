#include "UserCount.h"

int UserCount::userCount = 0;

int UserCount::getUserCount()
{
	return userCount;
}
void UserCount::increaseUserCount()
{
	userCount++;
}