#include <iostream>
#include <string>
using namespace std;

string buildStringCS(int n);

int main()
{
	try
	{
		cout << "n = 4: " << buildStringCS(4) << endl;
		cout << "n = 5: " << buildStringCS(5) << endl;
		cout << "n = -1: " << buildStringCS(-1) << endl;
	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

string buildStringCS(int n)
{

		if (n < 1)
		{
			throw invalid_argument("ERROR: Value of n is not positive!");
		}

		if (n == 1)
		{
			return "C";
		}

		string csOutput;
		if (n % 2 == 1)
		{
			csOutput = buildStringCS(n - 1) + "C";
		}
		else
		{
			csOutput = buildStringCS(n - 1) + "S";
		}
		return csOutput;
}