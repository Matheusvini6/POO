#include <stdio.h>
#include "matrix.hpp"
#include <fstream>

using namespace std;

int main()
{
    ifstream in("myMatrix.txt");

    if(in.is_open()){
        cout << "Arquivo aberto." << endl;
    }else{
        cout << "Arquivo não foi aberto. PROGRAMA ABORTADO!" << endl;
        exit(1);
    }

    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3, 2, 7.0);
    Matrix W(in);
    in.close();

    cout << "Matriz X: " << endl;
    X.print();
    
    cout << "\nMatriz Z:" << endl;
    Z.print();

    Matrix b(Z);
    cout << "\nB é a matriz cópia da matriz Z:" << endl;
    b.print();

    cout << "\nMatriz W(inicializada com os dados do arquivo): " << endl;
    W.print();
    
    Matrix a(3, 3 , 5);
    cout << "\nMatriz A: " << endl;
    a.print();
    cout << "\nMatriz A transformada em uma matriz identidade: " << endl;
    a.unit();
    a.print();

    cout << "\nMatriz A transformada em uma matriz nula: " << endl;
    a.zeros();
    a.print();

    cout << "\nMatriz A transformada em uma matriz com todos os elementos iguais a 1:" << endl;
    a.ones();
    a.print();

    return 0;
}