//header file

#include <iostream>
#include <cmath>

#ifndef INTEGRAL_H
#define INTEGRAL_H

class Funcao{
    public:
    Funcao(){};
    //funcao que obtem a integral da funcao pela regra do trapezio
    virtual double getIntegral(double limiteInferior, double limiteSuperior, double intervalos) = 0;

    // funcao virtual representando a funcao cuja integral deve ser calculada
    //virtual double func(double input) = 0;

    // destrutor
    virtual ~Funcao(){};
};

class Quadratica: public Funcao{
    private:
        double A, B, C;

    public:
        Quadratica(double a_, double b_, double c_):A(a_), B(b_), C(c_){};
        double getIntegral(double limInferior, double limSuperior, double intervalos);
        virtual ~Quadratica(){};
};

class Senoide: public Funcao{
    public:
        Senoide(){};
        double getIntegral(double limInferior, double limSuperior, double intervalo);
        virtual ~Senoide(){};
};

class Linear: public Funcao{
    private:
        double a, b;

    public:
        Linear(double a_, double b_): a(a_), b(b_){};
        virtual ~Linear(){};
        double getIntegral(double limInferior, double limSuperior, double intervalo);
};

#endif