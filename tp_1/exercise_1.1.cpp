#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char c;
    int espacoEmBranco = 0;
    ifstream arquivo; //("texto.txt"); 
    arquivo.open("texto.txt");

    if(arquivo.is_open()){
        cout << "arquivo aberto" << endl;
        while(arquivo.get(c)){
            if(c == ' '){
                espacoEmBranco += 1;
            }
        }
        arquivo.close();
    }else{
        cout << "Não foi possível abrir o arquivo." << endl;
        exit(1);
    }
    cout << "No arquivo aberto há " << espacoEmBranco << " espaços em branco." << endl;

    return 0;
}