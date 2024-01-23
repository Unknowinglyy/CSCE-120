/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.text
content: The text file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;

int main()
{
    // TODO: create arrays needed
	string input;
	double timeArray[SIZE];
	string countryArray[SIZE];
	unsigned int numberArray[SIZE];
	string lastnameArray[SIZE];
	unsigned int rankArray[SIZE];
	bool exceptionThrown = false;
	
	prep_double_array(timeArray);
	prep_string_array(countryArray);
	prep_unsigned_int_array(numberArray);
	prep_unsigned_int_array(rankArray);
	prep_string_array(lastnameArray);
	cout << "Enter file name: ";
	cin >> input;
	try{
		get_runner_data(input,timeArray,countryArray,numberArray,lastnameArray);
		get_ranking(timeArray, rankArray);
		print_results(timeArray, countryArray, lastnameArray, rankArray);
	}
	catch(std::domain_error& except){
		std::cout << "Invalid File: ";
		std::cout << except.what() << std::endl;
		exceptionThrown = true;
	  }
	catch(std::invalid_argument& except2){
		std::cout << "Invalid File: ";
		std::cout << except2.what() << std::endl;
		exceptionThrown = true;
	}
	while(exceptionThrown){
		try{
			cout << "Enter file name: ";
			cin >> input;
			get_runner_data(input,timeArray,countryArray,numberArray,lastnameArray);
			get_ranking(timeArray, rankArray);
			print_results(timeArray, countryArray, lastnameArray, rankArray);
			exceptionThrown = false;
		}
		catch(std::domain_error& except){
			std::cout << "Invalid File: ";
			std::cout << except.what() << std::endl;
			exceptionThrown = true;
		  }
		catch(std::invalid_argument& except2){
			std::cout << "Invalid File: ";
			std::cout << except2.what() << std::endl;
			exceptionThrown = true;
		}		
	}
	
    // TOTO: prep all arrays
	
    // TODO: prompt until both the file and the contained data are valid
	
    // TODO: determine ranking, notice the rank array receives the results

    // TODO: Output results

    return 0;
}

