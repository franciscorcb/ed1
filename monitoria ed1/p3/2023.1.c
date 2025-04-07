#include <stdio.h>
#include <stdlib.h>

typedef struct _tnode_{
    void *data;
    struct _tnode_ *left;
    struct _tnode_ *right;
}Tnode;

typedef struct _tree_ Tree;

#define TRUE 1
#define FALSE 0

/* 1) 
Escreva um algoritmo que retorna o número de nós em uma árvore binária que tem grau 1 (um único filho).*/


int calcNumNoGrau1(Tnode *t){
    int n, nr,nl;
    if(t!=NULL){
        nl= calcNumNoGrau1(t->left);
        nr = calcNumNoGrau1(t->right);
        if(t->left!=NULL && t->right==NULL){
            n=1;
        }
        else if(t->right!=NULL && t->left==NULL){
            n=1;
        }
        else{
            n=0;
        }
        return n+nl+nr;
    }
}

/* 2) 
Uma árvore t1 é maior que uma árvore t2 se elas são topologicamente iguais e para todos os nós nas posições 
correspondentes o valor armazenado no nó de t1 é maior que o valor armazenado no nó de t2. Usando o conceito 
acima, escreva um algoritmo que recebe o nó raiz de duas árvores binárias t1 e t2 e retorna 1 se t1 for maior 
que t2, 0 de outro modo. Não pode usar memória auxiliar (por exemplo converter a árvore para um vetor).
OBS: a função getvalue retorna o valor inteiro que está armazenado no nó da árvore.*/

int comparaArvores(Tnode *t1, Tnode *t2, int (*getvalue)(void *)){
    int noT1,noT2, spec1,spec2;
    if(t1!=NULL && t2!=NULL){
        noT1 = getvalue(t1->data);
        noT2 = getvalue(t2->data);
        if(noT1>noT2){
            spec1 = comparaArvores(t1->left,t2->left,getvalue);
            spec2 = comparaArvores(t1->right,t2->right,getvalue);
            return spec1 && spec2;
        }
        return FALSE;
    }
    else {
        if(t1==NULL && t2==NULL){
            return TRUE;
        }
    }
    return FALSE;
}

/*3)
Faça um algoritmo que recebe a raiz de uma arvore binária de pesquisa e e remove o elemento de maior valor na arvore*/

Tnode *abpremoveMaior(Tnode *t){
    Tnode *aux;
    if(t!=NULL){
        if(t->right!=NULL){
            t->right= abpremoveMaior(t->right);
            return t;
        }
        else{
            aux = t->right;
            free(t);
            return aux;
        }
    }
    return NULL;
}

//metodo 2:
/*
Tnode *abpremoveMaior(Tnode *t, void **data) {
    if (t != NULL) {
        if (t->right != NULL) {
            t->right = abpremoveMaior(t->right, data);
            return t;
        } else {
            *data = t->data;
            Tnode *aux = t->left;
            free(t);
            return aux;
        }
    }
    return NULL;
}*/
