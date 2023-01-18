/*

Student Grade Calculator part B

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
	cout << "Please enter an Exam Score: " << endl;
	cin >> examScore;

	//This block of nested if else statements determines what letter grade the inputted number grade corresponds to
	if (examScore >= 60)
	{
		if (examScore >= 70)
		{
			if (examScore >= 80)
			{
				if (examScore >= 90)
				{
					cout << "This student received an 'A'" << endl;
				}
				else cout << "This student received a 'B'" << endl;
			}
			else cout << "This student received a 'C'" << endl;
		}
		else cout << "This student received a 'D'" << endl;
	}
	else cout << "This student received an 'F'" << endl;

	return 0;
}