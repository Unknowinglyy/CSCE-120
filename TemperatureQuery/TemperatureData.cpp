/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
#include <string>
using namespace std;

TemperatureData::TemperatureData():id(""),year(0),month(0),temperature(0.0){} //initialize everything

TemperatureData::TemperatureData(string id, int year, int month, double temperature): id(id), year(year), month(month), temperature(temperature){} //initialize everything

void TemperatureData::setID(string id){
	this->id = id;
}
std::string TemperatureData::getID(){
	return id;
}
void TemperatureData::setYear(int year){
	this->year = year;
}
int TemperatureData::getYear(){
	return year;
}
void TemperatureData::setMonth(int month){
	this->month = month;
}
int TemperatureData::getMonth(){
	return month;
}
void TemperatureData::setTemp(double temperature){
	this->temperature = temperature;
}
double TemperatureData::getTemp(){
	return temperature;
}
TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	return this->month < b.month;
}

