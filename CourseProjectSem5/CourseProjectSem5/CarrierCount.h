#pragma once
class CarrierCount
{
private:
	static int carrierCount;
protected:
	static void increaseCarrierCount();
public:
	static int getCarrierCount();
};

