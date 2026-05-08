#include <stdio.h>
#include <sting.h>
#include <stlib.h>




typedef struct{
   int numj;
   char pseudo[50];
   int nb_carte;
   int score;
   int score_total;
   int actif;
   }joueur //structure du joueur

typedef stuct{
  



}




joueur CreationJoueur(int x){ 
  joueur a;
  char* pseudo[50];
  a.numj=x;
  
  printf (" Quelle est le pseudo du joueur %d \n ", x);
  scanf ( " %s", a.pseudo);
  a.nb_carte=0;
  a.score=0;
  a.score_total=0;
  a.actif=0

retun a;
}// fonction de creation des joueurs 










int main(){
int nbj;

//affichage 


do{
printf("Combien y a t'il de joueur ? \n");
scanf (" %d ", nbj);
  printf("Pas assez de joueurs");  
}while(nbj<2);//demande du nombre de joueur

joueur tab[nbj];



for(int i=1,i<=nbj,i++){
tab[i-1]=CreationJoueur(i);


}


}














































