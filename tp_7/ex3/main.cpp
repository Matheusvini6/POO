//test file

#include <iostream>
#include "traveler.h"

using namespace std;

int main(){

    Traveler t("traveler");
    cout << t.getName() << endl;

    Pager p("pager");
    cout << p.getPname()  << endl;

    BusinessTraveler b, b2 = b;

    cout << b.getName() << endl;
    cout << b.getPager() << endl << endl;

    
    BusinessTraveler b3("Business");
    cout << b3.getName() << endl;
    cout << b3.getPager() << endl ;

    cout << "\nAssignment operator:" << endl;
    cout << b2.getName() << endl;
    cout << b2.getPager() << endl << endl;

    BusinessTraveler b4(b3);
    cout << "Copy constructor:" << endl;
    cout << b4.getName() << endl;
    cout << b4.getPager() << endl;

    cout << endl;
    return 0;
}