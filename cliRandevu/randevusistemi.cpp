//randevusistemi.cpp
#include <iostream>
#include "ogrenci.h"
#include "akademisyen.h"
#include "randevu.h"
#include "randevusistemi.h"
#include <string>
#include <stdlib.h>
#include "fstream"

using namespace std;

randevuSistemi::randevuSistemi(){
    tempInt = 0;
    tempStr = "";
    rndGun = 0;
    rndAy = 0;
    rndYil = 0;

    rndBasH = 0;
    rndBasM = 0;

    buldunMu = true;

    infoEkle();
    ogrYenile();
    akdYenile();
    rndYenile();

}


void randevuSistemi::ogrEkle(){
    ogrYenile();
    fstream ogrFile;

    ogrFile.open("ogrenci.txt",ios::app);

    cout<<endl;
    cout<<"Lutfen ogrenci numarasi yazin :";
    cin>>tempInt;
    cout<<endl;
    ogr[ogrId].setOgrNumara(tempInt);
    ogrFile<<tempInt<<" ";

    cout<<"Lutfen ogrenci adini yazin :";
    cin>>tempStr;
    cout<<endl;
    ogr[ogrId].setAd(tempStr);
    ogrFile<<tempStr<<" ";

    cout<<"Lutfen ogrenci soyadini yazin :";
    cin>>tempStr;
    cout<<endl;
    ogr[ogrId].setSoyad(tempStr);
    ogrFile<<tempStr<<" ";

    cout<<"Lutfen ogrenci bolumunu yazin :";
    cin>>tempStr;
    cout<<endl;
    ogr[ogrId].setOgrBolum(tempStr);
    ogrFile<<tempStr<<" ";

    cout<<"Lutfen ogrenci kayit yilini yazin :";
    cin>>tempInt;
    cout<<endl;
    ogr[ogrId].setOgrKayitYili(tempInt);
    ogrFile<<tempInt<<" ";

    cout<<"Lutfen Ogrenci E-Mailini yazin :";
    cin>>tempStr;
    cout<<endl;
    ogr[ogrId].setEMail(tempStr);
    ogrFile<<tempStr<<" ";

    cout<<"Lutfen Ogrenci Telefon Numarasini yazin :";
    cin>>tempInt;
    cout<<endl;
    ogr[ogrId].setTelNum(tempInt);
    ogrFile<<tempInt<<endl;

    ogrId++;
    ogrFile.close();

}

void randevuSistemi::akdEkle(){
    akdYenile();

    fstream akdFile;
    akdFile.open("akademisyen.txt",ios::app);

    cout<<endl;

    cout<<"Lutfen akademisyen sicil numarasini yazin :";
    cin>>tempInt;
    cout<<endl;
    akd[akdId].setAkdNo(tempInt);
    akdFile<<tempInt<<" ";

    cout<<"lutfen akademisyen adini yazin :";
    cin>>tempStr;
    cout<<endl;
    akd[akdId].setAd(tempStr);
    akdFile<<tempStr<<" ";

    cout<<"lutfen akademisyen soyadini yazin :";
    cin>>tempStr;
    cout<<endl;
    akd[akdId].setSoyad(tempStr);
    akdFile<<tempStr<<" ";

    cout<<"lutfen akademisyenin anabilim dalini yazin :";
    cin>>tempStr;
    cout<<endl;
    akd[akdId].setAkdDal(tempStr);
    akdFile<<tempStr<<" ";

    cout<<"lutfen akademisyenin e-mailini yazin :";
    cin>>tempStr;
    cout<<endl;
    akd[akdId].setEMail(tempStr);
    akdFile<<tempStr<<" ";

    cout<<"lutfen akademisyenin telefon numarasini yazin :";
    cin>>tempInt;
    cout<<endl;
    akd[akdId].setTelNum(tempInt);
    akdFile<<tempInt<<" ";

    cout<<"Lutfen unvanini yazin :";
    cin>>tempStr;
    cout<<endl;
    akd[akdId].setAkdUnvan(tempStr);
    akdFile<<tempStr<<endl;

    akdId++;
     akdFile.close();

}

