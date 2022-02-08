//header file

#include <iostream>
#include <cstring>
#include <vector>

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

using namespace std;

class Professor{
        string nome;
    public:
        Professor(string n): nome(n){}
        string getName() const {return this->nome;};
        virtual double getSalario() = 0;
        virtual ~Professor(){};
        void setNome(string s) {this->nome = s;};
        Professor(){/*cout << "chamou" << endl;*/};

};

class ProfHorista: public Professor {
        double nrNorasTrabalhadas;
        double valorHora;
    public:
        ProfHorista(string n, double nht, double vh):Professor(n), 
        nrNorasTrabalhadas(nht), valorHora(vh){}
        
        double getSalario();
        virtual ~ProfHorista(){};
        double getHorasTrabalho(){return nrNorasTrabalhadas;}
        double getValorHora(){return valorHora;} 
};

class ProfIntegral: public Professor {
        double salarioMensal;
    public:
       ProfIntegral(string n, double sm):Professor(n), salarioMensal(sm){}
       double getSalario();
       virtual ~ProfIntegral(){};
};

class Universidade{
    private:
        vector<Professor*> professores;
        double total;
    public:
        Universidade(){};
        void addProfessor(Professor *p) {professores.push_back(p); };
        double totalPago();
        ~Universidade(){};
        void imprime();
};

#endif