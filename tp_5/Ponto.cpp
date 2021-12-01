// implementation 

#include <iostream>
#include "Ponto.hpp"

Ponto2D Ponto2D::operator+ (const Ponto2D &p) const{
    Ponto2D aux;
    aux.x = x + p.x;
    aux.y = y + p.y;
    return aux;
}

Ponto2D &Ponto2D::operator-- (){
    x = x-1;
    y -= 1;

    return *this;
}