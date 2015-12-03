//--File: dec2_challenge.cpp
//  Author: Aaron Pycraft
//  Created: 12/2/2015
//  Description: This program will be used to solve the Advent of Code 
//  challenges for December 2nd

/*
  Challenge prompt:
  http://adventofcode.com/day/2
*/

#include <cstdlib> //for exit()
#include <fstream>
#include <iostream>

using namespace std;

//--Function prototypes
void initFile(fstream &file);

int main() {
  //--Variables
  fstream fileIn; //--files used to obtain input from file

  initFile(fileIn);

  string input;
  while(!fileIn.eof()) {
    getline(fileIn,input);
    std::cout << input << endl;
    break;
  }//end while
 
  return 0;
}//end main


//--Initilze file object, and do error checking
void initFile(fstream &fileIn) {
  fileIn.open("dec2_challenge_input.txt");
  //--If the file could not be opened, display an error
  if(! fileIn.is_open()) {
    cout << "ERROR" << endl;
    cerr << "Unable to open file." << endl;
    exit(20); 
  }//end if
}//end function
