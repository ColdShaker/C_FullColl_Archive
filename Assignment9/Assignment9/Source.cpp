/*
Assignment 9 - Game library 

This assignment contains two games that the user can choose between. It's purpose is to practice switch statements and function

Created by Michael Ball



*/

#include <iostream>

//This library is included so that we can use strings and string functions
#include <string>

//This library is included so that we can manipulate float length
#include <iomanip>

//This library is included so that we can use the rand function
#include <cstdlib>

//This library is included so that the program can access the computer's time and generate random numbers
#include <ctime>

using namespace std;

//These are both the fucntions that contain our two games. I declared them up here so they can be called in the main function
void guessingGame();
void lettersGame();

int main()
{
	//This block of code is the menu where the user can see their choices
	int choice;
	do
	{
		cout << "\nMenu:" << endl;
		cout << "1. Guessing Game" << endl << "2. Letters Game" << endl;
		cin >> choice;

		//This switch statement allows the user to choose between the two games
	
		switch (choice)
		{
		case 1:
			guessingGame();
			break;
		case 2:
			lettersGame();
			break;
	//If the user inputs a number that isn't 1 or 2 then they are given this dialogue 
		default:
			cout << "You have to type 1 or 2" << endl;
		}
	//The user will be directed back to the start of the program if they input something that isn't either a one or a two as a result of this do while loop
	//This do while loop also brings the user back to the start of the program when they finish their game
	} while (choice != 1 || choice != 2);

}

//This function runs the guessing game
void guessingGame()
{

	int numTries = 0;
	int guess = 0;


	//This is where the random number is generated using your computer's time
	srand(time(0));
	int computerChoice = 1 + rand() % 100;

	//The program checks to see if the user input is the same as the computer generated number. If it is, the game ends
	//On the first iteration guess hasn't been inputted yet, and is defaulted to zero. Since the range of numbers is from 1-100, the while loop will run no matter what 
	//If the guess isn't correct, the program gives the user a hint and restarts the loop, incrementing the number of tries by one
	while (guess != computerChoice)
	{
		//This do while loop redirects the user back to the start of the program if they input a number less than 1 or greater than 100
		
		do
		{
			//This tells the user on their first guess the range of numbers they should guess in between
			if (numTries == 0)
				cout << "\nI'm thinking of a number (1-100):" << endl;
			cin >> guess;
		} while (guess < 1 || guess > 100);

		//This variable exists so that the number of tries can be displayed at the end of the program. For every iteration of the while loop this variable is incremented, so it keeps track of the number of tries
		numTries++;

	//The loop is going to run again no matter what, but we still want to give the user a hint as to which direction they should guess. 
	//These if statemtns tell the user if the guess is higher or lower than the computer generated number
		if (guess < computerChoice)
		{
			cout << "Too Low! Guess again" << endl;
		}

		if (guess > computerChoice)
		{
			cout << "Too High! Guess again" << endl;
		}
	//After the hint, the loop will run again
	}
	cout << "You won! It took " << numTries << " tries to find the number!" << endl;
}

//This function runs the letters game
void lettersGame() 
{
	//These are the variables that keep track of the number of times each letter was used
	int aCount = 0, eCount = 0, lCount = 0, sCount = 0, tCount = 0;

	char letter;
	string sentence;
	cout << "\nPlease enter a sentence" << endl;
	//cin.ignore was put in to fix an error. It automatically went through the program without asking for input without cin.ignore()
	cin.ignore();

	//getline was used because cin stops counting characters after it hits a space
	getline(cin, sentence);

	//the int pars is created. This int pars is incremented until it is equal to sentence length 
	for (int pars = 0; pars < sentence.length(); pars++)
	{
		//the character letter is the character that is used to check if each character in the string is either a, e, l, s, or t
		//as pars is incremented, letter is assigned the character value in the sentence string.
		//Each time letter is assigned to the next letter in the string, the switch statement checks to see if the letter is a, e, l, s, or t 
		//Once pars is no longer less than the sentence length, then the whole string has been parsed through, and the for loop ends
		letter = tolower(sentence[pars]);

		//Here is the switch statement that increments each of the letters if the character letter fits the case
		switch (letter)
		{
		case 'a':
			aCount++;
			break;
		case 'e':
			eCount++;
			break;
		case 'l':
			lCount++;
			break;
		case 's':
			sCount++;
			break;
		case 't':
			tCount++;
			break;
		}
	}
	
	float percentage;
	//Displays the number of characters in the string
	cout << "There are " << sentence.length() << " letters in your sentence" << endl;

	//Displays the number of 'a's as well as the percentage of 'a's that make up the whole sentence
	percentage = (float)aCount / (float)sentence.length();
	cout << "A = " << aCount << " => " << percentage * 100 << "%" << endl;

	//Displays the number of 'e's as well as the percentage of 'e's that make up the whole sentence
	percentage = (float)eCount / (float)sentence.length();
	cout << "E = " << eCount << " => " << percentage * 100 << "%" << endl;

	//Displays the number of 'l's as well as the percentage of 'l's that make up the whole sentence
	percentage = (float)lCount / (float)sentence.length();
	cout << "L = " << lCount << " => " << percentage * 100 << "%" << endl;

	//Displays the number of 's's as well as the percentage of 's's that make up the whole sentence
	percentage = (float)sCount / (float)sentence.length();
	cout << "S = " << sCount << " => " << percentage * 100 << "%" << endl;

	//Displays the number of 't's as well as the percentage of 't's that make up the whole sentence
	percentage = (float)tCount / (float)sentence.length();
	cout << "T = " << tCount << " => " << percentage * 100 << "%" << endl;
}

