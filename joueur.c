#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



    
joueur CreationJoueur(int x){ //creer le profil de chaque joueur de la partie
  joueur a;
  char* pseudo[50]; // stock le pseudonyme de chaque joueur 
  a.numj=x;
  
  printf (" Quelle est le pseudo du joueur %d \n ", x);
  scanf ( "%s", a.pseudo);
  a.nb_carte=0;
  a.score=0;
  a.score_total=0;                // initialise les données du joueur 
  a.actif=1;

return a;
} 


void class_joueurs( joueur* tab, int taille ){

int desordre; int etape = n-1; int temp;
Do{
    desordre = 0;
for ( int i = 0; i <= etape; i++ ){
    if( tab[i].score_final > tab[i+1].score_final ){
    desordre = 1;
    temp = tab[i].score_final;
    tab[i].score_final = tab[i+1].score_final;
    tab[i+1].score_final = temp;
        etape --;
}while ( desordre != 0 && etape > 0 );
}



void affiche_resulat( joueur* tab, int taille, int n){
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
for (int i = taille; i > 0; i--){
printf(" Le classement du joueur %s est : %d \n", tab[i].pseudo, j );
j++;
}
}else if ( n == 2 ){
class_joueurs( tab, taille );
printf(" Personne n'a réussit à obtenir 200 points durant cette partie mais nous avons quand même un gagnant ! " );
printf(" Le classement des joueurs est donc : \n");
for (int y = taille; y > 0; y--){
printf(" Le classement du joueur %s est : %d \n", tab[i].pseudo, k );
k++;
}
}
}

