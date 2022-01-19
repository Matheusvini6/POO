//header file 

#include <iostream>
#include <cmath>
#ifndef BOX_H
#define BOX_H

class Ponto3D{
    private:
        double x;
        double y;
        double z;

    public:
        Ponto3D(double xx = 0, double yy = 0, double zz = 0):x(xx),y(yy),z(zz){}
        Ponto3D(const Ponto3D& p){ x = p.x; y = p.y; z = p.z;}
        /*inline void set_x(double x_){ this->x = x_;}
        inline void set_y(double y_){ this->y = y_;}
        inline void set_z(double z_){ this->z = z_;}*/
        inline double get_x(){return x;}
        inline double get_y(){return y;}
        inline double get_z(){return z;}
};

class Box: public Ponto3D{
    private:
        double largura;
        double altura;
        double profundidade;
        Ponto3D p1, p2, p3, p4;
    
    public:
        Box(Ponto3D pp1, Ponto3D pp2, Ponto3D pp3, Ponto3D pp4):p1(pp1), p2(pp2), p3(pp3), p4(pp4){
            this->largura = abs(p1.get_x() - p2.get_y() );//referencia: p1=ponto inferior à esquerda da face maior
            this->altura = abs(p2.get_y() - p3.get_y() );       //p2=ponto inferior à direita da face maior
            this->profundidade = abs(p2.get_z() - p4.get_z() ); //p3=ponto superior exatamente  acima de p2  
        }                                                       //p4=ponto exatamente à frente de p2   
        inline double area(){
            double area = 2*( (largura*altura)+(largura*profundidade)+(profundidade*altura) );
            return area;
        };
        inline double volume(){double volume = largura*profundidade*altura; return volume;};

};

#endif