void randevuSistemi::rndEkle(){
    //rndYenile();
    int ogrKontrol;
    int akdKontrol;
    int ogrGirdi;
    int akdGirdi;
    bool akdCakisti = false;
    bool ogrCakisti = false;


    cout<<"Lütfen ogrenci numarası giriniz :";
    cin>>ogrGirdi;
    cout<<endl;
    ogrKontrol = bilgiDondur(ogrGirdi,0);

    cout<<"Lütfen akademisyen sicil numarasi giriniz:";
    cin>>akdGirdi;
    cout<<endl;
    akdKontrol = bilgiDondur(akdGirdi,1);

    cout<<"Lütfen randevu tarihi giriniz(12.12.2018) :";
    cin>>rndTarih;
    cout<<endl;

    cout<<"Lütfen randevu baslangic saati giriniz(00:00) :";
    cin>>rndBaslangic;
    cout<<endl;


    if(ogrKontrol==-1&&akdKontrol==-1){

        cout<<"Hem ogrenci numarasi hem akademisyen numarasi bulunamadi!!!"<<endl;
    }
    else if(ogrKontrol ==-1){
        cout<<"Ogrenci numarasi bulunamadi!!!"<<endl;
    }
    else if(akdKontrol ==-1){
        cout<<"Akademisyen numarasi bulunamadi!!!";
    }
    else{

        rndParcala();
        for(int i = 0; i<rndId;i++){
            if(rnd[i].getRndOgrNum()==ogrGirdi&&rnd[i].getGun()==rndGun&&rnd[i].getAy()==rndAy
                &&rnd[i].getYil() == rndYil&&rnd[i].getBasH()==rndBasH&&rnd[i].getBasM()==rndBasM
               )
            {
                cout<<"Ogrencinin belirtilen saatte zaten randevusu bulunmaktadir"<<endl;
                cout<<rnd[i].getRndAkdNum()<<" Akademisyeni ile "<<rnd[i].getGun()<<"."<<rnd[i].getAy()<<rnd[i].getYil()
                <<" tarihinde saat "<<rnd[i].getBasH()<<"."<<rnd[i].getBitM()<<" baslayan bir randevu vardir"
                <<endl;
                cout<<endl;
                ogrCakisti = true;
                //break;
            }
            else if(rnd[i].getRndAkdNum()==akdGirdi&&rnd[i].getGun()==rndGun&&rnd[i].getAy()==rndAy
                &&rnd[i].getYil() == rndYil&&rnd[i].getBasH()==rndBasH&&rnd[i].getBasM()==rndBasM
                    )
            {
                cout<<"Akademisyen belirtilen saatte zaten randevusu bulunmaktadir"<<endl;
                cout<<rnd[i].getRndOgrNum()<<" ogrencisi ile "<<rnd[i].getGun()<<"."<<rnd[i].getAy()<<rnd[i].getYil()
                <<" tarihinde saat "<<rnd[i].getBasH()<<"."<<rnd[i].getBitM()<<" baslayan bir randevu vardir"
                <<endl;
                akdCakisti = true;
                break;
            }

            else{



            }


        }
        if(ogrCakisti == false && akdCakisti==false){
            rnd[rndId].setRndOgrNum(ogrGirdi);
            rnd[rndId].setRndAkdNum(akdGirdi);
            rnd[rndId].setTarih(rndGun,rndAy,rndYil);
            rnd[rndId].setBaslangic(rndBasH,rndBasM);
            rndId++;
            dosyaGuncelle();



        }
        else{

            cout<<"hata 101!"<<endl;
        }

    }
}

