#include <stdlib.h>
#include <stdio.h>
#define MAX_EXPRESSION 100

typedef struct noeud_S *pNoeud;
typedef struct noeud_S{
    int info;
    pNoeud lien;
}liste;

pNoeud ajoutDebut(pNoeud l, int donnee);
int longueur(pNoeud l);
pNoeud supprimerDebut(pNoeud l);

int main(){
    char a[MAX_EXPRESSION] = "";
    printf("Entrer une expression : ");
    scanf("%[^\n]", a);
    parenthesee(a);
    return 0;https://i.ytimg.com/an_webp/sQh7fr53Xy0/mqdefault_6s.webp?du=3000&sqp=CJOhg_sF&rs=AOn4CLAt6vLCh0eFg25PEOSfLxJ_lBSmhg
}

void parenthesee(char* exp){
    int i = 0, par = 0;
    pNoeud p = NULL;
    while(exp[i] != '\0' && par == 0){
        if(exp[i] == '(')
            p = ajoutDebut(p,1);
        if(exp[i] == ')'){
            if(longueur(p) == 0){
                par = 1;
            }else{
                p = supprimerDebut(p);
            }
        }
        i++;
    }
    if(par == 1 || longueur(p) != 0){
        printf("L'expression n'est pas bien parenthesee !!\n");
    }else{
        printf("L'expression est bien parenthesee.\n");
    }
}

pNoeud ajoutDebut(pNoeud l, int donnee){
    pNoeud p = NULL;
    p = malloc(sizeof(pNoeud));
    p->info = donnee;
    p->lien = l;
    return p;
}

int longueur(pNoeud l){
    if(l == NULL)
        return 0;
    return 1+longueur(l->lien);
}

pNoeud supprimerDebut(pNoeud l){
    if(l == NULL)
        return l;
    pNoeud p = l;
    l = l->lien;
    free(p);
    return l;
}
