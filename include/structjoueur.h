#ifndef STRUCTJOUEUR_H
#define STRUCTJOUEUR_H

#include "structcarte.h"

typedef struct{
    int numj;
    char pseudo[20];
    carte main[20];
    int nb_carte;
    int score;
    int score_total;
    int actif;
} joueur;

#endif

