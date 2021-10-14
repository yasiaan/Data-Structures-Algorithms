#include <stdlib.h>
#include <stdio.h>

typedef struct noeud_S *arbre;
typedef struct noeud_S{
    int info;
    arbre filsD;
    arbre filsG;
}noeud;

arbre creeArbre(int valeur);
arbre creeArbre2(int valeur,arbre gauche,arbre droit);

void affichagePrefixe(arbre a);
void affichageInfixe(arbre a);
void affichagePostfixe(arbre a);

arbre insererABR(arbre a,int n);
int minimumArbre(arbre a);
int maximumArbre(arbre a);
int nbrNoeud(arbre a);
int estVide(arbre a);
int hauteur(arbre a);

int rechercherArbre(arbre a,int n);

int main(){
    arbre a2 = NULL;
    a2 = insererABR(a2,56);
    a2 = insererABR(a2,44);
    a2 = insererABR(a2,60);
    a2 = insererABR(a2,78);
    printf("\nle prefixe est :");
    affichagePrefixe(a2);
    printf("\nLe nombre des noeuds est : %d.\n",nbrNoeud(a2));
    printf("\nLe minimum de l'arbre : %d.\n",minimumArbre(a2));
    printf("\nLe maximum de l'arbre : %d.\n",maximumArbre(a2));
    printf("\nle prefixe est :");
    affichagePrefixe(a2);
    printf("\nLe nombre des noeuds est : %d.\n",nbrNoeud(a2));
    arbre g = creeArbre(3);
    arbre d = creeArbre2(4,g,NULL);
    arbre a = creeArbre2(2,NULL,d);
    printf("\n%d\n",estVide(a));
    printf("la hauteur est :%d.",hauteur(a));
    printf("\nle prefixe est :");
    affichagePrefixe(a);
    printf("\nl'infixe est :");
    affichageInfixe(a);
    printf("\nle postfixe est :");
    affichagePostfixe(a);
    printf("\n %d",rechercherArbre(a,43));
    printf("\n %d",rechercherArbre(a,3));
    return 1;
}

arbre creeArbre(int valeur){
    arbre a = (arbre)malloc(sizeof(noeud));
    a->info = valeur;
    a->filsD = NULL;
    a->filsG = NULL;
    return a;
}

arbre creeArbre2(int valeur,arbre gauche,arbre droit){
    arbre a = (arbre)malloc(sizeof(noeud));
    a->info = valeur;
    a->filsG = gauche;
    a->filsD = droit;
    return a;
}

int estVide(arbre a){
    return (a == NULL);
}


int hauteur(arbre a){
    if(a == NULL)
        return 0;
    else{
        if(a->filsG == NULL && a->filsD == NULL)
            return 1;
        else{
            if(hauteur(a->filsG) > hauteur(a->filsD))
                return 1 + hauteur(a->filsG);
            return 1 + hauteur(a->filsD);
        }
    }
}

void affichagePrefixe(arbre a){
    if(a != NULL){
        printf(" %d ",a->info);
        affichagePrefixe(a->filsG);
        affichagePrefixe(a->filsD);
    }
}

void affichageInfixe(arbre a){
    if(a != NULL){
        affichageInfixe(a->filsG);
        printf(" %d ",a->info);
        affichageInfixe(a->filsD);
    }
}

void affichagePostfixe(arbre a){
    if(a != NULL){
        affichagePostfixe(a->filsG);
        affichagePostfixe(a->filsD);
        printf(" %d ",a->info);
    }
}

int rechercherArbre(arbre a,int n){
    if(a == NULL)
        return 0;
    else{
        if(a->info == n)
            return 1;
        else{
            if(rechercherArbre(a->filsG,n) != 1 && rechercherArbre(a->filsD,n) != 1)
                return 0;
            return 1;
        }
    }
}

arbre insererABR(arbre a,int n){
    if(a == NULL){
        a = creeArbre(n);
    }else{
        if(a->info > n){
            a->filsG = insererABR(a->filsG,n);
        }else{
            a->filsD = insererABR(a->filsD,n);
        }
    }
    return a;
}

int minimumArbre(arbre a){
    int min = a->info;
    if(a->filsD){
        int temp = minimumArbre(a->filsD);
        if(temp < min)
            min = temp;
    }
    if(a->filsG){
        int temp = minimumArbre(a->filsG);
        if(temp < min)
            min = temp;
    }
    return min;
}

int maximumArbre(arbre a){
    int max = a->info;
    if(a->filsD){
        int temp = maximumArbre(a->filsD);
        if(temp > max)
            max = temp;
    }
    if(a->filsG){
        int temp = maximumArbre(a->filsG);
        if(temp > max)
            max = temp;
    }
    return max;
}

int nbrNoeud(arbre a){
    if(a == NULL)
        return 0;
    else{
        int nbr = 1;
        if(a->filsG){
            nbr += nbrNoeud(a->filsG);
        }
        if(a->filsD){
            nbr += nbrNoeud(a->filsD);
        }
        return nbr;
    }
}



