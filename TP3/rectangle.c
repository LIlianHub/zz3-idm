#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

/* Défini dans init_main.c et utilisé ici */
extern struct MetaRectangle LeMetaRectangle;

/* Implémentation des méthodes, elles seront pointés par la métaclass */
int getLargeur(struct Rectangle *this)
{
    return this->largeur;
}

void setLargeur(int largeur, struct Rectangle *this)
{
    this->largeur = largeur;
}

int getHauteur(struct Rectangle *this)
{
    return this->hauteur;
}

void setHauteur(int hauteur, struct Rectangle *this)
{
    this->hauteur = hauteur;
}

/* Implémentation du constructeur, il sera pointé par la métaclass*/
struct Rectangle *ConstructeurDefaultRectangle()
{
    printf("Constructeur par défaut de Rectangle\n");

    struct Rectangle *this = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    this->largeur = 1;
    this->hauteur = 1;
    this->myClass = &LeMetaRectangle;
    this->superClass = *(this->myClass->superMetaClass->ConstructeurDefautObjetGraphique());

    return this;
}

struct Rectangle *ConstructeurRectangle1(int largeur, int hauteur)
{
    printf("Constructeur de Rectangle(largeur, hauteur)\n");

    struct Rectangle *this = ConstructeurDefaultRectangle();
    this->largeur = largeur;
    this->hauteur = hauteur;

    return this;
}
