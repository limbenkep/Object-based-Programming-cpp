#include "Prototypes.h"
#include "memstat.hpp"
#include "Name.h"
#include "Address.h"
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

    // Testing Address functions


    Address address1("Vasaplan6D", "333 23", "Umea");
    cout << endl <<"Address:" << address1.fullAddress() << endl;

    Address address2;
    address2.setStreetName("Mariehem");
    address2.setPostNumber("653 23");
    address2.setCityName("Stockholm");
    cout << "\nAddress: \n" << address2.getStreetName() << endl << address2.getPostNumber() << endl << address2.getCityName()<<endl;

    return 0;
}
