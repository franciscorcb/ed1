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

int intCompare(void *a, void *b) {
    int *intA = (int *)a;
    int *intB = (int *)b;
    return *intA - *intB;
}

void preordem(Tnode *t,void(*visit)(void *)){
    if(t!=NULL){
        visit(t->data);
        preordem(t->left,visit);
        preordem(t->right,visit);
    }
}

void posordem(Tnode *t,void(*visit)(void *)){
    if(t!=NULL){
        posordem(t->left,visit);
        posordem(t->right,visit);
        visit(t->data);
    }
}

void simetrico(Tnode *t,void(*visit)(void *)){
    if(t!=NULL){
        simetrico(t->left,visit);
        visit(t->data);
        simetrico(t->right,visit);
    }
}

int *query(Tnode *t,void *key,int(*cmp)(void*,void*)){
    if(t!=NULL){
        int stat = cmp(t->data,key);
        if(stat==0){
            return t->data;
        }
        else if(stat<0){
            return query(t->left,key,cmp);

        }else{
            return query(t->right,key,cmp);
        }
    }
    return NULL;
}

Tnode *insert(Tnode *t,void *data,int(*cmp)(void*,void*)){
    if(t!=NULL){
        int stat = cmp(data,t->data);
        if(stat<0){
            t->left = insert(t->left,data,cmp);
        }
        else{
            t->right = insert(t->right,data,cmp);
        }
        return t;
    }
    else{
        Tnode* newnode;
        newnode = (Tnode*)malloc(sizeof(Tnode));
        if(newnode !=NULL){
            newnode->data = data;
            newnode->left = newnode->right = NULL;
            return newnode;
        }
        return NULL;
    }
}

// calcular a altura de uma arvore binaria

int calculaAltura(Tnode *t){
    int l,r;
    if(t!=NULL){
        l = calculaAltura(t->left);
        r = calculaAltura(t->right);

        if(l<r){
            return r+1;
        }
        else{
            return l+1;
        }
    }
    return -1;   
}

void imprimir(Tnode *t){
    if(t!=NULL){
        printf("%d ",*(int *)t->data);
        imprimir(t->left);
        imprimir(t->right);
    }

}

void imprimirSimetrico(Tnode *t){
    if(t!=NULL){
        imprimirSimetrico(t->left);
        printf("%d ",*(int *)t->data);
        imprimirSimetrico(t->right);
    }

}

int retornaQtdsNos(Tnode *t){
    if(t!=NULL){
        return 1 + retornaQtdsNos(t->left) + retornaQtdsNos(t->right);
    }
}

// Segunda forma:

int contaNumNos(Tnode *t){
    int n, nl,nr;
    if(t!=NULL){
        nl = contaNumNos(t->left);
        n= 1;
        nr = contaNumNos(t->right);
        return n + nl + nr;
        
    }
    return 0;
}

int retornaQtdsFolhas(Tnode *t){
    int nl, nr, n;
    if(t!=NULL){
        nl = retornaQtdsFolhas(t->left);
        if(t->left==NULL && t->right==NULL){
            n=1;
        }else{
            n=0;
        }
        nr = retornaQtdsFolhas(t->right);
        return n+nl+nr;
    }
    return 0;
}

int retornaQtdsNosComFilhos(Tnode *t){
    if(t!=NULL){
        if(t->left==NULL && t->right==NULL){
            return 0;
        }
        else{
            return 1 + retornaQtdsFolhas(t->left) + retornaQtdsFolhas(t->right);
        }
    }
    return 0;
}

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

int retornaAltura(Tnode *t){
    int r,l;
    if(t!=NULL){
        r = retornaAltura(t->right);
        l= retornaAltura(t->left);

        if(l<r){
            return l+1;
        }
        else{
            return r+1;;
        }
        return -1;
    }
}

int contaNoComGrau1(Tnode *t){
    int nr,nl,n;
    if(t!=NULL){
        nr = contaNoComGrau1(t->right);
        nl = contaNoComGrau1(t->left);

        if(t->right!=NULL && t->left==NULL){
            n=1;
        }
        else if(t->left!=NULL && t->right==NULL){
            n=1;
        }
        else{
            n=0;
        }
        return n+nr+nl;
    }
    return 0;
}

int contaNumGrau2(Tnode *t){
    int n,nr,nl;
    if(t!=NULL){
        nl = contaNumGrau2(t->left);
        nr = contaNumGrau2(t->right);

        if(t->left!=NULL && t->right!=NULL){
            n=1;
        }
        else{
            n=0;
        }
        return n+nl+nr;
    }
    return 0;
}


float somaNos(Tnode *t, float(*getdata)(void*)){
    float sumr, suml, sum;
    if(t!=NULL){

        sum = getdata(t->data);
        suml=somaNos(t->left,getdata);
        sumr=somaNos(t->right,getdata);
        return suml + sumr;
    }
    return 0;
}


