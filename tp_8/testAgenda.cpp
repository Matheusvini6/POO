#include <iostream>
#include "Agenda.h"
#include <vector>
#include <string>

using namespace std;

int main(){
    int qtdPessoas=0;
    cout << "Digite numero de pessoas da agenda" << endl;
    cin >> qtdPessoas;
    Agenda a(qtdPessoas);
    a.addInformacoes();
    a.imprimeAniversarios();
    
    return 0;
}