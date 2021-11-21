#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> *vec = new vector<int>[1000000];
    vector<int> *vecAux = new vector<int>[1000000];
    int i = 0, num = 0, qtdNumRepetido = 1;
    cout << "Digite quantos números inteiros desejar, separados por um espaço.\n"
            "Digite um número negativo para parar\n";
    while(cin >> num){
        if (num < 0){
            break;
        }
        vec->push_back(num);
        i++;
    }
    // = vec->at(0)
    int tamanho = vec->size();
    for(i = 0; i < tamanho - 1; i++){//checa quantos números repetidos há
        num = vec->at(i);
        if(num == vec->at(i+1) && i == vec->size() - 2){//pega os dois últimos números, se iguais
            qtdNumRepetido += 1;
            vecAux->push_back(qtdNumRepetido);
            vecAux->push_back(num);
        }
        else if(num == vec->at(i+1)){
            qtdNumRepetido += 1;
        }
        else{//primeiro adiciona a quantidade de números repetidos em vecAux, depois o número
            vecAux->push_back(qtdNumRepetido);
            vecAux->push_back(num);
            qtdNumRepetido = 1;
        }
    }
    cout << "\n";
    for(i = 0; i < vecAux->size(); i++){
        cout << vecAux->at(i) << " ";
    }
    cout << endl;

    /*vec.erase(vec.begin() + 2);
    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++ ){
        cout << vec[i] << " ";
    }
    cout << endl*/

    delete [] vec;
    delete [] vecAux;
    return 0;
}