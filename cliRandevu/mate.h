//mate.h
#ifndef MATE_H_INCLUDED
#define MATE_H_INCLUDED
#include <iostream>
#include <string>
//ogrenci ve akademisyenin ortak ozellikleri burada tutulur. diğer iki class bu classtan
//miras alır
using namespace std;
class mate{
    public:
        //degiskenlerin setter komutları
        mate();
        void setAd(string ad);
        void setSoyad(string soyad);
        void setEMail(string eMail);
        void setTelNum(long long int telNum);

        //degiskenlerin getter komutları
        string getAd();
        string getSoyad();
        string getEMail();
        long long int getTelNum();


    protected:
        string ad;
        string soyad;
        string eMail;
        long long int telNum;

};


#endif // MATE_H_INCLUDED
