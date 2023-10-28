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

/* Implémentation des méthodes de surcharges */

void afficherRectangle(struct ObjetGraphique *this)
{
    struct Rectangle *r = (struct Rectangle *)this;
    printf("Rectangle de largeur %d et de hauteur %d\n", r->largeur, r->hauteur);
}

void effacerRectangle(struct ObjetGraphique *this)
{
    struct Rectangle *r = (struct Rectangle *)this;
    printf("Effacer Rectangle de largeur %d et de hauteur %d\n", r->largeur, r->hauteur);
}

void deplacerRectangle(struct ObjetGraphique *this)
{
    struct Rectangle *r = (struct Rectangle *)this;
    printf("Deplacer Rectangle de largeur %d et de hauteur %d\n", r->largeur, r->hauteur);
}

int getCentreXRectangle(struct ObjetGraphique *this)
{
    struct Rectangle *r = (struct Rectangle *)this;
    return r->superClass.x + r->largeur / 2;
}

int getCentreYRectangle(struct ObjetGraphique *this)
{
    struct Rectangle *r = (struct Rectangle *)this;
    return r->superClass.y + r->hauteur / 2;
}

void libererRectangle(struct ObjetGraphique *this){
   struct Rectangle * r = (struct Rectangle *)this;
   free(&(r->superClass));
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

    this->superClass.type = RECTANGLE;

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
