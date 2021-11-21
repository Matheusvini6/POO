//Parte 02
//tempo.h (header file)

#include <iostream>

#ifndef TEMPO_H
#define TEMPO_H

class Tempo{
    private:

        int day;
        int hour;
        int min;
        int sec;
    
    public:
        //construtores
        Tempo();
        Tempo(int dia);
        Tempo(int dia, int hora);
        Tempo(int dia, int hora, int min);
        Tempo(int dia, int hora, int min, int seg);

        //setters
        void setDia(int dia);
        void setHora(int hora);
        void setMin(int min);
        void setSeg(int seg);

        //getter
        int getDia();
        int getHora();
        int getMin();
        int getSeg();

        //other functions
        void checaConsistencia();
        Tempo somaTempo(Tempo t);
        void read();
        void show();
        void incrementaSegundo();
        void decrementaSegundo();

};

#endif