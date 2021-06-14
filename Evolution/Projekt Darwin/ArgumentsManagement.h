#pragma once
#include <iostream>
#include "Defines.h"
using namespace std;

/*
Check of correctness of given arguments.
@param argc Number of arguments.
@param argv[] Array of arguments.
@param orderArgs Output array of correct arguments
@result true - Arguments are correct.
		false - Arguments aren't correct.
*/
bool checkArgs(int argc, char *argv[], char **orderArgs);