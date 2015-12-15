package advent_of_code;

//--File: ChristmasHouseLocation.java
//  created on: 12/14/2015
//  author: aaron pycraft

//--This class with be used to represent a location for 
//  santa to visit for advent of code challenge  December 3
public class ChristmasHouseLocation {
	//--Variables
	private int x;
	private int y;
	
	//--Constructors
	public ChristmasHouseLocation() {}
	public ChristmasHouseLocation(int x, int y) {
		this();
		this.x = x;
		this.y = y;
	}//end constructor
	
	//--Methods
	int getX() {
		return this.x;
	}
	int getY() {
		return this.y;
	}
	void setX(int x) {
		this.x = x;
	}
	void setY(int y) {
		this.y = y;
	}

	//--Returns true if the other christmas house is at the
	//  same location
	@Override
	public boolean equals(Object o) {
		//--check if the objects refer to the same data
		if (this == o) return true;
		//--bail if the object to compare to is null, or of the wrong class
        if (o == null || getClass() != o.getClass()) return false;

        //--Cast the object to compare to as the correct type
        ChristmasHouseLocation otherHouse = (ChristmasHouseLocation) o;
        
        //--compare the house locations of each object
        if (x != otherHouse.x) return false;
        return y == otherHouse.y;
		
	}//end method
	
	
	//--returns hashfunction of house location
	@Override
	public int hashCode() {
		return  (x*100 + 7*y);
	}
	//--communicates string information
	public String toString() {
//		return hasBeenVisited + "\t(" + x + "," + y + ")";
		return "\t(" + x + "," + y + ")";
	}
	
}//end class