void randevuSistemi::rndEkle(int ogrNum,int akdNum,int gun, int ay,int yil,int basH,int basM,int id){
    int ogrKontrol;
    int akdKontrol;
    int ogrGirdi = ogrNum;
    int akdGirdi = akdNum;
    bool akdCakisti = false;
    bool ogrCakisti = false;

    rndGun = gun;
    rndAy = ay;
    rndYil = yil;
    rndBasH = basH;
    rndBasM = basM;



    ogrKontrol = bilgiDondur(ogrNum,0);

    akdKontrol = bilgiDondur(akdNum,1);




    if(ogrKontrol==-1&&akdKontrol==-1){
        cout<<"Hem ogrenci numarasi hem akademisyen numarasi bulunamadi.!!"<<endl;
    }
    else if(ogrKontrol ==-1){
        cout<<"Ogrenci numarasi bulunamadi!!"<<endl;
    }
    else if(akdKontrol ==-1){
        cout<<"Akademisyen numarasi bulunamadi!!";
    }
    else{


        for(int i = 0; i<rndId;i++){
            if(i==id){

            }

            else if(rnd[i].getRndOgrNum()==ogrGirdi&&rnd[i].getGun()==rndGun&&rnd[i].getAy()==rndAy
                &&rnd[i].getYil() == rndYil&&rnd[i].getBasH()==rndBasH&&rnd[i].getBasM()==rndBasM
               )
            {
                cout<<"Ogrencinin belirtilen saatte zaten randevusu bulunmaktadir"<<endl;
                cout<<rnd[i].getRndAkdNum()<<" Akademisyeni ile "<<rnd[i].getGun()<<"."<<rnd[i].getAy()<<rnd[i].getYil()
                <<" tarihinde saat "<<rnd[i].getBasH()<<"."<<rnd[i].getBitM()<<" baslayan bir randevu vardir"
                <<endl;
                ogrCakisti = true;
                //break;
            }
            else if(rnd[i].getRndAkdNum()==akdGirdi&&rnd[i].getGun()==rndGun&&rnd[i].getAy()==rndAy
                &&rnd[i].getYil() == rndYil&&rnd[i].getBasH()==rndBasH&&rnd[i].getBasM()==rndBasM
                    )
            {
                cout<<"Akademisyen belirtilen saatte zaten randevusu bulunmaktadir"<<endl;
                cout<<rnd[i].getRndOgrNum()<<" ogrencisi ile "<<rnd[i].getGun()<<"."<<rnd[i].getAy()<<rnd[i].getYil()
                <<" tarihinde saat "<<rnd[i].getBasH()<<"."<<rnd[i].getBitM()<<" baslayan bir randevu vardir"
                <<endl;
                akdCakisti = true;
                break;
            }

            else{


            }


        }
        if(ogrCakisti == false && akdCakisti==false){
            rnd[id].setRndOgrNum(ogrGirdi);
            rnd[id].setRndAkdNum(akdGirdi);
            rnd[id].setTarih(rndGun,rndAy,rndYil);
            rnd[id].setBaslangic(rndBasH,rndBasM);
            dosyaGuncelle();


        }
        else{

        }

    }
}



void randevuSistemi::ogrSil(){
    int ogrKodu;
    int rndKodu;
    int ogrNum;
    int temp3 = 0;
    cout<<"Lutfen silmek istediginiz ogrencinin numarasini giriniz :";
    cin>>ogrNum;
    ogrKodu = bilgiDondur(ogrNum,0);
    if(ogrKodu == -1){
        cout<<"Aradiginiz kosullarda ogrenci bulunamadi!"<<endl;
    }
    else{
        tempInt=ogrKodu;

        //rndSil(0,ogrNum,0);



        for(int i = 1; i<ogrId-ogrKodu;i++){
            ogr[tempInt]=ogr[tempInt+1];
            tempInt++;
        }

        ogrId--;

        dosyaGuncelle();
        ogrYenile();
    }

}

void randevuSistemi::akdSil(){
    int akdKodu;
    cout<<"Lutfen silmek istediginiz akademisyenin numarasini giriniz :"<<endl;
    cin>>tempInt;
    akdKodu = bilgiDondur(tempInt,1);
    if(akdKodu == -1){
        cout<<"Aradiginiz kosullarda akademisyen bulunamadi!"<<endl;
    }
    else{
        tempInt=akdKodu;
        for(int i = 1; i<akdId-akdKodu;i++){
            akd[tempInt]=akd[tempInt+1];
            tempInt++;
        }

        akdId--;

        dosyaGuncelle();
        akdYenile();
    }

}

