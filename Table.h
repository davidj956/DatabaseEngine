#ifndef TABLE
#define TABLE
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Table
{

protected:
	string tableName;
	string fieldResponse;
	string fieldName;
	string *fieldArray;
	string fileLocation;
	string *recordArray;
	int i;
	int noOfFieldResponse;
	ifstream inFile;
	ofstream outFile;

public:
	//Table();
	//virtual ~Table();
	
	void setTableName(string);
	string getTableName();
	void makeTable(string);
	void chooseFieldNames(int,string*);
	void displayFieldNames(string,int);
	void addNewRecord(int,string,int);
	void updateRecord();

};

int getNoOfFields(string);
int getNoOfRows(string);

#endif
