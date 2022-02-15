//test file

#include <iostream>
#include "Agenda.h"
#include <vector>
#include <string>

using namespace std;

int main(){
    int qtdPessoas = 0;
    
    cout << "Quantas pessoas você deseja adicionar na agenda? ";
    cin >> qtdPessoas;

    Agenda a(qtdPessoas);
    cout << "\nQuantidade de AMIGOS na agenda: " << a.getNumberAmigos() << endl;
    cout << "Quantidade de CONHECIDOS na agenda: " << a.getNumberConhecidos() << endl;
    cout << endl;

    a.addInformacoes();
    a.imprimeAniversarios();
    a.imprimeEmail();

    return 0;
}