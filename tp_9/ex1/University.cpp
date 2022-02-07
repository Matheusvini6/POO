#include <iostream>
#include "University.h"
#include <vector>

using namespace std;

double ProfHorista::getSalario(){
    double retorno = 0;
    retorno = this->nrNorasTrabalhadas * this->valorHora;
    return retorno;
};

double ProfIntegral::getSalario(){
    return this->salarioMensal;
};

double Universidade:: totalPago(){
    total = 0;
    for(int i = 0; i < professores.size(); i++ ){
        ProfHorista *ph = dynamic_cast<ProfHorista*>(&professores[i]);
        ProfIntegral *pi = dynamic_cast<ProfIntegral*>(&professores[i]);

        if(ph){
            total+= ph->getSalario();
        }
        else if(pi){
            total+= pi->getSalario();
        }
    }
    return total;
};

