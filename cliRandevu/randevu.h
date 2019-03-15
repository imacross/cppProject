//randevu.h
#ifndef RANDEVU_H_INCLUDED
#define RANDEVU_H_INCLUDED
#include "mate.h"
#include "ogrenci.h"

#include <iostream>
#include <string>

class randevu{
    public:
        randevu();


        void setTarih(int gun,int ay,int yil);//tarih set fonk
        void setBaslangic(int basH,int basM);//randevu baslangic saati set fonk
        void setBitis(int h,int m);//randevu bitis saati set fonk

        void setRndOgrNum(int RndOgrNum);//randevu alan ogrenci numara bilgisi
        void setRndAkdNum(int RndAkdNum);//randevu alan akademisyen numara bilgisi




        int getRndOgrNum();
        int getRndAkdNum();

        int getGun();
        int getAy();
        int getYil();

        int getBasH();//baslangic saati
        int getBasM();//baslangic dakikasi

        int getBitH();
        int getBitM();


    private:

        int gun;
        int ay;
        int yil;
        int basH;
        int basM;
        int bitH;
        int bitM;
        int RndOgrNum;
        int RndAkdNum;
        ogrenci ogr;
        akademisyen akd;

};

#endif // RANDEVU_H_INCLUDED
