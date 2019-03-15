//mate.cpp

#include "mate.h"
#include <iostream>
#include <string>

using namespace std;

mate::mate(){

}

void mate::setAd(string ad){
    this->ad = ad;
}

void mate::setSoyad(string soyad){
    this->soyad = soyad;
}

void mate::setEMail(string eMail){
    this->eMail = eMail;
}

void mate::setTelNum(long long int telNum){
    this->telNum = telNum;
}

string mate::getAd(){
    return ad;
}

string mate::getSoyad(){
    return soyad;
}

string mate::getEMail(){
    return eMail;
}

long long int mate::getTelNum(){
    return telNum;
}
