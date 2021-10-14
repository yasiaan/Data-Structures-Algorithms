#include<stdlib.h>
#include<stdio.h>
#define MAX_FILE   10

typedef int element;
typedef struct{
    element elements[MAX_FILE];
    int itete;
    int iqueue;
}file;

file file_vide();
int est_vide(file f);
element tete(file f);
file enfiler(file f, element e);
file defiler(file f);

int main(){
    printf("***********( Question 2 )***********\n\n");
    printf("On enfile les cinq entiers 10, 20, 30, 40 et 50.\n\n");
    file f = file_vide();
    for(int i = 10; i <= 50; i = i+10){
        f = enfiler(f, i);
    }
    printf("La tete de la file est %d.\n\n", tete(f));
    printf("Les indices de la tete et de la queue sont respectivement %d et %d.\n\n", f.itete, f.iqueue);
    printf("On enfile les quatre entiers 60, 70, 80 et 90.\n\n");
    for(int i = 60; i <= 90; i = i+10){
        f = enfiler(f, i);
    }
    printf("On reaffiche les indices de la tete et de la queue de la fille.");
    printf("Les indices de la tete et de la queue sont respectivement %d et %d.\n\n", f.itete, f.iqueue);
    f = enfiler(f, 100);
    printf("La tete de la file est %d.\n\n", tete(f));
    for(int i = 1; i <= 9; i = i+1){
        f = defiler(f);
    }
    printf("Les indices de la tete et de la queue sont respectivement %d et %d.\n\n", f.itete, f.iqueue);
    return 1;
}

//( 1 )La file circulaire

file file_vide(){
    file f;
    f.itete=f.iqueue=0;
    return f;
}

int est_vide(file f){
    if(f.itete == f.iqueue) return 1;
    return 0;
}

element tete(file f){
    if(est_vide(f) == 1){
        printf("Erreur : file vide\n");
    }else{
        return f.elements[( f.itete + 1 ) % MAX_FILE ];
    }
}

file enfiler(file f, element e){
    if( f.itete == ( f.iqueue + 1 ) % MAX_FILE){
        printf("Erreur : file pleine\n");
    }else{
        f.iqueue = ( f.iqueue + 1 ) % MAX_FILE;
        f.elements[f.iqueue] = e;
        return f;
    }
}

file defiler(file f){
    if(est_vide(f) == 1){
        printf("Erreur : file vide\n");
    }else{
        f.itete = ( f.itete + 1 ) % MAX_FILE;
        return f;
    }
}



