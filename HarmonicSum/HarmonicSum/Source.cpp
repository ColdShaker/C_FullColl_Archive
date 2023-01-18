#include <iostream>
using namespace std; 

double harmonicNum(int pos);
void fillHarmonic(double hArray[], int hSize);

int main()
{
	double hValues[10];
	fillHarmonic(hValues, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << hValues[i] << " " << endl;
	}

	return 0;
}

double harmonicNum(int pos)
{
	double sum = 0;

	while (pos > 0)
	{
		sum = sum + (1 / pos);
		pos--;

	}

	return sum;
}

void fillHarmonic(double hArray[], int hSize)
{
	for (int i = 1; i <= hSize; i++)
	{
		hArray[i] = harmonicNum(i);
	}
}