//Parte 02
//main do tempo

#include <iostream>
#include "tempo.h"

using namespace std;

int main(){
    Tempo t1(72), t2(90,3), t3(4, 7,55), t4(45, 30, 56, 65);
    
    cout << "tempo t4:\n";
    t4.checaConsistencia();
    cout << t4.getDia() << "d " << t4.getHora() << "h " << t4.getMin() << "min " << t4.getSeg() << "s ";

    cout << "\n\nts é a soma entre os tempos t1 e t4: \ntempo ts:\n";
    Tempo ts = t4.somaTempo(t1);
    ts.show();
    
    cout << "tr é o tempo lido pelo teclado: \n";
    Tempo tr;
    tr.read();
    tr.checaConsistencia();
    cout << "tempo tr:\n";
    tr.show();

    cout << "ti é o tempo t4 incrementado 1 segundo: \ntempo ti:\n";
    Tempo ti = t4;
    ti.incrementaSegundo();
    ti.checaConsistencia();
    ti.show();

    cout << "td é o tempo ti decrementado 1 segundo:\ntempo td:\n";
    Tempo td = ti;
    td.decrementaSegundo();
    td.checaConsistencia();
    td.show();

    return 0;
}