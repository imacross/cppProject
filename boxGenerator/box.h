//başlangıç box.h

#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED
#include "coord.h"
class box {
public:
    box(double,double,double,coord);
    box();
    void setCorner();
    void setCornerRU();
    void setCornerRD();
    void setCornerLU();
    void setPointx(int px);
    void setPointy(int py);
    void setWidth(double w);
    void setHeight(double h);
    void setDensity(double d);
    void setWeight();
    void setCenterBoxX();
    void setCenterBoxY();


    void printBox();

    double  getCornerRUx();
    double  getCornerRUy();
    double  getCornerRDx();
    double  getCornerRDy();
    double  getCornerLUx();
    double  getCornerLUy();
    double  getPointx();
    double  getPointy();
    double  getWidth();
    double  getHeight();
    double  getDensity();
    double  getWeight();
    double  getCenterBoxX();
    double  getCenterBoxY();



private:
    double density;
    double width;
    double height;
    double weight;
    double centerBoxX;
    double centerBoxY;
    coord point;
    coord leftUp;
    coord rightUp;
    coord rightDown;
    double px;
    double py;
};


#endif // BOX_H_INCLUDED

//bitiş box.h
