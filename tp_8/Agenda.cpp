#include <iostream>
#include "Agenda.h"
#include <vector>
#include <ctime>
#include <string>

using namespace std;

//
Agenda::Agenda(int numPessoas){
    srand((unsigned int) time (NULL)); //activates the generator
    int max = 3, min = 1;

    for(int i = 0; i < numPessoas; i++){
        int randomNumber = (rand()%(max - min)) + min;

        if(randomNumber == 1){
            Amigo * amg = new Amigo();
            setPerson(amg);
            addNumberAmigos();
        }else{
            Conhecido * conhe= new Conhecido();
            setPerson(conhe);
            addNumberConhecidos();
        }
    }
}

void Agenda::addInformacoes(){
    for(unsigned int i = 0; i < person.size(); i++){
        cout << "\nPreencha Dados da Pessoa " << i + 1 << "\n" << endl; 
        Amigo * amg = dynamic_cast<Amigo*> (person[i]);
        Conhecido * conhe = dynamic_cast<Conhecido*> (person[i]);

        if(amg != NULL){//adicionar informações do amigo
            string data="";
            string nome="";
            int idade=0;
            
            
            cout << "Nome do Amigo" << endl;
            cin >> nome;
            cout << "Digite uma data de aniversário no formato: dd/mm/aaaa do Amigo" << endl;
            cin >> data;
            cout << "Idade do Amigo" << endl;
            cin >> idade;

            
            amg->setName(nome);
            amg->setDateBirthday(data);
            
        }else{ //adiciona informações para conhecido
            string email="";
            string nome="";
            int idade=0;


            
            cout << "nome do Amigo" << endl;
            cin >> nome;
            cout << "Digite um e-mail: " << endl;
            cin >> email;
            cout << "Idade do Amigo" << endl;
            cin >> idade;
            

            conhe->setName(nome);
            conhe->setAge(idade);
            conhe->setEmail(email);
        }
    }
}

void Agenda::imprimeAniversarios(){
    cout << "\nAniversarios de Amigos :\n" << endl; 
    for(unsigned int i = 0; i < person.size(); i++){
        Amigo *a = dynamic_cast<Amigo*>(person[i]);
        if(a!=NULL){
            cout << a->getInformation() <<"\n"<< endl;
        }   
    }
}

Agenda::~Agenda(){
    int size_vector = person.size();
    for(int i=0; i<size_vector; i++){
        delete(person[i]);
    }
}
