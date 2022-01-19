//test file

#include <iostream>
#include "Box.h"

using namespace std;

int main(){

    double area = 0, volume = 0;
    Ponto3D p1_(2,3,4), p2_(4,3,4), p3_(4,5,4), p4_(4,3,6);
    Box b(p1_,p2_,p3_,p4_);
    
    area = b.area();
    volume = b.volume();
    cout << "Área do paralelpípdedo: " << area << endl;
    cout << "volume do paralelepípedo: " << volume << endl;
    
    return 0; 
}