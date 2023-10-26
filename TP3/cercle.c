#include "cercle.h"
#include <stdio.h>
#include <stdlib.h>

/* Défini dans init_main.c et utilisé ici */
extern struct MetaCercle LeMetaCercle;

/* Implémentation des méthodes, elles seront pointés par la métaclass */
int getRayon(struct Cercle *this)
{
   return this->rayon;
}

void setRayon(int inRayon, struct Cercle *this)
{
   this->rayon = inRayon;
}

/* Implémentation des méthodes de surcharges */

void afficherCercle(struct ObjetGraphique *this){
   struct Cercle * c = (struct Cercle *)this;
   printf("Cercle de rayon %d\n", c->rayon);
}

void effacerCercle(struct ObjetGraphique *this){
   struct Cercle * c = (struct Cercle *)this;
   printf("Effacer Cercle de rayon %d\n", c->rayon);
}

void deplacerCercle(struct ObjetGraphique *this){
   struct Cercle * c = (struct Cercle *)this;
   printf("Deplacer Cercle de rayon %d\n", c->rayon);
}


/* Implémentation du constructeur, il sera pointé par la métaclass*/
struct Cercle *ConstructeurDefaultCercle()
{
   printf("Constructeur par défaut de Cercle\n");

   struct Cercle *this = (struct Cercle *)malloc(sizeof(struct Cercle));
   this->rayon = 1;
   this->myClass = &LeMetaCercle;
   this->superClass = *(this->myClass->superMetaClass->ConstructeurDefautObjetGraphique());

   this->superClass.type = CERCLE;

   return this;
}


