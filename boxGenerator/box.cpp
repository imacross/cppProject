//başlangıç box.cpp

#include <iostream>
#include "box.h"
#include "coord.h"

using namespace std;

//box::box(double density,double width, double height, coord point)
//:density(density),width(width),height(height),point(point)
//{
//    cout<<"density:"<<density<<" width:"<<width<<" height:"<<height<<endl;
//    cout<<"Point coordinant is x:"<<point.getCoordX()<<" y:"<<point.getCoordY()<<endl;
//    setCornerLU();
//    setCornerRD();
//    setCornerRU();
//    setCorner();
//
//}
box::box(){
    density = 0;
    width = 0;
    height = 0;
    weight = 0;
    centerBoxX = 0;
    centerBoxY = 0;
    px = 0;
    py = 0;


}


void box::printBox(){
    cout<<width<<"x"<<height<<" Width:"<<width<<", heigth:"<<height<<", density:"<<density<<". X,Y coord:"<<getPointx()
    <<","<<getPointy()<< " weight:"<<weight<<" cogx:"<<centerBoxX<<" cogy"<<centerBoxY<<endl;
}

void box::setCenterBoxX(){
    centerBoxX = getPointx()+(width/2.0);
}

void box::setCenterBoxY(){
    centerBoxY = getPointy()+(height/2.0);
}

void box::setWeight(){
    weight = width*height*density;
}
void box::setWidth(double w){
    width = w;
}

void box::setHeight(double h){
    height = h;
}

void box::setDensity (double d){
    density = d;
}


void box::setCornerLU(){
    leftUp.setCoordX(point.getCoordX());
    leftUp.setCoordY(point.getCoordY()+height);
}
void box::setCornerRD(){
    rightDown.setCoordX(point.getCoordX()+width);
    rightDown.setCoordY(point.getCoordY());
}

void box::setCornerRU(){
    rightUp.setCoordX(point.getCoordX()+width);
    rightUp.setCoordY(point.getCoordY()+height);

}
void box::setPointx(int px){
    this->px = px;
    point.setCoordX(px);
}

void box::setPointy(int py){
    this->py = py;
    point.setCoordY(py);
}


double box::getCenterBoxX(){
    return centerBoxX;
}

double box::getCenterBoxY(){
    return centerBoxY;
}
double box::getCornerLUx(){
    return leftUp.getCoordX();
}
double box::getCornerLUy(){
    return leftUp.getCoordY();
}

double box::getCornerRDx(){
    return rightDown.getCoordX();
}

double box::getCornerRDy(){
    return rightDown.getCoordY();
}

double box::getCornerRUy(){
    return rightUp.getCoordY();
}

double box::getCornerRUx(){
    return rightUp.getCoordX();
}
double box::getPointx(){
    return point.getCoordX();
}

double box::getPointy(){
    return point.getCoordY();
}

double box::getHeight(){
    return height;
}

double box::getWidth(){
    return width;
}

double box::getDensity(){
    return density;
}

double box::getWeight(){
    return weight;
}

void box::setCorner(){
    rightUp.setCoordX(point.getCoordX()+width);
    rightUp.setCoordY(point.getCoordY()+height);

    rightDown.setCoordX(point.getCoordX()+width);
    rightDown.setCoordY(point.getCoordY());

    leftUp.setCoordX(point.getCoordX());
    leftUp.setCoordY(point.getCoordY()+height);

}

//bitiş box.cpp
