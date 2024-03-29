#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <thread>
#include <time.h>
#include <vector>

#include "textFunctions.h"
#include "ConstValues.h"

extern int continentSize;
extern ConstValues CV;
extern int currentParticipantIndex;

class OtherFunctions {
public:
  OtherFunctions();

  // Check input-- maybe use template for this?
  std::string getInput(std::string text, std::vector<std::string> AV, bool redo);

  // Map stuff
  int translateCoordinate(int coordinate, char indicator, char whichWay);
  int translateCoordinateInput(int coordinate, char indicator);
  int translateCoordinateOutput(int coordinate, char indicator);

  // Name Functionality
  std::string createRandomName();

  // Other stuff
  void clearScreen();
  std::string printCoordinates(std::array<int, 2> coordinates);

  std::vector<int> addVectors(std::vector<int> primeVector, std::vector<int> secondaryVector);
  std::vector<int> subtractVectors(std::vector<int> primeVector, std::vector<int> secondaryVector);
  std::array<int, 5> modifyArray(std::array<int, 5> primeArray, std::array<int, 5> secondaryArray, bool isAdd);
  void printResources(std::array<int, 5> resourcesArray);

	void enterAnything ();

private:
};

#endif