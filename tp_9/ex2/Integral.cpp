//implementation file

/*regra do trapezio para calcular integral:

    Integral de a até b = I ~ (h/2)[ f(x0) +f(xn) + ∑f(xi)]
    h = (b-a)/n ; n = número de intervalos
    ∑ varia de i até n-1
    xi = x0 + (i*h)
*/
#include <iostream>
#include <cmath>
#include "Integral.h"

using namespace std;

//f(x) = ax² +bx + c
double Quadratica::getIntegral(double limInferior, double limSuperior, double intervalos){
    double xi, h, result, somatorio = 0;
    double fx0, fxn;

    h = (limSuperior - limInferior)/intervalos;

    for(int i = 1; i <= intervalos - 1; i++){
        xi = limInferior + (i*h);
        somatorio += (A * pow(xi,2) ) + (B*xi) + C;
    }

    fx0 = (A * pow(limInferior,2) ) + (B*limInferior) + C;
    fxn = (A * pow(limSuperior,2) ) + (B*limSuperior) + C;
    h = h/2;
    result = h * (fx0 + fxn + (2*somatorio) );
    
    return result;
}

double Senoide::getIntegral(double limInferior, double limSuperior, double intervalos){
    double xi, h, result, somatorio = 0;
    double fx0, fxn;

    h = (limSuperior - limInferior)/intervalos;

    for(int i = 1; i <= intervalos - 1; i++){
        xi = limInferior + (i*h);
        somatorio += sin(xi)/xi;
    }

    fx0 = sin(limInferior)/limInferior;
    fxn = sin(limSuperior)/limSuperior;
    h = h/2;
    result = h * (fx0 + fxn + (2*somatorio) );

    return result;
}


double Linear::getIntegral(double limInferior, double limSuperior, double intervalos){
    double xi, h, result, somatorio = 0;
    double fx0, fxn;

    h = (limSuperior - limInferior)/intervalos;

    for(int i = 1; i <= intervalos - 1; i++){
        xi = limInferior + (i*h);
        somatorio += (a*xi) + b;
    }

    fx0 = (a*limInferior) + (b*limInferior);
    fxn = (a*limSuperior) + b;
    h = h/2;
    result = h * (fx0 + fxn + (2*somatorio) );
    
    return result;
}
