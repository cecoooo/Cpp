#pragma once
class UserCount
{
private:
	static int userCount;
protected:
	static void increaseUserCount();
public:
	static int getUserCount();
};

