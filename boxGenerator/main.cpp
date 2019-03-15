//yusuf çağdaş yanar 365338 05071938828  cagdasyanar@outlook.com www.cagdasyanar.com
//başlangıç - main.cpp

#include <iostream>
#include "coord.h"
#include "box.h"
#include "space.h"

using namespace std;

int main()
{

    coord spaceArea(20,10);
    space s(spaceArea);
    s.fillRandomBox(10,6,10); //boxnum, maxboxsize,dens
    s.printBoxCoord();
    s.printCog();
    //s.printDebug();



    return 0;
}

//bitiş- main.cpp
