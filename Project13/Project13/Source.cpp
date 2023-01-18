#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{


	srand(time(0));
	int genderGenerator = rand() % 2;
	string gender = "dog";

	switch (genderGenerator)
	{
	case 0:
	{
		string gender = "male";
		break;
	}
	case 1:
	{
		string gender = "female";
		break;
	}
	default:
		string gender = "non-binary";
	}

	cout << "Congratulations on your new dog! It's gender is " << gender << endl;


}