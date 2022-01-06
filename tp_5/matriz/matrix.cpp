// matrix.cpp

#include "matrix.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    //READY
    this->nRows = 0;
    this->nCols = 0;
    m = new double *[nRows];
    m[0] = new double[nCols];

}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols, const double &value){
    // READY
    this->nRows = rows;
    this->nCols = cols;
    m = new double *[nRows];
    
    for(int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
    }
    
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            m[i][j] = value;
        }
    }
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
Matrix::Matrix(ifstream &myFile){
    int cont = 0, linha = 0, coluna = 0, espacoEntreLinha = 0, quebraLinha = 0;
    myFile >> linha;
    myFile >> coluna;
    this->nRows = linha;
    this->nCols = coluna;
    
    m = new double *[linha];

    for(int i = 0; i < linha; i++){
        m[i] = new double[coluna];
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            myFile >> this->m[i][j];
        }
    }
}

// contrutor de copia
Matrix::Matrix(const Matrix& that){
    //READY
    nRows = that.nRows;
    nCols = that.nCols;
    m = new double *[nRows];

    for(int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
    }

    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            m[i][j] = that.m[i][j];
        }
    }

}

// destrutor
Matrix::~Matrix() {
    //READY
    for(int i = 0; i < nRows; i++){
        delete [] m[i];
    }
    delete [] m;
}

// obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
double Matrix::get(int row, int col) const {
    //READY
    int linha = row - 1;
    int coluna = col - 1;

    if( (linha <= this->nRows && linha >=0) && (coluna <= this->nCols && coluna >= 0) ){
        return m[linha][coluna];
    }else{
        cout << "Acesso a posição inválida do vetor. PROGRAMA ABORTADO!";
        exit(1);
    }

}
  

// imprime o conteudo da matriz
void Matrix::print() const {
    //...READY
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit(){
    //READY
    if(this->nCols == this->nCols){
        for(int i = 0; i < this->nRows; i++){
            for(int j = 0; j < this->nCols; j++){
                if(i == j){
                    m[i][j] = 1;
                }else{
                    m[i][j] = 0;
                }
            }
        }
    }else{
        cout << "A matriz não é quadrada, portanto não pode haver matriz identidade!";
    }
}

// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros(){
    //READY
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
                m[i][j] = 0;
    
        }
    }
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
void Matrix::ones(){
    //READY
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
                m[i][j] = 1;
    
        }
    }
}

Matrix Matrix::operator+ (const Matrix &matriz) const{
    if(nRows == matriz.nRows && nCols == matriz.nCols){
        Matrix aux(nRows, nCols);

        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                aux.m[i][j] = m[i][j] + matriz.m[i][j];
            }
        }
        return aux;
    }else{
        cout << "As matrizes não possuem o mesmo tamanho, portanto, não é possível realizar a soma entre elas." << endl;
    }
    Matrix a;
    return a;
}

Matrix Matrix::operator- (const Matrix &matriz) const{
    if(nRows == matriz.nRows && nCols == matriz.nCols){
        Matrix aux(nRows, nCols);

        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                aux.m[i][j] = m[i][j] - matriz.m[i][j];
            }
        }
        return aux;
    }else{
        cout << "As matrizes não possuem o mesmo tamanho, portanto, não é possível realizar a subtração entre elas." << endl;
    }
    Matrix a;
    return a;
}

Matrix Matrix::operator* (const Matrix &rhs) const{
    int soma = 0, multiplica = 0, cont  = 0;
    int *vec = new int[99999999]; 

    if(nCols == rhs.nRows ){//nª de colunas de lhs é igual a nª de linhas de rhs? 
        Matrix aux(nRows, rhs.nCols);                      
        for(int i = 0; i < nRows; i++){//qtd linhas lhs
            for(int j = 0; j < rhs.nCols; j++){// qtd colunas rhs
                for(int k = 0; k < rhs.nRows; k++){//qtd colunas lhs 
                    multiplica = m[i][k] * rhs.m[k][j];
                    soma += multiplica;
                }
                vec[cont] = soma;
                cont++;
                soma = 0;
            }
        }
        cont = 0;
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < rhs.nCols; j++){
                aux.m[i][j] = vec[cont];
                cont++;
            }
        }
        delete [] vec;
        return aux;
    }else{
        cout << "As matrizes não podem ser multiplicadas, o nª de colunas da matriz à esquerda não é igual ao nª de linhas da matriz à direita." << endl;
    }
    //se chegar aqui as matrizes nao poderam ser multiplicadas
    delete [] vec;
    Matrix a;
    return a;
}

