#include <iostream>
#include "Agenda.h"
#include <vector>
#include <string>

using namespace std;

int main(){
    int qtdPessoas = 3;
    Agenda a(qtdPessoas);
    a.addInformacoes();
    a.imprimeAniversarios();
    
    return 0;
}