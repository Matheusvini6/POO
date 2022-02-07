#include <iostream>
#include <cstring>
#include <vector>

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

using namespace std;

class Professor{
        string nome;
    public:
        Professor(string n): nome(n){};
        string getName() const {return this->nome;};
        virtual double getSalario() = 0;
        virtual ~Professor();

        void setNome(string s) {this->nome = s;};
        Professor(){};

};

class ProfHorista: public Professor {
        double nrNorasTrabalhadas;
        double valorHora;
    public:
        ProfHorista(string n, double nht, double vh){
            setNome(n);
            nrNorasTrabalhadas = nht;
            valorHora = vh;
        };
        double getSalario();
        virtual ~ProfHorista();
};

class ProfIntegral: public Professor {
        double salarioMensal;
    public:
       ProfIntegral(string n, double sm){
           setNome(n);
           salarioMensal = sm;
       };
       double getSalario();
       virtual ~ProfIntegral(){}
};

class Universidade{
    private:
        vector<Professor> professores;
        double total;
    public:
        void addProfessor(Professor &p) {professores.push_back(p); };
        double totalPago();

};

#endif