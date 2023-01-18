#include <iostream>
using namespace std;

int main()
{
	srand(time(0)); 
	int books = rand() % 11; 
	int movies = rand() % 11;
	char answer; 
	double FIXED_PRICE = 9.99;
	int items = 0;
	
	while (books != 0 || movies != 0)
	{
		cout << "Please input new answer" << endl;
		cin >> answer;

		switch (answer)
		{
		case 'B':
			if (books > 0)
			{
				cout << "One book has been added to your inventory" << endl;
				books--;
				items++;
				cout << "Total Number of Items: " << items << endl;
				cout << "Current shopping cart total: " << items * FIXED_PRICE << endl;
				cout << "\nCurrent Inventory: " << endl;
				cout << "Books: " << books << endl;
				cout << "Movies: " << movies << endl;
				
			}
			else
			{
				cout << "We're all out of books!" << endl;
			}
			break;
		case 'M':
			if (movies > 0)
			{
				cout << "One movie has been added to your inventory" << endl;
				movies--;
				items++;
				cout << "Total Number of Items: " << items << endl;
				cout << "Current shopping cart total: " << items * FIXED_PRICE << endl;
				cout << "\nCurrent Inventory: " << endl;
				cout << "Books: " << books << endl;
				cout << "Movies: " << movies << endl;
				
			}
			else
			{
				cout << "We're all out of movies!" << endl;
			}
			break;

		case 'X':
			cout << "Why are you leaving the shop so soon? D:" << endl;
			return 0;
			break;
		} 
	}






}