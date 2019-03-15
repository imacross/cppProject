/*
   ______________________________
 / \                             \.
|   |  AUTHOR:  Cagdas Yanar     |.
 \_ |                            |.
    |           365338           |.
    |     Yusuf Cagdas Yanar     |.
    |   cagdasyanar@outlook.com  |.
    |                            |.
    |      +90507 193 88 28      |.
    |                            |.
    |     www.cagdasyanar.com    |.
    |                            |.
    |          26.12.2018        |.
    |                            |.
    |  Randevu Alma Programi v1  |.
    |   _________________________|.__
    |  /                            /.
    \_/____________________________/.


*/
//main.cpp
#include <iostream>
#include "mate.h"
#include "ogrenci.h"
#include "akademisyen.h"
#include "randevu.h"
#include "randevusistemi.h"
#include <string>

using namespace std;

int main()
{

    randevuSistemi rdvsis;



    int secim=1;
    while(secim!=0){
         cout<<"    ___________________"<<endl;
         cout<<"    [0]-Cikis"<<endl;
         cout<<"    [1]-Ogrenci ekle"<<endl;
         cout<<"    [2]-Ogrenci sil"<<endl;
         cout<<"    [3]-Ogrenci listele"<<endl;
         cout<<"    [4]-Ogrenci guncelle"<<endl;
         cout<<"    [5]-Akademisyen ekle"<<endl;
         cout<<"    [6]-Akademisyen  sil"<<endl;
         cout<<"    [7]-Akademisyen  listele"<<endl;
         cout<<"    [8]-Akademisyen  guncelle"<<endl;
         cout<<"    [9]-Randevu ekle"<<endl;
         cout<<"    [10]-Randevu sil"<<endl;
         cout<<"    [11]-Randevu guncelle"<<endl;
         cout<<"    [12]-Randevu listele"<<endl;
         cout<<"    [13]-Ogrenci randevusu listele"<<endl;
         cout<<"    [14]-Akademisyen randevusu listele"<<endl;
        cout<<"    ___________________"<<endl;
        cout<<"Secim :";
        cin>>secim;

        switch(secim){
        case 0:
            break;
        case 1:
            rdvsis.ogrEkle();
            rdvsis.ogrListele();
            break;
        case 2:
            rdvsis.ogrSil();
            rdvsis.ogrListele();
            break;
        case 3:
            rdvsis.ogrListele();
            break;

        case 4:
            rdvsis.ogrGuncelle();
            rdvsis.ogrListele();
            break;

        case 5:
            rdvsis.akdEkle();
            rdvsis.akdListele();
            break;
        case 6:
            rdvsis.akdSil();
            rdvsis.akdListele();

        break;
        case 7:
            rdvsis.akdListele();

        break;
        case 8:
            rdvsis.akdGuncelle();
            rdvsis.akdListele();

        break;
        case 9:
            rdvsis.rndEkle();
            rdvsis.rndListele();

        break;
        case 10:
            rdvsis.rndSil();
            rdvsis.rndListele();
        break;
        case 11:
            rdvsis.rndGuncelle();
            rdvsis.rndListele();

        break;
        case 12:
            rdvsis.rndListele();

        break;
        case 13:
             rdvsis.ogrRndListele();

        break;
        case 14:
            rdvsis.akdRndListele();

        }

    }



    return 0;
}