void randevuSistemi::rndSil(){
    int secim = 0;
    int rndKodu = 0;
    while(secim==0){


        cout<<"[1] Ogrenci sorgulayarak randevu sil"<<endl;
        cout<<"[2] Akademisyen sorgulayarak randevu sil"<<endl;
        cout<<" :";
        cin>>secim;

        if(secim==0){
            cout<<"Lutfen bir secim yapiniz"<<endl;
        }
        else if(secim==1){
            ogrRndListele();
            if(buldunMu==true){
                cout<<endl;
                cout<<"Lutfen hangi randevuyu silmek istiyorsaniz girin";
                cin>>tempNum;
                tempNum--;

                for(int i = 0; i<rndId;i++){
                    if(rnd[i].getRndOgrNum()==ogrRndList[tempNum].getRndOgrNum()&&rnd[i].getRndAkdNum()==
                       ogrRndList[tempNum].getRndAkdNum()&&
                       rnd[i].getGun()==ogrRndList[tempNum].getGun()&&rnd[i].getAy()==ogrRndList[tempNum].getAy()
                       &&rnd[i].getYil() == ogrRndList[tempNum].getYil()&&rnd[i].getBasH()==ogrRndList[tempNum].getBasH()
                       &&rnd[i].getBasH()==ogrRndList[tempNum].getBasH()
                   )
                    {
                        rndKodu = tempInt = i;
                        for(int j = 1; j<rndId-rndKodu;j++){
                            rnd[tempInt]=rnd[tempInt+1];
                            tempInt++;
                        }

                    rndId--;

                    dosyaGuncelle();

                    rndYenile();

                    }
                }
            }

        }
        else if(secim==2){
            akdRndListele();
            if(buldunMu==true){
                cout<<endl;
                cout<<"Lütfen hangi randevuyu silmek istiyorsaniz girin";
                cin>>tempNum;
                tempNum--;

                for(int i = 0; i<rndId;i++){
                    if(rnd[i].getRndOgrNum()==akdRndList[tempNum].getRndOgrNum()&&rnd[i].getRndAkdNum()==
                       akdRndList[tempNum].getRndAkdNum()&&
                       rnd[i].getGun()==akdRndList[tempNum].getGun()&&rnd[i].getAy()==akdRndList[tempNum].getAy()
                       &&rnd[i].getYil() == akdRndList[tempNum].getYil()&&rnd[i].getBasH()==akdRndList[tempNum].getBasH()
                       &&rnd[i].getBasH()==akdRndList[tempNum].getBasH()
                   )
                    {
                        rndKodu = tempInt = i;
                        for(int j = 1; j<rndId-rndKodu;j++){
                            rnd[tempInt]=rnd[tempInt+1];
                            tempInt++;
                        }

                    rndId--;

                    dosyaGuncelle();
                    rndYenile();

                    }
                }
            }

        }
        else{
            cout<<"Lütfen sadece 1 ve 2 giriniz!!"<<endl;
            secim = 0;
        }

    }
}

void randevuSistemi::rndSil(int id, int num,int durum){
    if(durum==0){
    int sayici =0;
    int l =0;
    int arananNum = num;
      for(int i = 0; i<rndId;i++){
            if(rnd[i].getRndOgrNum()==arananNum){
                ogrRndList[sayici]=rnd[i];
                sayici++;
            }
        }
    for(ogrRndSayici = 0; ogrRndSayici<sayici;ogrRndSayici++){
                cout<<" ["<<ogrRndSayici+1<<"] "<<ogrRndList[ogrRndSayici].getRndOgrNum()<<" "<<ogrRndList[ogrRndSayici].getRndAkdNum()<<" "<<ogrRndList[ogrRndSayici].getBasH()
                <<":"<<ogrRndList[ogrRndSayici].getBasM()<<" "<<ogrRndList[ogrRndSayici].getBitH()<<":"<<ogrRndList[ogrRndSayici].getBitM() <<endl;
            }
            while(ogrRndList[l].getRndOgrNum()!=NULL){

                cout<<"                     "<<l<<endl;
                tempNum = l;
                 for(int i = 0; i<rndId;i++){
                    if(rnd[i].getRndOgrNum()==akdRndList[tempNum].getRndOgrNum()&&rnd[i].getRndAkdNum()==
                       akdRndList[tempNum].getRndAkdNum()&&
                       rnd[i].getGun()==akdRndList[tempNum].getGun()&&rnd[i].getAy()==akdRndList[tempNum].getAy()
                       &&rnd[i].getYil() == akdRndList[tempNum].getYil()&&rnd[i].getBasH()==akdRndList[tempNum].getBasH()
                       &&rnd[i].getBasH()==akdRndList[tempNum].getBasH()
                   )
                    {
                       int rndKodu = tempInt = i;
                        for(int j = 1; j<rndId-rndKodu;j++){
                            rnd[tempInt]=rnd[tempInt+1];
                            tempInt++;
                        }

                    rndId--;

                    dosyaGuncelle();
                    rndYenile();

                    }
                }

            l++;




            }
    }

}


