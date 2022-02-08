//test file

#include <iostream>
#include <vector>
#include <cstring>
#include "University.h"

using namespace std;

int main(){

    ProfHorista ph1("Matheus", 10, 5), ph2("Jesimon", 20, 5);
    ProfIntegral pi("Diego", 1000);
    Professor *pHorista1 = &ph1, *pHorista2 = &ph2, *pIntegral = &pi;
    Universidade u;

    u.addProfessor(pHorista1);
    u.addProfessor(pHorista2);
    u.addProfessor(pIntegral);

    u.imprime();
    cout << "\nTotal pago: " << u.totalPago(); 
    cout << endl << endl;

    return 0;
}