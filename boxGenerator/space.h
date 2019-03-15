//başlangıç space.h
#ifndef SPACE_H_INCLUDED
#define SPACE_H_INCLUDED
#include "box.h"
#include "coord.h"
#include<time.h>
#include<stdlib.h>

class space{
public:
    space();
    space(coord spaceArea);
    space(coord spaceArea,box boxtest);
    void set3dArray();
    void setNoktalar();
    void fillRandomBox(int boxNum,int maxBoxSize, int dens);
    void cogCal();//center of gravity calculate
    void printCog();
    void printBoxCoord();
    void printDebug();
//    double noktalar[boxNum];

private:
    coord spaceArea;
    box boxtest;
    double sx;
    double sy;
    int boxSize;
    int dotSize;
    int boxNum;
    int dotNum;
    int maxBoxSize;
    int dens;
    int*** noktalar;
    int randomW;
    int randomH;
    int randomD;
    box* boxArr;
    int k;
    int l;
    double cogX;
    double cogY;

};


#endif // SPACE_H_INCLUDED
