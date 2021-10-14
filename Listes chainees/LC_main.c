#include <stdlib.h>
#include <stdio.h>
#include "LC.c"

int main(){
    pNoeud l1 = NULL;
    l1 = ajoutdebut(l1, 1);
    l1 = ajoutdebut(l1, 3);
    l1 = ajoutdebut(l1, 21);
    printf("\t********\t********\n");
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tLa longueur de cette liste est : %d.\n", longueurL(l1));
    printf("\n\t********\t********\n");
    printf("\tOn ajoute 6 et 9 a la fin de la liste.\n\n");
    l1 = ajoutfin(l1, 6);
    l1 = ajoutfin(l1, 9);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tOn supprime le premier element de la liste.\n\n");
    l1 = supprimerdebut(l1);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tOn supprime le dernier element de la liste.\n\n");
    l1 = supprimerfin(l1);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tOn ajoute 7 et 11 respectivement dans les indices 2 et 4.\n\n");
    l1 = ajouterPos(l1, 7, 2);
    printf("\tLa liste l1 : ");
    afficher(l1);
    l1 = ajouterPos(l1, 11, 4);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tOn supprime l'element d'indice 2.\n\n");
    l1 = supprimerPos(l1, 2);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tLa liste l2 : ");
    pNoeud l2 = NULL;
    l2 = ajoutdebut(l2, 9);
    l2 = ajoutdebut(l2, 15);
    afficher(l2);
    printf("\n\tOn concatene l1 avec l2.\n\n");
    l1 = concat(l1, l2);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    printf("\tOn inverse la liste l1.\n\n");
    l1 = inverserListe(l1);
    printf("\tLa liste l1 : ");
    afficher(l1);
    printf("\n\t********\t********\n");
    return 0;
}
