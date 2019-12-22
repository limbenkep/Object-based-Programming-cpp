#include "Prototypes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

int main() {
    laborationPrototype();

    auto timeStart = std::chrono::high_resolution_clock::now();
    std::cout << "Tryck ENTER!!" << std::endl;
    std::string s;
    while(!getline(std::cin, s)) {}        // Vänta på att användaren trycker på ENTER
    auto timeEnd = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(6);

    // beräkna skillnaden mellan slut- och starttiden
    size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
    double seconds = 1.0 * duration / 1000;

    std::cout << "Tid = "
         << seconds
         << " [s]" <<  std::endl;
    return 0;
}
