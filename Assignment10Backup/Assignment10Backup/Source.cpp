
//This library includes necessary input/output functions
#include <iostream>

//This library is used to write in files 
#include <fstream>

//This library includes necessary string functions
#include <string>

using namespace std;

//This function's purpose is to find the average word length in a text document
void func(ifstream &mytext)
{
	int letterCount = 0;
	int wordCount = 0;

	if (!mytext.is_open())
	{
		cout << "There is no file with that name in our database!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		string line;
		while (getline(mytext, line))
		{
			letterCount = line.length() + letterCount;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',' || line[i] == '.' || line[i] == ' ')
				{
					letterCount--;


					if (line[i] == ' ')
					{
						wordCount++;
					}
				}

			}
		}
	}

	cout << "The average word length is " << letterCount / wordCount << endl;
}



int main()
{
	

	char filename[50];
	ifstream mytext;
	cout << "Please input the name of your file, including the file type. Example: mytext.txt" << endl;
	cin.getline(filename, 50);
	mytext.open(filename);

	
	func(mytext);
	mytext.close();
	return(0);
}