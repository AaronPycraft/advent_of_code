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
  string inputLine;
  vector<int> lwh; //length, width, height
  string l, w, h;

  //--split line into separate units of lenght, width, height
  for(int i = 0; i < inputLine.length(); i++) {
    int delimIndx;
    if (inputLine[i] == 'x') {
      //--
      delimIndx = i;
    }//end if
    
    //--get string from beginning to the delimiter
    for


  }//end loop
  

  /*
  std::ifstream infile("thefile.txt");
  std::string line;//input line

  while (std::getline(infile, line))
  {
    std::istringstream iss(line);
    int n;
    std::vector<int> v;

    while (iss >> n) {
      v.push_back(n);
    }

    // do something useful with v
  }
 */
}//end function
