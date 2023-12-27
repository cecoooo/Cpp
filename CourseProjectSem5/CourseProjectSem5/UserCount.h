#pragma once
class UserCount
{
private:
	static int userCount;
protected:
	static int getUserCount();
	static void increaseUserCount();
};

