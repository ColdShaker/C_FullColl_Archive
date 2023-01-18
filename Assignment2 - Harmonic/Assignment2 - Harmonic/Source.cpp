#include <iostream>
using namespace std;

float harmonicNum(int arrayPos);
void fillHarmonic(float arr[]);

int main()
{
    float hValues[10];
    fillHarmonic(hValues);

    for (int i = 0; i <= 9; i++)
    {
        cout << hValues[i] << endl;
    }
}

//creates a harmonic output for whatever input given
float harmonicNum(int arrayPos)
{
    if (arrayPos == 0)
    {
        return 1;
    }

    return harmonicNum(arrayPos - 1) + (1.0 / (1.0 + arrayPos));

}


void fillHarmonic(float arr[])
{

    for (int i = 0; i <= 9; i++)
    {
        arr[i] = harmonicNum(i);
    }

}
