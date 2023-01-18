#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	int letterCount = 0;
	int wordCount = 0;
	char space = ' ';
	int charCount1 = 0;
	int charCount2 = 0;
	int wordLength = 0;

	char filename[50];
	ifstream mytext;
	cout << "Please input the name of your file, including the file type. Example: mytext.txt" << endl;
	cin.getline(filename, 50);
	mytext.open(filename);

	if (!mytext.is_open())
	{
		cout << "There is no file with that name in our database!" << endl;
		exit(EXIT_FAILURE);
	}
	


	while (!mytext.eof())
	{
		char file[1500];
		mytext >> file;
		cout << file;

		while (file[charCount2] != space)
		{
			wordLength = charCount2 - charCount1;
			if (charCount2 == ',' || charCount2 == '.')
				wordLength--;
			charCount2++;
			
		}
		charCount1 = charCount2 + 1;
		letterCount = letterCount + wordLength;
		wordCount++;
		
	}

	cout << "The average word length is " << letterCount / wordCount << endl;

	return(0);
}