// matrix.cpp
#include "matrix.h"
#include <fstream>
#include <iostream>

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

// obtem o numero de linhas
int Matrix::getRows() const {
    //READY
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    //READY
    return  nCols;
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
