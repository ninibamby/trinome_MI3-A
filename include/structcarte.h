#ifndef STRUCTCARTE_H
#define STRUCTCARTE_H

typedef struct { 
    char nom[3];
    int val;
    int type;         //indicateur de type de carte : 0 si valeur, 1 si addition, 2 si multiplication
}carte;               //structure d'une carte

#endif

