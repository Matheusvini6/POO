//header file

#include <iostream>

#ifndef TRAVELER_H
#define TRAVELERT_H

using namespace std;

class Traveler{
    private:
        string name;

    public:
        Traveler(string s):name(s){}
        Traveler(const Traveler &t){name = t.name;}
        Traveler &operator= (const Traveler &rhs);
        string getName(){return name;}

};      

class Pager{
    private: 
        string Pname;

    public:
        Pager(string s): Pname(s){}
        Pager(const Pager &rhs){Pname = rhs.Pname;}
        Pager &operator= (const Pager &rhs);
        string getPname(){return Pname;}
};


class BusinessTraveler: public Traveler{
    private:
        Pager p;

    public:
        BusinessTraveler(string s = "1"):Traveler(s), p(s) {}//funciona como os dois primeiros construtores pedidos
        //BusinessTraveler(string s):Traveler(s), p(s) {}
        BusinessTraveler(const BusinessTraveler &rhs) :Traveler(rhs) , p(rhs.p){};
        BusinessTraveler &operator= (const BusinessTraveler &rhs);
        string getPager(){return p.getPname(); };
};

#endif