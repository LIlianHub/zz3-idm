/**
 * @file question6.ccp
 * 
 * @brief Implementation of the question6 function.
 *
 */

#include <chrono>

#include "CLHEP/Random/MTwistEngine.h"
#include "questionN.hpp"
#include "utils.hpp"

/**
 *  The thread function wrapper for the question5 function.
 *
 * @param arg The file path to restore the random number generator state.
 */
void *question5ThreadWrapper(void *arg)
{
    std::string filePath = *static_cast<std::string *>(arg);
    question5(filePath);
    return nullptr;
}

/**
 * This function launches multiple threads to calculate the value of Pi in parallel using the Monte Carlo method.
 * Each thread uses the question5 function to perform the calculations.
 * The random number generator state is restored from the specified file path.
 */
void question6()
{
    const int numThreads = 10;
    std::string filePaths[numThreads];
    pthread_t threads[numThreads];

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; ++i)
    {
        filePaths[i] = "status/mtStatusQ3-" + std::to_string(i) + ".txt";
        std::cout << "Creating thread " << i << std::endl;
        if (pthread_create(&threads[i], nullptr, question5ThreadWrapper, &filePaths[i]) != 0)
        {
            std::cerr << "Error creating thread " << i << std::endl;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < numThreads; ++i)
    {
        pthread_join(threads[i], nullptr);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time used : " << elapsed.count() << " seconds" << std::endl;
}