/**
 * @file resultQuality.c
 * 
 * @brief This file contains functions for calculating the quality of experimental results for approximating Pi.
 * It includes functions for calculating the absolute and relative errors, mean value, estimate without bias,
 * value of r, standard deviation, and confidence interval.
 * The file also includes a function for reading the experimental results from a file and displaying the quality results.
 * 
 * compile with `gcc -Wall -Wextra -o resultQuality resultQuality.c -lm`
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the absolute error of an approximation of Pi.
 *
 * @param pseudoPi The approximation of Pi.
 * 
 * @return The absolute error of the approximation.
 */
double errorAbsolutePi(double pseudoPi)
{
    return M_PI - pseudoPi;
}

/**
 * Calculates the relative error of an approximation of Pi.
 *
 * @param pseudoPi The approximation of Pi.
 * 
 * @return The relative error of the approximation.
 */
double errorRelativePi(double pseudoPi)
{
    return pseudoPi / M_PI;
}


/**
 * Calculates the mean value from an array of results.
 *
 * @param resultExp The array of results.
 * @param nbExp The number of elements in the array.
 * 
 * @return The mean value of the array.
 */
double meanFromArray(double *resultExp, int nbExp)
{
    double meanExp = 0;

    for (int i = 0; i < nbExp; i++)
    {
        meanExp += resultExp[i];
    }

    return meanExp /= nbExp;
}

/**
 * Calculates the estimate without bias for a given set of experimental results.
 *
 * @param resultExp The array of experimental results.
 * @param mean The mean value of the experimental results.
 * @param nbExp The number of experimental results.
 * 
 * @return The estimate without bias.
 */
double estimateWithoutBiasCalculation(double *resultExp, double mean, int nbExp)
{
    double estimateWB = 0;

    for (int i = 0; i < nbExp; i++)
    {
        estimateWB += (resultExp[i] - mean) * (resultExp[i] - mean);
    }

    estimateWB /= (nbExp - 1);

    return estimateWB;
}


/**
 * Calculates the value of r using the given estimate of within-between variance ratio (estimateWB)
 * and the number of experiments (nbExp).
 *
 * @param estimateWB The estimate of within-between variance ratio.
 * @param nbExp The number of experiments.
 * 
 * @return The calculated value of r.
 */
double rCalculation(double estimateWB, int nbExp)
{
    double t05[30] = {12.706, 4.303, 3.182, 2.776, 2.571, 5.447, 2.365, 2.308, 2.262, 2.228,
                      2.201, 2.179, 2.160, 2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086, 2.080, 2.074,
                      2.069, 2.064, 2.060, 2.056, 2.052, 2.048, 2.045, 2.042};

    return t05[nbExp - 1] * sqrt(estimateWB / nbExp);
}


/**
 *  Calculate the standard deviation.
 *
 * @param resultExp The array of results.
 * @param mean The mean of the results.
 * @param nbExp The number of experiments.
 * 
 * @return The standard deviation of the results.
 */
double standardDeviationCalculation(double *resultExp, double mean, int nbExp)
{
    double sum = 0.0;
    for (int i = 0; i < nbExp; i++)
    {
        sum += (resultExp[i] - mean) * (resultExp[i] - mean);
    }

    double variance = sum / nbExp;
    return sqrt(variance);
}


/**
 *  Show the quality of the results including Mean, Relative error, Absolute error,
 *  Standard deviation and Confidence Interval.
 *
 * @param resultExp The array of results.
 * @param nbExp The number of experiments.
 */
void showQualityResult(double *resultExp, int nbExp)
{
    if (nbExp > 30 || nbExp < 1)
    {
        fprintf(stderr, "Erreur: le nombre d'experience doit être compris entre 1 et 30, %d est une entrée invalide\n", nbExp);
        exit(1);
    }
    else
    {
        double mean = meanFromArray(resultExp, nbExp);
        printf("Moyenne: %lf\n", mean);

        double errorRelative = errorRelativePi(mean);
        printf("Erreur relative: %lf\n", errorRelative);

        double errorAbsolute = errorAbsolutePi(mean);
        printf("Erreur absolue: %lf\n", errorAbsolute);

        double standardDeviation = standardDeviationCalculation(resultExp, mean, nbExp);
        printf("Ecart type: %lf\n", standardDeviation);

        double estimateWB = estimateWithoutBiasCalculation(resultExp, mean, nbExp);
        double r =rCalculation(estimateWB, nbExp);

        printf("Intervalle de confiance à 95%% : [%lf - %lf]\n", mean - r, mean + r);
    }
}


/**
 *  Get the results of the experiments from a file.
 *
 * @param fileName The name of the file to read the results from.
 * @param nbExp A pointer to the number of experiments.
 * 
 * @return A pointer to the array of results.
 */
double *getResultExpFromFile(char *fileName, int *nbExp)
{
    FILE * file;
    if ((file = fopen(fileName, "r")) != NULL)
    {
        fscanf(file, "%d\n", nbExp);

        double *resultExp = (double *)malloc((*nbExp) * sizeof(double));

        for (int i = 0; i < (*nbExp); i++)
        {
            fscanf(file, "%lf\n", &resultExp[i]);
        }

        fclose(file);

        return resultExp;
    }
    fprintf(stderr, "File %s does not exist\n", fileName);
    exit(1);
}


int main()
{
    int nbExp;
    double *resultExp = getResultExpFromFile("result.txt", &nbExp);

    showQualityResult(resultExp, nbExp);

    free(resultExp);

    return 0;
}
