#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void triTabCarte( carte* tab, int taille ){        //un tri a bulle de la main du joueur 
if ( tab == NULL || n <= 0){
    printf("erreur... la fonction n'arrive pas à lire la main du joueur \n");
    return;
}
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
}

int doublon(carte* tab, int taille){        //on verifie si 2 carte de type 0 se suivent ont la meme valeur 
triTabCarte( tab, taille);
 for(int i = 0; i < taille-1; i++ ){
    if( tab[i].type == 0 ){
         if( tab[i] == tab[i+1] ){
            return 1;
}
} return 0;
 }
}

int calcul_score(carte* tab, int taille){
    if ( tab == NULL || taille <= 0 ){
        printf("erreur... impossible de lire la main du joueur \n");
        return -1;
    }
int score0 = 0;
int socre1 = 0;
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


int flip_7( carte* tab, int taille){
    if ( tab == NULL || taille <= 0 ){
        printf("erreur... impossible de lire la main du joueur \n");
        return -1;
    }
int count_seven = 0;
    for ( int i = 0; i < taille; i++ ){        //compte le nb de crate de type 0
    if ( tab[i].type == 0 ){
        count_seven ++;
} if ( count_seven == 7 ){
        return 1;
}
} return 0;
}



void creation_pioche(carte* tab, int*n){
    if ( tab == NULL || n <= 0 ){
        printf("erreur... impossible de lire la main du joueur \n");
        return ;
    }
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




void melange_pioche(carte* tab,int taille){
    if ( tab == NULL || taille <= 0 ){
        printf("erreur... impossible de lire la main du joueur \n");
        return ;
    }
  carte temp;
  for (int i=0 ; i<taille ;i++){        //echange aleatoirement 2 element du tableau
    int r=srand()%taille;
    temp=tab[i];
    tab[i]=tab[r];
    tab[r]=temp;
  }
}
