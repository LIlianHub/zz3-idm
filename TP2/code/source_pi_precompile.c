#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

extern double tabMT[];
int CPT = 0;

// gcc -c source_pi_precompile.c -o source_pi_precompile.o -lm
// gcc source_pi_precompile.o tab.o -o exec_precompile

double simPi(int nbPoint)
{
    double x, y;
    double inCircle = 0;

    for (int i = 0; i < nbPoint; i++)
    {
        x = tabMT[CPT];
        CPT++;
        y = tabMT[CPT];
        CPT++;

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

 