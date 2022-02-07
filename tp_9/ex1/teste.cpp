#include <iostream>
#include <vector>
#include <cstring>
#include "University.h"

using namespace std;

int main(){

    ProfHorista ph1("HORISTA_1", 10, 5), ph2("HORISTA_2", 20, 5);
    ProfIntegral pi("INTEGRAL", 1000);
    Professor *pHorista1 = &ph1, *pHorista2 = &ph2, *pIntegral = &pi;
    Universidade u;

    u.addProfessor(*pHorista1);
    u.addProfessor(*pHorista2);
    u.addProfessor(*pIntegral);

    return 0;
}