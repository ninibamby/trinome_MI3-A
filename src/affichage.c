#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "structjoueur.h"
#include "affichage.h"


int Couleur(carte c) {

    if (c.type == 0) {
        switch(c.val) {
            case 0:  return 96; // cyan clair
            case 1:  return 37;  // gris
            case 2:  return 33;  // jaune
            case 3:  return 91;  // rouge clair
            case 4:  return 36;  // cyan 
            case 5:  return 32;  // vert
            case 6:  return 35;  // violet
            case 7:  return 95;  // violet brillant
            case 8:  return 92;  // vert clair
            case 9:  return 93;  // jaune clair
            case 10: return 31;  //  rouge    
            case 11: return 34;  // bleu
            case 12: return 90;  // gris 
        }
    }

    else if (c.type == 1 || c.type == 2) {
        return 33;
    }

return 37;
}

void affiche_main(joueur j) {

    int max = 6;
    
     printf("\033[36m");
printf("┌──────────────────────────────┐\n");
printf("│                              │\n");

printf("\033[0m");

printf("│  Main de %-20.20s│\n", j.pseudo);

printf("\033[36m");
printf("│                              │\n");
printf("└──────────────────────────────┘\n");
printf("\033[0m");
    for (int debut = 0; debut < j.nb_carte; debut += max) {

        int fin = debut + max;

        if (fin > j.nb_carte) {
            fin = j.nb_carte;
        }

       

        // Ligne 1
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);
            printf("╔═══════╗   ");
            printf("\033[0m");
        }
        printf("\n");

        // Ligne 2
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);
            printf("| ◆   ◆ |   ");
             printf("\033[0m");

        }
        printf("\n");

        // Ligne 3
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);
            printf("|═══════|   ");
            printf("\033[0m");
        }
        printf("\n");

        // Ligne centrale
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);

            if (j.main[i].type == 0) {
                printf("|) %2d  (|   ", j.main[i].val);
            }
            else {
                printf("|) %-3s (|   ", j.main[i].nom);
            }
            printf("\033[0m");
        }
        printf("\n");

        // Ligne 5
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);
            printf("|═══════|   ");
            printf("\033[0m");

        }
        printf("\n");

        // Ligne 6
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);
            printf("| ◆   ◆ |   ");
            printf("\033[0m");
        }
        printf("\n");

        // Ligne 7
        for (int i = debut; i < fin; i++) {
            int couleur = Couleur(j.main[i]);

            printf("\033[%dm", couleur);
            printf("╚═══════╝   ");
            printf("\033[0m");
        }
        printf("\n\n");
    }
}





void compte_carte(carte* tab, int n){
    if ( tab == NULL  || n <= 0 ){
        printf(" ❌erreur, n'arrive pas à lire la pioche❌ \n");
        return;
    }
int count0=0;
int count1=0;
int comp0;
int comp1;
char nom_c[3];

for (int i=0 ; i<n ;i++){        //compte les 0 et 1
comp0=strcmp("0",tab[i].nom);
comp1=strcmp("1",tab[i].nom);
  if (tab[i].type == 0 && comp0 == 0){
  count0++;
  }
  if (tab[i].type == 0 && comp1 == 0){
  count1++;
  }
}

      
printf(ROUGE_CLAIR"┌─────────────────────────────────────────┐\n"RESET);
printf(ROUGE_CLAIR"│"RESET);
printf( "   Cartes restantes dans la pioche:        ");
printf(ROUGE_CLAIR"│\n"RESET);
printf(ROUGE_CLAIR"├─────────────────────────────────────────┤\n" RESET);


printf("  il reste %-2d %c\n", count0, '0');
printf("  il reste %-2d %c\n", count1, '1');

for (int k = 2; k <= 12; k++) {

    int count = 0;
    char nom_c[20] = "";

    for (int i = 0; i < n; i++) {

        if (tab[i].type == 0 && tab[i].val == k) {
            count++;
            strcpy(nom_c, tab[i].nom);
        }
    }
if(count>0){
    printf("  il reste %-2d %s\n", count, nom_c);
}
}

for (int k = 2; k <= 10; k += 2) {

    int count2 = 0;
    char nom_c[20] = "";

    for (int i = 0; i < n; i++) {

        if (tab[i].type == 1 && tab[i].val == k) {
            count2++;
            strcpy(nom_c, tab[i].nom);
        }
    }
if(count2>0){
    printf("  il reste %-2d %s\n", count2, nom_c);
}
}

int countX2 = 0;

for (int i = 0; i < n; i++) {

    if (tab[i].type == 2) {
        countX2++;
    }
}
if(countX2>0){
printf("  il reste %-2d X2\n", countX2);
}

printf(ROUGE_CLAIR"└─────────────────────────────────────────┘\n"RESET);

}
