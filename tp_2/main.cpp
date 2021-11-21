//Parte 01
// main.cpp

#include "matrix.h"

using namespace std;

int main(){
    Matrix Y(3,2, 5);
    Matrix X(4,3,6);
    double cte = 5, inverso_cte = 1/cte;
    
    std::cout << "Matriz Y: " << std::endl;
    Y.print();
    std::cout << "Número de linhas de Y: " << Y.getRows() << endl;
    std::cout << "Número de colunas de Y: " << Y.getCols() << "\n\n";
   
    Matrix A = Y;
    A.multiplica_por_cte(cte);
    cout << "A é a matriz Y multiplicada por " << cte << ":" << endl;
    A.print();
    cout << endl;

    std::cout << "Z é transposta de Y: " << std::endl;
    Matrix Z = Y.transpose();
    Z.multiplica_por_cte(inverso_cte);
    Z.print();
    std::cout << "Número de linhas de Z: " << Z.getRows() << endl;
    std::cout << "Número de colunas de Z: " << Z.getCols() << endl;
    
    std::cout << "\nMatriz X: " << std::endl;
    X.print();
    
    std::cout << "Número de linhas de X: " << X.getRows() << endl;
    std::cout << "Número de colunas de X: " << X.getCols() << endl;
    

    Matrix B = X;
    B.multiplica_por_cte(cte);
    cout << "\nB é a matriz X multiplicada por " << cte << ":" << endl;
    B.print();
    cout << endl;

    std::cout << "T é transposta de X: " << std::endl;
    Matrix T = X.transpose();
    T.multiplica_por_cte(inverso_cte);
    T.print();
    std::cout << "Número de linhas de T: " << T.getRows() << endl;
    std::cout << "Número de colunas de T: " << T.getCols() << endl;

    X.~Matrix();
    Y.~Matrix();
    
    return 0;
}