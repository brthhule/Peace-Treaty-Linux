#include "MapMA.h"
#define print(x) std::cout << x;
#define println(x) std::cout << x << std::endl;
#define part() getParticipantIndex()



MapMA::MapMA(Participants *newParticipant) { participant = newParticipant;
pIndex = participant->getParticipantIndex();}

void MapMA::viewPlayerMap() {
  char whatToDo = ' ';
	
  if (participant->isPlayer())
  {
    participant->showMap();
    println("Welcome to the View Map action menu");

		whatToDo = OF.getInput("showOptions, 8", {}, false).at(0);
  }
  else
    whatToDo = 'P';
  

  switch (whatToDo) {
  case 'P': {
		OF.clearScreen();
		std::cout << "Selecting a province...\n";
    Provinces *province = participant->getYourProvince(1);
		
    if (province->deleteStatus() != true) {
      selectUnitOriginal(province);
    }
    viewPlayerMap();
    break;
  }
  case 'H': {
    showHelp(8);
    viewPlayerMap();
    break;
  }
  default:
    println("Returning to the previous menu.");
    std::cout << std::endl;
    break;
  }
}

Participants *MapMA::getParticipant() { return participant; }

void MapMA::selectUnitOriginal(Provinces *selectedProvince) {
	prov = selectedProvince;
  if (prov->part() == pIndex) // If belongs to participant
  {
    selectPlayerProvince();
  }
	else if (prov->part() == -1) // If empty province
  {
    if (prov->commandersNum() >
        0) // If there are more than 0 commnaders
    {
			//If the commander here is yours
      if (prov->getCommander(0)->getParticipantIndex() == pIndex)
      {
        playerUnitAction(prov);
      } 
			//If the commander here is an emey
			else {
        selectEnemyAction();
      }
    }
		
  } 
	else // If enemy province
  {
    selectEnemyProvince(prov);
  }
}
void MapMA::selectPlayerProvince() {
  if (prov->isCapital()) {
    print("This is your capital province ");
  } else {
    print ("This is one of your provinces ");
    ;
  }
  std::cout << std::endl << std::endl;

  char selectPlayerCapitalAction = getOption(9);

  switch (selectPlayerCapitalAction) {
  case 'B': {
    BuildMA newBuildMA(prov, participant);
    newBuildMA.playerBuildFunction();
    break;
  }
  case 'T': {
    TrainMA newTrainMA(participant);
    newTrainMA.TrainMAFunction();
    break;
  }
  case 'M':
    std::cout << "Returning to the map..." << std::endl;
    std::cout << std::endl;
    break;
  }
}


void MapMA::selectEnemyProvince(Provinces *newP) {
  Provinces *enemyProvince = newP;
	if (enemyProvince->isCapital()) {
    println("This is an enemy capital province ");
  } else {
    println("This is one of the enemy's provinces");
  }

  println("\n\nWelcome to the Enemy Provinces Action Selection menu ");
	
  char selectUnitEnemyProvinceChar = getOption(10);

  switch (selectUnitEnemyProvinceChar) {
  case 'A': {
    AttackMA newAttackMA(enemyProvince, participant);
		//selectEnemyProvince(enemyProvince);
    break;
  }
  case 'S': {
    ScoutMA newScout(participant, enemyProvince);
    newScout.selectTarget();
		//selectEnemyProvince(enemyProvince);
    break;
  }
  case 'V': {
    if (enemyProvince->getScoutReportTurn() != -1)
      if (OF.getInput("View scout log for this province? (Y/N) ", {"Y", "N"}, 1).at(0) ==
          'Y')
        scoutLogFunction(enemyProvince);
		
		selectEnemyProvince(enemyProvince);
    break;
  }
  case 'M':
    std::cout << "Returning to the menu... " << std::endl;
    break;
  }
}

//Get the commander that's here 
void MapMA::playerUnitAction(Provinces *newP) {
	Provinces *newProvince = newP;
  println("This is one of your armies ");
	
	switch (getOption(2)) {
	case 'P': //Move this unit
	{
		playerUnitActionP(newProvince);
		break;
	}
	case 'H':
	{
		showHelp(2);
		playerUnitAction(newProvince);
		break;
	}
	case 'M':
		std::cout << "Returning to menu... \n" ;
		break;
	}
}

void MapMA::playerUnitActionP(Provinces *newP)
{
	Provinces *newProvince = newP;
	std::cout << "The following commanders are at this province: \n";
	newProvince -> printCommanders();
	// find index of commander unit, fix this
	std::string commanderName = " ";
	std::cout << "\nEnter the name of the commander you would like to select: ";
	getline(std::cin, commanderName);
	if (newProvince->hasCommander(commanderName) == false)
	{
		std::cout << "Invalid name entered; please try again...";
		playerUnitAction(newProvince);
	}
	
	if (participant->getCommanderByName(commanderName)->hasMovedQuestion() == false) {
		Mobility newMobility (commanderName, participant);
		newMobility.moveUnitOne(); /*fix this*/
		playerUnitAction(newProvince);
	} 
	else
	{
		println("This unit has already moved this turn... returning to the View Map action menu \n");
	}
}




void MapMA::selectEnemyAction() /*Add implementation*/
{
  std::cout << "This is an enmy army. \n";

	switch (getOption(1))
	{
		case 'A':
			break;
		case 'S':
			break;
		case 'H':
			break;
		case 'M':
			break;
	}
}

void MapMA::scoutLogFunction(Provinces* enemyProvince) {
  char repeatScoutLog = 'N';
  char whatReportChar;

  std::cout << "Turn of scout report: " << enemyProvince->getScoutReportTurn() << "; Level of report: " << enemyProvince -> getScoutLogTurnLevel() << "\n\n";
  do 
	{
    whatReportChar = getOption(11);
    provinceReportLog(whatReportChar, enemyProvince);
  } while (repeatScoutLog == 'Y');
}
void MapMA::provinceReportLog(char whatReportChar, Provinces* enemyProvince) {
  int totalGarrisonedCP = 0;
  switch (whatReportChar) {
  case 'G': {
    std::cout << "Garrisoned troops: " << std::endl;
    for (int x = 0; x < 5; x++) {
      std::cout << "-" << CV.TROOP_NAMES[x] << ": "
                << enemyProvince->getTroopsPresent(x)
                << std::endl;
      totalGarrisonedCP +=
          (enemyProvince->getTroopsPresent(x) *
           CV.TROOPS_CP[x]);
    }
    std::cout << "Total Garrison Combat Power: " << totalGarrisonedCP << std::endl
              << std::endl;
    break;
  }
  case 'R':
    enemyProvince->printResources();
    break;
  case 'B':
    enemyProvince->printBuildingStats();
    break;
  case 'M':
    break;
  }
}
