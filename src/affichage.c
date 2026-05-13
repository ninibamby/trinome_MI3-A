#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include"structcarte.h"

void afficherCarte(Carte c) {

int couleur;
if(c.type == 0){
    if (c.val == 0){
        couleur = 96;
    }
    else if(c.val == 1){
        couleur = 37;
    }
    else if(c.val == 2){
        couleur = 33;
    }
    else if(c.val == 3){
        couleur = 91;
    }
    else if(c.val == 4){
        couleur = 36;
    }
    else if(c.val == 5){
        couleur = 32;
    }
    else if(c.val == 6){
        couleur = 35;
    }
    else if(c.val == 7){
        couleur = 95;
    }
    else if(c.val == 8){
        couleur = 92;
    }
    else if(c.val == 9){
        couleur = 33;
    }
    else if(c.val == 10){
        couleur = 31;
    }
    else if(c.val == 11){
        couleur = 34;
    }
    else if(c.val == 12){
        couleur = 90;
    }
}
else if(type == 1 || type == 2){
    couleur = 33;
}

if(type == 0){ 
    printf("\033[%dm", couleur);
    printf("╔═══════╗\n"); 
    printf("| ◆  ◆ |\n");  
    printf("|═══════|\n);                    
    printf("|)  %d (|\n", c.val);    
    printf("|═══════|\n");
    printf("| ◆  ◆ |\n");
    printf("╚═══════╝\n");


    printf("\033[0m ");
}
else if (type == 1 || type == 2){
     printf("\033[%dm", couleur);

    printf("╔═══════╗\n");  
    printf("| ◆  ◆ |\n");
    printf("|═══════|\n");      
    printf("|) %s (|\n", c.nom );          
    printf("|═══════|\n");          
    printf("| ◆  ◆ |\n");
    printf("╚═══════╝\n");

    printf("\033[0m ");
}
}

void affiche_main( joueur j){
printf(" votre main, %s est : \n ", j.pseudo );
for ( int i = 0; i < j.nb_carte; i++ ){
    printf(" [%s], ", j.main[i].nom )
}
printf(" \n ");
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

for (int i=0 ; i<n ;i++){        //compte les 0 et 1
comp0=strcmp("0",tab[i].nom);
comp1=strcmp("1",tab[i].nom);
  if (tab[i].type==0 && comp0=0){
  count0++;
  }
  if (tab[i].type==0 && comp1=0){
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
        count++;
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
