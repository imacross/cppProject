//randevu.cpp
#include "mate.h"
#include "ogrenci.h"
#include "akademisyen.h"
#include "randevu.h"
#include <iostream>
#include <string>

using namespace std;

randevu::randevu(){
    //constructer da default olması gereken degerler verildi
    gun=0;
    ay=0;
    yil=0;
    basH=0;
    basM=0;
    bitH=0;
    bitM=0;
    RndOgrNum=0;
    RndAkdNum=0;
}

void randevu::setTarih(int gun,int ay, int yil){
    this->gun = gun;
    this->ay = ay;
    this->yil = yil;
}

void randevu::setBaslangic(int basH,int basM){
    this->basH = basH;
    this->basM = basM;
    setBitis(basH,basM);
}

//bitis dakika ve saati baslangic baz alınarak 30dk eklenerek belirlendi
void randevu::setBitis(int h,int m){
    if(m==0){
        bitH = h;
        bitM = m+30;
    }
    else if(m==30){
        bitH = h+1;
        bitM = 0;
    }
}

void randevu::setRndOgrNum(int RndOgrNum){
     this->RndOgrNum = RndOgrNum;
}

void randevu::setRndAkdNum(int RndAkdNum){
    this->RndAkdNum = RndAkdNum;
}


int randevu::getRndOgrNum(){
    return RndOgrNum;
}

int randevu::getRndAkdNum(){
    return RndAkdNum;
}

int randevu::getGun(){
    return gun;
}

int randevu::getAy(){
    return ay;
}

int randevu::getYil(){
    return yil;
}

int randevu::getBasH(){
    return basH ;
}

int randevu::getBasM(){
    return basM;
}

int randevu::getBitH(){
    return bitH;
}

int randevu::getBitM(){
    return bitM;
}
