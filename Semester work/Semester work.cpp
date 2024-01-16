// СеместриалнаРабота.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "functions.h"
#include "menus.h"
#include "struct.h"
using namespace std;

const int MAX_PROPERTIES = 100;
int main()
{
    realEstate properties[MAX_PROPERTIES];
    int propertyCounter = 0;
    int choice = -1;
    int numberOfProperties;
    ofstream outFile;
    fstream data;
    fstream binFile;
    ifstream outBinFile;
    while (choice != 0)
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl;
            cout << "1. Add a single property " << endl;
            cout << "2. Add a list of properties" << endl;
            cout << "Your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                numberOfProperties = 1;
                addProperty(properties, propertyCounter, numberOfProperties);
            }
            else if (choice == 2)
            {
                cout << "Enter how many properties do you want to add: ";
                cin >> numberOfProperties;
                addProperty(properties, propertyCounter, numberOfProperties);
            }
            else
            {
                cout << endl;
                cout << "INVALID OUTPUT";
                cout << endl;
            }
            break;
        case 2:
            displayProperties(properties, propertyCounter);
            break;
        case 3:
            cout << endl;
            cout << "1. Display properties with the biggest area" << endl;
            cout << "2. Display properties that are already sold" << endl;
            cout << "Your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                displayBiggestAreaProperties(properties, propertyCounter);
            }
            else if (choice == 2)
            {
                displaySoldProperties(properties, propertyCounter);
            }
            else
            {
                cout << "Invalid output";
            }

            break;
        case 4:
            arragingPropertiesPrice(properties, propertyCounter);
            break;

        case 5:
            cout << endl;
            cout << "1.Insert all properties in the txt file" << endl;
            cout << "2.Insert properties from a txt file" << endl;
            cout << "3.Insert all properties in the bin file" << endl;
            cout << "4.Insert properties from a bin file" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                insertInFile(properties, propertyCounter, outFile);
            }
            else if (choice == 2)
            {
                insertDataFromFile(properties, propertyCounter, data);

            }
            else if (choice == 3)
            {
                insertInBinaryFile(properties,propertyCounter,binFile);
            }
            else if (choice == 4)
            {
                insertDataFromBinFile(properties, propertyCounter, outBinFile);
            }
            else
            {
                cout << "Wrong input!" << endl;
            }
            break;

        case 6:
            subMenu();
            cout << endl << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                string name;
                cin.ignore();
                cout << "Enter the name of the broker: ";
                getline(cin, name);
                specificBrokerSortPrice(properties, propertyCounter, name);
            }
            else if (choice == 2)
            {
                int numberOfRooms;
                cout << "Enter how many number of rooms do you want: ";
                cin >> numberOfRooms;
                numberOfRoomsSortPrice(properties, propertyCounter, numberOfRooms);
            }
            else if (choice == 3)
            {
                long refNum;
                cout << "Enter the refereal number of the property you want to change: ";
                cin >> refNum;
                editProperty(properties,propertyCounter, refNum);
            }
            else if (choice == 4)
            {
                string region;
                cout << "1. Most expensive property in a specific region"<<endl;
                cout << "2. Average price in a specific region"<<endl;
                cout << "3. Sale percent rate by a broker"<<endl;
                cout << "4. Exit"<<endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    
                    cout << "Enter the specific region: ";
                    cin >> region;
                    mostExpensivePropertyRegion(properties,propertyCounter,region);
                }
                else if (choice == 2)
                {
                    cout << "Enter the specific region: ";
                    cin>>region;
                    averagePricePropertyRegion(properties, propertyCounter, region);
                   
                }
                else if (choice == 3)
                {
                    string name;
                    cin.ignore();
                    cout << "Enter the name of the broker: ";
                    getline(cin, name);
                    percentRateByBroker(properties, propertyCounter, name);
                }
                if (choice == 4)
                {
                    break;
                }
                
            }
            else if (choice == 5)
            {

                break;
            }


        default:
            break;
        }


        

    }

}

