#include "CarrierCount.h"

int CarrierCount::carrierCount=0;

int CarrierCount::getCarrierCount() 
{
	return carrierCount;
}
void CarrierCount::increaseCarrierCount()
{
	carrierCount++;
}