#include "init_main.h"

/* Instanciation UNIQUE des métaclass */

struct MetaObjetGraphique LeMetaObjetGraphique;
struct MetaCercle LeMetaCercle;
struct MetaRectangle LeMetaRectangle;

/* Setup des Metaclass */

void initMetaObjetGraphiquePolymorphisme(){
    LeMetaObjetGraphique.TVMafficher[OG] = NULL;
    LeMetaObjetGraphique.TVMeffacer[OG] = NULL;
    LeMetaObjetGraphique.TVMdeplacer[OG] = NULL;
    LeMetaObjetGraphique.TVMgetCentreX[OG] = getCentreXOG;
    LeMetaObjetGraphique.TVMgetCentreY[OG] = getCentreYOG;
    LeMetaObjetGraphique.TVMliberer[OG] = libererOG;

    LeMetaObjetGraphique.TVMafficher[RECTANGLE] = afficherRectangle;
    LeMetaObjetGraphique.TVMeffacer[RECTANGLE] = effacerRectangle;
    LeMetaObjetGraphique.TVMdeplacer[RECTANGLE] = deplacerRectangle;
    LeMetaObjetGraphique.TVMgetCentreX[RECTANGLE] = getCentreXRectangle;
    LeMetaObjetGraphique.TVMgetCentreY[RECTANGLE] = getCentreYRectangle;
    LeMetaObjetGraphique.TVMliberer[RECTANGLE] = libererRectangle;

    LeMetaObjetGraphique.TVMafficher[CERCLE] = afficherCercle;
    LeMetaObjetGraphique.TVMeffacer[CERCLE] = effacerCercle;
    LeMetaObjetGraphique.TVMdeplacer[CERCLE] = deplacerCercle;
    LeMetaObjetGraphique.TVMgetCentreX[CERCLE] = LeMetaObjetGraphique.TVMgetCentreX[OG];
    LeMetaObjetGraphique.TVMgetCentreY[CERCLE] = LeMetaObjetGraphique.TVMgetCentreY[OG];
    LeMetaObjetGraphique.TVMliberer[CERCLE] = libererCercle;
    
}

void initMetaObjetGraphique(){
    LeMetaObjetGraphique.ConstructeurDefautObjetGraphique = ConstructeurDefaultObjetGraphique;
    LeMetaObjetGraphique.GetNbObjetGraphique = GetNbObjetGraphique;
    LeMetaObjetGraphique.NbObjetGraphique = 0;
    LeMetaObjetGraphique.getX = getX;
    LeMetaObjetGraphique.getY = getY;
    LeMetaObjetGraphique.setX = setX;
    LeMetaObjetGraphique.setY = setY;
    LeMetaObjetGraphique.afficher = afficher;
    LeMetaObjetGraphique.effacer = effacer;
    LeMetaObjetGraphique.deplacer = deplacer;
    LeMetaObjetGraphique.getCentreX = getCentreX;
    LeMetaObjetGraphique.getCentreY = getCentreY;
    LeMetaObjetGraphique.liberer = liberer;
    initMetaObjetGraphiquePolymorphisme();
}

void initMetaCercle(){
    LeMetaCercle.ConstructeurDefaultCercle = ConstructeurDefaultCercle;
    LeMetaCercle.getRayon = getRayon;
    LeMetaCercle.setRayon = setRayon;
    LeMetaCercle.superMetaClass = &LeMetaObjetGraphique;
}

void initMetaRectangle(){
    LeMetaRectangle.ConstructeurDefaultRectangle = ConstructeurDefaultRectangle;
    LeMetaRectangle.ConstructeurRectangle1 = ConstructeurRectangle1;
    LeMetaRectangle.getLargeur = getLargeur;
    LeMetaRectangle.setLargeur = setLargeur;
    LeMetaRectangle.getHauteur = getHauteur;
    LeMetaRectangle.setHauteur = setHauteur;
    LeMetaRectangle.superMetaClass = &LeMetaObjetGraphique;
}

void init_main(){
    initMetaObjetGraphique();
    initMetaCercle();
    initMetaRectangle();
}