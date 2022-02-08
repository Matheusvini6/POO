#include <iostream>
#include "University.h"
#include <vector>
#include <iomanip>

using namespace std;

double ProfHorista::getSalario(){
    double retorno = 0;
    retorno = this->nrNorasTrabalhadas * this->valorHora;
    return retorno;
};

double ProfIntegral::getSalario(){
    return this->salarioMensal;
};

double Universidade::totalPago(){
    total = 0;
    for(int i = 0; i < professores.size(); i++ ){
        ProfHorista *ph = dynamic_cast<ProfHorista*>(professores[i]);
        ProfIntegral *pi = dynamic_cast<ProfIntegral*>(professores[i]);

        if(ph){
            total+= ph->getSalario();
        }
        else if(pi){
            total+= pi->getSalario();
        }
    }
    return total;
};

void Universidade::imprime(){
    for(int i = 0; i < professores.size(); i++){
        ProfHorista *ph = dynamic_cast<ProfHorista*>(professores[i]);
        ProfIntegral *pi = dynamic_cast<ProfIntegral*>(professores[i]);

        if(ph){
            cout << "Professor horista: ";
            cout << ph->getName()<< "       Horas trabalhadas: " << ph->getHorasTrabalho() << "h";
            cout.precision(2);
            cout << "       Valor da hora: R$ " << fixed <<  ph->getValorHora();
            cout  << "      Salário: R$" << ph->getSalario();
            cout << endl;
            cout.precision(0);
        }
        else if(pi){
            cout.precision(2);
            cout << "Professor integral: ";
            cout << pi->getName() << fixed << "        Salário: R$ " << pi->getSalario() << endl;
        }

    }
}
