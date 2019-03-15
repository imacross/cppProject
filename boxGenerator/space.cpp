//başlangıç space.cpp

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "box.h"
#include "coord.h"
#include "space.h"


using namespace std;

space::space(coord spaceArea,box boxtest)
:spaceArea(spaceArea), boxtest(boxtest)

{
    cout<< "**** space cons *****"<<endl;
    cout<< "space x:"<<spaceArea.getCoordX()<< " y:"<<spaceArea.getCoordY()<<endl;

    sx = spaceArea.getCoordX();
    sy = spaceArea.getCoordY();
    boxSize = 1;
    dotSize = 1;


    cout<<boxtest.getCornerLUx()<<" ?? "<<boxtest.getCornerLUy()<<endl;
    fillRandomBox(1,2,3);
 //set3dArray();
}
space::space(coord spaceArea)
:spaceArea(spaceArea)
{

    sx = spaceArea.getCoordX();
    sy = spaceArea.getCoordY();
    boxSize = 0;
    dotSize = 0;
    boxNum = 0;
    dotNum = 0;
    maxBoxSize = 0;
    dens = 0;

    randomW = 0;
    randomH = 0;
    randomD = 0;
    k = 0;
    l = 0;
    cogX = 0;
    cogY = 0;

}


//void space::set3dArray(){
////3 boyutlu array yaratıldı
//    noktalar = new int**[boxSize];
//    for(int i = 0; i<boxSize; i++)
//    {
//        noktalar[i] = new int*[dotSize];
//        for(int j = 0; j<dotSize; j++)
//        {
//            int **ptr = noktalar[i];
//            ptr[j] = new int[2];
//        }
//
//    }
//    noktalar[0][0][0] = 10;

//}



void space::fillRandomBox(int boxNum,int maxBoxSize, int dens)
{
    //parametreler eşitleniyor
    this->boxNum = boxNum;
    this->maxBoxSize = maxBoxSize;
    this->dens = dens;
    //kutu arrayi oluşturuluyor
    boxArr = new box[boxNum];
    int minBoxSize = 1;
    int minDensSize = 1;

    srand(time(0)); //random sayıların bir birine benzememsi için


    //Kutular oluşturuluyor
    for(int i = 0; i<boxNum;i++){
        randomW = rand() % (maxBoxSize - minBoxSize + 1 ) + minBoxSize;
        randomH = rand() % (maxBoxSize - minBoxSize + 1 ) + minBoxSize;
        randomD = rand() % (dens - minDensSize + 1 ) + minDensSize;
       // cout<<"random x:"<<randomW<<" random y:" << randomH<<endl;
        boxArr[i].setWidth(randomW);
        boxArr[i].setHeight(randomH);
        boxArr[i].setDensity(randomD);
        //boxArr[i].printBox();
    }

//    boxArr[0].setWidth(6);
//    boxArr[1].setWidth(4);
//    boxArr[2].setWidth(4);
//    boxArr[3].setWidth(4);
//    boxArr[4].setWidth(3);
//    boxArr[5].setWidth(3);
//    boxArr[6].setWidth(2);
//    boxArr[7].setWidth(1);
//    boxArr[8].setWidth(1);
//    boxArr[9].setWidth(1);
//
//    boxArr[0].setHeight(1);
//    boxArr[1].setHeight(6);
//    boxArr[2].setHeight(6);
//    boxArr[3].setHeight(3);
//    boxArr[4].setHeight(6);
//    boxArr[5].setHeight(4);
//    boxArr[6].setHeight(4);
//    boxArr[7].setHeight(2);
//    boxArr[8].setHeight(2);
//    boxArr[9].setHeight(1);
//
//    boxArr[0].setDensity(1);
//    boxArr[1].setDensity(1);
//    boxArr[2].setDensity(1);
//    boxArr[3].setDensity(1);
//    boxArr[4].setDensity(1);
//    boxArr[5].setDensity(1);
//    boxArr[6].setDensity(1);
//    boxArr[7].setDensity(1);
//    boxArr[8].setDensity(1);
//    boxArr[9].setDensity(1);



    //boxArr dizisine width değişkenine göre insertion sort uygulanıyor ve büyükten
    //küçüğe diziliyor

    int j;
    for(int i = 0; i<boxNum; i++){
        double tempWidth = boxArr[i].getWidth();
        double tempHeight = boxArr[i].getHeight();
        double tempDensity = boxArr[i].getDensity();
        j = i-1;

        while(j>= 0 && boxArr[j].getWidth()<tempWidth){
            boxArr[j+1].setWidth(boxArr[j].getWidth());
            boxArr[j+1].setHeight(boxArr[j].getHeight());
            boxArr[j+1].setDensity(boxArr[j].getDensity());
            j--;

        }
        boxArr[j+1].setWidth(tempWidth);
        boxArr[j+1].setHeight(tempHeight);
        boxArr[j+1].setDensity(tempDensity);

    }
    j = 0;

    //Width e göre sıralanmış dizi bu sefer width leri aynı ama height leri farklı durumlarda
    //height leri büyükten küçüğe sıralıyor

    for(int i = 0; i<boxNum; i++){
        double tempWidth = boxArr[i].getWidth();
        double tempHeight = boxArr[i].getHeight();
        double tempDensity = boxArr[i].getDensity();
        j = i-1;

        while(j>= 0 && boxArr[j].getWidth()==tempWidth && boxArr[j].getHeight()<tempHeight){
            boxArr[j+1].setWidth(boxArr[j].getWidth());
            boxArr[j+1].setHeight(boxArr[j].getHeight());
            boxArr[j+1].setDensity(boxArr[j].getDensity());
            j--;

        }
        boxArr[j+1].setWidth(tempWidth);
        boxArr[j+1].setHeight(tempHeight);
        boxArr[j+1].setDensity(tempDensity);

    }




    bool isLoop = true;
    bool isNewColon = false;
    int controlX = 0;
    int controlY = 0;

    while (isLoop==true)
    {
       isLoop=false;
        for(int i=0;i<boxNum;i++)
        {
            if(boxArr[i].getWidth()>sx)
            {
                cout<<"!!ERROR "<<i<<". kutunun genişliği uzayın x inden büyük"<<endl;
                boxArr[i].printBox();
                isLoop = false;
                break;
            }
            else if(boxArr[i].getHeight()>sy)
            {
                cout<<"!!ERROR "<<i<<". kutunun uzunluğu uzayın y sinden büyük"<<endl;
                boxArr[i].printBox();
                isLoop = false;
                break;
            }

            else if(i==0)
            {
                boxArr[i].setPointx(0);
                boxArr[i].setPointy(0);
                k = boxArr[i].getHeight();
                l = boxArr[i].getWidth();
                controlY = sy-k;
                controlX = sx-l;

            }
            else if(boxArr[i].getHeight()<=controlY)
            {
                boxArr[i].setPointx(boxArr[i-1].getPointx());
                boxArr[i].setPointy(k);
                k = k+boxArr[i].getHeight();
                controlY = sy- k;

            }
            else if(boxArr[i].getHeight()>controlY)
            {

                if(boxArr[i].getWidth()<=controlX)
                {

                    boxArr[i].setPointx(l);
                    boxArr[i].setPointy(0);
                    k = boxArr[i].getHeight();
                    l = boxArr[i].getWidth()+l;
                    controlY = sy-k;
                    controlX = sx-l;

                }
                else if(boxArr[i].getWidth()>controlX){
                    cout<<"!!ERROR "<<i<<". Kutu boyutlardan dolayı yerleştirilemedi."<<endl;
                    cout<<endl;
                }
                else{
                    cout<<"!!!ERROR 11"<<endl;
                }

            }

            else{

            cout<<"!!error 22"<<endl;
            }

        }


    }


    cogCal();
<

}



