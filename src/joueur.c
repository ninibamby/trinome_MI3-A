#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "structjoueur.h"



    
joueur CreationJoueur(int x){ //creer le profil de chaque joueur de la partie
  joueur a;
  a.numj=x;
  
  printf (" Joueur %d, veuillez entrer votre pseudo : \n ", x);
  scanf ( "%s", a.pseudo);
  a.nb_carte=0;
  a.score=0;
  a.score_total=0;                // initialise les données du joueur 
  a.actif=1;

return a;
} 


void class_joueurs( joueur* tab, int taille ){

int desordre; 
int etape = taille-1; 
int temp;

do{
  desordre = 0;
  for ( int i = 0; i <= etape; i++ ){
    if( tab[i].score_total > tab[i+1].score_total ){
      desordre = 1;
      temp = tab[i].score_total;
      tab[i].score_total = tab[i+1].score_total;
      tab[i+1].score_total = temp;
      etape --;
    }
  }
}while ( desordre != 0 && etape > 0 );
}




void affiche_resultat( joueur* tab, int taille, int n){
  if( tab == NULL ){
    return;
  }
  if ( taille <= 0 ){
    return;
  }
  if ( n != 1 && n != 2 ){
    return;
  }

int j = 1;
int k = 1;

  if ( n == 1 ){
  class_joueurs( tab, taille );
  int i = taille-1;
  printf(" On a un grand gagnant ! c'est %s🏆 avec %d points \n ", tab[taille-1].pseudo, tab[taille-1].score_total );
  printf(" 🏆CLASSEMENT DES JOUEURS🏆 \n");
  printf(" _____________________________\n");
  printf("| #  |  JOUEUR    | SCORE     |\n");
  printf("|-----------------------------|\n");
  printf("| 🥇 | %-10s        | %8d        |\n", tab[i].pseudo, tab[i].score_total);
  i=taille-2;
  printf("| 🥈 | %-10s         | %8d        |\n", tab[i].pseudo, tab[i].score_total);
  i=taille-3;
  printf("| 🥉 | %-10s         | %8d        |\n", tab[i].pseudo, tab[i].score_total);
  
    for ( i = taille-4; i > 0; i--){
  printf("| %d  | %-10s        | %8d        | \n", j, tab[i].pseudo, tab[i].score_total);
    j++;
    }
 printf("---------------------------------\n");
    }
  }
  else if ( n == 2 ){
  int y=taille-1;
  class_joueurs( tab, taille );
  printf(" Personne n'a réussit à obtenir 200 points durant cette partie mais nous avons quand même un gagnant ! \n" );
  printf(" 🏆CLASSEMENT DES JOUEURS🏆 \n");
  printf(" _____________________________\n");
  printf("| #  |  JOUEUR    | SCORE     |\n");
  printf("|-----------------------------|\n");
  printf("| 🥇 | %-10s        | %8d        |\n", tab[y].pseudo, tab[y].score_total);
  y=taille-2;
  printf("| 🥈 | %-10s         | %8d        |\n", tab[y].pseudo, tab[y].score_total);
  y=taille-3;
  printf("| 🥉 | %-10s         | %8d        |\n", tab[y].pseudo, tab[y].score_total);
  
    for ( y = taille-4; y > 0; y--){
  printf("| %d  | %-10s        | %8d        | \n", k, tab[y].pseudo, tab[y].score_total);
    k++;
    }
 printf("---------------------------------\n");
  }


