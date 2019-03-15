//goruntu.cpp
#include <iostream>
#include <math.h>
#include "goruntu.h"

using namespace std;

goruntu::goruntu(){
    setGX();
    setGY();

}



//Dikey sobel maskesi
void goruntu::setGX(){
    gX[0][0]=-1;
    gX[0][1]=0;
    gX[0][2]=1;

    gX[1][0]=-2;
    gX[1][1]=0;
    gX[1][2]=2;

    gX[2][0]=-1;
    gX[2][1]=0;
    gX[2][2]=1;

}

//yatay sobel maskesi
void goruntu::setGY(){
    gY[0][0]=-1;
    gY[0][1]=-2;
    gY[0][2]=-1;

    gY[1][0]=0;
    gY[1][1]=0;
    gY[1][2]=0;

    gY[2][0]=1;
    gY[2][1]=2;
    gY[2][2]=1;

}

ifstream &operator>>( ifstream  &file, goruntu &g ){
    char* c; //dosyadaki tum veriyi barindiran karakter dizisi
    unsigned char m;// gecici olarak kullanilan degisken

    //dosya okunup c dizisine atiliyor
    file.seekg(0,file.end);
    int length = file.tellg();
    file.seekg(0,file.beg);

    c = new char [length];
    file.read(c,length);

    //ilk deger unsigned chara cevrildi daha sonra height e atandı
    m = c[0];
    g.height = (int)m;

    m = c[1];
    g.width = (int)m;

    //width ve height e gore arrayler kuruldu
    g.setAry();
    g.setAry2();

    int q = 2; // 0 ve 1 de boyut bilgisi tutuldugundan 2 den baslatildi

    //verileri iki boyutlu arraye aktarma islemi
    for(int i = 0;i<g.width;i++){
        for(int j = 0; j<g.height;j++){
            m = c[q];
            g.ary[j][i]=(int)m;
            q++;
        }

    }

}


//dosyaya yazdirma islemi
ofstream &operator<<( ofstream  &file, goruntu &g ){
    for(int i = 0;i<g.width;i++){
        for(int j = 0; j<g.height;j++){
            if(g.ary2[j][i]==0){
                file<<"-";
            }
            else if(g.ary2[j][i]==1){
                file<<"*";
            }
            else{
                file<<"@";
            }


        }
        file<<endl;

    }


}

void goruntu::sobel(){

    for(int i = 0;i<width;i++){
        for(int j = 0; j<height;j++){
            if(i==0 || i==width-1 || j==0 || j==height-1){
                ary2[j][i]=0;

            }
            else{

                sX = (ary[j-1][i-1]*gX[0][0])+
                        (ary[j-1][i]*gX[0][1])+
                        (ary[j-1][i+1]*gX[0][2])+

                        (ary[j][i-1]*gX[1][0])+
                        (ary[j][i]*gX[1][1])+
                        (ary[j][i+1]*gX[1][2])+

                        (ary[j+1][i-1]*gX[2][0])+
                        (ary[j+1][i]*gX[2][1])+
                        (ary[j+1][i+1]*gX[2][2]);

                sY = (ary[j-1][i-1]*gY[0][0])+
                        (ary[j-1][i]*gY[0][1])+
                        (ary[j-1][i+1]*gY[0][2])+

                        (ary[j][i-1]*gY[1][0])+
                        (ary[j][i]*gY[1][1])+
                        (ary[j][i+1]*gY[1][2])+

                        (ary[j+1][i-1]*gY[2][0])+
                        (ary[j+1][i]*gY[2][1])+
                        (ary[j+1][i+1]*gY[2][2]);



            int sx2 = pow(sX,2);
            int sy2 = pow(sY,2);
            int toplam = sx2+sy2;
            s = sqrt(toplam);
            ary2[j][i]=s;

            }


        }

    }

}

void goruntu::threshold(int x){
    for(int i = 0;i<width;i++){
        for(int j = 0; j<height;j++){

            if(ary2[j][i]<=x){
                ary2[j][i]=0;
            }
            else if(ary2[j][i]>x){
                ary2[j][i]=1;
            }
            else{
                cout<<"hata202!"<<endl;
            }

        }

    }


}

goruntu goruntu::operator+(const goruntu& g){
    goruntu gor;
    gor.height = this->height;
    gor.width = this->width;
    gor.setAry2();

    for(int i = 0;i<gor.width;i++){
        for(int j = 0; j<gor.height;j++){
            if(this->ary2[j][i]+g.ary2[j][i]!=0){
                gor.ary2[j][i] = 1;
            }
            else{
                gor.ary2[j][i]=0;
            }


        }

    }


    return gor;


}

goruntu goruntu::operator*(const goruntu& g){
    goruntu gor;
    gor.height = this->height;
    gor.width = this->width;
    gor.setAry2();

    for(int i = 0;i<gor.width;i++){
        for(int j = 0; j<gor.height;j++){
            if(this->ary2[j][i]+g.ary2[j][i]==2){
                gor.ary2[j][i] = 1;
            }
            else{
                gor.ary2[j][i]=0;
            }


        }

    }


    return gor;


}

goruntu goruntu::operator!(){
    goruntu gor;
    gor.height = this->height;
    gor.width = this->width;
    gor.setAry2();

    for(int i = 0;i<width;i++){
        for(int j = 0; j<height;j++){
            if(this->ary2[j][i]==1){
                gor.ary2[j][i]=0;
            }
            else if(this->ary2[j][i]==0){
                gor.ary2[j][i]=1;
            }
            else{
                gor.ary2[i][j]=2;
            }

        }

    }

    return gor;
}




void goruntu::debugMod(goruntu g){
    cout<<endl;
    cout<<"_______Debug_______"<<endl;
    int sifir = 0;
    int bir = 0;
    int hata=0;
//    for(int i = 0; i<height;i++){
//        for(int j = 0; j<width; j++){
//            if(ary2[i][j]==0)
//                sifir++;
//            else if(ary2[i][j]==1)
//                bir++;
//            else{
//                hata++;
//                 cout<<" i:"<<i<<" j:"<<j<<"  ---> "<<ary2[i][j]<<endl;
//            }
//            //cout<<" i:"<<i<<" j:"<<j<<"  ---> "<<ary[i][j]<<endl;
//
//        }
//
//    }


}
