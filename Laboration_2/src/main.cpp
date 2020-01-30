#include "Prototypes.h"
#include "memstat.hpp"
#include "Name.h"
#include <iostream>
#include <string>

int main()
{
    // Testing Name functions
    Name name1("Honorine", "Lima");
    string myFirstName = name1.getFirstName();
    string myLastName = name1.getLastName();
    cout << endl << "My name is " << myFirstName << " " << myLastName << endl;
    cout <<endl<< "Full name: " << name1.fullName() <<endl;

    Name name2;
    name2.setFirstName("Elin");
    name2.setLastName("Bengt");
    cout << endl << "My name is " << name2.getFirstName() << " " << name2.getLastName() << endl;
    cout <<endl<< "Full name: " << name2.fullName() <<endl;
    ///
    //

    return 0;
}
