#ifndef _OBJET_GRAPHIQUE
#define _OBJET_GRAPHIQUE

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


/* Définition des classes */

struct MetaObjetGraphique
{
   /* méthodes d’instances */
   void (*setX)(int, struct ObjetGraphique *);
   void (*setY)(int, struct ObjetGraphique *);
   int (*getX)(struct ObjetGraphique *);
   int (*getY)(struct ObjetGraphique *);

   /* attributs de classe statique */
   int NbObjetGraphique;

   /* méthodes de classe statique */
   int (*GetNbObjetGraphique)(void);

   /* constructeur  de la classe */
   struct ObjetGraphique * (*ConstructeurDefautObjetGraphique)();
};

struct ObjetGraphique
{
   /* Attributs de la classe */
   int x;
   int y;

   /* Pointeur vers la MétaClass */
   struct MetaObjetGraphique *myClass;
};

#endif