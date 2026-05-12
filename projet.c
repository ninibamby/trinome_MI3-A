#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct { 
    char nom[3];
    int val;
    int type;         //indicateur de type de carte : 0 si valeur, 1 si addition, 2 si multiplication
}carte;               //structure d'une carte

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

return a;
} 

void creation_pioche(carte*tab, int*n){
 int index=0

  for(int i=0; i <12 ;i++){        //cree toute les carte numero (type 0)
    for (int K=0; K<i; K++){ 
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

strcpy(tab[index].nom, "+4");        //cree tout les bonus (type 1)
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
strcpy(tab[index].nom, "x2");        //cree le X2 (type 2)
tab[index].val=-1;
tab[index].type=2;

*n=index+1;
    
}


void melange_pioche(carte* tab,int taille){
  carte temp;
  for (int i=0 ; i<taille ;i++){        //echange aleatoirement 2 element du tableau
    int r=srand()%taille;
    temp=tab[i];
    tab[i]=tab[r];
    tab[r]=temp;
  }
}


void triTabCarte( carte* tab, int taille ){        //un tri a bulle de la main du joueur 
int desordre;
int etape = taille-1;
carte temp;
do{

    desordre = 0;
    for( int i = 0; i < etape; i++){
        if ( tab[i].val > tab[i+1].val ){
            desordre = 1;
            temp = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = temp;
}
} etape--;
}while( etape > 0 && desordre != 0);
}            //fin tab carte



int doublon(carte* tab, int taille){        //on verifie si 2 carte de type 0 se suivent ont la meme valeur 
triTabCarte( tab, taille);
 for(int i = 0; i < taille-1; i++ ){
    if( tab[i].type == 0 ){
         if( tab[i].val == tab[i+1].val ){
            return 1;
}
} 
}
return 0;
}     //fin doublon 



int calcul_score(carte* tab, int taille){
int score0 = 0;
int score1 = 0;
int score2 = 0;
int score_final;

    for( int i = 0; i < taille; i++){        //calcul les carte valeur
        if( tab[i].type ==  0){
            score0 +=  tab[i].val;
    } else if ( tab[i].type == 1){        //calcul les bonus +
            score1 += tab[i].val;
    } else {                                //verifie si il y a un X2
score2 = 1;
  }
} 
    score2 *= 2*score0;
    if ( score2 == 0 ){
score_final = score0 + score1;
        
    }else {
        score_final = score2 + score1;
    }
return score_final;
}


int flip_7( int *tab, int taille){
int count_seven = 0;
    for ( int i = 0; i < taille; i++ ){        //compte le nb de crate de type 0
    if ( tab[i].type == 0 ){
        count_seven ++;
} if ( count_seven == 7 ){
        return 1;
}
} return 0;
}

void affiche_main( joueur j){
printf(" votre main, %s est : \n ", j.pseudo );
for ( int i = 0; i < j.nb_carte; i++ ){
    printf(" [%s], ", j.main[i].nom )
}
printf(" \n ");
}

    


void compte_carte(carte* tab, int n){
int count0=0;
int count1=0;
int comp0;
int comp1;

for (int i=0 ; i<n ;i++){        //compte les 0 et 1
comp0=strcmp("0",tab[i].nom);
comp1=strcmp("1",tab[i].nom);
  if (tab[i].type==0 && comp0==0){
  count0++;
  }
  if (tab[i].type==0 && comp1==0){
  count1++;
  }
}

printf (" il reste %d %c \n",count0,'0');
printf (" il reste %d %c \n",count1,'1');


for (int i=0 ; i<n ;i++){        //compte les carte de 2 a 12 
  for (int k=2 ; k<=12 ; k++){
      int count=0;
      char nom_c[3];
      if (tab[i].type==0 && tab[i].val==k){
        count++;
       strcpy(nom_c,tab[i].nom);
        
      }
printf (" il reste %d %s \n",count,nom_c);
  }

} 

for (int i=0 ; i<n ;i++){        //compte les bonus de type +
  for (int k=2 ; k<=10 ; k+2){
      int count2=0;
      char nom_c[3];
      if (tab[i].type==1 && tab[i].val==k){
        count2++;
       strcpy(nom_c,tab[i].nom);
        
      }
printf (" il reste %d %s \n",count2,nom_c);
  }

} 

int countX2=0;

for (int i=0 ; i<n ;i++){        //compte les X2
  if (tab[i].type==2 ){
  countX2++;
  }
}
printf (" il reste %d %c \n",countX2,"X2");
}


int  manche(joueur* tab_j, int nbj, carte* tab_p, int nbc){     //return 0 = pas fini 1=plus de carte 2= flip 7

  int manche_fini=0;
  int res;
  int rep;

  for (int i=0; i<nbj; i++){
    tab_j[i].actif=1;
    tab_j[i].score=0;
    tab_j[i].nb_carte=0;
  }

do{        //debut de la boucle de la manche 

 for (int i=0; i<nbj ;i++){           //passe de joueur a joueur 


if(tab_j[i].actif==1){
printf ("-------tour du joueur : %d-------\n",tab_j[i].numj);
printf ("voulez vous piocher une carte ? \n");
printf("\n");
    compte_carte(tab_p,nbc);
    affiche_main( tab_j[i] );
    
do{                            //verifie la reponse 
res=scanf(" %d",&rep);
if (res !=1){
  viderbuffer();
  printf("il faut entrer 1 ou 2 \n");
  rep=0;
}
else if(rep != 1 && rep != 2){
  printf("il faut entrer 1 ou 2 \n");
}
}while(rep!=1 && rep!=2);

if(rep==2){
  tab_j[i].actif=0;
}                        //rend le joueur inactif car il arrete 

else if(rep==1){            //debut si le joueur continue
int nb_carte=tab_j[i].nb_carte;
tab_j[i].nb_carte++;
tab_j[i].main[nb_carte]=tab_p[nbc-1];
nbc--;

printf("vous avez piocher un %s \n",tab[i].main[nb_carte].nom);

int est_doublon=0;
est_doublon=doublon(tab[i].main,nb_carte+1);
    
if(est_doublon==1){        //verif si il pioche un double
  tab_j[i].actif=0;
  printf(" Vous avez pioché un double, votre tour est terminé, vous gagnez 0 points \n");
  tab_j[i].nb_carte=0;
}
    
int recherche_flip7=0;
recherche_flip7=flip_7(tab_j[i].main,nb_carte+1);
    
if (recherche_flp7==1){        //recherche si il y a un flip7
  tab_j[i].score=15;
printf (" %s a sept carte la manche est terminée \n",tab[i].pseudo);
break
}   // fin recherche_flip7
if (nbc==0){
  printf ("la pioche est vide la manche est terminée \n");
  return 2;
}



}   //fin du si le joueur continue
}   //fin de si le joueur est actif
}   //fin de la boucle des joueur 


int joueurs_actifs = 0;

for(int i=0; i<nbj; i++){

    if(tab_j[i].actif == 1){        //cherche si tout les joueur on arreter 
        joueurs_actifs++;
    }
}

if(joueurs_actifs == 0 || nbc==0 || recherche_flip7==1){      //cherche si il y a une des condition pour finir la partie          
    manche_fini = 1;
}
}while(manche_fini==0);

// compte point 

for (int i=0 ; i<nbj ;i++){
  int nb_cartem=tab_j[i].nb_carte;
  tab_j[i].score=calcul_score(tab_j[i].main,nb_cartem);
  tab_j[i].score_total+=tab_[j].score;
  printf (" le score de %s est de %d sur cette manche \n score total de ce joueur : %d\n",tab_j[i].pseudo,tab_j[i].score,tab_j[i].score_total);

}
for (int i=0 ; i<nbj ;i++){
  if (tab_j[i].score_total>=200){
return 1;
  }
}
return 0;

}             //return 0  tout les joueurs arrete et return 1 si un joueur depasse 200 et return 2 si plus de carte 


partie (joueur* tab_j,int nbj, carte* tab_p , int nbc){   //debut fct partie
int nb_tour;

melange_pioche(tab_p,nbc);

do{
int res_manche=0;
res_manche=manche(tab_j,nbj,tab_p,nbc);

affiche_resultat(tab_j,nbj,res_manche);



}while(res_manche!=1 || res_manche!=2);

}   //fin fct partie




void viderBuffer() {         // supprime la saisie de l'utilisateur si celle-ci est mauvaise

    char c;

    do {
        c = getchar();
    } while (c != '\n');
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

void affiche_resulats( joueur* tab, int taille, int n){






int main(){
srand(time(NULL));
int nbj;                        // nb de joueurs ds la partie
int verif;                      // verificateur de nbj
int nbj;                        // nb de joueur
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


creation_pioche(pioche,&taille_pioche);

partie(tab_joueur,nbj,pioche,taille_pioche);









    
return 0;
}














































