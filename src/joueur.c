
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "structjoueur.h"
#include "affichage.h"




    
joueur CreationJoueur(int x){ //creer le profil de chaque joueur de la partie
  joueur a;
  a.numj=x;
  for(int i = 0; i < 20; i++) {
    a.pseudo[i] = '\0';
}
int espace = 0;

    
 printf("Joueur %d, entrez votre pseudo (max 15 caractères, sans espace):\n", x);

do{
    printf("Joueur %d, entrez votre pseudo (max 15 caractères, sans espace):\n", x);

    scanf("%19s", a.pseudo);

    if(strlen(a.pseudo) > 15){
        printf("⛔️ pseudo trop long ⛔️\n");
    }

}while(strlen(a.pseudo) > 15);
    
  a.nb_carte=0;
  a.score=0;
  a.score_total=0;                // initialise les données du joueur 
  a.actif=1;

return a;
} 


void class_joueurs(joueur* tab, int taille){

    int desordre;
    int etape = taille - 1;
    joueur temp;

    do{
        desordre = 0;

        for(int i = 0; i < etape; i++){

            if(tab[i].score_total > tab[i+1].score_total){

                desordre = 1;

                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
            }
        }

        etape--;

    }while(desordre && etape > 0);
}




void affiche_resultat( joueur* tab, int taille, int n){
      //verif des parametres 
  if( tab == NULL ){
    return;
  }
  if ( taille < 0 ){
    return;
  }
  if ( n != 1 && n != 2 ){
    return;
  }

int j = 4;
 
    
printf("\n");
printf("\n");


if ( n == 1 ){    //victoire par 200 points
    class_joueurs( tab, taille );
    if(taille == 2){     //pour 2 joueurs
      int i = taille-1;
      printf(" On a un grand gagnant ! c'est %s🏆 avec %d points \n ", tab[taille-1].pseudo, tab[taille-1].score_total );
      printf(JAUNE_CLAIR" 🏆 CLASSEMENT DES JOUEURS 🏆 \n"RESET);
      printf(" ______________________________________________\n");
      printf("| #  |      JOUEUR       |         SCORE       |\n");
      printf("|----------------------------------------------|\n");
      printf("| 🥇 |");
    printf(JAUNE_CLAIR"%15s    "RESET, tab[i].pseudo);
    printf("| %8d|\n", tab[i].score_total);
      i--;
      printf("| 🥈 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);
      printf("----------------------------------------------\n");
    }
    else{       //pour plus de 2 joueurs
    
    int i = taille-1;
    printf(" On a un grand gagnant ! c'est %s🏆 avec %d points \n ", tab[taille-1].pseudo, tab[taille-1].score_total );
    printf(JAUNE_CLAIR" 🏆 CLASSEMENT DES JOUEURS 🏆 \n"RESET);
      printf(" ______________________________________________\n");
      printf("| #  |      JOUEUR       |         SCORE       |\n");
      printf("|----------------------------------------------|\n");
      printf("| 🥇 |");
      printf(JAUNE_CLAIR"%15s    "RESET, tab[i].pseudo);
      printf("| %8d|\n", tab[i].score_total);
      i--;
      printf("| 🥈 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);
    i--;
      printf("| 🥉 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);  
    for ( i = taille-4; i >= 0; i--){
      printf("| %d |%15s    |            %9d|\n", j, tab[i].pseudo, tab[i].score_total);
    j++;
    }
      printf("----------------------------------------------\n");
    }
  }
  
  else if ( n == 2 ){         //plus de carte
    class_joueurs( tab, taille );
    if(taille == 2){     //pour 2 joueurs
      int i=taille-1;
      
    printf(" Personne n'a réussit à obtenir 200 points durant cette partie mais nous avons quand même un gagnant ! \n" );
    printf(JAUNE_CLAIR" 🏆 CLASSEMENT DES JOUEURS 🏆 \n"RESET);
      printf(" ______________________________________________\n");
      printf("| #  |      JOUEUR       |         SCORE       |\n");
      printf("|----------------------------------------------|\n");
      printf("| 🥇 |");
    printf(JAUNE_CLAIR"%15s    "RESET, tab[i].pseudo);
    printf("| %8d|\n", tab[i].score_total);
      i--;
      printf("| 🥈 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);
      printf("----------------------------------------------\n");
    }
  else{       //pour plus de 2 joueurs
  int i=taille-1;
  class_joueurs( tab, taille );
  printf(" Personne n'a réussit à obtenir 200 points durant cette partie mais nous avons quand même un gagnant ! \n" );
 printf(JAUNE_CLAIR" 🏆 CLASSEMENT DES JOUEURS 🏆 \n"RESET);
      printf(" ______________________________________________\n");
      printf("| #  |      JOUEUR       |         SCORE       |\n");
      printf("|----------------------------------------------|\n");
      printf("| 🥇 |");
      printf(JAUNE_CLAIR"%15s    "RESET, tab[i].pseudo);
      printf("| %8d|\n", tab[i].score_total);
      i--;
      printf("| 🥈 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);
    i--;
      printf("| 🥉 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);  
    for ( i = taille-4; i >= 0; i--){
      printf("| %d |%15s    |            %9d|\n", j, tab[i].pseudo, tab[i].score_total);
    j++;
    }
      printf("----------------------------------------------\n");
    }
}
}


