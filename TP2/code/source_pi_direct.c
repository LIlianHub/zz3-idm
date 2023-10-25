#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "mt.h"

// gcc -o exec_direct source_pi_direct.c mt.c -lm

double simPi(int nbPoint)
{
    double x, y;
    double inCircle = 0;

    for (int i = 0; i < nbPoint; i++)
    {
        x = genrand_real2();
        y = genrand_real2();

        //Si dans le cercle
        if (x * x + y * y < 1)
            inCircle++;
    }
    return inCircle / nbPoint * 4;
}

double meanPi(int nbIter, int nbPoint)
{
    double sum = 0;

    for (int i = 0; i < nbIter; i++)
        sum += simPi(nbPoint);

    return sum / nbIter;
}


double errorAbsolutePi(double pseudoPi)
{
    return M_PI - pseudoPi;
}

double errorRelativePi(double pseudoPi)
{
    return pseudoPi / M_PI;
}

int main(){

    double pseudo_pi;

    clock_t begin = clock();
 
    pseudo_pi = meanPi(10, 1000000);
 
    clock_t end = clock();
 
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Pseudo PI: %lf\n", pseudo_pi);
    printf("The elapsed time is %lf seconds\n", time_spent);
    printf("The relative error is: %lf\n", errorRelativePi(pseudo_pi));
    printf("The absolute error is: %lf\n", errorAbsolutePi(pseudo_pi));
    
}

 