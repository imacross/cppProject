//başlangıç coord.h

#ifndef COORD_H_INCLUDED
#define COORD_H_INCLUDED

class coord{
public:
    coord();
    coord(double,double);
    double getCoordX();
    double getCoordY();
    void setCoordX(double);
    void setCoordY(double);
private:
    double x;
    double y;
};



#endif // COORD_H_INCLUDED

//bitiş coord.h
