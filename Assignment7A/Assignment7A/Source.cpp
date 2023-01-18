/*

Student Grade Calculator part A 

This program is designed to display a student's letter grade using only if statements.
It accepts a float value for their number grade, then returns their correct letter grade

Created by Michael Ball


*/

#include <iostream>

using namespace std;

int main()
{
	//This block of code accepts the user's input for the student's exam score
	float examScore;
	cout << "Please enter an Exam Score: ";
	cin >> examScore;

	//This checks if the student has a number grade corresponding to A
	if (examScore >= 90)
	{
		cout << "This student received an 'A'" << endl;
	}

	//This checks if the student has a number grade corresponding to B
	if (examScore < 90 && examScore >= 80)
	{
		cout << "This student received a 'B'" << endl;
	}

	//This checks if the student has a number grade corresponding to C
	if (examScore < 80 && examScore >= 70)
	{
		cout << "This student received a 'C'" << endl;
	}

	//This checks if the student has a number grade corresponding to D
	if (examScore < 70 && examScore >= 60)
	{
		cout << "This student received a 'D'" << endl;
	}
	//This checks if the student has a number grade corresponding to F
	if (examScore < 60)
	{
		cout << "This student received an 'F'" << endl;
	}
}