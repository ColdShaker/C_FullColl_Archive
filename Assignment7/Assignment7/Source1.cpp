#include <iostream>
using namespace std;

int main()
{
	float examScore;

	cout << "Please enter an Exam Score: " << endl;
	cin >> examScore;

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