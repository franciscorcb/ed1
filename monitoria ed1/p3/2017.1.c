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

//2 
/* Escreva um algoritmo que recebe a raiz de uma arvore binária e um número h 
e retorna o número de nós de uma árvore binária que tem altura igual a h*/

//metodo 1
/*int abNumNosAlturah(Tnode *t, int h){
    int n;
    if(t!=NULL && h!=0){
        if(h==0){
            n=1;
        }else{
            n=0;
        }
        return n + abNumNosAlturah(t->left,h-1) + abNumNosAlturah(t->right,h-1);
    }
    return 0;
}*/

//metodo 2
int abNumNosAlturah(Tnode *t, int h){
    int n,nr,nl;
    if(t!=NULL){
        nr = abNumNosAlturah(t->right,h-1);
        nl = abNumNosAlturah(t->left,h-1);
        if(h==0){
            n=1;
        }else{
            n=0;
        }
        return n+nr+nl;
    }
    return 0;
}

//3
/*Escreva um algoritmo que calcula a diferença entre o maior e o menor valor existente em uma árvore 
binária de pesquisa. Use obrigatoriamente o protótipo do algoritmo abaixo:
OBS: A função getvalue retorna o valor inteiro que está armazenado no nó da árvore.*/

/*
LEMBRAR TNODE ******
Tnode *retornaMaior(Tnode *t){
    if(t!=NULL){
        if(t->right!=NULL){
            return retornaMaior(t->right);
        }else{
            return t;
        }
    }
    return NULL;
}

LEMBRAR TNODE ******
Tnode *retornaMenor(Tnode *t){
    if(t!=NULL){
        if(t->left!=NULL){
            return retornaMenor(t->left);
        }
        else{
            return t;
        }
    }
    return NULL;
}
*/

int getvalue(void *data) {
    return *(int *)data;
}

int abpCalculaDiferencaMaiorParaMenor(Tnode*t, int(*getvalue)(void *)){
    Tnode *valr,*vall;
    int maior,menor;
    if(t!=NULL){
        vall = retornaMenor(t->left);
        valr = retornaMaior(t->right);
        menor = getvalue(vall->data);
        maior = getvalue(valr->data);
        return maior - menor;
    }
}

