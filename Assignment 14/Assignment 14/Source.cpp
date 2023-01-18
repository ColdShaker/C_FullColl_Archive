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

	//gender boolean - 1 for male, 0 for female
	bool gender;

public:

	Dog(string name2)
	{
		name = name2;
		hunger = 1 + rand() % 10;
		cleanliness = 1 + rand() % 10;
		happiness = 1 + rand() % 10;
		age = 1 + rand() % 2;
		gender = 1 + rand() % 2;
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

	string getPronounHe()
	{
		if (gender)
		{
			return "he";
		}
		else
		{
			return "she";
		}
	}

	string getPronounHis()
	{
		if (gender)
		{
			return "his";
		}
		else
		{
			return "her";
		}
	}

	int getAge()
	{
		return age;
	}

	//function is a generalized random encounter
	//Takes in variable that determines how likely it is to occur 
	bool randomEncounter(int modulus)
	{
		bool happens;
		int test;
		test = rand() % modulus;
		if (test == 1)
		{
			happens = true;
		}
		else
		{
			happens = false;
		}
		return happens;
	}


	///////////////////////////////



	////////DISPLAY FUNCTIONS///////

	//displays all of the pet stats
	void displayStats()
	{
		cout << "Name = " << name << endl;
		cout << "Gender = " << getGender() << endl;
		cout << "age = " << age << endl;
		cout << "fullness = " << hunger << endl;
		cout << "cleanliness = " << cleanliness << endl;
		cout << "happiness = " << happiness << endl;
	}

	////////SETTER FUNCTIONS///////

	//increases age by 1

	void increaseAge()
	{
		age++;
		hunger = hunger - rand() % 3 + 1;
		happiness = happiness - rand() % 3 + 1;
		cleanliness = cleanliness - rand() % 3 + 1;
		cout << "Your dog's new age is " << age << ". " << getPronounHis() << " stats have been lowered. Help them out, would ya?" << endl;
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
		if (happiness < 9)
		{
			happiness = happiness + 2;
		}
		else if (happiness == 9)
		{
			happiness++;
		}
	}

	int checkForDeath()
	{
		bool dead;
		int chanceDeath = rand() % 6;
		if (age >= 10)
		{
			if (chanceDeath == 1)
			{
				dead = true;
			}
			else
			{
				dead = false;
			}
			return dead;
		}
	}

	///////////////////////////////

};




int main()
{
	//creates seed for random integer generator based on computer time. Used to randomly generate the gender, happiness, hunger, and cleanliness stats
	srand(time(0));

	int menuIterations = 0;

	string name;
	cout << "What would you like to name your dog?" << endl;
	cin >> name;

	//Creates coolDog, that is of the class Dog. name is passed in because the constructor needs the name.
	Dog coolDog(name);

	//Gives the user some information on their dog
	cout << "Congatulations on your " << coolDog.getAge() << " year old dog! " << coolDog.getName() << " is a lovely name!" << endl;

	//The menu choice has to be initialized to some value because the while loop needs something to compare
	int menuChoice = 0;
	while (menuChoice != 5)
	{
		if (menuChoice >= 1 && menuChoice <= 3)
		{
			menuIterations++;
		}

		if (coolDog.getCleanliness() <= 0)
		{
			cout << "Your dog has been neglected too much. It gets an infection and dies. What a horrible dog owner you are..." << endl;
			return 0;
		}

		if (coolDog.getHunger() <= 0)
		{
			cout << "Your dog has died of starvation. You did not feed for dog enough! It really isn't that hard to feed your dog!" << endl;
			return 0;
		}

		if (coolDog.getHappiness() <= 0)
		{
			cout << "Your dog has become so sad that it ran away. It doesn't want to live with your sorry butt anymore." << endl;
			return 0;
		}

		if (menuIterations == 3)
		{
			coolDog.increaseAge();
			if (coolDog.checkForDeath() == true)
			{
				cout << "Tragically, your dog has died. But it was from old age, surrounded by loved ones. \n\n\n ...Time to get a new one!" << endl;
				return 0;
			}
			menuIterations = 0;
		}

		
		//The menu is displayed accross multiple console lines
		cout << "\nMenu:\n" << "1.Feed your dog\n" << "2.Clean your dog\n" << "3.Play with your dog\n" << "4.Look at your dogs stats\n" << "5.End program" << endl;

		//The player gets to choose which member function they call in this switch statement
		cin >> menuChoice;
		switch (menuChoice)
		{b
		case 1:
			if (coolDog.randomEncounter(20) == true)
			{
				cout << "Your dog choked on its food and died. Sorry!" << endl;
				return 0;
			}

			coolDog.Feed();
			cout << "You fed your dog. Your new fullness is " << coolDog.getHunger() << " and your new happiness is " << coolDog.getHappiness() << endl;
			break;
		case 2:
			if (coolDog.randomEncounter(50) == true)
			{
				cout << "Your dog slipped on the soap bar and died! What are the odds??" << endl;
				return 0;
			}

			coolDog.Clean();
			cout << "You cleaned your dog. " << coolDog.getPronounHis() << " new cleanliness is " << coolDog.getCleanliness() << " and " << coolDog.getPronounHis() << " new happiness is " << coolDog.getHappiness() << endl;
			break;
		case 3:
			if (coolDog.randomEncounter(20) == true)
			{
				cout << "Your dog bit a child and had to be put down. So sad." << endl;
				return 0;
			}2


			coolDog.Play();
			cout << "You played with your dog. " << coolDog.getPronounHis() << " new happiness has increased to " << coolDog.getHappiness() << endl;
			break;
		case 4:
			coolDog.displayStats();
			break;
		case 5:
			return 0;
		default:2

			cout << "Learn how to use a menu" << endl;
			break;
		}
	}

}
