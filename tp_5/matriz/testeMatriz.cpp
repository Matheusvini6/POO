//Teste

#include <stdio.h>
#include "matrix.hpp"
#include <fstream>

using namespace std;

//TESTAR FUNÇÃO GET
int main(){
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

    X(2,1) = 10;

    cout << "\nMatrix X com o valor X(2,1) alterado: " << endl;
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

    Matrix m(2, 2, 4), t(2, 2, 5);
    cout << "\nMatriz M:" << endl;
    m.print();
    cout << "Matriz T:" << endl;
    t.print();
    Matrix s = m + t; 
    cout << "\nS é a matriz soma entre as matrizes M e T: \nMatriz S:\n";
    s.print();
    Matrix su = m - t; 
    cout << "SU é a matriz subtração entre as matrizes M e T: \nMatriz SU:\n";
    su.print();
    Matrix mu = m * t;
    cout << "MU é a matriz multiplicação entre as matrizes M e T: \nMatriz MU:\n";
    mu.print();
    m += t;
    cout << "Matriz M alterada para M += T: \nMatriz M:" << endl;
    m.print();
    m -= t; 
    cout << "Matriz M alterada para M -= T: \nMAtriz M:" << endl;
    m.print();
    m *= t;
    cout << "Matriz M alterada para M *= T: \nMatriz M: " << endl;
    m.print();
    int number = 2;
    t *= number; 
    cout << "Matriz T alterada para T *= " << number << ":\nMatriz T: " << endl;
    t.print();
    
    if(m == t){
        cout << "As matrizes M e T são iguais." << endl;
    }else{
        cout << "As matrizes M e T são diferentes." << endl;
    }

    if(m != t){
        cout << "As matrizes M e T são diferentes." << endl;
    }else{
        cout << "As matrizes M e T são iguais." << endl;
    }

    cout << "\nSobrecarga operador <<(output):\nMatriz T:\n";
    cout << t << endl;

    Matrix i(3, 3); //se quiser outra ordem so mudar os parametros
    cout << "Sobrecarga operador >>:(matriz 3x3)\n";
    cin >> i;
    cout << "\nMatriz I(matriz digitada):" << endl;
    cout << i;
    Matrix l = ~i;
    cout << "\nL é a matriz I transposta: \nMatriz L:" << endl;
    cout << l;
    ~i;//desfaxzendo tranposiçao da matriz I
    Matrix r = i * W;
    cout << "\nMatriz R = I * W:\nMatriz R:" << endl;
    cout << r;
    int elemento = r.get(2, 1);
    cout << "\nTestando função get(int row, int col): " << elemento << endl;
    return 0;
}