Matrix &Matrix::operator+= (const Matrix &rhs){
    if(nRows == rhs.nRows && nCols == rhs.nCols){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                m[i][j] += rhs.m[i][j];
            }
        }
    }else{
        cout << "As matrizes não possuem o mesmo tamanho, portanto, não é possível realizar a soma solicitada." << endl;
        cout << "Retornada matriz mais à esquerda." << endl;
    }
    return *this;
}

Matrix &Matrix::operator-= (const Matrix &rhs){
    if(nRows == rhs.nRows && nCols == rhs.nCols){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                m[i][j] -= rhs.m[i][j];
            }
        }
    }else{
        cout << "As matrizes não possuem o mesmo tamanho, portanto, não é possível realizar a subtração solicitada." << endl;
        cout << "Retornada matriz mais à esquerda." << endl;
    }
    return *this;
}

Matrix &Matrix::operator*= (const Matrix &rhs){
    int soma = 0, multiplica = 0, cont  = 0;
    int *vec = new int[99999999]; 

    if(nCols == rhs.nRows ){//nª de colunas de lhs é igual a nª de linhas de rhs? 
        Matrix aux(nRows, rhs.nCols);                      
        for(int i = 0; i < nRows; i++){//qtd linhas lhs
            for(int j = 0; j < rhs.nCols; j++){// qtd colunas rhs
                for(int k = 0; k < rhs.nRows; k++){//qtd colunas lhs 
                    multiplica = m[i][k] * rhs.m[k][j];
                    soma += multiplica;
                }
                vec[cont] = soma;
                cont++;
                soma = 0;
            }
        }
        cont = 0;
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < rhs.nCols; j++){
                m[i][j] = vec[cont];
                cont++;
            }
        }
    }else{
        cout << "As matrizes não podem ser multiplicadas, o nª de colunas da matriz à esquerda não é igual ao nª de linhas da matriz à direita." << endl;
        cout << "Retornando matriz à esquerda." << endl;
    }
    delete [] vec;
    return *this;
}

Matrix &Matrix::operator*= (const int &rhs){
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            m[i][j] *= rhs;
        }
    }
    return *this;
}

bool operator== (const Matrix &rhs, const Matrix &lhs){
    bool result = true;

    if(rhs.nRows != lhs.nRows || rhs.nCols != lhs.nCols){
        result = false;
        return result;
    }else{
        for(int i = 0; i < rhs.nRows; i++){
            for(int j = 0; j < rhs.nCols; j++){
                if(rhs.m[i][j] != lhs.m[i][j]){
                    result = false;
                    return result;
                }
            }
        }
    }
    return result;
}

bool operator!= (const Matrix &rhs, const Matrix &lhs){
    bool result = true;

    if(rhs.nRows != lhs.nRows || rhs.nCols != lhs.nCols){
        return result;
    }else{
        for(int i = 0; i < rhs.nRows; i++){
            for(int j = 0; j < rhs.nCols; j++){
                if(rhs.m[i][j] != lhs.m[i][j]){
                    return result;
                }
            }
        }
    }
    result = false;
    return result;
}

ostream& operator<< (ostream &out, const Matrix &rhs){
    for(int i = 0; i < rhs.getRows(); i++){
        for(int j = 0; j < rhs.getCols(); j++){
            out << rhs.get(i+1, j+1) << " ";
        }
        out << std::endl;
    }

    return out;
} 

istream &operator >> (istream &input, Matrix &rhs){
    cout << "Digite os valores da matriz separados por um espaço/enter: " << endl;

    for(int i = 0; i < rhs.getRows(); i++){
        for(int j = 0; j < rhs.getCols(); j++){
            input >> rhs.m[i][j];
        }
    }
    return input;

}

Matrix operator~(const Matrix &rhs){
    int *vec = new int[99999999];
    int cont = 0;
    
    for(int i = 0; i < rhs.nRows; i++){
        for(int j = 0; j < rhs.nCols; j++){
            vec[cont] = rhs.m[j][i];
            cont++;
        }
    }
    cont = 0;
    int tamanhoMatriz = rhs.nCols *rhs.nRows;
    for(int i = 0; i < rhs.nCols; i++){
        for(int j = 0; j < rhs.nRows; j++){
            rhs.m[i][j] = vec[cont];
            cont++;
        }
    }
    delete [] vec;
    return rhs;
}
