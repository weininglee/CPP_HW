#ifndef Train_H 
#define Train_H 
#include "Car.h"
#include <math.h>
#include <iomanip>

class Train
{
private:
	Car car;
	int carN;
public:
	Train() : car(),carN(0) {}

	void inputTrain() {
		cin >> carN;
		car.inputCar();
	}

	double getVolume() {
		//cout << fixed << setprecision(2) << car.getVolume() * carN << endl;
		return car.getVolume() * carN;
	}

	void printTrain() {
		cout << fixed << setprecision(0) << floor(getVolume()) << endl;
	}
};

#endif // Train_H 