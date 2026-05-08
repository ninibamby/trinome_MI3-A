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


  



joueur CreationJoueur(int x){ 
  joueur a;
  char* pseudo[50];
  a.numj=x;
  
  printf (" Quelle est le pseudo du joueur %d \n ", x);
  scanf ( " %s", a.pseudo);
  a.nb_carte=0;
  a.score=0;
  a.score_total=0;
  a.actif=1;

retun a;
}// fonction de creation des joueurs 










int main(){
int nbj;

//affichage 


do{
printf("Combien y a t'il de joueur ? \n");
scanf (" %d ", &nbj);
    if (nbj<"){
  printf("Pas assez de joueurs");  
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














































