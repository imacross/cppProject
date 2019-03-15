//başlangıç coord.cpp

#include "coord.h"
#include <iostream>

using namespace std;

coord::coord(){
    x=0;
    y=0;
}

coord::coord(double x,double y)
:x(x),y(y)
{

}

void coord::setCoordX(double x)
{
    this->x = x;
}

void coord::setCoordY(double y)
{
    this->y = y;
}


double coord::getCoordX(){
    return(x);
}

double coord::getCoordY(){
    return(y);
}

//bitiş coord.cpp
