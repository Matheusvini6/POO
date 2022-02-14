#include <iostream>
#include <vector>
#include <string>

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
        void setAge(int idade){this->age = idade;};
        virtual string getInformation() = 0;
        virtual ~Pessoa(){};
};


class Amigo: public Pessoa{
    private:
        string dateBirthday;
    public:
        Amigo(): dateBirthday("indefinido") {};
        inline void setDateBirthday(string s) { dateBirthday = s;};
        inline string getInformation(){return dateBirthday;};
        virtual ~Amigo(){};
};

class Conhecido: public Pessoa{
    private:
        string email;
    public:
        Conhecido(): email("indefinido") {/*cout << "criou conhecido" << endl;*/};
        inline void setEmail(string s){this->email = s;};
        inline string getInformation(){return email;};
        virtual ~Conhecido(){};
};

class Agenda{
    private:
        vector<Pessoa*> person;
        int numberAmigos, numberConhecidos;
        vector<int> tipoPessoa; //tipo 1 ou 2?
    
    public:
        Agenda(int numPessoas);
        void setNumberAmigos(int maisUm) {numberAmigos+= maisUm;};
        void setNumberConhecidos(int maisUm) {numberConhecidos += maisUm;};
        inline void setPerson(Pessoa *p) { person.push_back(p); };//define o tipo de pessoa
        inline void setTipoPessoa(int tipo) {tipoPessoa.push_back(tipo); }; //identificador do tipo de pessoa(1 or 2)
        void addInformacoes();
        void  imprimeAniversarios();
};


#endif