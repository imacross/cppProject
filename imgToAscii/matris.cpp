//matris.cpp
#include <iostream>
#include "matris.h"

using namespace std;

matris::matris(){

}

void matris::setWidth(int width){
    if(width <= 255)
        this->width = width;
    else
        cout<<"Genislik 255 den büyük!"<<endl;

}

void matris::setHeight(int height){
    if(height <= 255)
        this->height = height;
    else
        cout<<"Yukseklik 255 den büyük!"<<endl;
}

// iki boyutlu dinamik array olusturma
void matris::setAry(){
    ary = new int*[height];
    for(int i = 0; i<height;++i)
        ary[i] = new int[width];
}

// iki boyutlu dinamik array olusturma
void matris::setAry2(){
    ary2 = new int*[height];
    for(int i = 0; i<height;++i)
        ary2[i] = new int[width];
}

//void matris::setAry(){
//    ary = new int*[height];
//    for(int i = 0; i<height;++i)
//        ary[i] = new int[width];
//}

int** matris::getAry(){
    cout<<ary[0][0]<<endl;
    return ary;
}

int matris::getWidth(){
    return width;
}

int matris::getHeight(){
    return height;
}
