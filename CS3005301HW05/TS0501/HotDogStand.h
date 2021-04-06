#pragma once
#include <iostream>

using namespace std;
class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	char *standId;
	int hotDogSellAmount = 0;
	static int totalSellAmount;
};

