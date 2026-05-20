#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include"carte.h"
#include"joueur.h"
#include"affichage.h"
#include"partie.h"



int  manche(joueur* tab_j, int nbj, carte* tab_p, int* nbc){     //return 0 = pas fini 1=plus de carte 2= flip 7
  if ( tab_p == NULL  || tab_j == NULL ){
          printf("💥Aïe... impossible de lire la main du joueur \n");
          return -1;
      }
    int manche_fini=0;
    int res;
    int rep;
    int recherche_flip7=0;

    for (int i=0; i<nbj; i++){
      tab_j[i].actif=1;
      tab_j[i].score=0;
      tab_j[i].nb_carte=0;
    }

printf("\n\n");
printf(ROUGE_CLAIR_GRAS"---------- debut de la manche -------------"RESET);
printf("\n\n");

  do{        //debut de la boucle de la manche 

  for (int i=0; i<nbj ;i++){           //passe de joueur a joueur 
      if(tab_j[i].actif==1){
        printf (JAUNE_CLAIR"\033[1m-------tour du joueur : %d-------\033[0m\n\n"RESET,tab_j[i].numj);
        compte_carte(tab_p,(*nbc));
        affiche_main( tab_j[i] );
        printf ("voulez vous piocher une carte ? \n");
        printf(" Tapez 1 pour oui et 2 pour non \n");
        printf("\n");

      
        do{                            //verifie la reponse 
          res=scanf(" %d",&rep);
          if (res !=1){
            viderBuffer();
            printf("⛔️il faut entrer 1 ou 2⛔️ \n");
            rep=0;
          }
          else if(rep != 1 && rep != 2){
            printf("⛔️il faut entrer 1 ou 2⛔️ \n");
          }
        }while(rep!=1 && rep!=2);

        if(rep==2){
          tab_j[i].actif=0;
        }                        //rend le joueur inactif car il arrete 

        else if(rep==1){            //debut si le joueur continue
          int nb_carte=tab_j[i].nb_carte;
          tab_j[i].nb_carte++;
          tab_j[i].main[nb_carte]=tab_p[(*nbc)-1];
          (*nbc)--;

          printf(VIOLET_BRILLIANT"vous avez pioché un %s \n\n"RESET, tab_j[i].main[nb_carte].nom);
          

          int est_doublon=0;
          est_doublon=doublon(tab_j[i].main,nb_carte+1);
      
          if(est_doublon==1){        //verif si il pioche un double
            tab_j[i].actif=0;
            printf(" Vous avez pioché un double, votre tour est terminé, vous gagnez 0 points \n");
            tab_j[i].nb_carte=0;
          }else if(est_doublon == 0){
            if( tab_j[i].main[nb_carte].type == 0 || tab_j[i].main[nb_carte].type == 1 ){
            printf(VERT"votre score augmente de %s, bien joué ! Attention à ne pas être trop gourmand...\n\n"RESET, tab_j[i].main[nb_carte].nom);
            } else if ( tab_j[i].main[nb_carte].type == 2 ){
              printf(VERT" votre score se multiplie par %s, bien joué ! Attention à ne pas être trop gourmand...\n\n"RESET, tab_j[i].main[nb_carte].nom);
            }
          }
          recherche_flip7=flip_7(tab_j[i].main,nb_carte+1);
      
          if (recherche_flip7==1){        //recherche si il y a un flip7
            tab_j[i].score=15;
            printf (" %s a sept carte la manche est terminée !! \n\n",tab_j[i].pseudo);
            break;
          }   // fin recherche_flip7
          if ((*nbc)==0){
            printf ("la pioche est vide la manche est terminée !! \n\n");
            break;
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

    if(joueurs_actifs == 0 || (*nbc)==0 || recherche_flip7==1){      //cherche si il y a une des condition pour finir la partie          
      manche_fini = 1;
    }
  }while(manche_fini==0);

  // compte point 

  for (int i=0 ; i<nbj ;i++){
    if(tab_j[i].nb_carte==0){
      tab_j[i].score=0;
    }
    else {
    int nb_cartem=tab_j[i].nb_carte;
    tab_j[i].score=calcul_score(tab_j[i].main,nb_cartem);
    }
    tab_j[i].score_total+=tab_j[i].score;
    printf (" le score de %s est de %d sur cette manche \n score total de ce joueur : %d\n\n",tab_j[i].pseudo,tab_j[i].score,tab_j[i].score_total);

  }
  if ((*nbc)==0){
            return 2;
          }
  for (int i=0 ; i<nbj ;i++){
    if (tab_j[i].score_total>=200){
      return 1;
    }
  }
  return 0;

}




void partie (joueur* tab_j,int nbj, carte* tab_p , int* nbc){   //debut fct partie

  FILE* f=NULL;
  int rep;
  char nom[50];
  char nom_fichier[55];
  int k=0;
 int NBC=*nbc;

  if ( tab_p == NULL || nbj < 0 || tab_j == NULL ){
    printf("💥Aïe... impossible de lire les données \n");
    return;
  }
  int nb_tour;

  melange_pioche(tab_p,(*nbc));   //appel la fct melange_pioche
  int res_manche=0;
  do{
    res_manche=0;
    res_manche=manche(tab_j,nbj,tab_p,&NBC);

    affiche_resultat(tab_j,nbj,res_manche);



  }while(res_manche!=1 && res_manche!=2);

  //sauvegarde dans le fichier

  printf (" Voulez vous sauvegarder les score ? \n 1:oui \n 2:non \n");      //demande si on sauvegarde
  do{
    scanf("%d",&rep);
    viderBuffer();
  } while (rep!=1 && rep!=2);

if (rep==1){                //si on sauvegarde
  printf(CYAN"comment appelez vous votre fichier ?! \n"RESET);
  scanf("%s",nom);

  do{
    nom_fichier[k]=nom[k];
    k++;
  }while(nom[k]!='\0');             //ajoute le .txt
  nom_fichier[k] = '.';
  nom_fichier[k+1] = 't';
  nom_fichier[k+2] = 'x';
  nom_fichier[k+3] = 't';
  nom_fichier[k+4] = '\0';

  f=fopen(nom_fichier,"w");
  if(f == NULL) {
    printf("Erreur ouverture fichier");
  }
  for (int i = nbj-1; i>=0 ;i--){
    fprintf(f, "%s : %d points\n", tab_j[i].pseudo, tab_j[i].score_total);
  }
  fclose(f);
}
printf("\n");
printf(" ----------- FIN DE LA PARTIE -------- \n");

}

