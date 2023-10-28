#ifndef _CERCLE
#define _CERCLE

#include "object_graphique.h"

/* Implémentation des Classes dans cercle.c*/

struct MetaCercle;
struct Cercle;

/* Implémentation des méthodes dans cercle.c*/

int getRayon(struct Cercle *this);
void setRayon(int rayon, struct Cercle *this);
struct Cercle *ConstructeurDefaultCercle();

/* Implémentaion des méthodes surchargés dans cercle.c */

void afficherCercle(struct ObjetGraphique *this);
void effacerCercle(struct ObjetGraphique *this);
void deplacerCercle(struct ObjetGraphique *this);
void libererCercle(struct ObjetGraphique *this);


/* Définition des classes */

struct MetaCercle
{
   /* méthodes d’instances */
    int (*getRayon)(struct Cercle *this);
    void (*setRayon)(int rayon, struct Cercle *this);

   /* constructeur  de la classe */
    struct Cercle *(*ConstructeurDefaultCercle)();

    /* Meta super class */
    struct MetaObjetGraphique *superMetaClass;
};

struct Cercle
{
    /* Instance de la classe mère */
    struct ObjetGraphique superClass;

    /* Attributs de la classe */
    int rayon;

    /* Pointeur vers la MétaClass */
    struct MetaCercle *myClass;
};

#endif