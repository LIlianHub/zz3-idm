#include "pile.h"

#include <stdlib.h>
#include <stdio.h>

int main(){
    Pileint_t pile;
    pile.top = NULL;
    printf("Empiler 1, 2, 3, 4, 5\n");
    empilerint(1, &pile);
    empilerint(2, &pile);
    empilerint(3, &pile);
    empilerint(4, &pile);
    empilerint(5, &pile);

    printf("Est vide ? %d\n", estVideint(&pile));

    printf("Dépiler 5, 4, 3\n");
    printf("%d\n", depilerint(&pile));
    printf("%d\n", depilerint(&pile));
    printf("%d\n", depilerint(&pile));

    printf("Sommet 2\n");
    printf("%d\n", sommetint(&pile));

    printf("Dépiler 2, 1\n");
    printf("%d\n", depilerint(&pile));
    printf("%d\n", depilerint(&pile));

    printf("Est vide ? %d\n", estVideint(&pile));
    printf("Dépiler Pile Vide\n");
    printf("%d\n", depilerint(&pile));
    printf("Sommet Pile Vide\n");
    printf("%d\n", sommetint(&pile));


    return 0;
}