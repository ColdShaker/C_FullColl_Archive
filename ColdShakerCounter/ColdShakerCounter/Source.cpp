#include <iostream>
#include <string>
#include<fstream>
#include"header.h"
#include <ctime>

using namespace std;

int main()
{
	
	fstream fout;

	fout.open("ColdShakerDatabase.csv");
	cout << "Did you sleep before 9 pm? y,n (worth 5 points)" << endl;
	cellTester(sleep);
}

int cellTester(int contents)
{
	char answer;
	cin >> answer;

	switch (answer)
	{
	case('y'):
		return contents;
		
	case('n'):
		return 0;
	
		
	}
}