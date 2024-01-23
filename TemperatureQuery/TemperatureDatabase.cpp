#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase():records(),year(0),month(0),id(""),temperature(0.0){}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	int year =0;
	int month = 0;
	std::string id = "";
	double temperature = 0.0;
	string temp = "";
	ifstream is;
	is.open(filename);
	if(!is.is_open()){
		cout << "Error: Unable to open " << filename << endl;
	}
	else{
		while(getline(is,temp)){
			stringstream is2(temp);
			is2 >> id;
			is2 >> year;
			is2 >> month;
			is2 >> temperature;
			if(is2.fail()){
				cout << "Error: Other invalid input" << endl;
			}
			if(year < 1800 || year > 2022){
				cout << "Error: Invalid year " << year << endl;
			}
			if(month < 1 || month > 12){
				cout << "Error: Invalid month " << month << endl; 
			}
			if((temperature < -50.00 && temperature != -99.99) || temperature > 50.0){
				cout << "Error: Invalid temperature " << temperature << endl;
			}
			records.insert(id,year,month,temperature);
		}
	}
	is.close();

}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
	ifstream input(filename);
	if(!input.is_open()){
		cout << "Error: Unable to open " << filename << endl;
	}
	input.close();
}
