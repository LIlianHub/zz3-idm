#include "object_graphique.h"
#include <stdio.h>
#include <stdlib.h>

/* Défini dans init_main.c et utilisé ici */
extern struct MetaObjetGraphique LeMetaObjetGraphique;

/* Implémentation des méthodes, elles seront pointés par la métaclass */
int getX(struct ObjetGraphique *this)
{
    return this->x;
}

int getY(struct ObjetGraphique *this)
{
    return this->y;
}

void setX(int inX, struct ObjetGraphique *this)
{
    this->x = inX;
}

void setY(int inY, struct ObjetGraphique *this)
{
    this->y = inY;
}

/* Implémentation du constructeur, il sera pointé par la métaclass*/
struct ObjetGraphique *ConstructeurDefaultObjetGraphique()
{
    printf("Constructeur par défaut de ObjetGraphique\n");

    struct ObjetGraphique * this = (struct ObjetGraphique *)malloc(sizeof(struct ObjetGraphique));
    this->x = 0;
    this->y = 0;

    this->myClass = &LeMetaObjetGraphique;
    
    this->myClass->NbObjetGraphique++;
    return this;
}


int GetNbObjetGraphique(){
    return LeMetaObjetGraphique.NbObjetGraphique;
}
