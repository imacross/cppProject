//goruntu.h
#ifndef GORUNTU_H_INCLUDED
#define GORUNTU_H_INCLUDED
#include "matris.h"
#include <fstream>
#include <fstream>
#include <iostream>

using namespace std;

//matristen kalıtım alan goruntu classı
class goruntu:public matris{
    public:
        goruntu();
        friend ifstream &operator>>( ifstream  &file, goruntu &g ); // okuma overloading
        friend ofstream &operator<<( ofstream  &file, goruntu &g ); // yazma overloading

        goruntu operator+(const goruntu& g);    //+ operator overloading (or)
        goruntu operator*(const goruntu& g);    //* operator overloading (and)
        goruntu operator!();                    // ! operator overloading (not)

        //cons icinde cagrilir. sobel maskelerinin degerlerini atarlar
        void setGX();
        void setGY();

        void sobel(); // sobel filtreleme islemini yapan fonksiyon
        void threshold(int x); // parametreye gore treshold islemini yapar

        void debugMod(goruntu g); //hata ayiklama icin kullanılan fonksiyon

    private:

        int sX; //dikey sobel isleminin degiskeni
        int sY; //yatay sobel isleminin degiskeni
        int s;  //sobele gore pixelin degeri

        int gX[3][3]; //dikey sobel maskesi dizisi
        int gY[3][3]; //yatay sobel maskesi dizisi

};

//goruntu.cpp den erisebilmek icin classin disina prototip tanimlandi
ifstream &operator>>( ifstream  &file, goruntu &g );
ofstream &operator<<( ofstream  &file, goruntu &g );

#endif // GORUNTU_H_INCLUDED
