#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include"structjoueur.h"

#define CYAN_CLAIR     "\033[96m"
#define GRIS           "\033[37m"
#define JAUNE          "\033[33m"
#define ROUGE_CLAIR    "\033[91m"
#define CYAN           "\033[36m"
#define VERT           "\033[32m"
#define VIOLET         "\033[35m"
#define VIOLET_BRILLIANT  "\033[95m"
#define VERT_CLAIR     "\033[92m"
#define JAUNE_CLAIR    "\033[93m"
#define ROUGE          "\033[31m"
#define BLEU           "\033[34m"
#define GRIS_FONCE     "\033[90m"

#define RESET          "\033[0m"

int Couleur(carte c);

void affiche_main( joueur j);

void compte_carte(carte* tab, int n);

#endif
