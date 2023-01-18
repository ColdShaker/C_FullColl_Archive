/*
Assignment 8 - Function Calculator

This assignment's goal is to create a number calculator using functions. I created functions for addition, subtraction, multiplication, and division. 
In the main function, a switch statement is called that calculates the two given numbers with the given operation

Created by: 
Michael Ball 

*/

#include <iostream>
using namespace std;

float numberOne;
float numberTwo;
char operation;


//All of these float functions account for addition, subtraction, multiplication, and divisionl. They will be called later in the switch statement
float add(float a, float b)
{
	return a + b;
}

float subtract(float a, float b)
{
	return a - b;
}

float multiply(float a, float b)
{
	return a * b;
}

float divide(float a, float b)
{
	return a / b;
}

//This function is where everything is shown, and where the switch statement is decided. Inside of each case the add, subtract, multiply, and divide functions are called
void showChoice()
{

	cout << "Hello! what two numbers do you want to use?" << endl;
	cin >> numberOne;
	cin >> numberTwo;
	cout << "Great. What operation do you want to do? (Type +,-,* or /)" << endl;
	cin >> operation;

	switch (operation)
	{
	case '+':
		cout << numberOne << " + " << numberTwo << " = " << add(numberOne, numberTwo) << endl;
		break;

	case '-':
		cout << numberOne << " - " << numberTwo << " = " << subtract(numberOne, numberTwo) << endl;
		break;

	case '*':
		cout << numberOne << " * " << numberTwo << " = " << multiply(numberOne, numberTwo) << endl;
		break;

	case '/':

		cout << numberOne << " / " << numberTwo << " = " << divide(numberOne, numberTwo) << endl;
		break;
	}

}

//The main function calls the showChoice function and that's it.
int main()
{
	showChoice();
	return (0);
}
