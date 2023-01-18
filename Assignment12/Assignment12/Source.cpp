/*

Assignment 11 - Battleship

This program is a single player battleship game, where a 2x2 ship is placed in a 5x5 square, and the player has to decide where to shoot
The ship's position is randomly generated every time
Once the ship has been destroyed, the program ends

*/






#include <iostream>

//This library is included so that we can access the time of the computer
#include<ctime>

//This library is included so that we can use the rand() function
#include<cstdlib>

using namespace std;

//Declared the functions up here so that they don't have to overshadow the main function
void displayArray(char nums[5][5]);
void shoot(int grid[5][5], char gridDisplay[5][5]);
void displaySolution(int nums[5][5]);

//variable that determines the end of the game
int shotsLanded = 0;


int main() 
{
	//This 2d array is the array that holds the position of the battleship
	int grid[5][5] =  {{0,0,0,0,0},
					   {0,0,0,0,0},
					   {0,0,0,0,0},
		               {0,0,0,0,0},
		               {0,0,0,0,0}};
	//The 2d array is the array that will be modified to display the current map to the player
	char gridDisplay[5][5] = { {'-','-','-','-','-'},
							 {'-','-','-','-','-'},
							 {'-','-','-','-','-'},
							 {'-','-','-','-','-'},
							 {'-','-','-','-','-'}, };

	//These two variables determine the random location of the top left corner of the battleship. 
	srand(time(0));
	int shipLocationColumn = rand() % 4;
	int shipLocationRow = rand() % 4;

	//This position, along with the other three parts of the ship, are added to the 2d array here
	grid[shipLocationRow][shipLocationColumn] = 1;
	grid[shipLocationRow][shipLocationColumn + 1] = 1;
	grid[shipLocationRow + 1][shipLocationColumn] = 1;
	grid[shipLocationRow + 1][shipLocationColumn + 1] = 1;

	
	//variable that will be passed into the  menu switch statement
	int menuChoice;

	cout << "Hello! Welcome to battleship!" << endl;
	do
	{
		cout << "1. Fire a shot" << endl;
		cout << "2. Show Solution" << endl;
		cout << "3. Quit" << endl;
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			shoot(grid, gridDisplay);
			break;
		case 2:
			displaySolution(grid);
			break;
		case 3:
			cout << "Thanks for playing!" << endl;
			return 0;
		default:
			cout << "Please input 1,2, or 3" << endl;
		}

	} while (menuChoice != 3 && shotsLanded < 4); //If the player uses the menu wrong or lands all four shots on the battleship, the menu will no longer run, and the program will end

	//This cout statement prints just before the program ends
	cout << "Congratulations! You destroyed the battleship!" << endl;

}

//This function displays the array that holds the position of the battleship
void displayArray(char nums[5][5])
{
	cout << "  A B C D E" << endl;
	//This for statement runs after the top of each row has been displayed. It creates a new row
	for (int x = 0; x < 5; x++)
	{
		cout << x + 1 << " ";
		//This for loop displays the top of each row
		for (int y = 0; y < 5; y++)
		{
			cout << nums[x][y];
			cout << " ";
		}
		cout << endl;
	}	
	cout << endl;
}



void shoot(int grid[5][5], char gridDisplay[5][5])
{
	int rowChoice;
	char columnChoice;
	int columnChoiceInt;
	do 
	{
		//The user chooses the row and column they want to fire at 
		cout << "Please choose the row (1-5)" << endl;
		cin >> rowChoice;
		cout << "Please choose the column (A-E)" << endl;
		cin >> columnChoice;
		switch (columnChoice)
		{
		case 'A':
			columnChoiceInt = 1;
			break;
		case 'B':
			columnChoiceInt = 2;
			break;
		case 'C':
			columnChoiceInt = 3;
			break;
		case 'D':
			columnChoiceInt = 4;
			break;
		case 'E':
			columnChoiceInt = 5;
			break;

		}
	} while (columnChoiceInt - 1 > 4 || columnChoiceInt - 1 < 0 || rowChoice - 1 > 4 || rowChoice - 1 < 0); //If the user inputs something out of bounds, the program just prompts them to choose again
	
	//If the row and colum choice are correct, they hit the battleship, and the display array is updated and displayed accordingly
	if (grid[rowChoice - 1][columnChoiceInt - 1] == 1)
	{
		cout << "You hit the battleship!" << endl;
		gridDisplay[rowChoice - 1][columnChoiceInt - 1] = '*';
		displayArray(gridDisplay);
		shotsLanded++;
	}
	//If the row and colum choice are incorrect, they do not hit the battleship, and the display array is updated and displayed accordingly
	else
	{
		cout << "You missed the battleship" << endl;
		gridDisplay[rowChoice - 1][columnChoiceInt - 1] = 'X';
		displayArray(gridDisplay);
	}

}



void displaySolution(int nums[5][5])
{
	//This for statement runs after the top of each row has been displayed. It creates a new row
	for (int x = 0; x < 5; x++)
	{
		//This for loop displays the top of each row
		for (int y = 0; y < 5; y++)
		{
			//The 2d array will be inverted when it is displayed on the console, I switched the horizontal and vertical input to bring it back to normal
			cout << nums[x][y];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
