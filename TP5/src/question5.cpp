/**
 * @file question5.ccp
 * 
 * @brief Implementation of the question5 function.
 */

#include "CLHEP/Random/MTwistEngine.h"
#include "questionN.hpp"
#include "utils.hpp"

/**
 * Calculate the value of Pi using the Monte Carlo method with 1 billion draws
 *
 * @param filePath The file path to restore the random number generator state.
 */
void question5(std::string filePath)
{
    CLHEP::MTwistEngine *mt = new CLHEP::MTwistEngine();
    restoreStatusWrapper(mt, filePath);
    double generatedPi = simulPi(mt, 1'000'000'000);
    std::cout << "Pi = " << generatedPi << std::endl;
    delete mt;
}