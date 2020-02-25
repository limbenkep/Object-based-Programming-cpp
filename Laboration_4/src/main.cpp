#include "Prototypes.h"
#include "memstat.hpp"



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

    Program().run();
    return 0;
}
