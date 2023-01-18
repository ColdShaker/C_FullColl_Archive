#include <iostream>
#include <ctime>
#include <cstdlib>

void PrintIntroduction(int Difficulty); 
bool PlayGame(int Difficulty, int &TrialNumber);
bool LevelComplete = true;

int main()
{
	int LevelDifficulty = 1;
	int TrialNumber = 1;

	PrintIntroduction(LevelDifficulty);

	while (LevelComplete == true && TrialNumber < 9)
	{
		LevelComplete = PlayGame(LevelDifficulty , TrialNumber);
		std::cin.clear(); //Clears any errors
		std::cin.ignore(); //Discards the buffer

		if (TrialNumber == 3 || TrialNumber == 6)
		{
			LevelDifficulty++;
		}
			
		
	}
	
	if (TrialNumber == 9)
	{
		std::cout << "Good job. You have hacked into the mainframe and proven yourself. Welcome to the team!" << std::endl;
	}
	else
	{
		std::cout << "We can't risk citadel secrets falling into your hands. Goodbye. *Gunshot*" << std::endl;
	}
	
	return 0;

}

void PrintIntroduction(int Difficulty)
{
	//Intro code
	std::cout << "Welcome, hacker. Pass our trials and you can join our group of elite hackers" << std::endl;
	std::cout << "You are currently on trail #" << Difficulty << std::endl;
	std::cout << "Enter the correct code to continue. . ." << std::endl;
}

 bool PlayGame(int Difficulty , int &TrialNumber)
{
	 srand(0);
	 int CodeA = rand() % Difficulty + Difficulty;
	 int CodeB = rand() % Difficulty + Difficulty;
	 int CodeC = rand() % Difficulty + Difficulty;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "\nThere are 3 numbers in the code" << std::endl;
	std::cout << "The numbers add up to be " << CodeSum << std::endl;
	std::cout << "The numbers multiply to be " << CodeProduct << std::endl;
	std::cout << "What are the numbers, master hacker?" << std::endl;

	int GuessA, GuessB, GuessC;

	//store player guess
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		TrialNumber++;

		if (TrialNumber < 9)
		{
			std::cout << "Nice job. Time to move on to trial #" << TrialNumber << std::endl;
		}
		return true;
	}
	else
	{
		std::cout << "You messed up... You will have to killed now\n";
		return false;
	}
}