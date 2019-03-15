//ogrenci.cpp

#include "ogrenci.h"
#include <iostream>
#include <string>

using namespace std;

ogrenci::ogrenci(){

}

void ogrenci::setOgrNumara(int ogrNumara){
    this->ogrNumara = ogrNumara;
}

void ogrenci::setOgrKayitYili(int ogrKayitYili){
    this->ogrKayitYili = ogrKayitYili;
}

void ogrenci::setOgrBolum(string ogrBolum){
    this->ogrBolum = ogrBolum;
}

int ogrenci::getOgrNumara(){
    return ogrNumara;
}

int ogrenci::getOgrKayitYili(){
    return ogrKayitYili;
}

string ogrenci::getOgrBolum(){
    return ogrBolum;
}
