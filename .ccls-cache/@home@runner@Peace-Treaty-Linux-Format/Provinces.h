#ifndef PROVINCES_H
#define PROVINCES_H

#include <iostream>
#include <unordered_map>

#include "AllUnits.h"
#include "CommanderProfile.h"
#include "ConstValues.h"

extern ConstValues CV;

extern int continentSize;
extern const int BARRACKS_PRODUCTION;
extern int turn;

const int LOG_SIZE = 20;

class Provinces : public AllUnits {
public:
  /*Constructors*/
  Provinces();
  Provinces(int xCoordinate, int yCoordinate, int pIndex);
	void basicStats();

	/*Initialization*/
	bool isCapital(){return isACapital;}
	void setCoordinates(int xCoordinate, int yCoordinate);
  void initializeCapital(); // provinceIsACapital

	/*Province Identity*/
	int getCoordinate(char identifier);
  bool deleteStatus();
	std::string getProvinceName();
  void setDeleteProvince() { deleteProvince = true; }

  /*Garrisons*/
  int getMaxGarrison();
	int getMaxInfirmaryCapacity();


	//Buildings
  int findMaxInfirmaryCapacity() { return (otherBuildingsLevels[1] * 10); };
  int getBuildingLevel(int index);
  void increaseBuildingLevel(int index, int amount);


  // Commanders
  CommanderProfile* getCommander (std::string name);
  int findProvinceLevel();
  void addCommander(CommanderProfile *newCommander);
	void removeCommander(CommanderProfile *newCommander);
	std::vector <CommanderProfile*> getAllCommanders();
	int commandersNum(){return commanders.size();}
	void printCommanders ();
	bool hasCommander (std::string name);

	/*Training*/
  int getTroopsTrainedThisTurn() { return troopsTrainedThisTurn; };
  void addTroopsTrainedThisTurn(int amount);
  void resetTroopsTrainedThisTurn();



	/*Resources*/
	bool subtractCheckResources(std::array<int, 5> resourcesArray);
  std::array<int,5> getTotalResources();

	/*Stats*/
  void printBuildingStats();
	int getTotalCP ();
	void updateBuildingsProduction();
  void updateProvinceResources();

	/*Scout Stuff*/
	void completeProvinceScoutReport(int accuracy, Provinces* targetProvince, int scoutTurn);
	int getEstimate(int newAccuracy, int quantity);
	int getScoutReportTurn(){return scoutReportTurn;}
	int getScoutLogTurnLevel(){return scoutReportLogLevel;}
	std::array<int,5> getResourceBuildingLevels();
	std::array<int,5> getResourceBuildignsProduction();
	std::array<int,5> getOtherBuildingsLevels ();
	int getBarracksCapacity();
	int getBarracksLevel(){return *barracksLevel;}
	std::array<int,5> getMaxResources();

	
private:
	/*Garrison*/
  int maxGarrison;//derived
  int maxInfirmaryCapacity;//derived

	std::array<int, 5> resourceBuildingsLevels;
	std::array<int, 5> resourceBuildingsProduction;
	std::array<int, 5> otherBuildingsLevels;// Barracks, infirmary, Library, wall, residences
	int* barracksLevel = &otherBuildingsLevels[0];
	int* infirmaryLevel = &otherBuildingsLevels[1];
	int* libraryLevel = &otherBuildingsLevels[2];
	int* wallLevel = &otherBuildingsLevels[3];	
	int* residencesLevel = &otherBuildingsLevels[4];

	int barracksCapacity;//derived
	
  std::array<int,5> maxResources;//derived
  int totalMaxResources;//derived

  int troopsTrainedThisTurn;//variable
  int foodConsumption;//variable

  bool isACapital;//stat

  bool deleteProvince;//conditional

	std::unordered_map<std::string, CommanderProfile*> commanders;
	std::unordered_map<std::string, CommanderProfile*>::iterator it;

	int scoutReportTurn;
	int scoutReportLogLevel;
	int logAccuracy;
	double newAccuracy;
};

#endif