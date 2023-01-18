#include <iostream>
using namespace std;



int day;
int month;
int year;
int charCount1 = 0;
int charCount2 = 0;
int monthLength = 0;
string listOfMonths = "January Febuary March April May June July August September October November December";
int main()
{
    cout << "Please enter a date (MM DD YYYY): " << endl;
    cin >> month >> day >> year;
    int tempMonth = month;

    while (tempMonth != 0)
    {
        if (listOfMonths[charCount2] == " ")
        {
            monthLength = charCount2 - charCount1;
            tempMonth--;
            charCount1 = charCount2 + 1;
        }

        charCount2++;
    }

    string monthName = listOfMonths.substr(charCount1, monthLength);
    cout << "Your date is: " << monthName << day << "," << year << endl;



}
