#include <stdlib.h>
#include <stdio.h>
#define MAX_PILE   6

typedef int element;
typedef struct{
    element elements[MAX_PILE];
    int iSommet;
}pile;

pile pile_vide();
int est_vide(pile p);
element sommet(pile p);
pile empiler(pile p, element e);
pile depiler(pile p);

int main(){
    printf("**********Exercice 1 (1.2)**********\n\n");
    printf("On empile quatre entiers (10,20,30,40)\n\n");
    pile p = pile_vide();
    for(int i = 10; i <= 40; i = i+10){
        p = empiler(p, i);
    }
    printf("On affiche les elements de la pile : ");
    printf("[");
    int i = 0;
    while(i < p.iSommet){
        printf(" %d,", p.elements[i]);
        i++;
    }
    printf(" %d ]\n\n", p.elements[i]);
    printf("On affiche l'indice du sommet et le contenu du sommet de la pile\n\n");
    printf("L'indice du sommet est %d, l'indice affiche est %d.\n\n", sommet(p), p.iSommet);
    printf("On empile les trois entiers (50, 60, 70)\n\n");
    for(int i = 50; i <= 70; i = i+10){
        p = empiler(p, i);
    }
    printf("La valeur du sommet est %d.\n\n", sommet(p));
    printf("On depile six elements et On reaffiche le sommet et son indice\n\n");
    for(int i = 1; i <= 6; i++){
        p = depiler(p);
    }
    if(est_vide(p) == 0){
        printf("Le sommet de la pile est %d\n\n", sommet(p));
    }
    printf("L'indice du sommet est %d\n\n", p.iSommet);
    printf("On depile un autre element et on reaffiche le sommet et son indice.\n\n");
    p = depiler(p);
    if(est_vide(p) == 0){
        printf("Le sommet de la pile est %d\n\n", sommet(p));
    }
    printf("L'indice du sommet est %d\n\n", p.iSommet);

    return 1;

}

//**********Exercice 1 (1.1)**********

pile pile_vide(){
    pile p;
    p.iSommet = -1;
    return p;
}

int est_vide(pile p){
    if(p.iSommet == -1) return 1;
    return 0;
}

element sommet(pile p){
    if(est_vide(p) == 1){
        printf("Erreur : pile vide\n");
    }else{
        return p.elements[p.iSommet];
    }
}

pile empiler(pile p, element e){
    if(p.iSommet >= MAX_PILE-1){
        printf("Erreur : pile pleine\n");
    }else{
        p.iSommet++;
        p.elements[p.iSommet] = e;
        return p;
    }
}

pile depiler(pile p){
    if(est_vide(p) == 1){
        printf("Erreur : pile vide\n");
    }else{
        p.iSommet--;
        return p;
    }
}