void randevuSistemi::ogrGuncelle(){
    int ogrKodu;
    ogrListele();
    cout<<endl;
    cout<<"Lutfen duzenleme yapmak istediginiz ogrencinin numarasini giriniz :";
    cin>>tempInt;
    ogrKodu = bilgiDondur(tempInt,0);
    if(ogrKodu == -1){
        cout<<"Aradiginiz kosullarda ogrenci bulunamadi!"<<endl;

    }
    else{
            cout<<endl;
        cout<<"[0] Ad degistir"<<endl;
        cout<<"[1] soyad degistir"<<endl;
        cout<<"[2] bolum degistir"<<endl;
        cout<<"[3] kayit yili degistir"<<endl;
        cout<<"[4] e-mail degistir"<<endl;
        cout<<"[5] tel no degistir"<<endl;
        cout<<"Yukaridaki ozelliklerden hangisini degistirmek istersiniz :";
        cin>>tempInt;

        switch(tempInt){
            case 0:
                cout<<"Isim Giriniz :";
                cin>>tempStr;
                ogr[ogrKodu].setAd(tempStr);
                break;
            case 1:
                cout<<"Soyad Giriniz :";
                cin>>tempStr;
                ogr[ogrKodu].setSoyad(tempStr);
                break;
            case 2:
                cout<<"Bolum Giriniz :";
                cin>>tempStr;
                ogr[ogrKodu].setOgrBolum(tempStr);
                break;
            case 3:
                cout<<"Kayit Yili Giriniz :";
                cin>>tempInt;
                ogr[ogrKodu].setOgrKayitYili(tempInt);
                break;
            case 4:
                cout<<"E-Mail Giriniz :";
                cin>>tempStr;
                ogr[ogrKodu].setEMail(tempStr);
                break;
            case 5:
                cout<<"Telefon Numarasi Giriniz :";
                cin>>tempInt;
                ogr[ogrKodu].setTelNum(tempInt);
                break;
            default:
                cout<<"Gecersiz Secim"<<endl;
        }
            dosyaGuncelle();
    }



}

void randevuSistemi::akdGuncelle(){
    int akdKodu;
    cout<<"Lutfen duzenleme yapmak istediginiz akademisyenin numarasini giriniz :";
    cin>>tempInt;
    akdKodu = bilgiDondur(tempInt,1);
    if(akdKodu == -1){
        cout<<"Aradiginiz kosullarda akademisyen bulunamadi!"<<endl;

    }
    else{
        cout<<"[0] Ad degistir"<<endl;
        cout<<"[1] soyad degistir"<<endl;
        cout<<"[2] Anabilim dali degistir"<<endl;
        cout<<"[3] e-mail degistir"<<endl;
        cout<<"[4] tel no degistir"<<endl;
        cout<<"[5] Unvan degistir"<<endl;
        cout<<"Yukaridaki ozelliklerden hangisini degistirmek istersiniz :";
        cin>>tempInt;

        switch(tempInt){
            case 0:
                cout<<"Isim giriniz :";
                cin>>tempStr;
                akd[akdKodu].setAd(tempStr);
                break;
            case 1:
                cout<<"Soyad Giriniz :";
                cin>>tempStr;
                akd[akdKodu].setSoyad(tempStr);
                break;
            case 2:
                cout<<"Anabilim dali Giriniz :";
                cin>>tempStr;
                akd[akdKodu].setAkdDal(tempStr);
                break;
            case 3:
                cout<<"E-Mail Giriniz :";
                cin>>tempStr;
                akd[akdKodu].setEMail(tempStr);
                break;
            case 4:
                cout<<"Telefon Numarasi Giriniz :";
                cin>>tempInt;
                akd[akdKodu].setTelNum(tempInt);
                break;
            case 5:
                cout<<"Unvan Giriniz :";
                cin>>tempStr;
                akd[akdKodu].setAkdUnvan(tempStr);
                break;
            default:
                cout<<"Gecersiz Secim"<<endl;
        }
            dosyaGuncelle();
    }



}

void randevuSistemi::rndGuncelle(){
    int id;
    int secim;
    cout<<"Randevu Guncelleme Ekranindasiniz"<<endl;
    cout<<endl;
    rndListele();
    cout<<endl;
    cout<<"Hangi randevu uzerinde degisiklik yapmak istiyorsunuz :";
    cin>>id;
    id--;

    cout<<endl;
    cout<<"[1] Randevudaki ogrenciyi guncelle"<<endl;
    cout<<"[2] Randevudaki akademisyeni guncelle"<<endl;
    cout<<"[3] Randevunun tarihini guncelle"<<endl;
    cout<<"[4] Randevunun saatini guncelle"<<endl;
    cout<<" :"<<endl;
    cin>>secim;
    switch(secim){
        case 1:

            cout<<"Lütfen ogrencinin numarasini giriniz :";
            cin>>tempNum;
            rndEkle(tempNum,rnd[id].getRndAkdNum(),rnd[id].getGun(),rnd[id].getAy(),rnd[id].getYil(),
                    rnd[id].getBasH(),rnd[id].getBasM(),id);
            break;
        case 2:

            cout<<"Lutfen akademisyen numarasi giriniz :";
            cin>>tempNum;
            rndEkle(rnd[id].getRndOgrNum(),tempNum,rnd[id].getGun(),rnd[id].getAy(),rnd[id].getYil(),
                    rnd[id].getBasH(),rnd[id].getBasM(),id);
            break;
        case 3:

            cout<<"Lutfen tarih giriniz(12.12.2018) :";
            cin>>tempStr;
            rndTarih = tempStr;
            rndParcala();
            rndEkle(rnd[id].getRndOgrNum(),rnd[id].getRndAkdNum(),rndGun,rndAy,rndYil,
                    rnd[id].getBasH(),rnd[id].getBasM(),id);
            break;

        case 4:

            cout<<"Lutfen saat ve dakika giriniz(00.00) :";
            cin>>tempStr;
            rndBaslangic = tempStr;
            rndParcala();
            rndEkle(rnd[id].getRndOgrNum(),rnd[id].getRndAkdNum(),rnd[id].getGun(),rnd[id].getAy(),rnd[id].getYil()
                    ,rndBasH,rndBasM,id);
            break;


    }
}

