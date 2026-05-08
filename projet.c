#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char tab[10];
   unsigned int val;
   unsigned int bnus;
    
}carte;

typedef struct{
   int numj;
   char pseudo[50];
   int nb_carte;
   int score;
   int score_total;
   int actif;
   }joueur //structure du joueur


  



joueur CreationJoueur(int x){ //creer le profil de chaque joueur de la partie
  joueur a;
  char* pseudo[50]; // stock le pseudonyme de chaque joueur 
  a.numj=x;
  
  printf (" Quelle est le pseudo du joueur %d \n ", x);
  scanf ( " %s", a.pseudo);
  a.nb_carte=0;
  a.score=0;
  a.score_total=0;                // initialise les données du joueur 
  a.actif=1;

retun a;
} 









void viderBuffer() { // supprime la saisie de l'utilisateur si celle-ci est mauvaise

    char c;

    do {
        c = getchar();
    } while (c != '\n');
}

int main(){
int nbj;
int res;


do{
printf("Combien y a t'il de joueur ? \n"); // demande le nb de joueurs
res = scanf (" %d ", &nbj);
    if ( res != 1){ // si scanf n'arrive pas à lire un entier alors il ne renvoie pas 1
        viderBuffer();
        printf(" Il faut entrer un entier positif ! \n ");
        nbj = 0;
    } 
        
    if (nbj<2){
  printf("Pas assez de joueurs");   // message d'erreur si nb joueurs < 2
}
}while(nbj<2);//demande du nombre de joueur

joueur tab[nbj];



for(int i=1; i <=nbj ; i++){
tab[i-1]=CreationJoueur(i);
}
 printf("\n--- JOUEURS ---\n");

    for(int i = 0; i < nbj; i++){
        printf("%d : %s\n", tab[i].numj, tab[i].pseudo);
    }


}














































