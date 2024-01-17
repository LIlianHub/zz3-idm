/**
 * @file question3.ccp
 * 
 * @brief Implementation of the question3 function.
 */

#include <chrono>
#include <iostream>

#include "CLHEP/Random/MTwistEngine.h"
#include "questionN.hpp"
#include "utils.hpp"

/**
 * Perform draws using MTwistEngine.
 */
void question3()
{
    CLHEP::MTwistEngine *mt = new CLHEP::MTwistEngine();

    std::cout << "==== Performing series of 2 billions draws ====" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Performing serie n°" << i << std::endl;
        saveStatusWrapper(mt, "status/mtStatusQ3-" + std::to_string(i) + ".txt");
        performDraw(mt, 2'000'000'000);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time used : " << elapsed.count() << " seconds" << std::endl;

    delete mt;
}