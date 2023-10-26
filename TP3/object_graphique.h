#ifndef _OBJET_GRAPHIQUE
#define _OBJET_GRAPHIQUE

#include "config.h"

/* Implémentation des Classes dans objet_graphique.c*/

struct MetaObjetGraphique;
struct ObjetGraphique;

/* Implémentation des méthodes dans objet_graphique.c*/

int getX(struct ObjetGraphique *this);
int getY(struct ObjetGraphique *this);
void setX(int inX, struct ObjetGraphique *this);
void setY(int inY, struct ObjetGraphique *this);
int GetNbObjetGraphique(void);
struct ObjetGraphique *ConstructeurDefaultObjetGraphique();
int getCentreXOG(struct ObjetGraphique *this);
int getCentreYOG(struct ObjetGraphique *this);

/* Implémentation des méthodes à surcharger ou non dans objet_graphique.c */
void afficher(struct ObjetGraphique *this);
void effacer(struct ObjetGraphique *this);
void deplacer(struct ObjetGraphique *this);
int getCentreX(struct ObjetGraphique *this);
int getCentreY(struct ObjetGraphique *this);

/* Définition des classes */

struct MetaObjetGraphique
{
   /* méthodes d’instances */
   void (*setX)(int, struct ObjetGraphique *);
   void (*setY)(int, struct ObjetGraphique *);
   int (*getX)(struct ObjetGraphique *);
   int (*getY)(struct ObjetGraphique *);

   /* TVMs pour polymorphisme*/
   void (*TVMeffacer[NBCLASSES])(struct ObjetGraphique *);
   void (*TVMafficher[NBCLASSES])(struct ObjetGraphique *);
   void (*TVMdeplacer[NBCLASSES])(struct ObjetGraphique *);
   int (*TVMgetCentreX[NBCLASSES])(struct ObjetGraphique *);
   int (*TVMgetCentreY[NBCLASSES])(struct ObjetGraphique *);

   /* Méthodes à surcharger ou non */
   void (*effacer)(struct ObjetGraphique *);
   void (*afficher)(struct ObjetGraphique *);
   void (*deplacer)(struct ObjetGraphique *);
   int (*getCentreX)(struct ObjetGraphique *);
   int (*getCentreY)(struct ObjetGraphique *);

   /* attributs de classe statique */
   int NbObjetGraphique;

   /* méthodes de classe statique */
   int (*GetNbObjetGraphique)(void);

   /* constructeur  de la classe */
   struct ObjetGraphique *(*ConstructeurDefautObjetGraphique)();
};

struct ObjetGraphique
{
   /* Attributs de la classe */
   int x;
   int y;

   /* Pointeur vers la MétaClass */
   struct MetaObjetGraphique *myClass;

   /* Type de la classe */
   OG_t type;
};

#endif