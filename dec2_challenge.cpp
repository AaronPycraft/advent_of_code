//--File: dec2_challenge.cpp
//  Author: Aaron Pycraft
//  Created: 12/2/2015
//  Description: This program will be used to solve the Advent of Code 
//  challenges for December 2nd

/*
  Challenge prompt:
  http://adventofcode.com/day/2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "present.cpp"

using std::string;

//--Global variables
string FILENAME = "dec2_challenge_input.txt";
long int totalSA;	//total surface area

//--Function prototypes
void process_input();
void addPresentSurfaceArea(present p);
void split(string numStr, int (&nums)[3]);

int main() {
  process_input();
  std::cout << "The total surface area needed is: " << std::fixed 
	  << std::setprecision(2) << totalSA << " ft^3.\n";

  return 0;
}//end main

//--Reads in the data file into a vector, holding the dimensions of each present
void process_input() {
  //--Variables
  totalSA = 0; //--total surface area of all presents
  std::ifstream fin;
  string numStr; //--to hold the file's line
  char delimiter = 'x';
  
  //--setup file reader
  if(FILENAME.length() < 1 ) {
    std::cerr << "Error, no filename exists in file_reader object.\n";
    std::exit(20);
  }//end if
  //--open the file
  fin.open(FILENAME.c_str(), std::ios::in);
  if(!fin.is_open())   {
    std::cerr << "Error, file could not be opened!.\n";
    std::exit(20);
  }//end if

  //--Begin reading file
  while(fin.good()) {
    present p; 
    //--read length
    std::getline(fin, numStr);
    if(numStr.empty()) break;

    int nums[3];
    split(numStr, nums);

    //--set the dimensions of the present
    p.setLength(nums[0]);
    p.setWidth( nums[1]);
    p.setHeight(nums[2]);
    
    //--Add this present's SA to the total
    addPresentSurfaceArea(p);

  }//end while
  
  //--close the file
  fin.close();
}//end function

//--adds a present's surface area to the running total
void addPresentSurfaceArea(present p) {
  std::cout << "\n\tAdding SA of " << p.getSurfaceArea() 
	  << "\n\t and smallArea of: " << p.getAreaSmallestSide() << "\n";
  totalSA += p.getSurfaceArea() + p.getAreaSmallestSide();
}

void split(string numStr, int (&nums)[3]) {
  //--locate the delimiters
  int d1 = numStr.find('x', 0); 
  int d2 = numStr.find('x', d1 + 1); 
  //--convert to ints, and add to number array 
  nums[0] = atoi(numStr.substr(0     , d1   		).c_str());
  nums[1] = atoi(numStr.substr(d1 + 1, d2 - 1		).c_str());
  nums[2] = atoi(numStr.substr(d2 + 1, numStr.length()	).c_str());

}//end funciton
