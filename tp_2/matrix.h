//Parte 01
// matrix.h (header file)

#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, double elem);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        
        // other methods
        Matrix multiplica_por_cte(double cte);
        Matrix transpose();
        void print() const;
          
};

#endif 