void randevuSistemi::ogrListele(){
    cout<<endl;
    for(int i = 0; i<ogrId;i++){

        cout<<ogr[i].getOgrNumara()<<" "<<ogr[i].getAd()<<" "<<ogr[i].getSoyad()<<" "<<ogr[i].getOgrBolum()<<" "<<
        ogr[i].getOgrKayitYili()<<" "<<ogr[i].getEMail()<<" "<<ogr[i].getTelNum()<<endl;
    }
    cout<<"_____________________"<<endl;

}

void randevuSistemi::akdListele(){
    infoEkle();
    cout<<endl;
     for(int i = 0; i<akdId;i++){
        cout<<akd[i].getAkdNo()<<" "<<akd[i].getAd()<<" "<<akd[i].getSoyad()<<" "<<akd[i].getAkdDal()<<" "<<
        akd[i].getEMail()<<" "<<akd[i].getTelNum()<<" "<<akd[i].getAkdUnvan()<<endl;
    }
    cout<<"_____________________"<<endl;
}

void randevuSistemi::rndListele(){
    cout<<endl;
    for(int i = 0; i<rndId;i++){
        cout<<" ["<<i+1<<"] "<<rnd[i].getRndOgrNum()<<" "<<rnd[i].getRndAkdNum()<<" "<<rnd[i].getGun()<<"."<<rnd[i].getAy()
        <<"."<<rnd[i].getYil()<<" "<<rnd[i].getBasH()<<":"<<rnd[i].getBasM()<<" "<<rnd[i].getBitH()<<":"<<rnd[i].getBitM() <<endl;
    }
    cout<<"_____________________"<<endl;
}


void randevuSistemi::ogrRndListele(){
    int arananNum=0;
    int sayici = 0;
    cout<<"Sorgulama yapmak istediginiz ogrencinin numarasini giriniz :";
    cin>>arananNum;
    int ogrKodu = bilgiDondur(arananNum,0);

    if(ogrKodu==-1){
        cout<<"Boyle bir ogrenci bulunamadi!!"<<endl;
        buldunMu = false;
    }
    else{

        for(int i = 0; i<rndId;i++){
            if(rnd[i].getRndOgrNum()==arananNum){
                ogrRndList[sayici]=rnd[i];
                sayici++;
            }
        }

        if(sayici==0){
            cout<<"Ogrencinin hiç randevusu yok"<<endl;
            buldunMu = false;
        }
        else{
            buldunMu = true;
            cout<<"Ogrencinin "<<sayici<<" tane randevusu vardir"<<endl;
            cout<<endl;
            for(ogrRndSayici = 0; ogrRndSayici<sayici;ogrRndSayici++){
                cout<<" ["<<ogrRndSayici+1<<"] "<<ogrRndList[ogrRndSayici].getRndOgrNum()<<" "<<ogrRndList[ogrRndSayici].getRndAkdNum()<<" "<<ogrRndList[ogrRndSayici].getBasH()
                <<":"<<ogrRndList[ogrRndSayici].getBasM()<<" "<<ogrRndList[ogrRndSayici].getBitH()<<":"<<ogrRndList[ogrRndSayici].getBitM() <<endl;
            }


        }

    }

}

