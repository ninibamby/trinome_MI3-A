#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
   int numj;
   char pseudo[50];
   carte main[20];
   int nb_carte;
   int score;
   int score_total;
   int actif;
   }joueur; //structure du joueur 
   