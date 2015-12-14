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
  


