#ifndef JOUEUR_H
#define JOUEUR_H

#include "structjoueur.h"

joueur CreationJoueur(int x);

void class_joueurs( joueur* tab, int taille );

void affiche_resulat( joueur* tab, int taille, int n);

void viderBuffer();

#endif
