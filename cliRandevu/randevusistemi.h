//randevusistemi.h
#ifndef RANDEVUSISTEMI_H_INCLUDED
#define RANDEVUSISTEMI_H_INCLUDED

class randevuSistemi{
    public:
        randevuSistemi();
        void ogrEkle();//ogrenci ekleme
        void akdEkle();//akademisyen ekleme
        void rndEkle();//randevu ekler
        //diger fonksiyonlarda kullanabilmek icin farklı parametreler alan randevu ekleme fonksiyonu
        void rndEkle(int ogrNum, int akdNum,int gun,int ay,int yil, int basH, int basM, int id);

        void ogrSil(); //ogrenci siler
        void akdSil(); //akademisyen siler
        void rndSil(); //randevu siler
        void rndSil(int id,int num,int durum);

        void ogrGuncelle(); //ogrenci bilgilerini gunceller
        void akdGuncelle(); //akademisyen bilgilerini gunceller
        void rndGuncelle(); //randevu degisikligi yapar

        void ogrListele(); //ogrencilerin listesi
        void akdListele(); //akademisyenlerin listesi
        void rndListele(); //randevuların toplamını listeler

        void ogrRndListele(); //ogrencinin randevularını sıralar
        void akdRndListele(); //akademisyenin randevularını sıralar


        void ogrYenile();//öğrenci listesini dosyadan çekip günceller
        void akdYenile();//akademisyen listesini dosyadan çekip günceller
        void rndYenile();//randevular listesini dosyadan çekip günceller





        void rndParcala();//tarih saat gibi string degiskenleri int e cevirir

        void debugMod(); //yazılımcının test için kullandığı fonksiyon
        void test();

        void infoEkle();//öğrenci ve akademisyenlerden kaç tane olduğunu ilgili değişkenlere atar
        int bilgiDondur(int,int);//Bu fonksiyonun parametresine girilen numaradan kullanıcı bilgisi döndürür
        //ikinci parametresi ise hangi dosyada araması gerektiğini söyler *0 = ogrFile *1=akdFile
        void dosyaGuncelle();//yapılan değişiklikler karşısında dosyayı listeye göre düzenler
    private:
        ogrenci ogr[100];
        akademisyen akd[100];
        randevu rnd[300];

        randevu rndTemp[100];//fonksiyonlarda kullanılan gecici listeler
        randevu ogrRndList[100];
        randevu akdRndList[100];

        ogrenci tempOgr;
        akademisyen tempAkd;

        int ogrId;//kac ogrencinin bulundugunu tutar
        int akdId;
        int rndId;

        int ogrRndSayici;//ogrencinin randevu sayisini tutar
        int akdRndSayici;

        bool buldunMu;//numaraya göre id aramasinda kullanilir

        string rndTarih;//parcalamadan önce string degerleri tutan degiskenler
        string rndBaslangic;
        string rndBitis;

        int rndGun;//parcaladıktan sonra henuz randevu listesine yazmadan kullanılan degiskenler
        int rndAy;
        int rndYil;

        int rndBasH;
        int rndBasM;

        long long int tempInt;//sürekli kullanılan gecici degiskenler
        string tempStr;
        int tempNum;

};


#endif
