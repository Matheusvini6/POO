#include <iostream>
#include "Agenda.h"
#include <vector>
#include <ctime>
#include <string>

using namespace std;

Agenda::Agenda(int numPessoas){
    srand((unsigned int) time (NULL)); //activates the generator
    int max = 3, min = 1;
    this->numberAmigos = 0;
    this->numberConhecidos = 0;

    for(int i = 0; i < numPessoas; i++){
        int randomNumber = (rand()%(max - min)) + min;

        if(randomNumber == 1){
            Amigo *amg = new Amigo();
            setPerson(amg);
            addNumberAmigos();
        }else{
            Conhecido *conhe = new Conhecido();
            setPerson(conhe);
            addNumberConhecidos();
        }
    }
}

void Agenda::addInformacoes(){
    for(unsigned int i = 0; i < person.size(); i++){
        cout << "Preencha os dados da pessoa " << i + 1 << endl << endl; 
        Amigo * amg = dynamic_cast<Amigo*> (person[i]);
        Conhecido * conhe = dynamic_cast<Conhecido*> (person[i]);

        if(amg != NULL){//adicionar informações do AMIGO
            string data = "";
            string nome = "";
            int idade = 0;
            
            cout << "Nome do(a) amigo(a): ";
            cin >> nome;
            cout << "Digite a data de aniversário do(a) " << nome << " no formato dd/mm/aaaa: ";
            cin >> data;
            cout << "Digite a idade do(a) " << nome << ": ";
            cin >> idade;
            cout << endl;
            
            amg->setName(nome);
            amg->setDateBirthday(data);
            amg->setAge(idade);
            
        }else{ //adiciona informações para CONHECIDO     
            string email = "";
            string nome = "";
            int idade = 0;
    
            cout << "Nome do(a) conhecido(a): ";
            cin >> nome;
            cout << "Digite o e-mail do(a) " << nome << ": ";
            cin >> email;
            cout << "Digite a idade do(a) " << nome << ": ";
            cin >> idade;
            cout << endl;

            conhe->setName(nome);
            conhe->setAge(idade);
            conhe->setEmail(email);
        }
    }
}

void Agenda::imprimeAniversarios(){
    cout << "Aniversários dos amigos armazenados na agenda:\n";

    for(unsigned int i = 0; i < person.size(); i++){
        Amigo *a = dynamic_cast<Amigo*>(person[i]);
        if(a != NULL){
            cout << a->getInformation() << endl;
        }   
    }
    cout << endl;
}

void Agenda::imprimeEmail(){
    cout << "E-mail dos conhecidos armazenados na agenda:\n";

    for(unsigned int i = 0; i < person.size(); i++){
        Conhecido *c = dynamic_cast<Conhecido*>(person[i]);
        if(c != NULL){
            cout << c->getInformation() << endl;
        }   
    }
    cout << endl;
}

Agenda::~Agenda(){
    int size_vector = person.size();

    for(int i = 0; i < size_vector; i++){
        delete(person[i]);
    }
}