void randevuSistemi::akdRndListele(){
    int arananNum=0;
    int sayici = 0;
    cout<<"Sorgulama yapmak istediginiz akademisyenin sicil numarasini giriniz :";
    cin>>arananNum;
    int akdKodu = bilgiDondur(arananNum,1);

    if(akdKodu==-1){
        cout<<"Boyle bir akademisyen bulunamadi!!"<<endl;
        buldunMu = false;
    }
    else{

        for(int i = 0; i<rndId;i++){
            if(rnd[i].getRndAkdNum()==arananNum){
                akdRndList[sayici]=rnd[i];
                sayici++;
            }
        }

        if(sayici==0){
            cout<<"Akademisyenin hiç randevusu yok"<<endl;
            buldunMu = false;
        }
        else{
                buldunMu = true;
            cout<<"Akademisyenin "<<sayici<<" tane randevusu vardır"<<endl;
            cout<<endl;
            for(int akdRndSayici = 0; akdRndSayici<sayici;akdRndSayici++){
                cout<<" ["<<akdRndSayici+1<<"] "<<akdRndList[akdRndSayici].getRndAkdNum()<<" "<<akdRndList[akdRndSayici].getRndOgrNum()<<" "<<akdRndList[akdRndSayici].getBasH()
                <<":"<<akdRndList[akdRndSayici].getBasM()<<" "<<akdRndList[akdRndSayici].getBitH()<<":"<<akdRndList[akdRndSayici].getBitM() <<endl;
            }

        }

    }

}


int randevuSistemi::bilgiDondur(int numara,int durum){
   string tempStr2;
    if(durum == 0){
        ifstream ogrFile("ogrenci.txt");

        for(int i = 0; i<ogrId;i++){

            ogrFile>>tempNum;

            if(numara==tempNum){
                ogrFile.close();
                return i;
            }

            for(int j = 0;j<6;j++){
                ogrFile>>tempStr2;
            }
        }
        ogrFile.close();
        return -1;
    }
    else if(durum==1){
        ifstream akdFile("akademisyen.txt");

        for(int i = 0; i<akdId;i++){

            akdFile>>tempNum;

            if(numara==tempNum){
                akdFile.close();
                return i;
            }

            for(int j = 0;j<6;j++){
                akdFile>>tempStr2;
            }
        }
        akdFile.close();
        return -1;
    }


}


void randevuSistemi::rndParcala(){

    rndGun = atoi(rndTarih.substr(0,2).c_str());
    rndAy = atoi(rndTarih.substr(3,2).c_str());
    rndYil = atoi(rndTarih.substr(6,4).c_str());

    rndBasH = atoi(rndBaslangic.substr(0,2).c_str());
    rndBasM = atoi(rndBaslangic.substr(3,2).c_str());

}


void randevuSistemi::infoEkle(){
    ifstream ogrFile("ogrenci.txt");
    ifstream akdFile("akademisyen.txt");
    ifstream rndFile("randevu.txt");
    string temp2;
    ogrId = 0;
    akdId = 0;
    rndId = 0;

    while(getline(ogrFile,temp2)){
        ++ogrId;

    }

    while(getline(akdFile,temp2)){
        ++akdId;
    }

    while(getline(rndFile,temp2)){
        ++rndId;
    }
    ogrFile.close();
    akdFile.close();
    rndFile.close();

}


void randevuSistemi::ogrYenile(){
    string t1,t2,t3,t4;
    long long int z1,z2,z3;
    ifstream ogrFile("ogrenci.txt");
    for(int i = 0; i<ogrId;i++){
        ogrFile>>z1>>t1>>t2>>t3>>z2>>t4>>z3;
        ogr[i].setOgrNumara(z1);
        ogr[i].setAd(t1);
        ogr[i].setSoyad(t2);
        ogr[i].setOgrBolum(t3);
        ogr[i].setOgrKayitYili(z2);
        ogr[i].setEMail(t4);
        ogr[i].setTelNum(z3);
    }
    ogrFile.close();

}

void randevuSistemi::akdYenile(){
    string t1,t2,t3,t4,t5;
    long long int z1,z2;
    ifstream akdFile("akademisyen.txt");
    for(int i = 0; i<akdId;i++){
        akdFile>>z1>>t1>>t2>>t3>>t4>>z2>>t5;
        akd[i].setAkdNo(z1);
        akd[i].setAd(t1);
        akd[i].setSoyad(t2);
        akd[i].setAkdDal(t3);
        akd[i].setEMail(t4);
        akd[i].setTelNum(z2);
        akd[i].setAkdUnvan(t5);
    }
    akdFile.close();

}

