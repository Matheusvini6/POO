#include <iostream>
#include "Agenda.h"
#include <vector>
#include <ctime>

using namespace std;

//ENDED
Agenda::Agenda(int numPessoas){// DELETAR COUTS
    srand((unsigned int) time (NULL)); //activates the generator
    int max = 3, min = 1;

    for(int i = 0; i < numPessoas; i++){
        int randomNumber = (rand()%(max - min)) + min;
        if(randomNumber == 1){
            Amigo a;
            setPerson(a);
            //cout << "criou amigo" << endl;
        }else{
            Conhecido c;
            setPerson(c);
            //cout << "criou conhecido" << endl;
        }
    }
}

