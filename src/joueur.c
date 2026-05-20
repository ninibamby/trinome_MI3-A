
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "structjoueur.h"
#include "affichage.h"




    
joueur CreationJoueur(int x){
    joueur a;
    a.numj = x;

    int valide;
    int len;

    printf("Joueur %d, entrez votre pseudo (max 15 caractères, sans espace):\n", x);

    do{
        valide = 1;

        fgets(a.pseudo, sizeof(a.pseudo), stdin);

        len = strlen(a.pseudo);

        // enlever \n si présent
        if(len > 0 && a.pseudo[len - 1] == '\n'){
            a.pseudo[len - 1] = '\0';
            len--;
        }
        else{
            // 🔥 cas : entrée trop longue → il reste du texte dans stdin
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // vide
        if(len == 0){
            printf("⛔ pseudo vide ⛔\n");
            valide = 0;
        }

        // trop long (logique)
        if(len > 15){
            printf("⛔ pseudo trop long ⛔\n");
            valide = 0;
        }

        // espace
        if(strchr(a.pseudo, ' ') != NULL){
            printf("⛔ pas d'espaces ⛔\n");
            valide = 0;
        }

    }while(valide != 1);

    a.nb_carte = 0;
    a.score = 0;
    a.score_total = 0;
    a.actif = 1;

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
    printf("| %-8d|\n", tab[i].score_total);
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
      printf("| %-8d|\n", tab[i].score_total);
      i--;
      printf("| 🥈 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);
    i--;
      printf("| 🥉 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);  
    for ( i = taille-4; i >= 0; i--){
      printf("| %d  |%15s    |            %9d|\n", j, tab[i].pseudo, tab[i].score_total);
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
    printf("| %-8d|\n", tab[i].score_total);
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
      printf("| %-8d|\n", tab[i].score_total);
      i--;
      printf("| 🥈 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);
    i--;
      printf("| 🥉 |%15s    |            %9d|\n", tab[i].pseudo, tab[i].score_total);  
    for ( i = taille-4; i >= 0; i--){
      printf("| %d  |%15s    |            %9d|\n", j, tab[i].pseudo, tab[i].score_total);
    j++;
    }
      printf("----------------------------------------------\n");
    }
}
}


