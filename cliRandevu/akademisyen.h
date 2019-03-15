//akademisyen.h
#ifndef AKADEMISYEN_H_INCLUDED
#define AKADEMISYEN_H_INCLUDED
#include "mate.h"
#include <iostream>
#include <string>
//mate classından miras alındı ve gerekli set get komutları yazıldı
class akademisyen:public mate{
    public:
        akademisyen();
        void setAkdNo(int akdNo);
        void setAkdDal(string akdDal);
        void setAkdUnvan(string akdUnvan);

        int getAkdNo();
        string getAkdDal();
        string getAkdUnvan();

    private:
        int akdNo;
        string akdDal;
        string akdUnvan;




};


#endif // AKADEMISYEN_H_INCLUDED
