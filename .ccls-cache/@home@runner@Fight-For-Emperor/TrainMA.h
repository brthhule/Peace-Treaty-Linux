#include <iostream>
#include <iostream>
#include <vector>

#include "Units.h"
#include "textFunctions.h"
#include "coordinateFunctions.h"
#include "Lists.h"

class TrainMA
{
public:
	//constructor
	TrainMA(Provinces *newP);
	//other functions
	void TrainMAFunction();
	vector <Provinces*> getTrainProvince();
private:
	Provinces *province;
};