int abpEspelhadas(Tnode *t1, Tnode *t2, int(*cmp)(void*,void*)){
    int stat1,stat2,stat3;
    if(t1!=NULL && t2!=NULL){
        stat1 = cmp(t1->data,t2->data);
        stat2 = abpEspelhadas(t1->left,t2->right,cmp);
        stat3 = abpEspelhadas(t1->right,t2->left,cmp);

        return stat1 && stat2 && stat3;
    }
    else{
        if(t1==NULL && t2==NULL){
            return TRUE;
        }
    }
    return FALSE;
}

int contaNoPorNivel(Tnode *t,int n , int level){
    int hr,hl,nos_root=0;
    if(t!=NULL){
        hr = contaNoPorNivel(t->right,n,level+1);
        hl = contaNoPorNivel(t->left,n, level+1);

        if(level==n){
            nos_root =1;
        }

        return hr+hl+nos_root;

    }
    return 0;
}

int abContaNoComAlturaMenorQh(Tnode *t,int n,int level){
    int nr,nl,n_root =0;
    if(t!=NULL){
        nl = abContaNoComAlturaMenorQh(t->left,n,level+1);
        nr = abContaNoComAlturaMenorQh(t->right,n,level+1);

        if(level<n){
            n_root=1;
        }
        return nr+nl+n_root;
    }
}

int abContaNoComAlturaMaiorQh(Tnode *t, int n, int level){
    int nr,nl,n_root =0;
    if(t!=NULL){
        nr = abContaNoComAlturaMaiorQh(t->right,n,level+1);
        nl = abContaNoComAlturaMaiorQh(t->left,n,level+1);

        if(level>n){
            n_root=1;
        }
        return nr+nl+n_root;
    }
    return 0;
}

// int abNumNosMenorQueH(Tnode *t, int h){
//     if (t != NULL && h>0){
//         return 1 + abNumNosMenorQueH(t->left,h - 1) + abNumNosMenorQueH(t->right, h - 1);
//     }
//     return 0;
// }

int abNumNosMenorQueH(Tnode *t, int h){
    int nl,nr,n;
    if (t != NULL){
        nl = abNumNosMenorQueH(t->left,h - 1);
        nr = abNumNosMenorQueH(t->right, h - 1);
        if(h > 0) {
            n=1;
        }
        else{
            n=0;
        }
        return n+nl+nr;
    }
    return 0;
}

// -------------------------------- Provas --------------------------------

//-------------------------------------------------------------------2017.1

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


//-------------------------------------------------------------------2023.1

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

//-------------------------------------------------------------------2023.2

//1 - remover o maior da arvore
int abRetornaSomaAb(Tnode *t,int(*getvalue)(void*)){
    int nr,nl,n;
    if(t!=NULL){
        n = getvalue(t->data);
        nl = abRetornaSomaAb(t->left,getvalue);
        nr = abRetornaSomaAb(t->right,getvalue);
        return n+nl+nr;
    }
    return FALSE;
}


//2- verifica se duas arvores são topologicamente iguais
int comparaArvs(Tnode *t1, Tnode *t2){
    int spec1,spec2;
    if(t1!=NULL && t2!=NULL){
        spec1 = comparaArvs(t1->left,t2->left);
        spec2 = comparaArvs(t1->right,t2->right);
        return spec1 && spec2;
    }
    else{
        if(t1==NULL && t2==NULL){
            return TRUE;
        }
        
    }
    return FALSE;
}


//3 - Remover o menor elemento de uma arvore

