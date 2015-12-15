//--File: dec2_challenge.cpp
//  Author: Aaron Pycraft
//  Created: 12/14/2015
//  Description: This program will be used to solve the Advent of Code 
//  challenges for December 3rd
package advent_of_code;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import advent_of_code.ChristmasHouseLocation;

public class Dec3_challenge {
	//--variables
	static ChristmasHouseLocation santa;
	static Set<ChristmasHouseLocation> visited;
	static Set<ChristmasHouseLocation> visited2;

	//--Main method
	public static void main(String[] args) {
		//--initialize variables
		santa = new ChristmasHouseLocation(0,0);
		visited = new HashSet<ChristmasHouseLocation>();
		
		//--declare file input objects
		String filename = "dec3_input.txt";
		File f = new File(filename);
		
		//--Attempt to input data from file
		try{
			Scanner fin = new Scanner(f);
			processInput(fin.next().toCharArray());
		}//end try
		
		catch(FileNotFoundException e) {
			e.printStackTrace();
			System.exit(0);
		}//end catch
		
		//--Output result for part 1
		System.out.println("The number of houses " 
			+ "visited at least once is " + visited.size());
		
	}//end main
	public static void processInput(char[] input) {
		//--Visit the house at the starting location
		visited.add(santa);
		
		ChristmasHouseLocation house;
		
		for(int i = 0; i < input.length; i++) {
			house = next(input[i]); //--move pointer to next house
			santa = next(input[i]); //--move santa to next house
			visited.add(house);
				
		}//end loop
	}//end method
	
	//--Returns house location after following input character
	public static ChristmasHouseLocation next(char input) {
		switch(input) {
		  case '^': 
		    return new ChristmasHouseLocation(santa.getX(), santa.getY() + 1);
		  case 'v':
			return new ChristmasHouseLocation(santa.getX(), santa.getY() - 1);
		  case '<':
			return new ChristmasHouseLocation(santa.getX() - 1, santa.getY());
		  case '>':
			return new ChristmasHouseLocation(santa.getX() + 1, santa.getY());
	  }//end switch
		System.out.println("SOMETHING WENT WRONG");
		return null;
	}//end method

}//end class

