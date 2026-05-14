#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "structjoueur.h"



    
joueur CreationJoueur(int x){ //creer le profil de chaque joueur de la partie
  joueur a;
  a.numj=x;
  
  printf (" Quel est le pseudo du joueur %d \n ", x);
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
  printf(" On a un grand gagnant ! c'est %s avec %d points \n ", tab[taille-1].pseudo, tab[taille-1].score_total );
  printf(" Le classement des joueurs est donc : \n");
    for (int i = taille-1; i > 0; i--){
    printf(" Le classement du joueur %s est : %d \n", tab[i].pseudo, j );
    j++;
    }
  }
  else if ( n == 2 ){
  class_joueurs( tab, taille );
  printf(" Personne n'a réussit à obtenir 200 points durant cette partie mais nous avons quand même un gagnant ! " );
  printf(" Le classement des joueurs est donc : \n");
    for (int y = taille-1; y > 0; y--){
    printf(" Le classement du joueur %s est : %d \n", tab[y].pseudo, k );
    k++;
    }
  }
}

