#include "init_main.h"

/* Instanciation UNIQUE des métaclass */

struct MetaObjetGraphique LeMetaObjetGraphique;
struct MetaCercle LeMetaCercle;
struct MetaRectangle LeMetaRectangle;

/* Setup des Metaclass */

void initMetaObjetGraphique(){
    LeMetaObjetGraphique.ConstructeurDefautObjetGraphique = ConstructeurDefaultObjetGraphique;
    LeMetaObjetGraphique.GetNbObjetGraphique = GetNbObjetGraphique;
    LeMetaObjetGraphique.NbObjetGraphique = 0;
    LeMetaObjetGraphique.getX = getX;
    LeMetaObjetGraphique.getY = getY;
    LeMetaObjetGraphique.setX = setX;
    LeMetaObjetGraphique.setY = setY;
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