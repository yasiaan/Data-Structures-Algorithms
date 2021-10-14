#ifndef DEF_LC
#define DEF_LC

#include <stdlib.h>
#include <stdio.h>

typedef struct noeud_S *pNoeud;
typedef struct noeud_S{
    int info;
    pNoeud lien;
}liste;

pNoeud ajoutdebut(pNoeud l, int donnee);
void afficher(pNoeud l);
pNoeud ajoutfin(pNoeud l, int donnee);
pNoeud supprimerdebut(pNoeud l);
pNoeud supprimerfin(pNoeud l);
pNoeud supprimerPos(pNoeud l, int pos);
pNoeud ajouterPos(pNoeud l,int donnee, int pos);
pNoeud concat(pNoeud l1, pNoeud l2);
pNoeud inverserListe(pNoeud l);

//liste chainee recursives

pNoeud afficherR(pNoeud l);
pNoeud ajoutfinR(pNoeud l, int donnee);
int longueurR(pNoeud l);
int nbOcc(pNoeud l, int e);
pNoeud supprimerfinR(pNoeud l);

#endif
