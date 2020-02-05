#include "Prototypes.h"




void addPerson(vector<Person> &people);
void printPeople(vector<Person> &people);
int main()
{
    Name name1("Honorine", "Lima");
    Name name2("Elin", "Bengt");
    Name name3("Eva", "Larsson");

    Address address1("Vasaplan6D", "333 23", "Umea");
    Address address2("Smagatan5A", "223 45", "Stockholm");
    Address address3("Storgatan5A", "245 45", "Stockholm");



    Person person1(name1, address1, "139228-5555", 6);
    Person person2(name2, address2, "139228-2222", 7);
    Person person3(name3, address3, "139228-3333", 4);


    vector<Person> people;
    people.push_back(person1);
    people.push_back(person2);
    people.push_back(person3);

    addPerson(people);
    printPeople(people);


    return 0;
}


