//Parte 02
//tempo.cpp

#include "tempo.h"

using namespace std;
//construtores
Tempo::Tempo(){
    this->day = 0;
    this->hour = 0;
    this->min = 0;
    this->sec = 0;
}

Tempo::Tempo(int dia){
    this->day = dia;
    this->hour = 0;
    this->min = 0;
    this->sec = 0;
}

Tempo::Tempo(int dia, int hora){
    this->day = dia;
    this->hour = hora;
    this->min = 0;
    this->sec = 0;
}

Tempo::Tempo(int dia, int hora, int min){
    this->day = dia;
    this->hour = hora;
    this->min = min;
    this->sec = 0;
}

Tempo::Tempo(int dia, int hora, int min, int seg){
    this->day = dia;
    this->hour = hora;
    this->min = min;
    this->sec = seg;
}

//setters
void Tempo::setDia(int dia){
    this->day = dia;
}

void Tempo::setHora(int hora){
    this->hour = hora;
}

void Tempo::setMin(int min){
    this->min = min;
}

void Tempo::setSeg(int seg){
    this->sec = seg;
}

//getters
int Tempo::getDia(){
    return this->day;
}

int Tempo::getHora(){
    return this->hour;
}

int Tempo::getMin(){
    return this->min;;
}

int Tempo::getSeg(){
    return this->sec;
}

//other functions
void Tempo::checaConsistencia(){
    int ajuste = 0;

    if(this->sec >= 60){
        ajuste = (this->sec)/60;
        setMin(this->min + ajuste);
        ajuste = (this->sec)%60;
        setSeg(ajuste);
    }

    if(this->min >= 60){
        ajuste = this->min/60;
        setHora(this->hour + ajuste);
        ajuste = (this->min)%60;
        setMin(ajuste);
    } 

    if(this->hour >= 24){
        ajuste = this->hour/24;
        setDia(this->day + ajuste);
        ajuste = (this->hour) % 24;
        setHora(ajuste);
    }
}

Tempo Tempo::somaTempo(Tempo time){
    Tempo t(0, 0, 0, 0);

    t.day = this->day + time.day;
    t.hour = this->hour + time.hour;
    t.min = this->min + time.min;
    t.sec = this->sec + time.sec;

    t.checaConsistencia();

    return t;
}

void Tempo::read(){
    cout << "Dia(s): ";
    cin  >> this->day;
    cout << "Hora(s): ";
    cin >> this->hour;
    cout << "Minuto(s): ";
    cin >> this->min;
    cout << "Segundo(s): ";
    cin >> this->sec;

}

void Tempo::show(){
    cout << this->day << "d " << this->hour << "h " << this->min << "m " << this->sec << "s\n\n"; 
}

void Tempo::incrementaSegundo(){
    this->sec = this->sec + 1;
}

void Tempo::decrementaSegundo(){
    this->sec = this->sec - 1;
}