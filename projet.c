#include <stdio.h>

typedef struct{
   int numj;
   char pseudo[50];
   int score;
   }joueur //structure du joueur




joueur CreationJoueur(int x){ 
joueur a;

a.numj=x;
a.pseudo=CreationPseudo(a.pseudo);
a.score=0;

retun a;
}// fonction de creation des joueurs 

char* CreationPseudo(char* tab){














int main(){
int nbj;

//affichage 


do{
printf("Combien y a t'il de joueur ? \n");
scanf (" %d ", nbj);
if (nbj<2){
  printf("Pas assez de joueurs");  
}while(nbj<2);//demande du nombre de joueur

joueur tab[nbj];



for(int i=0,i<nbj,i++){
tab[i]=CreationJoueur(i);










}





























