// Class file for StatePark class

#include "Passport.h"

using std::string, std::vector;

// Mandatory
// Constructor for StatePark class
// TODO(student): implement constructor using member initializer list
StatePark::StatePark(std::string parkName, double entranceFee, double trailMiles): parkName(parkName), entranceFee(entranceFee), trailMiles(trailMiles), camperLog({}){
}

// Mandatory
// Getter for data member parkName
string StatePark::getParkName() {
	return parkName;
}

// Mandatory
// Getter for data member entranceFee
double StatePark::getEntranceFee() {
	return entranceFee;
}

// Mandatory
// Getter for data member trailMiles
double StatePark::getTrailMiles() {
	// TODO(student): implement getter
	return trailMiles;
}

// Mandatory
// Adds a camper (represented by Passport object) to data member camperLog
void StatePark::addCamper(Passport* camper) {
	INFO(camper)
	// TODO(student): implement function
	camperLog.push_back(camper);
	return;
}

// Option A
// Calculates the park revenue based on the campers in camperLog
double StatePark::getRevenue() {
	// TODO(student): implement function
	return 0.0;
}