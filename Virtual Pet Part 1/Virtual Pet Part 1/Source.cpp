/*
Assignment 13 - Virtual Pet Part 1

This project is designed to give a basic introduction to classes and their application.
It simulates a virtual pet. The program generates a dog of class dog that has all of the attributes of the class dog
The dog has hunger, cleanliness, and happiness.
The dog's age starts at zero. 
The dog's hunger, cleanliness, hapiness, and gender are randomly generated

By: Michael Ball

*/
#include <iostream> //For input and output to console
#include <string> //For the use of strings
#include<ctime> //For accessing computer time function
#include<cstdlib> //For accessing rand function

using namespace std;

class Dog
{

	int age;

	//ranges from 0-10
	int hunger;

	//ranges from 0-10
	int cleanliness;

	//ranges from 0-10
	int happiness;

	//name of dog
	string name;

	bool gender;



public:

	Dog(string name2)
	{
		name = name2;
		hunger = rand() % 10;
		cleanliness = rand() % 10;
		happiness = rand() % 10;
		age = 0;
		gender = rand() % 2;
	}


	////////GETTER FUNCTIONS///////


	int getHunger()
	{
		return hunger;
	}

	int getCleanliness()
	{
		return cleanliness;
	}

	int getHappiness()
	{
		return happiness;
	}

	string getName()
	{
		return name;
	}

	string getGender()
	{
		if (gender)
		{
			return "male";
		}
		else
		{
			return "female";
		}
	}

	int getAge()
	{
		return age;
	}


	///////////////////////////////


	
	////////DISPLAY FUNCTIONS///////

	//displays all of the pet stats
	void displayStats()
	{
		cout << "Name = " << getName() << endl;
		cout << "Gender = " << getGender() << endl;
		cout << "age = " << age << endl;
		cout << "fullness = " << hunger << endl;
		cout << "happiness = " << happiness << endl;
		cout << "cleanliness = " << cleanliness << endl;
	}

	////////SETTER FUNCTIONS///////

	//increases age by 1

	void changeAge()
	{
		age++;
		cout << "Your dog's new age is " << age << endl;
	}

	//Decreases hunger and increases happiness
	void Feed()
	{
		if (hunger < 10)
		{
			hunger++;
		}
		
		if (happiness < 10)
		{
			happiness++;
		}
		
	}

	//Increases cleanliness and happiness
	void Clean()
	{

		if (cleanliness < 10)
		{
			cleanliness++;
		}
		
		if (happiness < 10)
		{
			happiness++;
		}
	}

	//Increases happiness
	void Play()
	{
		if (happiness < 10)
		{
			happiness++;
		}
	}

	///////////////////////////////

};




int main() 
{
	//creates seed for random integer generator cased on computer time. Used to randomly generate the gender, happiness, hunger, and cleanliness stats
	srand(time(0));

	string name;
	cout << "What would you like to name your dog?" << endl;
	cin >> name;

	//Creates coolDog, that is of the class Dog. name is passed in because the constructor needs the name.
	Dog coolDog(name);

	//Gives the user some information on their dog
	cout << "Congatulations on your " << coolDog.getAge() << " year old dog! " << coolDog.getName() << " is a lovely name!" << endl;

	//The menu choice has to be initialized to some value because the while loop needs something to compare
	int menuChoice = 0;
	while (menuChoice != 6)
	{
		//The menu is displayed accross multiple console lines
		cout << "\nMenu:\n" << "1.Feed your dog\n" << "2.Clean your dog\n" << "3.Play with your dog\n" << "4.Add 1 to your dog's age\n" << "5.Look at your dogs stats\n" << "6.End program" << endl;
		
		//The player gets to choose which member function they call in this switch statement
		cin >> menuChoice;
			switch (menuChoice)
			{
			case 1:
				coolDog.Feed();
				cout << "You fed your dog. Your new fullness is " << coolDog.getHunger() << " and your new happiness is " << coolDog.getHappiness() << endl;
				break;
			case 2:
				coolDog.Clean();
				cout << "You cleaned your dog. Your new cleanliness is " << coolDog.getCleanliness() << " and your new happiness is " << coolDog.getHappiness() << endl;
				break;
			case 3:
				coolDog.Play();
				cout << "You played with your dog. Your new happiness has increased to " << coolDog.getHappiness() << endl;
				break;
			case 4:
				 coolDog.changeAge();
			case 5:
				coolDog.displayStats();
				break;
			case 6:
				return 0;
			default:
				cout << "Learn how to use a menu" << endl;
				break;
			}
	}
	
}
