#include "CommanderProfile.h"
#include "AllUnits.h"

extern string provinceResourcesNames [5];
extern string troopNames [5];
extern int turn;

/*Constructors*/
CommanderProfile::CommanderProfile()
{
    for (int x = 0; x < 20; x++)
    {
        commanderArmyStats[x] = 0;
    }
    commanderIdentifier = '0';
    commanderLevel = 1;
    for (int x = 0; x < 22; x++)
    {
        commanderScoutReport[x] = 0;
    }
    hasMoved = 'N';
    maxTroops = 0;
    totalMaxResources = 0;
    indexInList = 0;
}
CommanderProfile::CommanderProfile(int level, char identifier, int index)
{
    for (int x = 0; x < sizeof(commanderScoutReport) / sizeof(int); x++)
    {
        commanderScoutReport[x] = 0;
    }

    commanderLevel = level;
    commanderIdentifier = identifier;

    for (int x = 0; x < 5; x++)
    {
        commanderArmyStats[x] = &resourcesPresent[x];
        commanderArmyStats[x + 5] = &troopsPresent[x];
        commanderArmyStats[x + 10] = &troopsInjured[x];
    }
    commanderArmyStats[15] = &totalTroops;
    commanderArmyStats[16] = &totalCP;
    commanderArmyStats[17] = &commanderLevel;
    commanderArmyStats[18] = &maxTroops;
    commanderArmyStats[19] = &foodConsumption;

    for (int x = 0; x < 5; x++)
    {
        namesOfMAN[x] = provinceResourcesNames[x];
        namesOfMAN[x + 5] = troopNames[x];
        namesOfMAN[x + 10] = troopNames[x];
    }
    namesOfMAN[15] = "Total Troops";
    namesOfMAN[16] = "Total Army CP";
    namesOfMAN[17] = "Commander Level";
    namesOfMAN[18] = "Max Troops this army can have";
    namesOfMAN[19] = "Army Food consumption";
    maxTroops = commanderLevel * 10;
    totalMaxResources = 0;
    indexInList = index;
}
/*Destructor*/
CommanderProfile::~CommanderProfile()
{

}

/*Accessor Functions*/
char CommanderProfile::getCommanderIdentifier()
{
    return commanderIdentifier;
}
void CommanderProfile::printCommanderStats()
{
    //print out stats
    cout << "\033[;34m";
    int c = 0;
    for (int a = 0; a < 4; a++)
    {
        std::cout << MANDescriptions[a] << " this army: " << endl;
        for (int b = 0; b < 5; b++)
        {
            std::cout << "- " << namesOfMAN[c] << ": " << commanderArmyStats[c] << endl;
            c++;
        }
    }
    cout << endl;
    cout << "\033[;0m";
}
int CommanderProfile::getCommanderStat(int index)
{
    return *commanderArmyStats[index];
}
int CommanderProfile::printCommanderScoutReport(int index)
{
    return commanderScoutReport[index];
}
int CommanderProfile::getCommanderLevel()
{
    return commanderLevel;
}
char CommanderProfile::hasCommanderMoved()
{
    return hasMoved;
}

/*Mutator Functions*/
void CommanderProfile::changeCommanderCoordinates(int xCoordinate, int yCoordinate)
{

}
void CommanderProfile::changeCommanderStat(int index, int amount)
{
    commanderArmyStats[index] += amount;
}
void CommanderProfile::changeCommanderIdentifier(char identifier)
{
    commanderIdentifier = identifier;
}
void CommanderProfile::changeCoordinates(int xCoordinate, int yCoordinate)
{
    unitXCoordinate = xCoordinate;
    unitYCoordinate = yCoordinate;
}
void CommanderProfile::updateCommanderScoutReport(int index, int value)
{
    commanderScoutReport[index] = value;
}
void CommanderProfile::addCommanderLevel(int amount)
{
    commanderLevel += amount;
}
void CommanderProfile::resetCommanderMoved()
{
    hasMoved = 'N';
}

void CommanderProfile::completeCommanderScoutReport(int accuracy)
{
    /*Higher accuracy = more accurate scout log-- default is 50% accuracy (if there are 10 food resources in a province,
    the margin is 50%-- 5-15 units. 100 accuracy is the most accurate, 0 accuracy is the least accurate*/
    double newAccuracy = (double)accuracy / 100;
    newAccuracy = 1 - newAccuracy;
    double accuracyAdjustedValueOne;
    int accuracyAdjustedValueTwo;
    int fooOne;
    int fooTwo;
    int findRange;
    srand(time(NULL));
    for (int x = 0; x < 20; x++)
    {
        findRange = getCommanderStat(x);
        accuracyAdjustedValueOne = findRange * newAccuracy;
        fooOne = findRange - (int)accuracyAdjustedValueOne;
        fooTwo = findRange + (int)accuracyAdjustedValueOne;
        accuracyAdjustedValueTwo = rand() % fooOne + fooTwo;
        updateCommanderScoutReport(x, accuracyAdjustedValueTwo);
    }
    updateCommanderScoutReport(20, turn);
    updateCommanderScoutReport(21, accuracy);
}