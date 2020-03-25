#include "Prototypes.h"
#include "memstat.hpp"
#include <QList.h>

int main()
{
    QList numbers;
    cout << "Quese size = " << numbers.getSize() << endl;
    numbers.enque(Person());
    for (int i=1; i<20; i++)
    {
        numbers.enque(Person());
    }
    cout <<"Size " <<numbers.getSize() << endl;
    Person temp{};
    while(!numbers.isEmpty()){
        numbers.deque(temp);
        cout << "Number from queue= " << temp << ", queue size = " << numbers.getSize() <<  endl;
    }
    for (int i=0; i<numbers.getSize(); i++)
    {
        std::cout << "I am here in for-loop" << endl;
        if(numbers.deque(temp)){
            cout <<  temp << endl;
        }
    }

    return 0;
}
