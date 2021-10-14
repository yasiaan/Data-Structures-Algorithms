#include <stdlib.h>
#include <stdio.h>
#include "LC.h"

pNoeud ajoutdebut(pNoeud l, int donnee){
    pNoeud debut = malloc(sizeof(pNoeud));
    debut->info = donnee;
    debut->lien = l;
    return debut;
}

void afficher(pNoeud l){
    if(l == NULL){
        printf("la liste est vide.\n");
    }else{
        printf("[");
        while(l->lien != NULL){
            printf(" %d,", l->info);
            l = l->lien;
        }
        printf(" %d ]\n", l->info);
    }
}

int longueurL(pNoeud l){
    int i = 0;
    while(l != NULL){
        i++;
        l = l->lien;
    }
    return i;
}

/*int longueurL(pNoeud l){
    if(l == NULL) return 0;
    else{
        int i = 1;
        while(l->lien != NULL){
            l = l->lien;
            i++;
        }
        return i;
    }
}*/

pNoeud ajoutfin(pNoeud l, int donnee){
    if(l == NULL) return ajoutdebut(l, donnee);
    else{
        pNoeud temp;
        temp = malloc(sizeof(pNoeud));
        temp->info = donnee;
        temp->lien = NULL;
        pNoeud p = l;
        while(p->lien != NULL){
            p = p->lien;
        }
        p->lien = temp;
        return l;
    }
}

pNoeud supprimerdebut(pNoeud l){
    if(l == NULL){
        printf("\nErreur : la liste est vide.\n");
        return l;
    }else{
        pNoeud p = l->lien;
        free(l);
        return p;
    }
}

pNoeud supprimerfin(pNoeud l){
    if(l == NULL){
        printf("\nErreur : la liste est vide.\n");
        return l;
    }
    if(l->lien == NULL){
        return supprimerdebut(l);
    }else{
        pNoeud p = l, temp = l;
        while(p->lien != NULL){
            temp = p;
            p = p->lien;
        }
        temp->lien = NULL;
        free(p);
    }
    return l;
}

pNoeud supprimerPos(pNoeud l, int pos){
    if(longueurL(l) == 0 || pos <= 0 || pos > longueurL(l)){
        printf("\n\tErreur : la liste ou la position n'est pas valide\n");
    }
    if(pos == 1)
        l = supprimerdebut(l);
    if(pos == longueurL(l))
        l = supprimerfin(l);
    if(pos < longueurL(l) && pos > 1){
        int i = 1;
        pNoeud p1 = l, p2 = l;
        while(i < pos){
            p1 = p2;
            p2 = p2->lien;
            i++;
        }
        p1->lien = p2->lien;
        free(p2);
    }
    return l;
}

pNoeud ajouterPos(pNoeud l, int donnee, int pos){
    if(longueurL(l) == 0 || pos <= 0 || pos > 1+longueurL(l)){
        printf("\nErreur : la liste ou la position n'est pas valide.\n");
    }
    if(pos == longueurL(l)+1)
        return ajoutfin(l, donnee);
    if(pos == 1){
        return ajoutdebut(l, donnee);
    }
    if(pos <= longueurL(l) && pos > 1){
        int i = 1;
        pNoeud p1 = l, p2 = l;
        while(i != pos){
            p1 = p2;
            p2 = p2->lien;
            i++;
        }
        p2 = ajoutdebut(p2, donnee);
        p1->lien = p2;
    }
    return l;
}

pNoeud concat(pNoeud l1, pNoeud l2){
    if(l1 == NULL)
        l1 = l2;
    else{
        pNoeud p = l1;
        while(p->lien != NULL){
            p = p->lien;
        }
        p->lien = l2;
    }
    return l1;
}

pNoeud inverserListe(pNoeud l){
    if(l == NULL)
        printf("\nErreur : la liste est vide.\n");
    else{
        pNoeud p = NULL;
        while(l != NULL){
            p = ajoutdebut(p, l->info);
            l = l->lien;
        }
        return p;
    }
}




