#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>




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

}




partie (joueur* tab_j,int nbj, carte* tab_p , int nbc){   //debut fct partie
int nb_tour;

melange_pioche(tab_p,nbc);

do{
int res_manche=0;
res_manche=manche(tab_j,nbj,tab_p,nbc);

affiche_resultat(tab_j,nbj,res_manche);



}while(res_manche!=1 || res_manche!=2);

}


void viderBuffer() {         // supprime la saisie de l'utilisateur si celle-ci est mauvaise

    char c;

    do {
        c = getchar();
    } while (c != '\n');
}
