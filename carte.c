#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void creation_pioche(carte*tab, int*n){
 int index=0

  for(int i=0; i <12 ;i++){        //cree toute les carte numero (type 0)
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





void compte_carte(carte* tab, int n){
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



void melange_pioche(carte* tab,int taille){
  carte temp;
  for (int i=0 ; i<taille ;i++){        //echange aleatoirement 2 element du tableau
    int r=srand()%taille;
    temp=tab[i];
    tab[i]=tab[r];
    tab[r]=temp;
  }
}
