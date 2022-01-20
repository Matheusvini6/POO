//implementaiton file

#include <iostream>
#include "traveler.h"

using namespace std;

Traveler &Traveler::operator= (const Traveler &rhs){
    name = rhs.name;
    return *this;
}

Pager &Pager::operator= (const Pager &rhs){
    Pname = rhs.Pname;
    return *this;
}

BusinessTraveler &BusinessTraveler::operator= (const BusinessTraveler &rhs ){
    p = rhs.p;
    return *this;
}