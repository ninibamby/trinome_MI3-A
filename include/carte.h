#ifndef CARTES_H
#define CARTES_H



 void triTabCarte( carte* tab, int taille );

 int doublon(carte* tab, int taille);

int calcul_score(carte* tab, int taille);

int flip_7( carte* tab, int taille);

void creation_pioche(carte* tab, int*n);

void melange_pioche(carte* tab,int taille);

#endif