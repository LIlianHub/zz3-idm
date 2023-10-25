#include <stdio.h>

#include "object_graphique.h"
#include "cercle.h"
#include "rectangle.h"
#include "init_main.h"

/* Recuperation des instances des métaclass présente dans init_main.c*/

extern struct MetaObjetGraphique LeMetaObjetGraphique;
extern struct MetaCercle LeMetaCercle;
extern struct MetaRectangle LeMetaRectangle;

int main(){

    // Init les métaclass
    init_main();

    struct ObjetGraphique *og1 = LeMetaObjetGraphique.ConstructeurDefautObjetGraphique();
    struct Cercle *c1 = LeMetaCercle.ConstructeurDefaultCercle();
    struct Rectangle *r1 = LeMetaRectangle.ConstructeurDefaultRectangle();
    struct Rectangle *r2 = LeMetaRectangle.ConstructeurRectangle1(100, 100);

    printf("X : %d\n", og1->myClass->getX(og1));

    c1->myClass->setRayon(5, c1);
    printf("Rayon du cercle : %d\n", c1->myClass->getRayon(c1));
    printf("X : %d\n", c1->myClass->superMetaClass->getX(og1));

    r1->myClass->setLargeur(10, r1);
    r1->myClass->setHauteur(20, r1);
    printf("Largeur du rectangle : %d\n", r1->myClass->getLargeur(r1));
    printf("Hauteur du rectangle : %d\n", r1->myClass->getHauteur(r1));
    printf("X : %d\n", r1->myClass->superMetaClass->getX(og1));

    printf("Largeur du rectangle : %d\n", r2->myClass->getLargeur(r2));
    printf("Hauteur du rectangle : %d\n", r2->myClass->getHauteur(r2));
    
    printf("NbObjetGraphique : %d\n", LeMetaObjetGraphique.GetNbObjetGraphique());
    return 0;
}