#include <stdio.h>

#include "object_graphique.h"
#include "cercle.h"
#include "rectangle.h"
#include "init_main.h"

// gcc -o exec *.c -g -Wall -Wextra

/* Recuperation des instances des métaclass présente dans init_main.c*/

extern struct MetaObjetGraphique LeMetaObjetGraphique;
extern struct MetaCercle LeMetaCercle;
extern struct MetaRectangle LeMetaRectangle;

int main(){

    // Init les métaclass
    init_main();

    struct ObjetGraphique *og1 = LeMetaObjetGraphique.ConstructeurDefautObjetGraphique();
    printf("\n");
    struct Cercle *c1 = LeMetaCercle.ConstructeurDefaultCercle();
    printf("\n");
    struct Rectangle *r1 = LeMetaRectangle.ConstructeurDefaultRectangle();
    printf("\n");
    struct Rectangle *r2 = LeMetaRectangle.ConstructeurRectangle1(100, 200);
    printf("\n");

    printf("X : %d\n", og1->myClass->getX(og1));
    printf("Y : %d\n", og1->myClass->getY(og1));
    printf("Centre X : %d\n", og1->myClass->getCentreX(og1));
    printf("Centre Y : %d\n", og1->myClass->getCentreY(og1));

    printf("\n");

    c1->myClass->setRayon(5, c1);
    printf("Rayon du cercle : %d\n", c1->myClass->getRayon(c1));
    printf("X : %d\n", c1->myClass->superMetaClass->getX(&(c1->superClass)));
    printf("Y : %d\n", c1->myClass->superMetaClass->getY(&(c1->superClass)));
    printf("Centre X : %d\n", c1->myClass->superMetaClass->getCentreX(&(c1->superClass)));
    printf("Centre Y : %d\n", c1->myClass->superMetaClass->getCentreY(&(c1->superClass)));
    c1->myClass->superMetaClass->afficher(&(c1->superClass));
    c1->myClass->superMetaClass->effacer(&(c1->superClass));
    c1->myClass->superMetaClass->deplacer(&(c1->superClass));
    printf("\n");

    r1->myClass->setLargeur(10, r1);
    r1->myClass->setHauteur(20, r1);
    printf("Largeur du rectangle : %d\n", r1->myClass->getLargeur(r1));
    printf("Hauteur du rectangle : %d\n", r1->myClass->getHauteur(r1));
    printf("X : %d\n", r1->myClass->superMetaClass->getX(&(r1->superClass)));
    printf("Y : %d\n", r1->myClass->superMetaClass->getY(&(r1->superClass)));
    printf("Centre X : %d\n", r1->myClass->superMetaClass->getCentreX(&(r1->superClass)));
    printf("Centre Y : %d\n", r1->myClass->superMetaClass->getCentreY(&(r1->superClass)));
    r1->myClass->superMetaClass->afficher(&(r1->superClass));
    r1->myClass->superMetaClass->effacer(&(r1->superClass));
    r1->myClass->superMetaClass->deplacer(&(r1->superClass));
    printf("\n");

    printf("Largeur du rectangle : %d\n", r2->myClass->getLargeur(r2));
    printf("Hauteur du rectangle : %d\n", r2->myClass->getHauteur(r2));
    printf("\n");
    
    printf("NbObjetGraphique : %d\n", LeMetaObjetGraphique.GetNbObjetGraphique());
    printf("\n");

    og1->myClass->liberer(og1);
    c1->superClass.myClass->liberer(&(c1->superClass));
    r1->superClass.myClass->liberer(&(r1->superClass));
    r2->superClass.myClass->liberer(&(r2->superClass));

    return 0;
}