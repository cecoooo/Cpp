#pragma once
class UserCount
{
private:
	static int userCount;
	static int getLatestUserId();
protected:
	static void increaseUserCount();
public:
	static int getUserCount();
};

