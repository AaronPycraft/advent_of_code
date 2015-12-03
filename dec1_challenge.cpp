//--File: dec1_challenge1.cpp
//  Author: Aaron Pycraft
//  Date Created: 12/2/2015
//  Synopsis: This program will be used to solve Dec1 challenge 1 of the 
//  adventOfCode challenge. This challenge involves Santa getting an 
//  input file containing instructions to go up a floor, or down a floor
//  to deliever presents in a very tall, very deep apartment building

//#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//--processes input
//void processInput(int &floor, const string input); //--part 1 version
int processInput(int &floor, const string input);

int main() {
  //--Variables
  int floor = 0; //santa starts at floor zero
  fstream fileIn;//--object to read from file
  string input;//-input from file

  //--Initialize file object
  fileIn.open("dec1_challenge1_input.txt");

  //--If the file could not be opened, display an error
  if(! fileIn.is_open()) {
    cerr << "Unable to open file." << endl;
    return 1;
  }//end if

  //--Input data from file. The file contains one long string
  fileIn >> input;
  
  //--determine final floor
  //processInput(floor, input); //--Part 1
  int posEnterBsmnt = processInput(floor, input);  
  //--close the file
  fileIn.close();
  
  //--ouput result
  //cout << "End floor = " << floor << endl; //--Part 1
  //138 is the correct answer

  cout << "Santa will enter the basement at position: ";
  cout << posEnterBsmnt << endl;

}//end main

//--Modifies the floor number depending on the directions in the input
//--Part 1 version 
/*
int processInput(int &floor, const string input) {
  //--characters to determint floor up/down action
  const char upChar = '(';
  const char downChar = ')';
  for(int i = 0; i < input.length(); i++) {
    if(input.at(i) == upChar) floor++;
    else if(input.at(i) == downChar) floor--;
  }//end for
}//end function
*/

//  Part2: What is the position of the character that causes Santa to first
//  enter the basement?
//  Method was copied, and modified to stop processing input, and to return
//  the char location ASAP
int processInput(int &floor, const string input) {
  //--characters to determint floor up/down action
  const char upChar = '(';
  const char downChar = ')';
  for(int i = 0; i < input.length(); i++) {
    if(input.at(i) == upChar) floor++;
    else if(input.at(i) == downChar) {
      floor--;
      //--If this causes santa to enter the basement, return the positon
      //  need to return i+1, because the 1st character is char # 1 (not 0)
      if(floor == -1) return i+1; //--Correct answer: 1771
    }//end if
  }//end for
}//end function
  