void space::cogCal(){
    double sumofweights;
    for(int i=0;i<boxNum;i++){
        boxArr[i].setWeight();
        boxArr[i].setCenterBoxX();
        boxArr[i].setCenterBoxY();
        boxArr[i].setCorner();
        cogX += (boxArr[i].getCenterBoxX()*boxArr[i].getWeight());
        cogY += (boxArr[i].getCenterBoxY()*boxArr[i].getWeight());
        sumofweights += boxArr[i].getWeight();
    }
    cogX = cogX/sumofweights;
    cogY = cogY/sumofweights;

}

void space::printCog(){
    cout<<"Agirlik merkezi koordinantlari X:"<<cogX<<" Y:"<<cogY<<endl;
}

void space::printBoxCoord(){
    ofstream file;
    file.open("BoxCoord.txt");
    for(int i = 0; i<boxNum;i++)
    {
        file<<i+1<<" Numaralı kutu, Başlangıç Koordinantı:"<<boxArr[i].getPointx()<<"x"<<boxArr[i].getPointy()<<" ; Bitiş Koordinantı:"
        <<boxArr[i].getCornerRUx()<<"x"<<boxArr[i].getCornerRUy()<<endl;
    }
    file<<endl;
    file<<"Ağırlık merkezi koordinantları X:"<<cogX<<" Y:"<<cogY<<endl;
    file.close();
    for(int i = 0; i<boxNum;i++)
    {
        cout<<i+1<<" Numarali kutu, Baslangic Koordinanti:"<<boxArr[i].getPointx()<<"x"<<boxArr[i].getPointy()<<" ; Bitis Koordinanti:"
        <<boxArr[i].getCornerRUx()<<"x"<<boxArr[i].getCornerRUy()<<endl;
    }
}

void space::printDebug(){
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"----***DEBUG MOD***-----"<<endl;
    cout<<endl;
    cout<<"Space x,y:"<<sx<<"x"<<sy<<" Kutu sayısı:"<<boxNum<<" Max Kutu boyutu:"<<maxBoxSize<<" Density:"<<dens<<endl;
    cout<<endl;
    for(int i = 0;i<boxNum;i++){
    cout<<i+1<<"# size:"<<boxArr[i].getWidth()<<"x"<<boxArr[i].getHeight()<<" # Başlangıç:"<<boxArr[i].getPointx()<<"x"<<boxArr[i].getPointy()
    <<" # Bitiş:"<<boxArr[i].getCornerRUx()<<"x"<<boxArr[i].getCornerRUy()<<" # center:"<<boxArr[i].getCenterBoxX()<<"x"<<
    boxArr[i].getCenterBoxY()<<" # Ağ,Yoğ:"<<boxArr[i].getWeight()<<" , "<<boxArr[i].getDensity()<<endl;
    }
    cout<<endl;
    cout<<"##CenterofGravity x:"<<cogX<<" Y:"<<cogY<<endl;
}


//bitiş space.cpp
