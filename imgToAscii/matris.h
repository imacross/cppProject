//matris.h
#ifndef MATRIS_H_INCLUDED
#define MATRIS_H_INCLUDED
#include <iostream>
using namespace std;


class matris{
    public:
        matris();
        void setWidth(int width); //width degiskenini ayarlamak icin yazilan fonk.
        void setHeight(int height); //heigt degiskenini ayarlamak icin yazilan fonk
        void setAry();  //dosyadan okuma ve sobel isleminde kullanılan array setleme
        void setAry2(); //sobel isleminden cikmis, treshold ve dosya yazma isleminde kullanılan array setleme

        //array getleme fonksiyonlar
        int** getAry();
        int** getAry2();
        //yukseklik ve genislik getleme fonksiyonları
        int getWidth();
        int getHeight();


    protected:
        int** ary; //gri tonlarının tutuldugu array
        int** ary2; //sobel, treshold islemlerinde kullanılan array
        int width;
        int height;



};



#endif // MATRIS_H_INCLUDED
