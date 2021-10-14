#include <stdlib.h>
#include <stdio.h>

typedef struct noeud_S *ABR;
typedef struct noeud_S{
    int info;
    ABR filsDroit;
    ABR filsGauche;
}noeud;

//Question (1)
ABR creeABR(int valeur,ABR g,ABR d);
//Question (2)
ABR insererABR(ABR a,int n);
//Question (3)
void parcours(ABR a);
//Question (4)
int rechercherABR(ABR a,int n);
//Question (5)
int maximumAB(ABR a);
//Question (6)
ABR chercherMin(ABR a);
ABR chercherMax(ABR a);
//Question (7)
ABR supprimerABR(ABR a,int n);
ABR supprimerABR2(ABR a,int n);

int main(){
    ABR a = NULL;
    for(int i = 12; i < 60; i += 9){
        a = insererABR(a,i);
    }
    printf("L'affichage de l'arbre en ordre croissant : ");
    parcours(a);
    for(int i = 1; i < 31; i++){
        if(rechercherABR(a,i) == 1)
            printf("\n\n  %d existe dans la liste.",i);
    }
    printf("\n\nLe minimum de l'arbre est : %d.",chercherMin(a)->info);
    printf("\n\nLe maximum de l'arbre est : %d.",chercherMax(a)->info);
    a = supprimerABR(a,30);
    printf("\n\nL'affichage de l'arbre apres la suppression de 30 : ");
    parcours(a);
    return 0;
}

ABR creeARB(int valeur,ABR g,ABR d){
    ABR a = (ABR)malloc(sizeof(noeud));
    a->info = valeur;
    a->filsGauche = g;
    a->filsDroit = d;
    return a;
}

ABR insererABR(ABR a,int n){
    if(a == NULL){
        a = creeARB(n,NULL,NULL);
    }else{
        if(a->info > n){
            a->filsGauche = insererABR(a->filsGauche,n);
        }else{
            a->filsDroit = insererABR(a->filsDroit,n);
        }
    }
    return a;
}

void parcours(ABR a){
    if(a != NULL){
        parcours(a->filsGauche);
        printf(" %d ",a->info);
        parcours(a->filsDroit);
    }
}

int rechercherABR(ABR a,int n){
    if(a == NULL)
        return 0;
    else{
        if(a->info == n)
            return 1;
        if(a->info > n)
            return rechercherABR(a->filsGauche,n);
        if(a->info < n)
            return rechercherABR(a->filsDroit,n);
    }
}

int rechercherAB(ABR a,int n){
    if(a == NULL)
        return 0;
    else{
        if(a->info == n)
            return 1;
        else
            return fmax(rechercherAB(a->filsDroit,n),rechercherAB(a->filsGauche,n));
    }
}

ABR chercherMin(ABR a){
    if(a == NULL)
        return NULL;
    else{
        if(a->filsGauche)
            return chercherMin(a->filsGauche);
        return a;
    }
}

ABR chercherMax(ABR a){
    if(a == NULL)
        return NULL;
    else{
        if(a->filsDroit)
            return chercherMax(a->filsDroit);
        return a;
    }
}

int nbrFils(ABR a){
    if(a->filsDroit == NULL && a->filsGauche == NULL)
        return 0;
    if(a->filsDroit != NULL && a->filsGauche != NULL)
        return 2;
    return 1;
}

ABR supprimerABR(ABR a,int n){
    if(a == NULL)
        printf("Erreur : %d n'existe pas dans l'arbre !",n);
    else{
        if(a->info > n)
            a->filsGauche = supprimerABR(a->filsGauche,n);
        else if(a->info < n)
                a->filsDroit = supprimerABR(a->filsDroit,n);
        else{
            ABR tempABR;
            if(a->info == n){
                if(nbrFils(a) == 0)
                    a = NULL;
                else{
                    if(nbrFils(a) == 1){
                        tempABR = a;
                        if(a->filsDroit == NULL){
                            a = a->filsGauche;
                        }else{
                            a = a->filsDroit;
                        }
                        free(tempABR);
                    }else{
                        tempABR = chercherMin(a->filsDroit);
                        a->info = tempABR->info;
                        a->filsDroit = supprimerABR(a->filsDroit,tempABR->info);
                    }
                }
            }
        }
    }
    return a;
}

ABR supprimerABR2(ABR a,int n){
    if(a == NULL)
        printf("Erreur : %d n'existe pas dans l'arbre !",n);
    else{
        if(a->info > n)
            a->filsGauche = supprimerABR2(a->filsGauche,n);
        else if(a->info < n)
                a->filsDroit = supprimerABR2(a->filsDroit,n);
        else{
            ABR tempABR;
            if(a->info == n){
                if(nbrFils(a) == 0)
                    a = NULL;
                else{
                    if(nbrFils(a) == 1){
                        tempABR = a;
                        if(a->filsDroit == NULL){
                            a = a->filsGauche;
                        }else{
                            a = a->filsDroit;
                        }
                        free(tempABR);
                    }else{
                        tempABR = chercherMax(a->filsGauche);
                        a->info = tempABR->info;
                        a->filsGauche = supprimerABR2(a->filsGauche,tempABR->info);
                    }
                }
            }
        }
    }
    return a;
}




