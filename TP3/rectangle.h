#ifndef _RECTANGLE
#define _RECTANGLE

#include "object_graphique.h"

/* Implémentation des Classes dans rectangle.c*/

struct MetaRectangle;
struct Rectangle;

/* Implémentation des méthodes dans rectangle.c*/

int getLargeur(struct Rectangle *this);
void setLargeur(int largeur, struct Rectangle *this);
int getHauteur(struct Rectangle *this);
void setHauteur(int hauteur, struct Rectangle *this);
struct Rectangle *ConstructeurDefaultRectangle();
struct Rectangle *ConstructeurRectangle1(int largeur, int hauteur);

/* Implémentaion des méthodes surchargés dans rectangle.c */

void afficherRectangle(struct ObjetGraphique *this);
void effacerRectangle(struct ObjetGraphique *this);
void deplacerRectangle(struct ObjetGraphique *this);

int getCentreXRectangle(struct ObjetGraphique *this);
int getCentreYRectangle(struct ObjetGraphique *this);

/* Définition des classes */

struct MetaRectangle
{
   /* méthodes d’instances */
    int (*getLargeur)(struct Rectangle *this);
    void (*setLargeur)(int largeur, struct Rectangle *this);
    int (*getHauteur)(struct Rectangle *this);
    void (*setHauteur)(int hauteur, struct Rectangle *this);

    /* constructeur de la classe */
    struct Rectangle *(*ConstructeurDefaultRectangle)();
    struct Rectangle *(*ConstructeurRectangle1)(int largeur, int hauteur);

    /* Meta super class */
    struct MetaObjetGraphique *superMetaClass;
};

struct Rectangle
{
    /* Instance de la classe mère */
    struct ObjetGraphique superClass;

    /* Attributs de la classe */
    int largeur;
    int hauteur;

    /* Pointeur vers la MétaClass */
    struct MetaRectangle *myClass;
};

#endif