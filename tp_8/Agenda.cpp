#include <iostream>
#include "Agenda.h"
#include <vector>
#include <ctime>
#include <string>

using namespace std;

//
Agenda::Agenda(int numPessoas){
    srand((unsigned int) time (NULL)); //activates the generator
    int max = 3, min = 1, maisUm = 1;

    for(int i = 0; i < numPessoas; i++){
        int randomNumber = (rand()%(max - min)) + min;
        if(randomNumber == 1){
            Amigo a;
            Pessoa *p = &a;
            setPerson(p);
            setTipoPessoa(randomNumber);
            setNumberAmigos(maisUm);
            //cout << "criou amigo" << endl;
        }else{
            Conhecido c;
            Pessoa *p = &c;
            setPerson(p);
            setTipoPessoa(randomNumber);
            setNumberConhecidos(maisUm);
            //cout << "criou conhecido" << endl;
        }
    }
}

void Agenda::addInformacoes(){
    for(int i = 0; i < person.size(); i++){
        if(tipoPessoa[i] == 1){//cria um amigo
            cout << "Digite uma data de aniversário no formato: dd/mm/aaaa" << endl;
            string data;
            cin >> data;
            Amigo *a = new Amigo();
            a->setDateBirthday(data);
            person[i] = a;
            
        }else if(tipoPessoa[i] == 2){ //cria um conhecido
            cout << "Digite um e-mail: " << endl;
            string email;
            cin >> email;
            Conhecido *c = new Conhecido();
            c->setEmail(email);
            person[i] = c;   
        }
    }
}

void Agenda::imprimeAniversarios(){
    for(int i = 0; i < person.size(); i++){
        if(tipoPessoa[i] == 1){
            Amigo *a = dynamic_cast<Amigo*>(person[i]);
            cout << a->getInformation() << endl;
        }
    }
}

Agenda::~Agenda(){
    int size_vector = person.size();
    for(int i=0; i<size_vector; i++){
        delete(person[i]);
    }
}
