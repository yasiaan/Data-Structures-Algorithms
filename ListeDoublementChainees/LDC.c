#include <stdlib.h>
#include <stdio.h>

typedef struct noeud_S *Noeud;
typedef struct noeud_S{
    int info;
    Noeud suivant;
    Noeud precedant;
} noeud;

typedef struct{
    Noeud tete;
    Noeud queue;
    int nbr_noeud;
} liste_DC;
typedef liste_DC *liste;

//Les listes doublement chaînées

liste creationListeVide();
liste ajouterDebut(liste l, int data);
liste ajouterFin(liste l, int data);
void afficher(liste l);
void afficherInverse(liste l);
void chercherNoeud(liste l, int data);
liste supprimer(liste l, int data);

int main(){
    liste l = creationListeVide();
    l = ajouterDebut(l,9);
    l = ajouterDebut(l,4);
    l = ajouterFin(l,55);
    l = ajouterDebut(l,34);
    l = ajouterDebut(l,94);
    printf("\nl'affichage de la liste et son inverse :\n");
    afficher(l);
    afficherInverse(l);
    printf("\nLa recherche de 34, 55 et 66 dans la liste :\n");
    chercherNoeud(l,34);
    chercherNoeud(l,55);
    chercherNoeud(l,66);
    printf("\nLa suppression de 3 et 4 :\n");
    l = supprimer(l, 3);
    l = supprimer(l, 4);
    afficher(l);
    return 1;
}

liste creationListeVide(){
    liste l = malloc(sizeof(liste));
    l->tete = malloc(sizeof(Noeud));
    l->queue = malloc(sizeof(Noeud));
    l->tete->info = l->queue->info = 0;
    l->queue->suivant = l->tete->precedant = NULL;
    l->tete->suivant = l->queue;
    l->queue->precedant = l->tete;
    l->nbr_noeud = 0;
    return l;
}

liste ajouterDebut(liste l, int data){
    Noeud debut = malloc(sizeof(Noeud));
    debut->info = data;
    if(l->nbr_noeud == 0){
        debut->precedant = l->tete;
        debut->suivant = l->queue;
        l->queue->precedant = debut;
    }else{
        debut->precedant = l->tete;
        debut->suivant = l->tete->suivant;
        l->tete->suivant->precedant = debut;
    }
    l->tete->suivant = debut;
    l->nbr_noeud++;
    return l;
}

liste ajouterFin(liste l, int data){
    Noeud fin = malloc(sizeof(Noeud));
    fin->info = data;
    if(l->nbr_noeud == 0){
        fin->suivant = l->queue;
        fin->precedant = l->tete;
        l->tete->suivant = fin;
        l->nbr_noeud++;
    }else{
        fin->suivant = l->queue;
        fin->precedant = l->queue->precedant;
        l->queue->precedant->suivant = fin;
    }
    l->queue->precedant = fin;
    l->nbr_noeud++;
    return l;
}

void afficher(liste l){
    if(l->nbr_noeud == 0)
        printf("Erreur : la liste est vide.\n");
    else{
        printf("La liste est :");
        Noeud p = l->tete->suivant;
        while(p != l->queue->precedant){
            printf(" %d,", p->info);
            p = p->suivant;
        }
        printf(" %d.\n", p->info);
    }
}

void afficherInverse(liste l){
    if(l->nbr_noeud == 0)
        printf("Erreur : la liste est vide.\n");
    else{
        printf("L'inverse de la liste est :");
        Noeud p = l->queue->precedant;
        while(p != l->tete->suivant){
            printf(" %d,", p->info);
            p = p->precedant;
        }
        printf(" %d.\n", p->info);
    }
}

void chercherNoeud(liste l, int data){
    if(l->nbr_noeud == 0)
        printf("Erreur : la liste est vide.\n");
    else{
        Noeud p = l->tete->suivant;
        int i = 0, var = 0;
        while(p != l->queue){
            i++;
            if(p->info == data){
                printf("la position de %d est %d.\n", data, i);
                var = 1;
            }
            p = p->suivant;
        }
        if(var == 0)
            printf("%d ne se trouve pas dans la liste.\n", data);
    }
}

liste supprimer(liste l, int data){
    if(l->nbr_noeud == 0)
        printf("Erreur : la liste est vide.\n");
    else{
        int verification = 0;
        Noeud p1 = l->tete, p2 = l->tete->suivant;
        while(p2 != l->queue){
            if(p2->info == data){
                verification = 1;
                p1->suivant = p2->suivant;
                p2->suivant->precedant = p1;
                free(p2);
            }
            p1 = p2;
            p2 = p2->suivant;
        }
        if(verification == 0)
            printf("%d n'existe pas dans la liste.\n", data);
    }
    return l;
}




