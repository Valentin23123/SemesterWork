#pragma once


#include<string>
#include "struct.h"
using namespace std;

void addProperty(realEstate properties[], int& propertyCounter, int numberOfProperties);

void displayProperties(realEstate properties[], int propertyCounter);

void displaySoldProperties(realEstate properties[], int propertyCounter);

void displayBiggestAreaProperties(realEstate properties[], int propertyCounter);

void arragingPropertiesPrice(realEstate properties[], int propertyCounter);

void insertInFile(realEstate properties[], int propertyCounter, ofstream& outFile);

void insertDataFromFile(realEstate properties[], int& propertyCounter, fstream& data);

void specificBrokerSortPrice(realEstate properties[], int propertyCounter, string name);

void numberOfRoomsSortPrice(realEstate properties[], int propertyCounter, int numberOfRooms);

void editProperty(realEstate properties[], int propertyCounter, long refNum);

void mostExpensivePropertyRegion(realEstate properties[], int propertyCounter, string region);

void averagePricePropertyRegion(realEstate properties[], int propertyCounter, string region);

void percentRateByBroker(realEstate properties[], int propertyCounter, string name);

void insertInBinaryFile(realEstate properties[], int propertyCounter, fstream& binFile);

void insertDataFromBinFile(realEstate properties[], int& propertyCounter, ifstream& outBinFile);