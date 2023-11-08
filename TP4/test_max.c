#include <stdio.h>

#define DEFINIR_MAX(TYPE) \
    TYPE max##TYPE(TYPE a, TYPE b) { return a >= b ? a : b; }

DEFINIR_MAX(int)
DEFINIR_MAX(float)

int main(int argc, char *argv[])
{
    printf("%d\n", maxint(1, 2));
    printf("%f\n", maxfloat(1, 2));
    return 0;
}