#pragma once

class CarrierCount
{
private:
	static int carrierCount;
	static int getLatestCarrierId();
protected:
	static void increaseCarrierCount();
public:
	static int getCarrierCount();
};

