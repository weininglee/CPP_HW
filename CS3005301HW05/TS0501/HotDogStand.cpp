#include "HotDogStand.h"


int HotDogStand::totalSellAmount = 0;
HotDogStand::HotDogStand()
{
}

HotDogStand::HotDogStand(const char * id)
{
	standId= const_cast<char*>(id);
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	standId = const_cast<char*>(id);
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	hotDogSellAmount += 1;
	totalSellAmount += 1;
}

void HotDogStand::print()
{
	cout << standId << " " << hotDogSellAmount << endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
