/*

Student Grade Calculator part C

This program is designed to display a student's letter grade using if else statements
It accepts a float value for their number grade, then returns their correct letter grade

Created by Michael Ball


*/

#include <iostream>

using namespace std;

int main()
{
	//This block of code accepts the user's input for the student's exam score
	float examScore;
	cout << "Please enter an Exam Score: " << endl;
	cin >> examScore;


	//This chain of if else statements checks to see if students have a number grade corresponding to the letter grade A, B, C, D, F
	if (examScore >= 90)
	{
		cout << "This student received an 'A'" << endl;
	}
	else if (examScore < 90 && examScore >= 80)
	{
		cout << "This student received a 'B'" << endl;
	}
	else if (examScore < 80 && examScore >= 70)
	{
		cout << "This student received a 'C'" << endl;
	}
	else if (examScore < 70 && examScore >= 60)
	{
		cout << "This student received a 'D'" << endl;
	}
	else cout << "This student received an 'F'" << endl;

	return 0;
}