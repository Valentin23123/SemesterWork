#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

void addProperty(realEstate properties[], int& propertyCounter, int numberOfProperties)
{

    for (int i = 0; i < numberOfProperties; i++)
    {
        if (propertyCounter >= 100)
        {
            cout << "You are out of storage. The limit is 100 propery!";
            break;
        }
        else
        {
            if (propertyCounter > 0)
            {
                bool flagRefExit = false;
                do
                {
                    cout << endl;
                    cout << "Enter a ref numner: ";
                    cin >> properties[propertyCounter].refNum;
                    flagRefExit = false;
                    for (int j = 0; j < propertyCounter; j++)
                    {
                        if (properties[j].refNum == properties[propertyCounter].refNum)
                        {
                            flagRefExit = true;
                            cout << endl;
                            cout << "Error: Property with this ref number already exists. Please choose a different one." << endl;
                            break;
                        }
                    }
                } while (flagRefExit);
            }
            else
            {
                cout << endl;
                cout << "Enter a ref numner: ";
                cin >> properties[propertyCounter].refNum;
            }


            cout << "Enter the broker name (first name and last name): ";
            cin.ignore();
            getline(cin, properties[propertyCounter].brokerName);
            cout << "Enter the type of the property: ";
            cin >> properties[propertyCounter].type;
            cout << "Enter the region of the propery: ";
            cin >> properties[propertyCounter].region;
            cout << "Enter the exposure of the property: ";
            cin >> properties[propertyCounter].exposure;
            cout << "Enter the price of the property: ";
            cin >> properties[propertyCounter].price;
            cout << "Enter the area of the property: ";
            cin >> properties[propertyCounter].area;
            cout << "Enter the number of rooms in the property: ";
            cin >> properties[propertyCounter].numbersOfRooms;
            cout << "Enter the floor of the property: ";
            cin >> properties[propertyCounter].floor;

            while (properties[propertyCounter].status != "sold"
                && properties[propertyCounter].status != "reserved"
                && properties[propertyCounter].status != "free")
            {
                cout << "Enter the status [sold/reserved/free]: ";
                cin >> properties[propertyCounter].status;
                if (properties[propertyCounter].status == "reserved")
                {
                    properties[propertyCounter].price = properties[propertyCounter].price * 0.8;
                }
            }

            propertyCounter++;
        }


    }


}

void displayProperties(realEstate properties[], int propertyCounter)
{
    for (int i = 0; i < propertyCounter; i++)
    {
        cout << setw(15) << setfill('-') << "" << endl;
        cout << "Id of the property: " << i + 1 << endl;
        cout << "Ref number: " << properties[i].refNum << endl;
        cout << "Broker name: " << properties[i].brokerName << endl;
        cout << "Type: " << properties[i].type << endl;
        cout << "Region: " << properties[i].region << endl;
        cout << "Exposure: " << properties[i].exposure << endl;
        cout << "Price: " << properties[i].price << endl;
        cout << "Area: " << properties[i].area << endl;
        cout << "Numbers of rooms: " << properties[i].numbersOfRooms << endl;
        cout << "Floor: " << properties[i].floor << endl;
        cout << "Status: " << properties[i].status << endl;
        cout << setw(15) << setfill('-') << "" << endl;
    }
}

