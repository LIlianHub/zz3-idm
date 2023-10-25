#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "mt.h"

// gcc -o generate_tab generate_tab.c mt.c -lm
// gcc -c tab.c -o tab.o

void generateTab(FILE * output, int n){
    fprintf(output, "double tabMT[] = {\n");
    for(int i = 0; i < n; i++){
        fprintf(output, "\t%lf", genrand_real2());
        if(i != n - 1) fprintf(output, ",\n");
    }
    fprintf(output, "\n\t};\n");
}

int main(){
    FILE * file = fopen("tab.c", "w");
    generateTab(file, 20000000);
    fclose(file);
    
    return 0;   
}