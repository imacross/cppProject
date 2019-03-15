//akademisyen.cpp
#include <iostream>
#include "mate.h"
#include "akademisyen.h"
#include <string>

using namespace std;

akademisyen::akademisyen(){

}

void akademisyen::setAkdDal(string akdDal){
    this->akdDal = akdDal;
}

void akademisyen::setAkdUnvan(string akdUnvan){
    this->akdUnvan = akdUnvan;
}

void akademisyen::setAkdNo(int akdNo){
    this->akdNo = akdNo;
}

string akademisyen::getAkdDal(){
    return akdDal;
}

string akademisyen::getAkdUnvan(){
    return akdUnvan;
}

int akademisyen::getAkdNo(){
    return akdNo;
}
