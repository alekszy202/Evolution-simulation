#include "FileManagement.h"
using namespace std;


//Check if given string is a number.
bool isNumber(string s)
{

	//String doesn't exist.
	if (s.size() == 0) return false;

	//Loop checking each of characters.
	for (int i = 0; i < s.size(); i++) 
	{

		//Check if given character is a digit.
		if ((s[i] >= '0' && s[i] <= '9') == false) 
		{
			return false;
		}
	}
	return true;
}


//Annoucement of sucess of reading a file.
bool errorHandle(int errorHandling)
{
	//File doesn't exist.
	if (errorHandling == FILE_DOES_NOT_EXIST) 
	{
		cerr << "File does not exist!\n";
		return false;
	}

	//File is empty.
	else if (errorHandling == FILE_EMPTY) 
	{
		cerr << "File is empty\n";
		return false;
	}

	//File has a bad format.
	else if (errorHandling == FILE_BAD_FORMAT) 
	{
		cerr << "File has a bad format!\nOnly digits allowed!\n";
		return false;
	}

	//File has correct format.
	else if (errorHandling == FILE_CORRECT) 
	{
		cout << "File was read correctly!\n";
		return true;
	}
}

//Reading of input file.
vector<vector<int>> readFile(int &errorResult, string fileName)
{
	//Creation of main container for population.
	vector<vector<int>> generation;

	//Temporary variable of data of given line.
	string myLine;

	//Reading from the input file.
	ifstream myReadFile(fileName);

	//Check if file was open corectly.
	if (myReadFile.is_open()) 
	{

		//Reading of the file's lines, one by one, using a while loop together with the getline() function.
		while (getline(myReadFile, myLine)) 
		{

			//Vector container for one population subject.
			vector<int> vec;

			//Silvertyping - if line doen't end with space, put it there.
			if (myLine[myLine.length() - 1] != ' ') 
			{ 
				myLine += " "; 
			}

			//Creation of empty variable.
			string word = "";

			//Temporary variable used in transformation of string to int.
			int wordAsInt = 0;

			//Split one subject's code into individual numbers.
			for (auto x : myLine)
			{
				//If white space was found.
				if (x == ' ')
				{
					//When whitespace multiply.
					if (word != "") {
						//Check if word is number.
						if (isNumber(word))
						{
							//Transformation of string to int.
							wordAsInt = stoi(word);
							//Placement of variable into container.
							vec.push_back(wordAsInt);
						}
						//Word isn't a number.
						else
						{
							errorResult = FILE_BAD_FORMAT;
							return generation;
						}

						word = "";
					}
				}
				//White space wasn't found.
				else 
				{
					word = word + x;
				}
			}
			//Placement of container with variable into main container.
			generation.push_back(vec);
		}
	}
	//File wasn't open corectly.
	else 
	{
		errorResult = FILE_DOES_NOT_EXIST;
		return generation;
	}

	//Closing of file.
	myReadFile.close();

	//Check if file was empty.
	if (generation.size() == 0)
	{
		errorResult = FILE_EMPTY;
		return generation;
	}
	//File was correct.
	else 
	{
		errorResult = FILE_CORRECT;
		return generation;
	}
}

//Creation of output file.
void writeFile(vector<vector<int>> mainContainer, string fileName)
{
	//Writing to the output file.
	ofstream myFile(fileName);

	//Check if there is any data.
	if (mainContainer.size() > 0)
	{
		for (int i = 0; i < mainContainer.size(); i++) 
		{
			for (int j = 0; j < mainContainer[i].size(); j++) 
			{
				myFile << mainContainer[i][j] << " ";
			}
			myFile << "\n";
		}
	}
	//There wasn't any data.
	else 
	{
		
		myFile << "Everybody died!";
	}

	//Anoucement of correct creation of output file.
	cout << "Result saved to file " + fileName + "\n";

	//Closing of file.
	myFile.close();

}

void writeLogFile(list<logPart> logContainer, string fileName)
{
	//Writing to the output file.
	ofstream myFile(fileName);

	//Check if there is any data.
	if (logContainer.size() > 0)
	{
		for (list<logPart>::iterator it = logContainer.begin(); it != logContainer.end(); ++it) 
		{
			myFile << "Generation number: " << it->no << endl;
			myFile << "Input number of indiviuals: " << it->elements << endl;
			myFile << "Alive: " << it->alive << endl;
			myFile << "Dead: " << it->died << endl;
			myFile << "Cloned: " << it->cloned << endl << endl;
		}
	}

	//Anoucement of correct creation of output file.
	cout << "Log file have been saved to log.txt\n";

	//Closing of file.
	myFile.close();
}
