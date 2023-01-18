#include <iostream>
using namespace std;



void eraseFile() {
    cout << "T";
}

void showMenu() {
    cout << "Q";
    eraseFile();
}


void processRequest() {
    cout << "2";
}

int main()
{
    showMenu();
    eraseFile();
    cout << "B";
    showMenu();
}
