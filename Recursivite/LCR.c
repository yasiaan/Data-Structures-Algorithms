#include <stdlib.h>
#include <stdio.h>

typedef struct noeud_S *pNoeud;
typedef struct noeud_S{
    int info;
    pNoeud lien;
}liste;

pNoeud ajoutdebut(pNoeud l, int donnee);
//Les listes chaînées recursives
pNoeud afficherR(pNoeud l);
int longueurR(pNoeud l);
int nbOccuR(pNoeud l, int donnee);
pNoeud ajoutfinR(pNoeud l, int donnee);
pNoeud supprimerfinR(pNoeud l);
pNoeud concatR(pNoeud l1, pNoeud l2);
pNoeud inverserListeR(pNoeud l);
pNoeud inve(pNoeud l);


int main(){
    pNoeud l = NULL;
    for(int i =12; i < 60; i+=9){
        l = ajoutdebut(l,i);
    }
    printf("\nLa liste est :");
    afficherR(l);
    printf("\nla longueur de cette liste est : %d.\n", longueurR(l));
    printf("\nOn ajoute 12 a la fin de la liste :\n");
    l = ajoutfinR(l,12);
    printf("\nLa liste est :");
    afficherR(l);
    printf("\nla longueur de cette liste est : %d.\n", longueurR(l));
    printf("\nle nombre d'occurence de 12 dans la liste est %d.\n", nbOccuR(l,12));
    printf("\nle nombre d'occurence de 30 dans la liste est %d.\n", nbOccuR(l,30));
    printf("\nLa liste est :");
    afficherR(l);
    pNoeud l2 = NULL, l3 = NULL;
    for(int i =12; i < 60; i+=13){
        l2 = ajoutdebut(l2,i);
    }
    printf("\nLa liste l2 est :");
    afficherR(l2);
    printf("\nLa concatenation des deux listes est :");
    afficherR(concatR(l,l2));
    printf("\nL'inverse de cette derniere est :");
    afficherR(inve(l2));
    printf("\nL'inverse de cette derniere est :");
    afficherR(inverserListeR(l2));
    return 0;
}

pNoeud ajoutdebut(pNoeud l, int donnee){
    pNoeud debut = malloc(sizeof(pNoeud));
    debut->info = donnee;
    debut->lien = l;
    return debut;
}

// Question 1

pNoeud afficherR(pNoeud l){
    if(l == NULL)
        printf(".\n");
    else{
        if(l->lien == NULL)
            printf(" %d.\n", l->info);
        else{
            printf(" %d,", l->info);
            afficherR(l->lien);
        }
    }
}

// Question 2

int longueurR(pNoeud l){
    if(l == NULL)
        return 0;
    return 1+longueurR(l->lien);
}

// Question 3

int nbOccuR(pNoeud l, int donnee){
    if(l == NULL)
        return 0;
    else{
        if(l->info == donnee)
            return 1+nbOccuR(l->lien,donnee);
        return nbOccuR(l->lien,donnee);
    }
}

// Question 4

pNoeud ajoutfinR(pNoeud l, int donnee){
    pNoeud new;
    if(l == NULL){
        l = (pNoeud)malloc(sizeof(liste));
        l->info = donnee;
        l->lien = NULL;
    }else{
        if(l->lien == NULL){
            new = (pNoeud)malloc(sizeof(liste));
            new->info = donnee;
            l->lien = new;
            new->lien = NULL;
        }else
            l->lien = ajoutfinR(l->lien,donnee);
    }
    return l;
}

// Question 5

pNoeud supprimerfinR(pNoeud l){
    if(l->lien == NULL){
        l = NULL;
        free(l);
    }else{
        l->lien = supprimerfinR(l->lien);
    }
    return l;
}

// Question 6

pNoeud concatR(pNoeud l1, pNoeud l2){
    if(l1 == NULL)
        return l2;
    else{
        if(l1->lien == NULL)
            l1->lien = l2;
        else{
            l1->lien = concatR(l1->lien, l2);
        }
        return l1;
    }
}

//Question 7

pNoeud inverserListeR(pNoeud l){
    if(l == NULL || l->lien == NULL)
        return l;
    else{
        pNoeud p = inverserListeR(l->lien);
        l->lien->lien = l;
        l->lien = NULL;
        return p;
    }
}

pNoeud inve(pNoeud l){
    pNoeud N =NULL;
    if(l == NULL){
        return N;
    }else{
        N = ajoutfinR(inve(l->lien),l->info);
    }
}

