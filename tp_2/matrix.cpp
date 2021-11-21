//Parte 01
// matrix.cpp

#include "matrix.h"

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    //... 
    nRows = 0;
    nCols = 0;
}
    
// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem){
    //...READY
    this->nRows = rows;
    this->nCols = cols;
    m = new double *[nRows];
    
    for(int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
    }
    
    for(int i = 0; i < nRows; i++){//atribui a todos os elementos da matriz o valor "elem"
        for(int j = 0; j < nCols; j++){
            m[i][j] = elem;
        }
    }

}

// destrutor
Matrix::~Matrix() {
    //...READY
    for(int i = 0; i < nRows; i++){
        delete [] m[i];
    }

    delete [] m;
}


// obtem o numero de linhas
int Matrix::getRows() const {
    //...READY
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    //...READY  
    return nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose(){
    //...READY
    Matrix M(nCols, nRows, **m);

    return M;
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

Matrix Matrix::multiplica_por_cte(double constante){
    Matrix mtz(nRows, nCols, this->m[0][0]);

    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            m[i][j] = (this->m[i][j]) * (constante);
        }
    }

    return mtz;
}