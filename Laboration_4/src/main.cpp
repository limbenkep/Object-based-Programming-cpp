#include "Prototypes.h"
#include "memstat.hpp"
#include "IntArray.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

int main() {
    /*assignmentFunction();

    // Example usage of <chrono>
    auto timeStart = std::chrono::high_resolution_clock::now();
    std::cout << "Tryck ENTER!!" << std::endl;
    std::string s;
    while(!getline(std::cin, s)) {}        // wait for the user to press ENTER
    auto timeEnd = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(6);

    // calculate duration by subtracting start time from end time
    size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
    double seconds = 1.0 * duration / 1000;

    std::cout << "Duration = "
         << seconds
         << " [s]" <<  std::endl;*/

    IntArray intArray5000(5000);
    //intArray5000.setSize(5000);
    intArray5000.fillIntArray();
    int *myarr = new int[5000];
    myarr = intArray5000.getArr();

    for (int i = 0; i < 10; i++ )
        cout<< myarr[i]<< endl;
    delete[](myarr);
    myarr = nullptr;
    //IntArray intArray1000()
    cout << intArray5000.getSize()<<endl;





    return 0;
}
