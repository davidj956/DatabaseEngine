#include "Table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

ifstream inFile;
ofstream outFile;



void Table::setTableName(string userTableNameInput)
{
	this->tableName = userTableNameInput + ".csv";
}

//---------------------------------------------------------------------------------

string Table::getTableName()
{
	return tableName;
}

//---------------------------------------------------------------------------------

void Table::makeTable(string)
{
	ofstream outFile(tableName);
}

//----------------------------------------------------------------------------------


void Table::chooseFieldNames(int noOfFieldResponse, string *fieldArray)
{
	outFile.open((fileLocation + tableName).c_str());
	for (i = 0; i < noOfFieldResponse; i++)
	{
		cout << "Enter Field Name " << i + 1 << ": " << endl;
		cin >> fieldArray[i];
		outFile << fieldArray[i] << ",";
	}
	
	outFile << endl;
	outFile.close();

}

//----------------------------------------------------------------------------------

void Table::displayFieldNames(string tableName, int noOfFieldResponse)
{
	string field, fileLocation;
	fileLocation = "C:\\Users\\David\\Documents\\Visual Studio 2012\\Projects\\Database2403\\Database2403\\";

	inFile.open((fileLocation + tableName + ".csv").c_str());

	cout << "\nYour chosen fields are:\n" << endl;

	for (int i = 0; i < noOfFieldResponse; i++)
	{
		getline(inFile, field, ',');
		cout << field << "\t";
	}

	inFile.close();

}

//--------------------------------------------------------------------------------------


void Table::addNewRecord(int noOfFieldResponse, string tableName, int noOfRows)
{
	string field, fileLocation, *recordArray;
	int i;

	fileLocation = "C:\\Users\\David\\Documents\\Visual Studio 2012\\Projects\\Database2403\\Database2403\\";

	inFile.open((fileLocation + tableName +  ".csv").c_str());
	outFile.open(tableName +".csv", std::ios::app);
	//http://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
	

	for (int i = 0; i < noOfFieldResponse; i++)
	{
		if (i == noOfFieldResponse - 1)
		{
		getline(inFile, field, ',');
		cout << "\n Choose Value for " << field << ": " << endl;
		recordArray = new string[noOfFieldResponse + 1];
		cin >> recordArray[i];
		outFile << recordArray[i] << "\n";
		}
		else
		{
		getline(inFile, field, ',');
		cout << "\n Choose Value for " << field << ": " << endl;
		recordArray = new string[noOfFieldResponse + 1];
		cin >> recordArray[i];
		//outFile << endl;
		outFile << recordArray[i] << ",";
		}
	}
	inFile.close();
	outFile.close();
}

//----------------------------------------------------------------------------------------------


void Table::updateRecord()
{

}

//---------------------------------------------------------------------------------------------


int getNoOfFields(string tableName)
{
	string fileLocation = "C:\\Users\\David\\Documents\\Visual Studio 2012\\Projects\\Database2503\\Database2503\\";

	   //code referenced from http://stackoverflow.com/questions/23042707/getting-the-number-of-columns-and-rows-of-a-csv-file-in-c
			 ifstream file(fileLocation + tableName +".csv");
			 string line;
			 int tot = 0;
			 int row = 0;
			 
			 while (getline(file, line))
			 {
				 std::istringstream iss(line);
				 string result;
				 while (getline(iss, result, ','))
				 {
					 tot = tot + 1;
				 }
				 row = row + 1;   
			 }
	//end of reference

			int noOfFields = tot/row;
			return noOfFields;
}

//----------------------------------------------------------------------------------------------------


int getNoOfRows(string tableName)
{
	string fileLocation = "C:\\Users\\David\\Documents\\Visual Studio 2012\\Projects\\Database2503\\Database2503\\";


	//code referenced from http://stackoverflow.com/questions/23042707/getting-the-number-of-columns-and-rows-of-a-csv-file-in-c
	ifstream file(fileLocation + tableName);
     string line;
     int tot = 0;
     int row = 0;

     while (getline(file, line))
     {
         istringstream iss(line);
         string result;
         while (getline(iss, result, ','))
         {tot = tot + 1;}
         row = row + 1;
	 }
	 //end of reference
	 int noOfRows = row;
	 return noOfRows;
}
