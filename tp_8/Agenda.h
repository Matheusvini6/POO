#include <iostream>
#include <vector>

#ifndef AGENDA_H
#define AGENDA_H

using namespace std;//fazer destrutor de todas as classes

class Pessoa{
    private:
        string name;
        int age;
    public:
        Pessoa(string nome, int idade): name(nome), age(idade) {};
        Pessoa(): name("indefinido"), age(0) {};
};


class Amigo: public Pessoa{
    private:
        string dateBirthday;
    public:
        Amigo(): dateBirthday("indefinido") {};

};


class Conhecido: public Pessoa{
    private:
        string email;
    public:
        Conhecido(): email("indefinido") {};
};


class Agenda{
    private:
        vector<Pessoa> person;
        int numberAmigos, numberConhecidos;
    
    public:
        Agenda(int numPessoas);
        inline void setPerson(Pessoa &p){ person.push_back(p); };

};


#endif