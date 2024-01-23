#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "parallel_tracks.h"

using std::string;


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given
//---------------------------------------------------------
void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
  //TODO
  std::fstream inputFile(file);
  string line = "";
  string temp;
  string nameTemp;
  double time;
  unsigned int number;
  string numTest;
  string lastnameTest;
  int i = 0;
  if(!inputFile.is_open()){
	  throw std::invalid_argument("Cannot open file");
  }
  while(getline(inputFile, line) && !inputFile.fail()){
	  line = trim(line);
	  if(line == "" && !inputFile.eof()){
		  throw std::domain_error("File missing data");
	  }
	  std::stringstream(line) >> time;
	  timeArray[i] = time;
	  if(timeArray[i] <= 0 || !(std::stringstream(line) >> time)){
		  throw std::domain_error("File contains invalid data (time)");
	  }
	  line = line.substr(line.find(" ")+1);
	  std::stringstream(line) >> temp;
	  countryArray[i] = temp;
	  for(long unsigned int x = 0; x < countryArray[i].size(); x++){
		  if(!isupper(countryArray[i][x])){
			  throw std::domain_error("File contains invalid data (country)");
			  break;
		  }
	  }
	  if(countryArray[i].size() != 3 ||!(std::stringstream(line) >> temp)){
		  throw std::domain_error("File contains invalid data (country)");
	  }
	  line = line.substr(line.find(" ")+1);
	  std::stringstream(line) >> number;
	  numberArray[i] = number;
	  numTest = std::to_string(number);
	  if(!(std::stringstream(line)>>number) || numTest.size() > 2){
		  throw std::domain_error("File contains invalid data (number)");
	  }
	  line = line.substr(line.find(" ")+1);
	  nameTemp = std::stringstream(line).str();
	  lastnameArray[i] = nameTemp;
	  lastnameTest = trim(lastnameArray[i]);
	  for(long unsigned int j = 0; j < lastnameTest.size(); j++){
		  if(!isalpha(lastnameTest[j]) && !isspace(lastnameTest[j])){
			  throw std::domain_error("File contains invalid data (name)");
			  break;
		  }
	  }
	  if(lastnameTest.size() <= 1){
		  throw std::domain_error("File contains invalid data (name)");
	  }
	  i++;
  }
  inputFile.close();
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
  for(int i = 0; i < 9; i++){
	  ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	//TODO
	for(int i = 0; i < 9; i++){
	  ary[i] = 0;
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	//TODO
	for(int i = 0; i < 9; i++){
	  ary[i] = "N/A";
  }
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	int rank = 0;
	for(long unsigned int i = 0; i < SIZE; i++){
		rank = 1;
		for(long unsigned int j = 0; j < SIZE; j++){
			if(timeArray[j] < timeArray[i]){
				rank++;
			}
		}
	rankArray[i] = rank;
	}	
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}