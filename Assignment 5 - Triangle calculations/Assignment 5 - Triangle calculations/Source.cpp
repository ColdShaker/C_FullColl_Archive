/* Triangle Calculations Script 
* 
* This script is designed to calculate the perimiter and area of a custom triangle inputted by the user
* The user inputs two side lengths (a,b) and an angle (angle C).
* With these inputs, the program will calculate the area and permiter of the triangle
* 
*/




#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	float sideA;
	float sideB;
	float angleC;

	float sideC;
	float angleA;
	float angleB;
	float SP;
	float area;
	float pi = 3.14159265;
	
	float angleARad;
	float angleBRad;
	float angleCRad;
	
	//prompts the user for input 
	cout << "Please enter the lengths of Sides a and b: ";
	cin >> sideA >> sideB;
	cout << "Please enter the size of Angle C in degrees ";
	cin >> angleC;
	
	
	
	//angle C needs to be converted to radians because the sine function's input is radians
	angleCRad = angleC * (pi / 180);
	
	//sideC is calculated using the cosine forumula 
	sideC = sqrt(pow(sideA, 2.0) + pow(sideB, 2.0) - 2.0 * sideA * sideB * cos(angleCRad));

	//angleA and angleB are calculated using the sine formule
	angleA = asin((sideA * sin(angleCRad)) / sideC) * (180 / pi);
	angleB = asin((sideB * sin(angleCRad)) / sideC) * (180 / pi);
	
	//We calculate area using heron's formula 
	//SP stands for semiperimeter
	SP = (sideA + sideB + sideC) / 2;
	area = sqrt(SP * (SP - sideA)*(SP - sideB)*(SP - sideC));
	float perimeter = sideA + sideB + sideC;
	
	//This is where we display the length of all 3 sides of the triangle 
	cout << "        /\\        " << endl;
	cout << "       /  \\       " << endl;
	cout << "      /    \\      " << endl;
	printf("%3.1f" , sideA); //I use printf here so that the numbers always have exactly 1 decimal place, and the triangle will not be screwed up
	cout << " /      \\ ";
	printf("%3.1f\n", sideB);
	cout << "    /        \\      " << endl;
	cout << "   /          \\     " << endl;
	cout << "  /____________\\    " << endl;
	cout << "       ";
	printf("%3.1f\n\n", sideC);

	//This is where i display all of the information about the triangle. To keep the numbers aligned, i used the printf function.
	//All the numbers will be right justified and will have 3 decimal places 
	printf("%7.3f = Side a\n", sideA);
	printf("%7.3f = Side b\n", sideB);
	printf("%7.3f = Side c\n", sideC);
	printf("%7.3f = Angle A in degrees\n", angleA);
	printf("%7.3f = Angle B in degrees\n", angleB);
	printf("%7.3f = Angle C in degrees\n", angleC);
	printf("%7.3f = Perimeter\n", perimeter);
	printf("%7.3f = Area\n", area);

	return 0;
}