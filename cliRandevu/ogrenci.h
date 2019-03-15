//ogrenci.h
#ifndef OGRENCI_H_INCLUDED
#define OGRENCI_H_INCLUDED
#include "mate.h"
#include <iostream>
#include <string>
//
class ogrenci:public mate
{
    public:
        ogrenci();
        //ogrenci numara,bolum kayit yili gibi bilgilerin set ve get prototipleri
        void setOgrNumara(int ogrNumara);
        void setOgrBolum(string ogrBolum);
        void setOgrKayitYili(int ogrKayitYili);

        int getOgrNumara();
        string getOgrBolum();
        int getOgrKayitYili();

    private:
        int ogrNumara;
        string ogrBolum;
        int ogrKayitYili;


};


#endif // OGRENCI_H_INCLUDED
