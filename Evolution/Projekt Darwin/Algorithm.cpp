#include "Algorithm.h"

//Calculation of strength of individual.
float elementStrength(vector<int> element) 
{
	
	//Temporary variable sum.
	float sum = 0;

	//Loop adding up individuals' code.
	for (int i = 0; i < element.size(); i++)
	{
		sum += (float)element[i];
	}

	//Loop dividing sum to make fraction from it.
	while (sum > 1)
	{
		sum = sum / 10;
	}

	return sum;
}

//Extermination of weak elements of population.
void naturalSelection(vector<vector<int>> &mainContainer, logPart &log, float vanishFactor, float reproductFactor)
{
	//Temporary container.
	vector<vector<int>> tmp;

	//Count of all individuals in generation.
	log.elements = mainContainer.size();

	//Extermination loop.
	for (int i = 0; i < mainContainer.size(); i++) 
	{
	
		//Strength of given element.
		float strength = elementStrength(mainContainer[i]);

		//Element is stronger or equal then vanishing factor.
		if (strength >= vanishFactor) 
		{
			//Copy element to temporary container
			tmp.push_back(mainContainer[i]);

			//If element is stronger or equal then reproduct factor.
			if (strength >= reproductFactor) 
			{
				//Copy element again.
				tmp.push_back(mainContainer[i]);
				//Count element as cloned to log.
				log.cloned = log.cloned + 1;
			}
			//If element isn't stronger or equal then reproduct factor.
			else
			{
				//Count element as alive to log.
				log.alive = log.alive + 1;
			}
		}
		//Element is weaker than vanishing factor.
		else
		{
			//Count element as dead to log.
			log.died = log.died + 1;
		}
	}

	//Clear main container.
	mainContainer.clear();

	//Loop adding data from temporary container to main one.
	for (int j = 0; j < tmp.size(); j++) 
	{
		mainContainer.push_back(tmp[j]);
	}
}

//Crossbreed of random pairs.
void crossBreeding(vector<vector<int>> &mainContainer, int crossingCouples)
{
	
	//Variable with size of population.
	int populationSize = mainContainer.size();

	//Temporary container.
	vector<vector<int>> tmp;

	//Loop crossbreeding random elements.
	for (int i = 0; i < crossingCouples; i++)
	{

		//Temporary containers with copy of random elements.
		vector<int> v1 = mainContainer.at(rand() % populationSize);
		vector<int> v2 = mainContainer.at(rand() % populationSize);
		//Empty temporary container.
		vector<int> v3;

		//Size of temporary containers.
		int v1Size = v1.size();
		int v2Size = v2.size();
		//Adjusting and stable pointers to the breakPtr point.
		int breakPtr, pointer = 0;

		//Creating random breakPtr point of first cointainer.
		breakPtr = (rand() % v1Size);
		pointer = breakPtr;
		//Coping loop of container's tail to empty one.
		for (breakPtr; breakPtr < v1Size; breakPtr++) 
		{
			v3.push_back(v1[breakPtr]);
		}

		//Shrinking of cointainer to pointer size.
		v1.resize(pointer);

		//Creating random breakPtr point of second cointainer.
		breakPtr = (rand() % v2Size);
		pointer = breakPtr;
		//Coping loop of container's tail to first one.
		for (breakPtr; breakPtr < v2Size; breakPtr++) 
		{
			v1.push_back(v2[breakPtr]);
		}
		
		//Shrinking of cointainer to pointer size.
		v2.resize(pointer);

		////Coping loop of container's tail to second one.
		for (breakPtr = 0; breakPtr < v3.size(); breakPtr++) 
		{
			v2.push_back(v3[breakPtr]);
		}

		//Clearing of third one.
		v3.clear();

		//Adding temporary containers to other one.
		tmp.push_back(v1);
		tmp.push_back(v2);
	}

	//Coping loop to main container.
	for (int i = 0; i < tmp.size(); i++) 
	{
		mainContainer.push_back(tmp[i]);
	}
}

//Managing of generations progress.
void generationProgress(vector<vector<int>> &mainContainer, list<logPart> &logContainer, float vanishFactor, float reproductFactor, int generationsCount, int crossingCouples)
{	
	//Main algorithm loop - progress of generations.
	for (int i = 0; i < generationsCount; i++) 
	{
		//Creation of each generation log.
		logPart log;
		//Number of generation.
		log.no = i+1;
		//Number of individuals in current generation.
		log.elements = 0;
		//Number of dead indiviuals.
		log.died = 0;
		//Number of alive individuals.
		log.alive = 0;
		//Number of cloned individuals.
		log.cloned = 0;

		//If any of individuals are alive.
		if (mainContainer.size() > 0) 
		{
			crossBreeding(mainContainer, crossingCouples);
			naturalSelection(mainContainer, log, vanishFactor, reproductFactor);
		}

		//Creation of generation log with data.
		logContainer.push_back(log);
	}
}