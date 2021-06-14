#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Defines.h"
using namespace std;

/*
Calculation of strength of individual.
@param element Vector with individual's code.
@return Value of strength.
*/
float elementStrength(vector<int> element);

/*
Extermination of weak elements of population.
@param mainContainer Container with data.
@param log Structure to get info for log.
@param vanishFactor Value of vanishing factor.
@param reproductFactor Value of reproducting factor.
*/
void naturalSelection(vector<vector<int>>& mainContainer, logPart &log, float vanishFactor, float reproductFactor);

/*
Crossbreed of random pairs.
@param mainContainer Container with data.
@param crossingCouples Number of pairs to crossbreed.
*/
void crossBreeding(vector<vector<int>> &mainContainer, int crossingCouples);

/*
Managing of generations progress.
@param mainContainer Container with data.
@param logContainer List of logs with generation info.
@param vanishFactor Value of vanishing factor.
@param reproductFactor Value of reproducting factor.
@param generationsCount Number of generations.
@param crossingCouples Number of pairs to crossbreed.
*/
void generationProgress(vector<vector<int>> &mainContainer, list<logPart> &logContainer, float vanishFactor, float reproductFactor, int generationsCount, int crossingCouples);
