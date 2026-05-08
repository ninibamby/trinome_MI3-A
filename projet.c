#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct { 
    char tab[10];
    int val;
    int type; // 0 si carte = valeur, 1 si addition, 2 si multiplication
}carte;   // structure d'une carte

typedef struct{
   int numj;
   char pseudo[50];
   int nb_carte;
   int score;
   int score_total;
   int actif;
   }joueur; //structure du joueur


  



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

retun a;
} 

void creation_pioche(carte*tab, int*n){
 int index=0

  for(int i=0; i <12 ;i++){
    for (int K=0; K<i; k++){ 
      tab[index].nom[0]=('0'+i);
      tab[index].val=i;
        tab[index].type=0; // indicateur de type de  carte : 0 si carte "normale"
      index++;
    }
  }
tab[0].val=1;

strcpy(tab[index].nom, "+4");
tab[index].val=4;
index++;
strcpy(tab[index].nom, "+6");
tab[index].val=6;
index++;
strcpy(tab[index].nom, "+8");
tab[index].val=8;
index++;
strcpy(tab[index].nom, "+10");
tab[index].val=10;
index++;
strcpy(tab[index].nom, "x2");
tab[index].val=-1;

n=index;
    
}



void viderBuffer() { // supprime la saisie de l'utilisateur si celle-ci est mauvaise

    char c;

    do {
        c = getchar();
    } while (c != '\n');
}



int main(){
srand(time(NULL));
int nbj;                     // nb de joueurs ds la partie
int verif;                      // verificateur de nbj
carte pioche[85];
int taille_pioche;


do{
printf("Combien y a t'il de joueur ? \n"); // demande le nb de joueurs
verif = scanf ("%d", &nbj);
    if ( verif != 1){ // si scanf n'arrive pas à lire un entier alors il ne renvoie pas 1
        viderBuffer();
        printf(" Il faut entrer un entier positif ! \n ");
        nbj = 0;
    } else if (nbj<2){
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














































