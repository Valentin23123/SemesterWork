#pragma once
#include <iostream>
using namespace std;

void printMenu()
{
    cout << endl;
    cout << "1. Add a new property " << endl;
    cout << "2. Display all real estate properties  " << endl;
    cout << "3. Search and display a property " << endl;
    cout << "4. Arraging properties in ascending order of the price " << endl;
    cout << "5. Insert from a file or input in a file " << endl;
    cout << "6. Enter the sub menu " << endl;
    cout << "0. Exit from the program " << endl;
    cout << endl;
}

void subMenu()
{
    cout << "1. Choose a broker and sort price properties" << endl;
    cout << "2. Choose how many rooms and sort the properties" << endl;
    cout << "3. Edit a property" << endl;
    cout << "4. Property reference" << endl;
    cout << "5. Back to the main menu" << endl;
}