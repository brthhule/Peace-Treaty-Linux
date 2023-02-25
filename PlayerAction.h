#ifndef PLAYERACTION_H
#define PLAYERACTION_H

#include <iostream>
#include <cmath>

#include "Participants.h"
#include "Lists.h"
#include "BuildMA.h"
#include "TrainMA.h"
#include "OtherFunctions.h"
#include "ArmyDeploymentMA.h"
#include "MapMA.h"

class PlayerAction
{
public:
	PlayerAction();
	PlayerAction(Participants *newP);
	char randomAction();
	int initialDecision();
private:
	Participants *participant;
};

#endif