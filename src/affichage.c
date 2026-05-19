#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include"structjoueur.h"

int Couleur(carte c) {

    if (c.type == 0) {
        switch(c.val) {
            case 0:  return 96;
            case 1:  return 37;
            case 2:  return 33;
            case 3:  return 91;
            case 4:  return 36;
            case 5:  return 32;
            case 6:  return 35;
            case 7:  return 95;
            case 8:  return 92;
            case 9:  return 93;
            case 10: return 31;
            case 11: return 34;
            case 12: return 90;
        }
    }

    else if (c.type == 1 || c.type == 2) {
        return 33;
    }

return 37;
}

void affiche_main(joueur j) {

    int max = 6;

    printf("\nMain de %s :\n\n", j.pseudo);

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
        printf("erreur, n'arrive pas à lire la pioche ");
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

printf (" il reste %d %c \n",count0,'0');
printf (" il reste %d %c \n",count1,'1');

for ( int k = 2 ; k <= 12 ; k++ ){              //compte les carte de 2 a 12 
     int count=0;
    for ( int i = 0 ; i < n ;i++ ){          
        
        if (tab[i].type == 0 && tab[i].val == k){
        count++;       
        strcpy(nom_c,tab[i].nom);
        }
    }
printf (" il reste %d %s \n",count,nom_c);
} 

for (int k=2 ; k<=10 ; k+=2 ){
    int count2=0;
for (int i=0 ; i<n ;i++){        //compte les bonus de type +
    
  
      char nom_c[3];
      if (tab[i].type==1 && tab[i].val==k){
        count2++;
       strcpy(nom_c,tab[i].nom);
        
      }

  }
printf (" il reste %d %s \n",count2,nom_c);
} 

int countX2=0;

for (int i=0 ; i<n ;i++){        //compte les X2
  if (tab[i].type==2 ){
  countX2++;
  }
}
printf (" il reste %d %s \n",countX2,"X2");
}
