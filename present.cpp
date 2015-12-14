//--File: present.cpp
//  author: aaron pycraft
//  Date created: 12/13/2015
//
//--This class is used to represent the presents given in advent of code challenge 
//  day 2, december 2nd.  

class present {
  private:
    int length;
    int width;
    int height;

  public:
    //--Constructors
    present();
    present(int l, int w, int h);

    //--Accessors
    void setLength(int l);
    void setWidth(int w);
    void setHeight(int h);

    //--Mutators
    int getLength();
    int getHeight();
    int getWidth();

    //--Computations
    int getSurfaceArea();
    double getAreaSmallestSide();
    int getSmallestPerimiter();
    int getVolume();

};//end class

//--Constructors
present::present() {}
present::present(int l, int w, int h) {
}

//--Accessors
void present::setLength(int l) {
  present::length = l;
}
void present::setWidth(int w) {
  present::width = w;
}
void present::setHeight(int h) {
  present::height = h;
}

//--Mutators
int present::getLength() {
  return present::length;
}
int present::getWidth() {
  return present::width;
}
int present::getHeight() {
  return present::height;
}

//--computes and returns surface area of present
int present::getSurfaceArea() {
  return 2*(length*width + length*height + width*height); 
}

//--computes and returns the area of the smallest side
//  there are 3 cases for the smallest side, lw lh wh
//  To quickly find the two smaller values:
//    1. find max
//    2. multiply all dimensions
//    3. divide by max
double present::getAreaSmallestSide() {
  //--variables
  int max = -1;
  int temp[] = {length, width, height};
  //--determine smallest side
  for(int i = 0; i < 3; i++) {
    if (temp[i] > max) max = temp[i];
  }//end for

  return double(temp[0] * temp[1] * temp[2])/max;
}//end function
  
//--returns the value of the smallest perimiter of the box
//  the smallest permiter will be 2x the smallest sum of two sides
//  we can get the smallest permiter by setting the largest side length to 0
//  and compute 2 x the sum of length of sides
int present::getSmallestPerimiter() {
  //--variables
  int max = -1;
  int temp[] = {length, width, height};
  //--determine smallest side
  for(int i = 0; i < 4; i++) {
    //--If we're at the last iteration...
    if( i > 2)  { 
      //--after the max has been found, set that value to zero
      temp[max] = 0; break;
    } 
    else if (temp[i] > temp[max]) max = i;
  }//end for

  //--perimiter is the sum of the lengts of sides, with the largest side set
  //  to zero, we can just sum twice the length of each side
  return (2*temp[0] + 2*temp[1] + 2*temp[2]);
}

//--computes and returns cubic volume
int present::getVolume() {
  return length*width*height;
}
