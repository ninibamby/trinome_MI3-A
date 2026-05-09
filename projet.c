#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct { 
    char tab[10];
    int val;
    int type;         //indicateur de type de carte : 0 si valeur, 1 si addition, 2 si multiplication
}carte;               // structure d'une carte

typedef struct{
   int numj;
   char pseudo[50];
   carte main[20];
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
      if (i<10){
      tab[index].nom[0]=('0'+i);
      tab[index].val=i;
      tab[index].type=0;
      }
      else if (i=10){
      tab[index].nom[0]='1';
      tab[index].nom[1]='0';
      tab[index].val=i;
      tab[index].type=0;
      }
      else if (i=11){
      tab[index].nom[0]='1';
      tab[index].nom[1]='1';
      tab[index].val=i;
      tab[index].type=0;
      }
      else if (i=12){
      tab[index].nom[0]='1';
      tab[index].nom[1]='2';
      tab[index].val=i;
      tab[index].type=0;
      }
      index++;
    }
  }
tab[0].val=1;

strcpy(tab[index].nom, "+4");
tab[index].val=4;
tab[index].type=1;
index++;
strcpy(tab[index].nom, "+6");
tab[index].val=6;
tab[index].type=1;
index++;
strcpy(tab[index].nom, "+8");
tab[index].val=8;
tab[index].type=1;
index++;
strcpy(tab[index].nom, "+10");
tab[index].val=10;
tab[index].type=1;
index++;
strcpy(tab[index].nom, "x2");
tab[index].val=-1;
tab[index].type=2;

*n=index+1;
    
}


void melange_pioche(carte* tab,int taille){
  carte temp;
  for (int i=0 ; i<taille ;i++){
    int r=srand()%taille;
    temp=tab[i];
    tab[i]=tab[r];
    tab[r]=temp;
  }
}





void manche(joueur* tab_j, int nbj, carte* tab_p, int nbc){
  int manche_fini=0;
  for (int i=0; i<nbj; i++){
    tab_j[i].actif=1;
    tab_j[i].score=0;
    tab_j[i].nb_carte=0;
  }
do{
for (int i=0; i<nbj ;i++){


  



}


int joueurs_actifs = 0;

for(int i=0; i<nbj; i++){

    if(joueurs[i].actif == 1){
        joueurs_actifs++;
    }
}

if(joueurs_actifs == 0){
    manche_finie = 1;
}
}while(manche_fini==0)

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
int res;
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
  printf("Pas assez de joueurs");   // message d'erreur si nb joueurs < 2
}
}while(nbj<2);//demande du nombre de joueur

joueur tab_joueur[nbj];



for(int i=1; i <=nbj ; i++){
tab_joueur[i-1]=CreationJoueur(i);
}
 printf("\n--- JOUEURS ---\n");

    for(int i = 0; i < nbj; i++){
        printf("%d : %s\n", tab_joueur[i].numj, tab_joueur[i].pseudo);
    }

return 0;
}














































