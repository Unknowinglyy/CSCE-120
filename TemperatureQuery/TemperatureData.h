/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>
struct TemperatureData {
	// Put data members here
	std::string id;
	int year;
	int month;
	double temperature;
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	void setID(std::string id);
	std::string getID();
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setTemp(double temp);
	double getTemp();
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */
