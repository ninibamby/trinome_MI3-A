#ifndef PARTIE_H
#define PARTIE_H

#include"affichage.h"
#include"carte.h"
#include"joueur.h"

int  manche(joueur* tab_j, int nbj, carte* tab_p, int *nbc);

void partie (joueur* tab_j,int nbj, carte* tab_p , int *nbc);

#endif
