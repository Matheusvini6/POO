//header file

#include <iostream>

#ifndef PONTO_HPP
#define PONTO_HPP

class Ponto2D{ 
        int x, y;
    
    public:
        Ponto2D(int xx=0, int yy=0): x(xx), y(yy){}
        Ponto2D& operator-- ();
        Ponto2D operator+ (const Ponto2D&) const;
        ~Ponto2D(){}; 
        int getx(){return x;}
        int gety(){return y;}

};

#endif