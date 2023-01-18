#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int numTries = 0;
	int guess = 0;
	
	

	srand(time(0));
	int computerChoice = 1 + rand() % 100;
	
	while (guess != computerChoice)
	{
		do
		{
			if (numTries == 0)
				cout << "I'm thinking of a number (1-100):" << endl;
			cin >> guess;
		} while (guess < 1 || guess > 100);

		numTries++;
		
		if (guess < computerChoice)
		{
			cout << "Too Low! Guess again" << endl;
		}

		if (guess > computerChoice)
		{
			cout << "Too High! Guess again" << endl;
		}

	}
	
}