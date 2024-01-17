/**
 * @file question2.ccp
 * 
 * @brief Implementation of the question2 function.
 */

#include <iostream>

#include "CLHEP/Random/MTwistEngine.h"
#include "questionN.hpp"
#include "utils.hpp"

/**
 * Perform draws using MTwistEngine and check if the random numbers
 * sequence can be restored
 */
void question2()
{
    CLHEP::MTwistEngine *mt = new CLHEP::MTwistEngine();

    std::cout << "==== Performing draws ====" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Performing draw n°" << i << std::endl;
        saveStatusWrapper(mt, "status/mtStatusQ2-" + std::to_string(i) + ".txt");
        performDrawWithPrint(mt, 10);
    }

    std::cout << "==== Restoring status ====" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Restoring status n°" << i << std::endl;
        restoreStatusWrapper(mt, "status/mtStatusQ2-" + std::to_string(i) + ".txt");
        performDrawWithPrint(mt, 10);
    }

    delete mt;
}