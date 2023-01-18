/*

Assignment #11: Arrays

The point of this assignment is to experiment with arrays and functions
There are 6 functions that the user can call through a switch statement that can modify their array

By Michael Ball 
11/4/2020

*/






//No special libraries are needed for this program
#include <iostream>
using namespace std;

//I define all of the integers in the array so that each one can be inputted through a cin statement
int input0, input1, input2, input3, input4, input5, input6, input7, input8, input9;

//This is the user inputted array
int mixArray[10];

//This is the variable that will determine which case the switch statement runs
int menuChoice;

//I declare all of the array functions here so that I don't have to have them all collapsed above my main function
void overwriteArray(int mixArray[]);
void displayReg(int nums[]);
void displayRev(int nums[]);
void displayValLoc(int nums[]);
void findVal(int nums[]);
void insertVal(int nums[]);


int main()
{
	//This beginning part only ever runs once. Here is the first time we define the values in the array mixArray
	cout << "So, you want to mess with an array huh? Well make one! (Please input 10 integers for your array)" << endl;
	overwriteArray(mixArray);

	//I need the menu to run over and over until the user chooses to exit the program. In order to do this, I put all of it inside of a do while loop
	//In order to quit the program, the user must input 7. If they input anything else, the program will keep running
	do
	{

		cout << "\nMenu:" << endl;
		cout << "1. Make new array" << endl;
		cout << "2. Display the array" << endl;
		cout << "3. Display the array in reverse" << endl;
		cout << "4. Display the value at the location of your choice" << endl;
		cout << "5. Find a value within the array" << endl;
		cout << "6. Insert value into the array" << endl;
		cout << "7. End Program" << endl;
		cin >> menuChoice;

		//The user inputs a menu choice, which is passed into this switch statement
		//The switch statement runs the function associated with the choice
		switch (menuChoice)
		{
		case 1:
			overwriteArray(mixArray);
			break;
		case 2:
			displayReg(mixArray);
			break;
		case 3:
			displayRev(mixArray);
			break;
		case 4:
			displayValLoc(mixArray);
			break;
		case 5:
			findVal(mixArray);
			break;
		case 6:
			insertVal(mixArray);
			break;
		case 7:
			return 0;
		default:
			//If the user inputs a value that doesn't fit into any of the other cases, it tells them to input something else
			cout << "Please input a value between 1 and 7" << endl;
			
		}
	}  while (menuChoice != 7);
}

//Thia function overwrites the previous array with a new user inputted one
void overwriteArray(int mixArray[])
{
	int input0, input1, input2, input3, input4, input5, input6, input7, input8, input9;
	cin >> input0 >> input1 >> input2 >> input3 >> input4 >> input5 >> input6 >> input7 >> input8 >> input9;
	mixArray[0] = input0;
	mixArray[1] = input1;
	mixArray[2] = input2;
	mixArray[3] = input3;
	mixArray[4] = input4;
	mixArray[5] = input5;
	mixArray[6] = input6;
	mixArray[7] = input7;
	mixArray[8] = input8;
	mixArray[9] = input9;
}

//Displays the current array
void displayReg(int nums[])
{
	//This for loop iterates up the array and displays whatever value is at each position
	for (int i = 0; i < 10; i++)
	{
		cout << nums[i] << endl;
	}
}

//Displays the current array in reverse
void displayRev(int nums[])
{
	//This for loop iterates down the array and displays whatever value is at each position
	for (int i = 0; i < 10; i++)
	{
		cout << nums[10 - i] << endl;
	}
}

//Displays the value in the array at the user inputted location
void displayValLoc(int nums[])
{
	//The user-inputted varaible arrayLocation is passed into mixArray and displayed
	int arrayLocation;
	cout << "Please input the location of the value you want displayed" << endl;
	cin >> arrayLocation;
	cout << "The value at this location is " << nums[arrayLocation - 1]; //The reason we have a -1 here is because the array begins at zero. We need to compensate for that
}

//Determines whether or not a user inputted value is in the array
void findVal(int nums[])
{
	int arrayValue;
	cout << "Please input a value and we will check if its in the array" << endl;
	cin >> arrayValue;

	//This for loops parses through each location in the array. If it goes through the whole loop and the if statement is never accessed, the cout at the bottom is displayed and the function ends
	for (int i = 0; i < 11; i++)
	{
		//Each interation of i is a new location, which is tested to see if it is eqaul to the user-inputted arrayValue
		if (nums[i] == arrayValue) 
		{
			cout << arrayValue << "Is in the array! Hooray! It is at position " << i + 1 << endl;
			//Ends the function so that the cout outside the for loop is not displayed
			return;
		} 
	}

	cout << "Sorry, the value you gave me is not in the array!" << endl;
}

//Inserts a new value into the array at a user specified location, replacing the old value
void insertVal(int nums[])
{
	int arrayValue; //The value the user wants
	int i; //The location the user wants this value stored
	cout << "Please tell me the value you want to insert" << endl;
	cin >> arrayValue;
	cout << "Please tell me the location you want to insert this value at" << endl;
	cin >> i;
	//The value and location are assigned
	nums[i - 1] = arrayValue; //The -1 here is included because the array begins at zero. I need to compensate for this.
}