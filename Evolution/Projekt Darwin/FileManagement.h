#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include "Defines.h"
using namespace std;

/*
Check if given string is a number.
@param s Given string.
@return true - Given string is a number.
		false - Given string isn't a number.
*/
bool isNumber(string s);

/*
Annoucement of sucess of reading a file.
@param errorHandling Variable used as status of correctness of input file.
@return true - Input file is correct.
		false - Input file isn't correct.
*/
bool errorHandle(int errorHandling);

/*
Reading of input file.
@param errorResult Variable used as status of reading of input file
@param fileName Name of input file.
@return Container with the data assigned from input file.
*/
vector<vector<int>> readFile(int &errorResult, string fileName);

/*
Creation of output file with indiviuals' data.
@param mainContainer Container with closing data.
@param fileName Name of output data file.
*/
void writeFile(vector<vector<int>> mainContainer, string fileName);

/*
Creation of output file with log data.
@param logContainer Container with log data.
@param fileName Name of output log file.
*/
void writeLogFile(list<logPart> logContainer, string fileName);