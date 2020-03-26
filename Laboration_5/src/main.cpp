/*
 * This program handles information on persons on a housing queue. The program allows the user to ;
 * Add a person to queue, Offer a person housing, Print housing queue list, Print data on a person in the queue,
 * Remove a person from the queue and  Save queue to file by choosing options from a menu.
 */

#include "Prototypes.h"
#include "memstat.hpp"
#include <HousingQ.h>

int main()
{

    HousingQ housing;
    housing.run();


    return 0;
}
