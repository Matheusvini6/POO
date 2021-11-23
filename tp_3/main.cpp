//main.cpp

#include <stdio.h>
#include "Ponto.hpp"
#include <vector>

using namespace std;

int main(){
    Ponto2D *a = new Ponto2D(1, 3);
    Ponto2D *b = new Ponto2D(5, 5);   
    cout << "A";
    a->print();
    cout << "id A: " << a->getId() << endl;
    cout << "B";
    b->print();
    cout << "id B: " << b->getId() << endl << endl; 

    Ponto2D *c = nullptr;
    c = a -> sumof(b);
    cout << "C é o ponto soma entre os pontos A e B: \nC";
    c->print();
    cout << "id C: " << c->getId() << endl;
    cout << endl;

    a->sumof(*b);
    cout << "Ponto A somado ao ponto B: \nA";
    a->print();
    cout << endl;
    
    double d = a->distToOrig();
    cout << "d é a distância do ponto A à origem: \nd = " << d << "u" << endl;
    cout << endl;

    Ponto2D *m = new Ponto2D(3, 5);
    Ponto2D *n = new Ponto2D(6, 1);
    cout << "M";
    m->print();
    cout << "id M: " << m->getId() << endl;
    cout << "N";
    n->print();
    cout << "id N: " << n->getId() << endl;
    double ds = m->distTo(*n);
    cout << "ds é a distâcia do ponto M ao ponto N: \nds = " << ds << "u" << endl;
    cout << endl;

    delete a;
    delete b;
    delete c;
    delete m;
    delete n;

    return 0;
}
