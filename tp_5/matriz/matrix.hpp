// matrix.h (header file)

#include <iostream>
#include <fstream>

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
        //Matrix(ifstream &myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        double get(int row, int col) const;   
        
        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();

        Matrix operator+ (const Matrix &m) const;
        Matrix operator- (const Matrix &m) const;
        Matrix operator* (const Matrix &m) const;
        Matrix& operator+= (const Matrix &rhs);
        Matrix& operator-= (const Matrix &rhs);
        Matrix& operator*= (const Matrix &rhs);
        Matrix& operator*= (const int &rhs);
};
#endif