#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "Algorithm.h"
#include "FileManagement.h"
#include "ArgumentsManagement.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Allocating memory for ordered args and filling them with nullptr
	char **orderArgs = new char*[argc-1];
	for (int i = 0; i < (argc - 1); i++) {
		orderArgs[i] = nullptr;
	}

	//Check if arguments exist.
	if (!checkArgs(argc, argv, orderArgs))
	{
		delete[] orderArgs;
		return 0;
	}

	//Variable to check errors.
	int errorHandling = 0;

	/*Varaibles of numbers*/
	//Value of vanishing factor.
	float vanishFactor = atof(orderArgs[7]);
	//Value of reproducting factor.
	float reproductFactor = atof(orderArgs[9]);
	//Number of generations.
	int generationsCount = atoi(orderArgs[11]);
	//Number of pairs to crossbreed.
	int crossingCouples = atoi(orderArgs[13]);

	//Creation of main container and assignment of data to it from file.
	vector<vector<int>> mainContainer = readFile(errorHandling, orderArgs[1]);
	//List with log information
	list<logPart> logContainer;

	//If file is correct.
	if (errorHandle(errorHandling)) 
	{
		//Seed of random generator.
		srand(time(NULL));

		//Transition to algorithm - handling of generations.
		generationProgress(mainContainer, logContainer, vanishFactor, reproductFactor, generationsCount, crossingCouples);

		writeLogFile(logContainer, orderArgs[5]);
		//Creation of new file with closing data.
		writeFile(mainContainer, orderArgs[3]);
	}

	return 0;
}