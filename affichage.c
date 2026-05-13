#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
