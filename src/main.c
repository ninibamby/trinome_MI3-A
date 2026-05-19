#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "partie.h"



int main(){
srand(time(NULL));
int nbj;                        // nb de joueurs ds la partie
int verif;                      // verificateur de nbj
carte pioche[85];
int taille_pioche=85;



do{
printf("Combien y a t'il de joueur ? \n"); // demande le nb de joueurs
verif = scanf ("%d", &nbj);
    if ( verif != 1){ // si scanf n'arrive pas à lire un entier alors il ne renvoie pas 1
        viderBuffer();
        printf(" Il faut entrer un entier positif ! \n ");
        nbj = 0;
    } else if (nbj<2){
  printf("Pas assez de joueurs\n");   // message d'erreur si nb joueurs < 2
}
}while(nbj<2);//demande du nombre de joueur

joueur tab_joueur[nbj];



for(int i = 0; i < nbj; i++){
    tab_joueur[i] = CreationJoueur(i + 1);
}
 printf("\n--- JOUEURS ---\n");

    for(int i = 0; i < nbj; i++){
        printf("%d : %s\n", tab_joueur[i].numj, tab_joueur[i].pseudo);
    }


creation_pioche(pioche,&taille_pioche);

partie(tab_joueur,nbj,pioche,&taille_pioche);


    
return 0;
}