void displaySoldProperties(realEstate properties[], int propertyCounter)
{
    for (int i = 0; i < propertyCounter; i++)
    {
        if (properties[i].status == "sold")
        {
            cout << setw(15) << setfill('-') << "" << endl;
            cout << "Id of the property: " << i + 1 << endl;
            cout << "Ref number: " << properties[i].refNum << endl;
            cout << "Broker name: " << properties[i].brokerName << endl;
            cout << "Type: " << properties[i].type << endl;
            cout << "Region: " << properties[i].region << endl;
            cout << "Exposure: " << properties[i].exposure << endl;
            cout << "Price: " << properties[i].price << endl;
            cout << "Area: " << properties[i].area << endl;
            cout << "Numbers of rooms: " << properties[i].numbersOfRooms << endl;
            cout << "Floor: " << properties[i].floor << endl;
            cout << "Status: " << properties[i].status << endl;
            cout << setw(15) << setfill('-') << "" << endl;
        }

    }
}
void displayBiggestAreaProperties(realEstate properties[], int propertyCounter)
{
    realEstate* newProperties = new realEstate[propertyCounter];
    copy(properties, properties + propertyCounter, newProperties);


    for (int i = 0; i < propertyCounter - 1; i++)
    {
        for (int j = 0; j < propertyCounter - i - 1; j++)
        {
            if (newProperties[j].area < newProperties[j + 1].area) {
                realEstate temp = newProperties[j];
                newProperties[j] = newProperties[j + 1];
                newProperties[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < propertyCounter; i++)
    {
        cout << setw(15) << setfill('-') << "" << endl;
        cout << "Id of the property: " << i + 1 << endl;
        cout << "Ref number: " << newProperties[i].refNum << endl;
        cout << "Broker name: " << newProperties[i].brokerName << endl;
        cout << "Type: " << newProperties[i].type << endl;
        cout << "Region: " << newProperties[i].region << endl;
        cout << "Exposure: " << newProperties[i].exposure << endl;
        cout << "Price: " << newProperties[i].price << endl;
        cout << "Area: " << newProperties[i].area << endl;
        cout << "Numbers of rooms: " << newProperties[i].numbersOfRooms << endl;
        cout << "Floor: " << newProperties[i].floor << endl;
        cout << "Status: " << newProperties[i].status << endl;
        cout << setw(15) << setfill('-') << "" << endl;
    }
    delete[] newProperties;
}
void arragingPropertiesPrice(realEstate properties[], int propertyCounter)
{
    for (int i = 0; i < propertyCounter - 1; i++)
    {
        for (int j = 0; j < propertyCounter - i - 1; j++)
        {
            if (properties[j].price > properties[j + 1].price) {
                realEstate temp = properties[j];
                properties[j] = properties[j + 1];
                properties[j + 1] = temp;
            }
        }
    }
}


void insertInFile(realEstate properties[], int propertyCounter, ofstream& file)
{
    file.open("data.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        for (int i = 0; i < propertyCounter; i++)
        {
            ;
            file << "Refnum: " << properties[i].refNum
                << ", Name: " << properties[i].brokerName
                << ", Type: " << properties[i].type
                << ", Region: " << properties[i].region
                << ", Exposure: " << properties[i].exposure
                << ", Price: " << properties[i].price
                << ", Area: " << properties[i].area
                << ", NumberOfRooms: " << properties[i].numbersOfRooms
                << ", Floor: " << properties[i].floor
                << ", Status: " << properties[i].status << endl;

        }
        file.close();
        cout << endl;
        cout << "Successfully inserted!" << endl;
    }


}

void insertDataFromFile(realEstate properties[], int& propertyCounter, fstream& file)
{
    file.open("data.txt");
    int lineCount = 0;
    string line;
    bool refNumExist = false;
    while (getline(file, line))
    {
        lineCount++;
    }
    file.close();
   
   
        file.open("data.txt");
        int from = propertyCounter;
        if (!file)
        {
            cout << "Eror opening the file! Maybe it is not created ?";
        }
        else
        {
            for (int i = from; i < from + lineCount; i++)
            {
                if (propertyCounter >= 100)
                {
                    cout << "You are out of storage. The limit is 100 propery!";
                    
                    break;
                }
                else
                {

                   
                    string label="";
                    while (label != "Status:")
                    {


                        file >> label;

                        if (label == "Refnum:") {
                            file.ignore();
                            file >> properties[i].refNum;
                            file.ignore();
                        }
                        else if (label == "Name:") {
                            file.ignore();
                            string firstName, lastName;
                            file >> firstName;
                            file >> lastName;
                            properties[i].brokerName = firstName + " " + lastName;
                            properties[i].brokerName.erase(properties[i].brokerName.size() - 1);
                            file.ignore();
                        }
                        else if (label == "Type:") {
                            file.ignore();
                            file >> properties[i].type;
                            properties[i].type.erase(properties[i].type.size() - 1);
                            file.ignore();
                        }
                        else if (label == "Region:") {
                            file.ignore();
                            file >> properties[i].region;
                            properties[i].region.erase(properties[i].region.size() - 1);
                            file.ignore();
                        }
                        else if (label == "Exposure:") {
                            file.ignore();
                            file >> properties[i].exposure;
                            properties[i].exposure.erase(properties[i].exposure.size() - 1);
                            file.ignore();
                        }
                        else if (label == "Price:") {
                            file.ignore();
                            file >> properties[i].price;
                            file.ignore();
                        }
                        else if (label == "Area:") {
                            file.ignore();
                            file >> properties[i].area;
                            file.ignore();
                        }
                        else if (label == "NumberOfRooms:") {
                            file.ignore();
                            file >> properties[i].numbersOfRooms;
                            file.ignore();
                        }
                        else if (label == "Floor:") {
                            file.ignore();
                            file >> properties[i].floor;
                            file.ignore();
                        }
                        else if (label == "Status:") {
                            file.ignore();
                            file >> properties[i].status;
                            file.ignore();
                            propertyCounter++;
                        }



                    }
                }




            }
            
                cout << endl;
            cout << "Successfully added your properties from the file!" << endl;
        }
    

    file.close();
}
void specificBrokerSortPrice(realEstate properties[], int propertyCounter, string name)
{
    realEstate* newProperties = new realEstate[propertyCounter];
    int ctr = 0;
    for (int i = 0; i < propertyCounter; i++)
    {
        if (properties[i].brokerName == name)
        {
            newProperties[ctr++] = properties[i];
        }
    }
    for (int i = 0; i < ctr - 1; i++)
    {
        for (int j = 0; j < ctr - i - 1; j++)
        {
            if (newProperties[j].price > newProperties[j + 1].price) {
                realEstate temp = newProperties[j];
                newProperties[j] = newProperties[j + 1];
                newProperties[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < ctr; i++)
    {
        cout << setw(15) << setfill('-') << "" << endl;
        cout << "Id of the property: " << i + 1 << endl;
        cout << "Ref number: " << newProperties[i].refNum << endl;
        cout << "Broker name: " << newProperties[i].brokerName << endl;
        cout << "Type: " << newProperties[i].type << endl;
        cout << "Region: " << newProperties[i].region << endl;
        cout << "Exposure: " << newProperties[i].exposure << endl;
        cout << "Price: " << newProperties[i].price << endl;
        cout << "Area: " << newProperties[i].area << endl;
        cout << "Numbers of rooms: " << newProperties[i].numbersOfRooms << endl;
        cout << "Floor: " << newProperties[i].floor << endl;
        cout << "Status: " << newProperties[i].status << endl;
        cout << setw(15) << setfill('-') << "" << endl;
    }

    delete[] newProperties;
}

void numberOfRoomsSortPrice(realEstate properties[], int propertyCounter, int numberOfRooms)
{
    realEstate* newProperties = new realEstate[propertyCounter];
    int ctr = 0;
    for (int i = 0; i < propertyCounter; i++)
    {
        if (numberOfRooms == properties[i].numbersOfRooms) {
            newProperties[ctr++] = properties[i];
        }
    }
    for (int i = 0; i < ctr - 1; i++)
    {
        for (int j = 0; j < ctr - i - 1; j++)
        {
            if (newProperties[j].price < newProperties[j + 1].price) {
                realEstate temp = newProperties[j];
                newProperties[j] = newProperties[j + 1];
                newProperties[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < ctr; i++)
    {
        cout << setw(15) << setfill('-') << "" << endl;
        cout << "Id of the property: " << i + 1 << endl;
        cout << "Ref number: " << newProperties[i].refNum << endl;
        cout << "Broker name: " << newProperties[i].brokerName << endl;
        cout << "Type: " << newProperties[i].type << endl;
        cout << "Region: " << newProperties[i].region << endl;
        cout << "Exposure: " << newProperties[i].exposure << endl;
        cout << "Price: " << newProperties[i].price << endl;
        cout << "Area: " << newProperties[i].area << endl;
        cout << "Numbers of rooms: " << newProperties[i].numbersOfRooms << endl;
        cout << "Floor: " << newProperties[i].floor << endl;
        cout << "Status: " << newProperties[i].status << endl;
        cout << setw(15) << setfill('-') << "" << endl;
    }

    delete[] newProperties;
}


void editProperty(realEstate properties[], int propertyCounter, long refNum)
{
    bool flag = false;
    for (int i = 0; i < propertyCounter; i++)
    {
        if (refNum == properties[i].refNum && properties[i].status != "sold")
        {
            flag = true;
            cout << "Enter the new data: ";
            cout << endl;
            cout << "Enter a ref numner: ";
            cin >> properties[i].refNum;
            cout << "Enter the broker name: ";
            cin.ignore();
            getline(cin, properties[i].brokerName);
            cout << "Enter the type of the property: ";
            cin >> properties[i].type;
            cout << "Enter the region of the propery: ";
            cin >> properties[i].region;
            cout << "Enter the exposure of the property: ";
            cin >> properties[i].exposure;
            cout << "Enter the price of the property: ";
            cin >> properties[i].price;
            cout << "Enter the area of the property: ";
            cin >> properties[i].area;
            cout << "Enter the number of rooms in the property: ";
            cin >> properties[i].numbersOfRooms;
            cout << "Enter the floor of the property: ";
            cin >> properties[i].floor;
            properties[i].status = "nothing";
            while (properties[i].status != "sold"
                && properties[i].status != "reserved"
                && properties[i].status != "free")
            {
                cout << "Enter the status [sold/reserved/free]: ";
                cin >> properties[i].status;
                if (properties[i].status == "reserved")
                {
                    properties[i].price = properties[i].price * 0.8;
                }
            }

        }
    }
    if (!flag)
    {
        cout << endl;
        cout << "Error! Maybe wrong referal number or the property is already sold!" << endl;
    }
}

void mostExpensivePropertyRegion(realEstate properties[], int propertyCounter, string region)
{
    int refNum = 0;
    int maxPrice = 0;
    for (int i = 0; i < propertyCounter; i++)
    {
        if (properties[i].region == region)
        {
            if (maxPrice < properties[i].price)
            {

                maxPrice = properties[i].price;
                refNum = properties[i].refNum;
            }
        }
    }
    for (int i = 0; i < propertyCounter; i++)
    {
        if (properties[i].refNum == refNum) {
            cout << endl;
            cout << "This is the property with the biggest price in " << region << ":";
            cout << endl;
            cout << setw(15) << setfill('-') << "" << endl;
            cout << "Id of the property: " << i + 1 << endl;
            cout << "Ref number: " << properties[i].refNum << endl;
            cout << "Broker name: " << properties[i].brokerName << endl;
            cout << "Type: " << properties[i].type << endl;
            cout << "Region: " << properties[i].region << endl;
            cout << "Exposure: " << properties[i].exposure << endl;
            cout << "Price: " << properties[i].price << endl;
            cout << "Area: " << properties[i].area << endl;
            cout << "Numbers of rooms: " << properties[i].numbersOfRooms << endl;
            cout << "Floor: " << properties[i].floor << endl;
            cout << "Status: " << properties[i].status << endl;
            cout << setw(15) << setfill('-') << "" << endl;
            break;

        }
    }
}

void averagePricePropertyRegion(realEstate properties[], int propertyCounter, string region)
{
    double avg = 0;
    int ctr = 0;
    bool flag = false;
    for (int i = 0; i < propertyCounter; i++)
    {
        if (properties[i].region == region)
        {
            ctr++;
            avg += properties[i].price;
            flag = true;
        }
    }
    cout << endl;
    if (flag)
    {
        cout << "This is the average price for a property " << avg / ctr << " in " << region;
    }
    else
    {
        cout << "There is not " << region << " region in the data!";
    }

}

void percentRateByBroker(realEstate properties[], int propertyCounter, string name)
{
    int ctrSold = 0;
    int ctrProp = 0;
    bool flag = false;
    for (int i = 0; i < propertyCounter; i++)
    {
        if (properties[i].brokerName == name)
        {
            flag = true;
            ctrProp++;
            if (properties[i].status == "sold")
            {
                ctrSold++;
            }
        }
    }

    if (flag)
    {
        double howManyPercent = ((double)ctrSold / ctrProp) * 100;
        cout << endl;
        cout << fixed << setprecision(2);
        cout << "This is the sell percent rate from " << name << ": " << howManyPercent << "%";
        cout << endl;
    }
    else
    {
        cout << endl << "There is not a broker with that name: " << name << endl;
    }


}


void insertInBinaryFile(realEstate properties[], int propertyCounter,fstream& binFile)
{
    binFile.open("data.bin", ios::binary | ios::app);
    if (!binFile.is_open())
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        for (int i = 0; i < propertyCounter; i++)
        {
            binFile.write(reinterpret_cast<const char*>(&properties[i].refNum), sizeof(long));

            size_t nameSize = properties[i].brokerName.size();
            binFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(size_t));
            binFile.write(properties[i].brokerName.c_str(), nameSize);
            
            size_t typeSize = properties[i].type.size();
            binFile.write(reinterpret_cast<const char*>(&typeSize), sizeof(size_t));
            binFile.write(properties[i].type.c_str(), typeSize);

            size_t regionSize = properties[i].region.size();
            binFile.write(reinterpret_cast<const char*>(&regionSize), sizeof(size_t));
            binFile.write(properties[i].region.c_str(), regionSize);

            size_t exposureSize = properties[i].exposure.size();
            binFile.write(reinterpret_cast<const char*>(&exposureSize), sizeof(size_t));
            binFile.write(properties[i].exposure.c_str(), exposureSize);

            binFile.write(reinterpret_cast<const char*>(&properties[i].price), sizeof(long double));
            binFile.write(reinterpret_cast<const char*>(&properties[i].area), sizeof(double));
            binFile.write(reinterpret_cast<const char*>(&properties[i].numbersOfRooms), sizeof(int));
            binFile.write(reinterpret_cast<const char*>(&properties[i].floor), sizeof(int));

            size_t statusSize = properties[i].status.size();
            binFile.write(reinterpret_cast<const char*>(&statusSize), sizeof(size_t));
            binFile.write(properties[i].status.c_str(), statusSize);

            
        }
        binFile.close();
        cout << endl;
        cout << "Successfully inserted!" << endl;
    }
}

void insertDataFromBinFile(realEstate properties[], int& propertyCounter, ifstream& inBinFile)
{
    inBinFile.open("data.bin", ios::binary);

    if (!inBinFile.is_open())
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        while (inBinFile.read(reinterpret_cast<char*>(&properties[propertyCounter].refNum), sizeof(long)))
        {
            size_t nameSize;
            inBinFile.read(reinterpret_cast<char*>(&nameSize), sizeof(size_t));
            properties[propertyCounter].brokerName.resize(nameSize);
            inBinFile.read(&properties[propertyCounter].brokerName[0], nameSize);

            size_t typeSize;
            inBinFile.read(reinterpret_cast<char*>(&typeSize), sizeof(size_t));
            properties[propertyCounter].type.resize(typeSize);
            inBinFile.read(&properties[propertyCounter].type[0], typeSize);

            size_t regionSize;
            inBinFile.read(reinterpret_cast<char*>(&regionSize), sizeof(size_t));
            properties[propertyCounter].region.resize(regionSize);
            inBinFile.read(&properties[propertyCounter].region[0], regionSize);

            size_t exposureSize;
            inBinFile.read(reinterpret_cast<char*>(&exposureSize), sizeof(size_t));
            properties[propertyCounter].exposure.resize(exposureSize);
            inBinFile.read(&properties[propertyCounter].exposure[0], exposureSize);

            inBinFile.read(reinterpret_cast<char*>(&properties[propertyCounter].price), sizeof(long double));
            inBinFile.read(reinterpret_cast<char*>(&properties[propertyCounter].area), sizeof(double));
            inBinFile.read(reinterpret_cast<char*>(&properties[propertyCounter].numbersOfRooms), sizeof(int));
            inBinFile.read(reinterpret_cast<char*>(&properties[propertyCounter].floor), sizeof(int));

            size_t statusSize;
            inBinFile.read(reinterpret_cast<char*>(&statusSize), sizeof(size_t));
            properties[propertyCounter].status.resize(statusSize);
            inBinFile.read(&properties[propertyCounter].status[0], statusSize);

            propertyCounter++;
            if (propertyCounter >= 100) {
                cout << "Reached the limit of properties!" << endl;
                break;
            }
        }

        inBinFile.close();
        cout << endl;
        cout << "Successfully added your properties from the file!" << endl;
    }
}