void randevuSistemi::rndYenile(){
    string t1,t2,t3;
    long long int z1,z2;
    ifstream rndFile("randevu.txt");
    for(int i = 0; i<rndId;i++){
        rndFile>>z1>>z2>>t1>>t2>>t3;
        rndTarih = t1;
        rndBaslangic = t2;
        rndParcala();
        rnd[i].setRndOgrNum(z1);
        rnd[i].setRndAkdNum(z2);
        rnd[i].setTarih(rndGun,rndAy,rndYil);
        rnd[i].setBaslangic(rndBasH,rndBasM);

    }
    rndFile.close();


}



void randevuSistemi::dosyaGuncelle(){
    ofstream ogrFile("ogrenci.txt");
    ofstream akdFile("akademisyen.txt");
    ofstream rndFile("randevu.txt");

    for(int i = 0; i<ogrId;i++){
        ogrFile<<ogr[i].getOgrNumara()<<" "<<ogr[i].getAd()<<" "<<ogr[i].getSoyad()<<" "<<ogr[i].getOgrBolum()<<" "<<
        ogr[i].getOgrKayitYili()<<" "<<ogr[i].getEMail()<<" "<<ogr[i].getTelNum()<<endl;
    }

    for(int i = 0; i<akdId;i++){
        akdFile<<akd[i].getAkdNo()<<" "<<akd[i].getAd()<<" "<<akd[i].getSoyad()<<" "<<akd[i].getAkdDal()<<" "<<
        akd[i].getEMail()<<" "<<akd[i].getTelNum()<<" "<<akd[i].getAkdUnvan()<<endl;
    }

    for(int i = 0; i<rndId;i++){
        rndFile<<rnd[i].getRndOgrNum()<<" "<<rnd[i].getRndAkdNum()<<" "<<rnd[i].getGun()<<"."<<rnd[i].getAy()<<"."<<
        rnd[i].getYil()<<" "<<rnd[i].getBasH()<<"."<<rnd[i].getBasM()<<" "<<rnd[i].getBitH()<<"."<<rnd[i].getBitM()<<endl;
    }

    ogrFile.close();
    akdFile.close();
    rndFile.close();
}



void randevuSistemi::debugMod(){
    cout<<"---DEBUG MOB ---"<<endl;
    cout<<endl;
    cout<<"ogr :"<<ogrId<<endl;
    cout<<"akd :"<<akdId<<endl;
    cout<<"rnd :"<<rndId<<endl;

    cout<<endl;
    cout<<"ogrenci listeleme**"<<endl;
    ogrListele();
//    cout<<"O-0: "<<ogr[0].getOgrNumara()<<endl;
//    cout<<"O-1: "<<ogr[1].getOgrNumara()<<endl;
//    cout<<"O-2: "<<ogr[2].getOgrNumara()<<endl;
//    cout<<"O-3: "<<ogr[3].getOgrNumara()<<endl;

    cout<<endl;
    cout<<"akademisyen listeleme**"<<endl;

    akdListele();
//    cout<<"a-0: "<<akd[0].getAkdNo()<<endl;
//    cout<<"a-1: "<<akd[1].getAkdNo()<<endl;
//    cout<<"a-2: "<<akd[2].getAkdNo()<<endl;
//    cout<<"a-3: "<<akd[3].getAkdNo()<<endl;
    cout<<endl;

    cout<<"randevu listeleme**"<<endl;
    rndListele();
//    cout<<"r-0: "<<rnd[0].getRndOgrNum()<<" "<<rnd[0].getRndAkdNum()<<" "<<rnd[0].getBasH()<<":"<<rnd[0].getBasM()<<" "<<rnd[0].getBitH()<<":"<<rnd[0].getBitM() <<endl;
//    cout<<"r-1: "<<rnd[1].getRndOgrNum()<<" "<<rnd[1].getRndAkdNum()<<" "<<rnd[1].getBasH()<<":"<<rnd[1].getBasM()<<" "<<rnd[1].getBitH()<<":"<<rnd[1].getBitM() <<endl;
//    cout<<"r-2: "<<rnd[2].getRndOgrNum()<<" "<<rnd[2].getRndAkdNum()<<" "<<rnd[2].getBasH()<<":"<<rnd[2].getBasM()<<" "<<rnd[2].getBitH()<<":"<<rnd[2].getBitM() <<endl;
//    cout<<"r-3: "<<rnd[3].getRndOgrNum()<<" "<<rnd[3].getRndAkdNum()<<" "<<rnd[3].getBasH()<<":"<<rnd[3].getBasM()<<" "<<rnd[3].getBitH()<<":"<<rnd[3].getBitM() <<endl;



}