Tnode *abpRemoveMenor(Tnode *t, int(*cmp)(void*,void*)){
    Tnode *aux;
    if(t!=NULL){
        if(t->left!=NULL){
            t->left = abpRemoveMenor(t->left,cmp);
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


//-------------------------------------------------------------------2024.1(a)

//1-Retorna a maior diferença entre dois de duas arvores topologicamente iguais
int diferencaNosCorrespondentes(Tnode *t1,Tnode *t2, int(*getvalue)(void*)){
    int maior, difatual,spec1,spec2,difL,difR;

    if(t1!=NULL && t2!=NULL){
        
        spec1 = getvalue(t1->data);
        spec2 = getvalue(t2->data);
        difatual = spec1-spec2;

        difL - diferencaNosCorrespondentes(t1->left,t2->left,getvalue);
        difR = diferencaNosCorrespondentes(t1->right,t2->right,getvalue);

        maior = difatual;

        if(difL>maior){
            maior = difL;
        }
        if(difR>maior){
            maior= difR;
        }
        return maior;
    }
    return 0;
}


//2-Retorna o numero de nos que estão na posição h
int abNUmNosIgualH(Tnode *t,int h){
    int n,nr,nl;
    if(t!=NULL){
        nl = abNumNosAlturah(t->left,h-1);
        nr = abNumNosAlturah(t->right,h-1);
        if(h==0){
            n=1;
        }
        else{
            n=0;
        }
        return n+nr+nl;
    }
}


//3-Conta o numero de nos que não tem filhos
int contaNUmNoGrau0(Tnode *t){
    int n,nr,nl;
    if(t!=NULL){
        nr = contaNUmNoGrau0(t->right);
        nl = contaNUmNoGrau0(t->left);
        if(t->left==NULL && t->right==NULL){
            n=1;
        }
        else{
            n=0;
        }
        return n+nr+nl;
    }
    return 0;
}

//-------------------------------------------------------------------2024.1(b)

//1 menor diferenca entre nos correspondentes
int menorDiferencaNosCorresp(Tnode*t1,Tnode *t2,int(*getvalue)(void*)){
    int spec1,spec2,menor,noR,noL,difAtual;
    if(t1!=NULL && t2!=NULL){
        spec1 = getvalue(t1->data);
        spec2 = getvalue(t2->data);
        
        difAtual = spec1 - spec2;
        menor = difAtual;

        noL = menorDiferencaNosCorresp(t1->left,t2->left,getvalue);
        noR = menorDiferencaNosCorresp(t1->right,t2->right,getvalue);

        if(noL<menor){
            menor = noL;
        }
        if(noR<menor){
            menor = noR;
        }
        return menor;
    }
    return 0;
}

//2 numero de nos maiores que H
int abNumNosMaiorQh(Tnode *t,int h){
    int noR,noL,n;
    if(t!=NULL){
        noL = abNumNosMaiorQh(t->left,h-1);
        noR = abNumNosMaiorQh(t->right,h-1);
        if(h<0){
            n=1;
        }
        else{
            n=0;
        }
        return n+noL+noR;
    }
    return 0;
}

//Calcular a quantidade de numeros com dois filhos
int abCalcNumNosGrau2(Tnode*t){
    int n, nr,nl;
    if(t!=NULL){
        nl = abCalcNumNosGrau2(t->left);
        nr = abCalcNumNosGrau2(t->right);

        if(t->left!=NULL && t->right!=NULL){
            n=1;
        }
        else{
            n=0;
        }
        return n+nr+nl;
    }
    return 0;
}

//-------------------------------------------------------------------2024.1(c)

//1
int nosIguaisCorrespondentes(Tnode *t1,Tnode *t2,int(*getvalue)(void*)){
    int spec1,spec2,cont,nr,nl;

    if(t1!=NULL && t2!=NULL){

        nr = getvalue(t1->data);
        nl = getvalue(t2->data);

        if(nr==nl){
            cont=1;
        }
        else{
            cont=0;
        }
        spec1 = nosIguaisCorrespondentes(t1->left,t2->left,getvalue);
        spec2 = nosIguaisCorrespondentes(t1->right,t2->right,getvalue);

        return spec1+spec2+cont;

    }
    else{
        if(t1==NULL && t2==NULL){
            return 0;
        }
    }
    return 0;
}

//2 
int abNumNosMenorQh(Tnode *t,int h){
    int n, nr,nl;
    if(t!=NULL && h>0){
        nl = abNumNosMenorQh(t->left,h-1);
        nr = abNumNosMenorQh(t->right,h-1);
        if(h>0){
            n=1;
        }else{
            n=0;
        }
        return n+nr+nl;
    }
    return 0;
}

//3
int abCalcNumNosGrau1(Tnode *t){
    int n,nr,nl;
    if(t!=NULL){
        nl = abCalcNumNosGrau1(t->left);
        nr = abCalcNumNosGrau1(t->right);
        if(t->left!=NULL && t->right==NULL){
            n=1;
        }
        else if(t->right!=NULL && t->left==NULL){
            n=1;
        }
        else{
            n=0;
        }
        return nl+nr+n;
    }
    return 0;
}

//-------------------------------------------------------------------20xx

//1) resposta acima


//2)Compara se a soma de uma arvore é maior que a outra
int retornaSomaNos(Tnode *t,int(*getvalue)(void*)){
    int nl,nr,soma;
    if(t!=NULL){
        soma = getvalue(t->data);
        nl = retornaSomaNos(t->left,getvalue);
        nr = retornaSomaNos(t->right,getvalue);
        return soma+nl+nr;
    }
    return 0;
}

int comparaSomaArvores(Tnode *t1,Tnode*t2){
    int resultT1,resultT2;
    if(t1!=NULL && t2!=NULL){
        resultT1 = retornaSomaNos(t1,getvalue);
        resultT2 = retornaSomaNos(t2,getvalue);
        if(resultT1>resultT2){
            return 0;
        }
    }
    return -1;
}

//3)Calcula altura de uma arvore binaria
int calAlturaArvBinaria(Tnode*t){
    int r,l;
    if(t!=NULL){
        l = calAlturaArvBinaria(t->left);
        r = calAlturaArvBinaria(t->right);

        if(l>r){
            return l+1;
        }
        else{
            return r+1;
        }
    }
    return -1;
}


int main(){
    Tnode *arv = NULL;
    Tnode *arv2 = NULL;
    int soma;
    int num[] =  {800,400,900,80,450,850,920,40,420,478,880,960};
    int tam = sizeof(num)/sizeof(int);

    for(int i =0; i<tam;i++){
        soma += num[i];
        arv = insert(arv,&num[i],intCompare);
        
    }

    int num2[] = {49,23,99,34,71,20,18,110,116,117,113};
    int tam2 = sizeof(num2)/sizeof(int);
    for(int i =0; i<tam2;i++){
       arv2 = insert(arv2,&num2[i],intCompare);
    }

    printf("-----Arvore 1-----\n");
    printf("Pre-ordem:\n");
    imprimir(arv);

    printf("\nSimetrico:\n");
    imprimirSimetrico(arv);
    printf("\n");

    int somaArv = retornaSomaNos(arv,getvalue);
    int compArv = comparaSomaArvores(arv,arv2);
    printf("%d\n",soma);
    printf("%d\n",somaArv);
    printf("%d\n",compArv);


    /*Tnode *arv2 = NULL;
    int num2[] = {49,23,99,34,71,20,18,110,116,117,113};
    int tam2 = sizeof(num2)/sizeof(int);
    for(int i =0; i<tam2;i++){
       arv2 = insert(arv2,&num2[i],intCompare);
    }
    printf("\n-----Arvore 2-----\n");
    printf("Pre- ordem:\n");
    imprimir(arv2);

    printf("\nSimetrico:\n");
    imprimirSimetrico(arv2);
    

    int comparaArvs = comparaArvores(arv,arv2,getvalue);

    printf("\n%d",comparaArvs);
    Tnode *maior = retornaMaior(arv);
    Tnode *menor = retornaMenor(arv);

    int altura = calculaAltura(arv);
    int folha = retornaQtdsFolhas(arv);
    int no = contaNumNos(arv);
    int noCom1Filho = contaNoComGrau1(arv);
    int noCom1Filho2 = calcNumNoGrau1(arv);
    int noLevel = contaNoPorNivel(arv,2,0);
    int menorQh = abNumNosMenorQueH(arv,2);

    int numNosAlturaH = abNumNosAlturah(arv,2);

    int diferenca = abpCalculaDiferencaMaiorParaMenor(arv,getvalue);*/

    /*printf("Maior: %d\n",*(int *)maior->data);
    printf("Menor: %d\n",*(int *)menor->data);
    printf("\nQtds de nos com 1 filho: %d\n",noCom1Filho );
    printf("Qtds de nos com 1 filho: %d\n",noCom1Filho2 );
    printf("Qtds de nos: %d\n",no );
    printf("Qtds de folhas: %d\n",folha );
    printf("Altura : %d\n",altura);
    printf("No nivel 2 existem %d no(s)\n",noLevel);
    printf("No nivel 2 existem %d no(s)\n",numNosAlturaH);
    printf("Existem %d nos que estao em uma altura abaixo de 2\n",menorQh);
    printf("Diferenca: %d",diferenca);
    int soma = abRetornaSomaAb(arv,getvalue);
    printf("%d\n",soma);
    int compara = comparaArvs(arv,arv2);
    printf("%d",compara);
    arv = abpRemoveMenor(arv,intCompare);
    int noLevel = contaNoPorNivel(arv,3,0);
    int nivel = abNumNosAlturah(arv,3);
    printf("No nivel 2 existem %d no(s)\n",noLevel);
    printf("No nivel 2 existem %d no(s)\n",nivel);
    int noGrau0 = contaNUmNoGrau0(arv);
    printf("\n%d",noGrau0);
    int maiorQh = abContaNoComAlturaMaiorQh(arv,0,0);
    int maior = abNumNosMaiorQh(arv,0);
    printf("Existem %d nos que estao em uma altura acima de 3\n",maiorQh);
    printf("Existem %d nos que estao em uma altura acima de 3\n",maior);
    int iguais = nosIguaisCorrespondentes(arv,arv2,getvalue);
    printf("%d",iguais);
    int menorQh = abNumNosMenorQh(arv,3);
    printf("%d",menorQh);
    int nosGrau1 = abCalcNumNosGrau1(arv);
    printf("%d",nosGrau1);*/

    return 0;
}