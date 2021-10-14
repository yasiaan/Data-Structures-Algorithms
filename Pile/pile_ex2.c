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
    printf("**********Exercice 2 (1. et 2.)**********\n\n");
    printf("On va verifier si l'expression (a+b) est bien parenthesee :");
    char a[100] = {'(','a','+','b',')','\0'};
    pile p = pile_vide();
    int i = 0;
    int par = 0;
    while(a[i] != '\0'){
        if(a[i] == '('){
            p = empiler(p, 1);
        }
        if(a[i] == ')'){
            if(est_vide(p) == 1){
                par = 1;
            }else{
                p = depiler(p);
            }
        }
        i++;
    }
    if(par == 1 || est_vide(p) == 0){
        printf("L'expression n'est pas bien parenthesee !\n\n");
    }else{
        printf("L'expression est bien parenthesee.\n\n");
    }
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

