

/*
Change Calculator
*/



#include <iostream>
using namespace std;

int gPrice;
int sPrice;
int kPrice;

int gCash;
int sCash;
int kCash;

int gChange;
int sChange;
int kChange;

int Calculator()
{
    cout << "Welcome to Flourish and Blotts" << endl;
    cout << "Please enter amount of sale (G S K):";
    cin >> gPrice >> sPrice >> kPrice;
    cout << "Please enter amount given (G S K):";
    cin >> gCash >> sCash >> kCash;

    if (kCash >= kPrice)
    {
        kChange = kCash - kPrice;
    }
    else if (sCash >= 1)
    {
        sCash--;
        kCash = kCash + 29;
        kChange = kCash - kPrice;
    }
    else if (gCash >= 1)
    {
        gCash--;
        sCash = sCash + 17;
        sCash--;
        kCash = kCash + 29;
        kChange = kCash - kPrice;
    }
    else
    {
        cout << "Insufficient Funds" << endl;
        return 0;
    }


    if (sCash >= sPrice)
    {
        sChange = sCash - sPrice;
    }
    else if (gCash >= 1)
    {
        gCash--;
        sCash = sCash + 17;
        sChange = sCash - sPrice;
    }
    else
    {
        cout << "Insufficient Funds" << endl;
        return 0;
    }

    if (gCash >= gPrice)
    {
        gCash = gCash - gPrice;
    }
    else
    {
        cout << "Insufficient Funds" << endl;
        return 0;
    }


    cout << gChange << sChange << kChange <<
}