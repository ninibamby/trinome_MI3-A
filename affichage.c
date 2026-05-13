#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void affiche_main( joueur j){
printf(" votre main, %s est : \n ", j.pseudo );
for ( int i = 0; i < j.nb_carte; i++ ){
    printf(" [%s], ", j.main[i].nom )
}
printf(" \n ");
}


