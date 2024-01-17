/**
 * @file question4.ccp
 * 
 * @brief Implementation of the question4 function.
 */

#include <chrono>
#include <iostream>

#include "CLHEP/Random/MTwistEngine.h"
#include "questionN.hpp"
#include "utils.hpp"

/**
 * Function to calculate 10 approximations of Pi using the Monte Carlo method with 1 billion draws
 */
void question4()
{
    CLHEP::MTwistEngine *mt = new CLHEP::MTwistEngine();
    double pseudo_pi;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        restoreStatusWrapper(mt, "status/mtStatusQ3-" + std::to_string(i) + ".txt");
        pseudo_pi = simulPi(mt, 1'000'000'000);
        std::cout << "Pi = " << pseudo_pi << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time used : " << elapsed.count() << " seconds" << std::endl;

    delete mt;
}