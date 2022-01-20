//imlementation file

#include <iostream>
#include "Ponto3D.h"

using namespace std;

ostream& operator<< (ostream &op, const Ponto2D &p){
            op << endl;
            op << "x = " << p.x << endl;
            op << "y = " << p.y << endl;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}

ostream &operator<< (ostream &output, const Ponto3D &p3){
    output << endl;
    double x_ = p3.get_x(), y_ = p3.get_y();
    output << "x = " << x_ << endl;
    output << "y = " << y_ << endl;
    output << "z = " << p3.z << endl;
    return output;
}

Ponto3D &Ponto3D::operator= (const Ponto2D &p2){
    /*double x_= 0, y_ = 0;
    x_ = p2.get_x();
    y_ = p2.get_y();
    z = z;
    set(x_, y_);*/
    set(p2.get_x(), p2.get_y(), z );

    return *this;
}