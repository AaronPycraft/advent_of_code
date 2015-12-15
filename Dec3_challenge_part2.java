//--File: dec2_challenge.cpp
//  Author: Aaron Pycraft
//  Created: 12/14/2015
//  Description: This program will be used to solve the Advent of Code 
//  challenges for December 3rd

/* --- Day 3: Perfectly Spherical Houses in a Vacuum ---
 * Santa is delivering presents to an infinite two-dimensional grid of 
 * houses. He begins by delivering a present to the house at his starting 
 * location, and then an elf at the North Pole calls him via radio and tells
 * him where to move next. Moves are always exactly one house to the north 
 * (^), south (v), east (>), or west (<). After each move, he delivers 
 * another present to the house at his new location.
 * However, the elf back at the north pole has had a little too much eggnog, 
 * and so his directions are a little off, and Santa ends up visiting some 
 * houses more than once. How many houses receive at least one present?
 * 
 * For example:
 * 
 * > delivers presents to 2 houses: one at the starting location, and one to the 
 * east.
 * ^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
 * ^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.
 * 
 * --- Part Two ---
 * The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.
 * Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.
 * This year, how many houses receive at least one present?
 * For example:
 * ^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
 * ^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
 * ^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.
 */

package advent_of_code;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import advent_of_code.ChristmasHouseLocation;

public class Dec3_challenge_part2 {
	//--variables
	static ChristmasHouseLocation santa;
	static ChristmasHouseLocation robot;
	static Set<ChristmasHouseLocation> visited;

	//--Main method
	public static void main(String[] args) {
		//--initialize variables
		santa = new ChristmasHouseLocation(0,0); //--santas location
		robot = new ChristmasHouseLocation(0,0); //--robot's location
		visited = new HashSet<ChristmasHouseLocation>();//--all visited houses
		
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
		
		//--Output result for part 2
		System.out.println("The number of houses visited at least once "
				+ "by either santa or his robot is " + visited.size());
		
	}//end main
	public static void processInput(char[] input) {
		//--Visit the house at the starting location
		visited.add(santa);
		visited.add(robot);
		
		for(int i = 0; i < input.length; i++) {
			//--Santa and the robot take turns following the input directions
			if(i % 2 == 0)
				santa = next(input[i], santa); //--move santa to next house
			else 
				robot = next(input[i], robot); //--move santa to next house
			
			//--add the locations to the set
			visited.add(santa);
			visited.add(robot);
		}//end loop
	}//end method
	
	//--Returns house location of santa/robot after following input direction
	public static ChristmasHouseLocation next(char input, ChristmasHouseLocation h) {
		switch(input) {
		  case '^': 
		    return new ChristmasHouseLocation(h.getX(), h.getY() + 1);
		  case 'v':
			return new ChristmasHouseLocation(h.getX(), h.getY() - 1);
		  case '<':
			return new ChristmasHouseLocation(h.getX() - 1, h.getY());
		  case '>':
			return new ChristmasHouseLocation(h.getX() + 1, h.getY());
	  }//end switch
		System.out.println("SOMETHING WENT WRONG");
		return null;
	}//end method
}//end class

