//PARTE 1.1
#include <iostream> 

using namespace std;

template <class T> T fibonacci(T position){ //sequencia: 0,1,1,2,3,5,8...
    if(position == 1){
        return 0;
    }
    else if(position == 2){
        return 1;
    }else{
        return fibonacci(position-1) + fibonacci(position-2);
    }
}

int main(){

    int position = 0, value = 0;
    cout << "Digite a posição do n-ésimo termo da série de Fibonacci: ";
    cin >> position;
    value = fibonacci(position);
    cout << value << endl;
    return 0;
}
