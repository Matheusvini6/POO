#include <iostream>
#include "Ponto.hpp"

using namespace std;

int main() {

    Ponto2D a(1,4), b(3,2), c;
    c = a + b;               // soma as coordenadas dos pontos a e b 
    cout << "A(" << a.getx() << "," << a.gety()  << ")" << endl;
    cout << "B(" << b.getx() << "," << b.gety()  << ")" << endl << endl;
    cout << "C é o ponto soma entre os pontos A e B:" << endl;
    cout << "C(" << c.getx() << "," << c.gety()  << ")" << endl << endl;
    --c;                    // decrementa em uma unidade as coordenadas de c
    cout << "Ponto C decrementado uma unidade em cada coordenada:" << endl;
    cout << "C(" << c.getx() << "," << c.gety()  << ")" << endl;

    return 0;
}