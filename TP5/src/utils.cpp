/**
 * @file utils.cpp
 * 
 * @brief Implementation of utility functions for my project.
 */

#include <climits>

#include "utils.hpp"

/**
 * Saves the status of the MTwistEngine to a file.
 *
 * @param mt The MTwistEngine object.
 * @param filePath The path to the file where the status will be saved.
 */
void saveStatusWrapper(CLHEP::MTwistEngine *mt, std::string filePath)
{
    mt->saveStatus(filePath.c_str());
}

/**
 * Restores the status of the MTwistEngine from a file.
 *
 * @param mt The MTwistEngine object.
 * @param filePath The path to the file from where the status will be restored.
 */
void restoreStatusWrapper(CLHEP::MTwistEngine *mt, std::string filePath)
{
    mt->restoreStatus(filePath.c_str());
}

/**
 * Performs a draw using the MTwistEngine and prints the result.
 *
 * @param mt The MTwistEngine object.
 * @param n The number of draws to perform.
 */
void performDrawWithPrint(CLHEP::MTwistEngine *mt, int n)
{
    double fRn;
    unsigned int iRn;
    for (int i = 1; i <= n; i++)
    {
        fRn = mt->flat();
        iRn = (unsigned int)(fRn * UINT_MAX);
        std::cout << iRn << "\t ";
        if(i % 2 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

/**
 * Performs a draw using the MTwistEngine.
 *
 * @param mt The MTwistEngine object.
 * @param n The number of draws to perform.
 */
void performDraw(CLHEP::MTwistEngine *mt, int n)
{
    double fRn;
    unsigned int iRn;
    for (int i = 0; i < n; i++)
    {
        fRn = mt->flat();
        iRn = (unsigned int)(fRn * UINT_MAX);
    }
}

/**
 * Calculates an approximation of pi using the Monte Carlo method.
 *
 * @param mt The MTwistEngine object.
 * @param inNbPts The number of points to use for the approximation.
 * @return The calculated approximation of pi.
 */
double simulPi(CLHEP::MTwistEngine *mt, long inNbPts)
{
    long i;
    double xr = 0.,
           yr = 0.,
           pi = 0.;
    long inDisk = 0;

    for (i = 0; i < inNbPts; i++)
    {
        xr = mt->flat();
        yr = mt->flat();

        if ((xr * xr + yr * yr) <= 1)
        {
            inDisk++;
        }
    }

    pi = ((double)inDisk / (double)inNbPts) * 4.;

    return pi;
}