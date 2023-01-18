/*
*Assignment 8 : Shell Game 2.0
*
*This assignment simulates the shell game that gamblers play 
*
*
*/
#include <iostream>

//This library is inluced so that we can use the random number generator function
#include <cstdlib>

//We include the ctime library so that the program can access the computer's clock, and use the number generated from that as a seed for the number generation
#include <ctime>

using namespace std;

int main()
{
	string name;
	int money;
	int ballLocationChosen;

	//This block of code is where we get input from the user about their name and if they are able to afford the game. It has nothing to do with the actual game.
	cout << "Hello!" << endl;
	cout << "What is your name? ";
	cin >> name;
	cout << "\nHi " << name << ". How much money do you have?";
	cin >> money;

	
	if (money >= 20)
	{
		cout << money <<" is enough. Let's Play!\n" << endl;
	}
	else 
	{
		cout << "Get the friggen heck outta here! No money, no gamblin!" << endl;
		return 0;
	}
//The game begins with a display of the cups before the shuffule, which actually has nothing to do with the game. It just shows the format of the game.
	cout << "     ___        ___        ___     " << endl;
	cout << "    /  \\       /  \\       /  \\    " << endl;
	cout << "   /    \\     /    \\     /    \\   " << endl;
	cout << "  /      \\   /  O   \\   /      \\  " << endl;

	cout << "\nShuffling...\n\n" << endl;

	cout << "     ___        ___        ___     " << endl;
	cout << "    /  \\       /  \\       /  \\    " << endl;
	cout << "   /    \\     /    \\     /    \\   " << endl;
	cout << "  /   1  \\   /  2   \\   /   3  \\  " << endl;

	//Here is where the ball location is chosen by the user
	cout << "Pick a shell (1, 2 or 3): ";
	cin >> ballLocationChosen;

	//This is where the random location for the ball is chosen. It will be displayed after the user inputs their guess.
	srand(time(0));
	int ballLocationRandom = 1 + rand() % 3;
	//We now check whether each of the three cups has been chosen. Every if statement after this one is just testing the different cases.
	if (ballLocationRandom == 1)
	{
		cout << "     ___        ___        ___     " << endl;
		cout << "    /  \\       /  \\       /  \\    " << endl;
		cout << "   /    \\     /    \\     /    \\   " << endl;
		cout << "  /   O  \\   /      \\   /      \\  " << endl;
		//Here is where we see whether or not the user wins or loses.
		if (ballLocationChosen == 1)
			cout << " You got it right!!" << endl;
		else 
		{
			cout << "Haha you suck loser!" << endl;
		}
	}


	//check cup 2
	if (ballLocationRandom == 2)
	{
		cout << "     ___        ___        ___     " << endl;
		cout << "    /  \\       /  \\       /  \\    " << endl;
		cout << "   /    \\     /    \\     /    \\   " << endl;
		cout << "  /      \\   /   O  \\   /      \\  " << endl;

		if (ballLocationChosen == 2)
			cout << " You got it right!!" << endl;
		else
		{
			cout << "Haha you suck loser!" << endl;
		}
	}


	//check cup 3
	if (ballLocationRandom == 3)
	{
		cout << "     ___        ___        ___     " << endl;
		cout << "    /  \\       /  \\       /  \\    " << endl;
		cout << "   /    \\     /    \\     /    \\   " << endl;
		cout << "  /      \\   /      \\   /   O  \\  " << endl;

		if (ballLocationChosen == 3)
			cout << " You got it right!!" << endl;
		else
		{
			cout << "Haha you suck loser!" << endl;
		}
	}
	return 0;
}