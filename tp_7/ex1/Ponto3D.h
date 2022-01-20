//header file 

#include <iostream>

#ifndef PONTO3D_H
#define PONTO3D_H

using namespace std;

class Ponto2D{
    
     public:
        Ponto2D(int xx = 0.0, int yy = 0.0):x(xx),y(yy){ };
        Ponto2D(double xx, double yy ):x(xx),y(yy){ };
        friend ostream& operator<< (ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);
        ~Ponto2D(){};
        double get_x(void) const{ return x; }
        double get_y(void) const{ return y; }
        void set(double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};

// a ser implementada
class Ponto3D: public Ponto2D{
    
    public:
        Ponto3D(double xx = 0, double yy = 0, double zz=0):Ponto2D(xx,yy),z(zz){};
        friend ostream& operator<< (ostream &op, const Ponto3D &p);
        Ponto3D& operator= (const Ponto2D &p);
        void set(double nx, double ny, double nz){Ponto2D::set(nx,ny); z = nz;}
        double get_z(){return z;};
            
    private:
        double z;
};    

#endif
