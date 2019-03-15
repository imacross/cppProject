/*
 / \                             \.
|   |  AUTHOR:  Cagdas Yanar     |.
 \_ |                            |.
    |           365338           |.
    |     Yusuf Cagdas Yanar     |.
    |   cagdasyanar@outlook.com  |.
    |                            |.
    |      +90 507 193 88 28     |.
    |                            |.
    |     www.cagdasyanar.com    |.
    |                            |.
    |          31.12.2018        |.
    |                            |.
    |         Sobel Filter       |.
    |   _________________________|.__
    |  /                            /.
    \_/____________________________/.

*/


//main.cpp
#include <iostream>
#include "matris.h"
#include "goruntu.h"
#include <fstream>
using namespace std;

int main()
{

    ifstream f1("image1.bin",ifstream::binary);
    ifstream f2("image2.bin");
    ofstream f3("fileout.txt");

    goruntu g1;
    goruntu g2;
    goruntu g3;

    f1>>g1;
    f2>>g2;

    g1.sobel();
    g2.sobel();

    g1.threshold(100);
    g2.threshold(100);
    g3 = g1+g2;
    g3 = !g3;

    f3<<g2;

    f1.close();
    f2.close();
    f3.close();

    cout<<"ISLEM BASARILI BIR SEKİLDE GERCEKLESTI"<<endl;

    return 0;
}

