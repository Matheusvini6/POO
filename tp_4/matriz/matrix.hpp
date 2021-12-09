// matrix.h (header file)

#include <iostream>
#include <fstream>

using namespace std; 

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
        Matrix(int rows, int cols, const double &value = 0.0);
        Matrix(ifstream &myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        inline int getRows() const {return nRows;};
        int getCols() const{return nCols;};
        double get(int row, int col) const;   
        
        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();
           
};
#endif