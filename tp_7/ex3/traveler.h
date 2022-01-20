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

};      

class Pager{
    private: 
        string Pname;

    public:
        Pager(string s): Pname(s){}
        Pager(const Pager &rhs){Pname = rhs.Pname;}
        Pager &operator= (const Pager &rhs);
};

class BusinessTraveler: public Traveler{
    private:
        Pager p;

    public:
        BusinessTraveler::BusinessTraveler(string s1 = "1", string s2 = "1"):Traveler(s1), p(s2) {}
        BusinessTraveler::BusinessTraveler(string s):Traveler(s), p(s) {}
        BusinessTraveler::BusinessTraveler(const BusinessTraveler &rhs) :Traveler(rhs) , p(rhs.p){};
        BusinessTraveler &operator= (const BusinessTraveler &rhs);
};

#endif;