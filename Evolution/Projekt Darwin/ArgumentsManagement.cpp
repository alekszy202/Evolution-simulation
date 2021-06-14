#include "ArgumentsManagement.h"

//Check of correctness of given arguments.
bool checkArgs(int argc, char *argv[], char **orderArgs)
{
	switch (argc)
	{
		//Main argument management
		case 15:
		{
			//Loop through all args
			for (int i = 1; i < argc; i++)
			{
				//Input file
				if (strcmp(argv[i], "-i") == 0)
				{
					orderArgs[0] = argv[i];

					int iLen = strlen(argv[i + 1]);
					if (iLen >= 4 && strcmp(&(argv[i + 1])[iLen - 4], ".txt") == 0)
					{
						orderArgs[1] = argv[i + 1];
					}
					else
					{
						cerr << "File input is not .txt!: " << argv[i + 1] << "\n";
					}
				}

				//Output file
				if (strcmp(argv[i], "-o") == 0)
				{
					orderArgs[2] = argv[i];

					int iLen = strlen(argv[i + 1]);
					if (iLen >= 4 && strcmp(&(argv[i + 1])[iLen - 4], ".txt") == 0)
					{
						orderArgs[3] = argv[i + 1];
					}
					else
					{
						cerr << "File input is not .txt!: " << argv[i + 1] << "\n";
					}
				}

				//Log file
				if (strcmp(argv[i], "-l") == 0)
				{
					orderArgs[4] = argv[i];

					int iLen = strlen(argv[i + 1]);
					if (iLen >= 4 && strcmp(&(argv[i + 1])[iLen - 4], ".txt") == 0)
					{
						orderArgs[5] = argv[i + 1];
					}
					else
					{
						cerr << "File input is not .txt!: " << argv[i + 1] << "\n";
					}
				}


				//Vector of vanishing
				if (strcmp(argv[i], "-w") == 0)
				{
					orderArgs[6] = argv[i];

					if (atof(argv[i + 1]) != 0)
					{
						orderArgs[7] = argv[i + 1];
					}
					else
					{
						cerr << "Argument value is not numeric: " << argv[i + 1] << "\n";
					}
				}


				//Vector of reproduction
				if (strcmp(argv[i], "-r") == 0)
				{
					orderArgs[8] = argv[i];

					if (atof(argv[i + 1]) != 0)
					{
						orderArgs[9] = argv[i + 1];
					}
					else
					{
						cerr << "Argument value is not numeric: " << argv[i + 1] << "\n";
					}
				}


				//Number of generations
				if (strcmp(argv[i], "-p") == 0)
				{
					orderArgs[10] = argv[i];

					if (atof(argv[i + 1]) != 0)
					{
						orderArgs[11] = argv[i + 1];
					}
					else
					{
						cerr << "Argument value is not numeric: " << argv[i + 1] << "\n";
					}
				}


				//Number of k pairs
				if (strcmp(argv[i], "-k") == 0)
				{
					orderArgs[12] = argv[i];

					if (atof(argv[i + 1]) != 0)
					{
						orderArgs[13] = argv[i + 1];
					}
					else
					{
						cerr << "Argument value is not numeric: " << argv[i + 1] << "\n";
					}
				}
			}


			//Check if all args are in place
			bool noWayOut = true;
			for (int i = 0; i < (argc - 1); i++) {

				if (orderArgs[i] == nullptr)
				{
					noWayOut = false;
					cerr << "Invalid argument no " << i << "!\nUse -h to display instruction!\n";
				}
				//cout << orderArgs[i] << endl;
			}

			return noWayOut;
			break;
		}

		//In case of -h parameter
		case 2:
			if (strcmp(argv[1], "-h") == 0)
			{
				//Instructions.
				cout << "INSTRUCTION\n"
					<< "[1] Commands:\n"
					<< "   " << "-i input file with population,\n"
					<< "   " << "-o output file with generated population,\n"
					<< "   " << "-l output of log file with information of each generation\n"
					<< "   " << "-w factor of vanishing w, which ranges between [0,1],\n"
					<< "   " << "-r factor of reproduction r, which ranges between [0,1],\n"
					<< "   " << "-p number of generations p,\n"
					<< "   " << "-k number of k pairs of random individuals to crossbreed,\n"
					<< "   " << "-h help command.\n"
					<< "[2] Example of correct input arguments:\n"
					<< "   " << "-i [input file name].txt -o [output file name].txt -w [number between 0 and 1] - r [number between 0  and 1] -p [number] -k [number of pairs]\n"
					<< "   " << "-i file1.txt -o file2.txt -w 0.3 -r 0.7 -p 3 -k 4\n"
					<< "[3] How it all works?\n"
					<< "   " << "This program is a simulation of the evolution of population, which can have random number of individuals.\n"
					<< "   " << "Each of individuals have chromosom, which is a sequence of numbers of random lenght.\n"
					<< "   " << "In each generation random pairs of individuals are crossbreed and after that simulations checks which of them are allowed to live on.\n"
					<< "   " << "This extermination is based on result f of special function:\n"
					<< "      " << "[f < w] Individuals, whose factor of vanishing is larger than result are killed off.\n"
					<< "      " << "[f > r] Individuals, whose factor of reproduction is smaller than result are copied.\n"
					<< "      " << "[w <= f <= r] Individuals, which meet this requirement are allowed to stay in population, but they can't reproduce.\n"
					<< "Have fun with your population and this simulation! :)\n"
					<< "\nAleksandra Szymczak, Informatyka\n"
					<< "Projekt Darwin - Podstawy Porgramowania Komputerów.\n";
			}
			else
			{
				cerr << "Incorrect parameter " << argv[1] << "\nPlease type -h to display instruction!\n";
			}

			return false;
			break;

		//Every other sytuation
		default:
			cerr << "Incorrect amount of arguments!\n";
			return false;
			break;
	}
}