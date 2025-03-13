#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// exemplo professor
typedef struct _SlNode_{
    void *valor;
    struct _SlNode_ *proximo;
} SlNode;

typedef struct _SlLista_{
    SlNode *primeiro;
} SlLista;


int slInsert(SlLista *l, void *valor)
{
    SlNode *newnode;
    if (l != NULL)
    {
        newnode = (SlNode *)malloc(sizeof(SlNode));
        if (newnode != NULL)
        {
            newnode->valor = valor;         // newnode->valor = 10
            newnode->proximo = l->primeiro; // newnode->proximo = Null (vai ser null pois não vai ter nenhum elemento a frente dele)
            l->primeiro = newnode;          // agora o valor que estava em primeiro o qual estava apontando para NULL, vai apontar para o newNode(nova caixa de informações)
            return TRUE;
        }
    }
    return FALSE;
}

void imprimir(SlLista *l)
{
    if (l != NULL)
    {
        SlNode *atual = l->primeiro;
        while (atual != NULL)
        {
            printf("%d ", *(int *)atual->valor);
            atual = atual->proximo;
        }
    }
}

int sllRemoveBeforeLast(SlLista *l)
{
    SlNode *prev, *last;
    if (l != NULL && l->primeiro != NULL)
    {
        prev = NULL;
        last = l->primeiro;

        while (last->proximo != NULL)
        {
            prev = last;
            last = last->proximo;
        }

        if (prev == NULL)
        {
            l->primeiro = last->proximo;
        }
        else
        {
            prev->proximo = last->proximo;
        }
        free(last);
        return TRUE;
    }
    return FALSE;
}

int sllInsertAsSecond(SlLista *l, void *valor)
{
    SlNode *newnode, *aux, *second;
    if (l != NULL && l->primeiro != NULL)
    {
        newnode = (SlNode *)malloc(sizeof(SlNode));
        if (newnode != NULL)
        {
            newnode->valor = valor;
            aux = l->primeiro;
            if (aux->proximo == NULL)
            {
                aux->proximo = newnode;
                newnode->proximo = NULL;
            }
            else
            {
                second = aux->proximo;
                newnode->proximo = second;
                aux->proximo = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int intCompare(void *a, void *b) {
    int *elmA = (int *)a;
    int *elmB = (int *)b;
    if (*elmA == *elmB) {
        return TRUE;
    } else {
        return FALSE;
    }
}


void *sllQuery(SlLista *l, void *key, int (*cmp)(void *, void *))
{
    SlNode *atual;
    if (l != NULL && l->primeiro != NULL)
    {
        atual = l->primeiro;
        while (atual != NULL)
        {
            if (cmp(atual->valor, key) == 0)
            {
                return atual->valor;
            }
            atual = atual->proximo;
        }
    }
    return NULL;
}


int sllInsertBeforeSpec(SlLista *l, void *key, int (*cmp)(void *, void *),void *valor){
    SlNode *spec, *prev, *newnode;
    int stat;

    if (l != NULL && l->primeiro != NULL){
        spec = l->primeiro;
        prev = NULL;
        stat = cmp(spec->valor, key);

        while (spec!= NULL && stat != TRUE){
            prev = spec;
            spec = spec->proximo;
            stat = cmp(spec->valor, key);
        }

        if(stat == TRUE){
            newnode = (SlNode *)malloc(sizeof(SlNode));
            if(newnode!=NULL){
                newnode -> valor = valor;
                newnode->proximo = spec;
                if(prev!=NULL){
                    prev->proximo = newnode;
                }
                else{
                    l->primeiro = newnode;
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

int sllInsertAfterSpec(SlLista *l, void *key, int (*cmp)(void *, void *), void *valor){
    SlNode *newnode,*spec, *next;
    int achou;
    if(l!=NULL && l->primeiro !=NULL){
        spec = l->primeiro;
        achou = cmp(key,spec->valor);
        while(spec->proximo!=NULL && achou != TRUE){
            spec = spec->proximo;
            achou = cmp(key,spec->valor);
        }
        if(achou == TRUE){
            newnode = (SlNode *)malloc(sizeof(SlNode));
            if(newnode != NULL){
                newnode ->valor = valor;
                next = spec->proximo;
                spec->proximo = newnode;
                newnode->proximo = next;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *sllRemoveSpec(SlLista *l, void *key, int (*cmp)(void *, void *)){
    SlNode *prev,*spec;
    void *valor;
    int achou;
    if(l!=NULL && l->primeiro!=NULL){
        prev = NULL;
        spec = l->primeiro;
        achou = cmp(key,spec->valor);
        while(spec ->proximo !=NULL && achou !=TRUE){
            prev = spec;
            spec = spec->proximo;
            achou = cmp(key,spec->valor);
        }
        if(achou==TRUE){
            valor = spec->valor;
            if(spec==l->primeiro){
                l->primeiro = spec->proximo;
            }
            else{
                prev->proximo = spec->proximo;
            }
            free(spec);
            return valor;
        }
    }
    return NULL;
}


void *sllRemoveBeforeSpec(SlLista *l, void *key, int (*cmp)(void *, void *)){
    SlNode *spec,*prev, *beforePrev;
    void *valor;
    int achou;
    if(l!=NULL && l->primeiro != NULL){
        beforePrev = NULL;
        prev = NULL;
        spec = l->primeiro;
        achou = cmp(key, spec->valor);
        while(spec->proximo!=NULL && achou != TRUE){
            beforePrev = prev;
            prev = spec;
            spec = spec->proximo;
            achou = cmp(key, spec->valor);
        }
        if(achou == TRUE && beforePrev !=NULL){
            valor =  beforePrev->valor;
            if(beforePrev == l->primeiro){
                l->primeiro = prev;
            }else{
                prev->proximo = spec;
            }
            free(beforePrev);
            return valor;
        }
    }
    return NULL;
}

int retornaNosEmL2diferenteL1(SlLista *l1, SlLista *l2,int(*cmp)(void *,void *)){
    SlNode *cur1,*cur2;
    int stat,achou,no=0;
    if(l1!=NULL && l2!=NULL){
        if(l1->primeiro !=NULL && l2->primeiro!=NULL){
            cur2 = l2->primeiro;
            while(cur2!=NULL){
                achou = 0;
                cur1 = l1->primeiro;
                while(cur1!=NULL && achou==0){
                    stat = cmp(cur1->valor,cur2->valor);
                    if(stat == TRUE){
                        achou=1;
                    }
                    cur1 = cur1->proximo;
                }
                if(achou == 0){
                    no++;
                }
                cur2 = cur2->proximo;
            }
        }
    }
    return no;
}

int sllremoveIguais(SlLista *l1,int(*cmp)(void *,void *)){
    SlNode *prev,*cur,*aux;
    int stat;

    if(l1!=NULL){
        if(l1->primeiro!=NULL){
            aux = l1->primeiro;
            while(aux!=NULL){
                cur = aux->proximo;
                prev=aux;
                while(cur!=NULL){
                    stat = cmp(aux->valor,cur->valor);
                    if(stat==TRUE){
                        prev->proximo = cur->proximo;
                        free(cur);
                    }else{
                        prev=cur;
                    }
                    cur = prev->proximo;
                }
                aux= aux->proximo;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int retornaNosEmL1diferenteL2(SlLista *l1, SlLista *l2,int(*cmp)(void *,void *)){
    SlNode *cur1,*cur2;
    int stat,achou,no=0;
    if(l1!=NULL && l2!=NULL){
        if(l1->primeiro !=NULL && l2->primeiro!=NULL){
            sllremoveIguais(l1,intCompare);
            sllremoveIguais(l2,intCompare);
            cur1 = l1->primeiro;
            while(cur1!=NULL){
                achou = 0;
                cur2 = l2->primeiro;
                while(cur2!=NULL && achou==0){
                    stat = cmp(cur1->valor,cur2->valor);
                    if(stat == TRUE){
                        achou=1;
                    }
                    cur2 = cur2->proximo;
                }
                if(achou == 0){
                    no++;
                }
                cur1 = cur1->proximo;
            }
        }
    }
    return no;
}

int main() {
    SlLista lista1;
    SlLista lista2;
    lista1.primeiro = NULL;
    lista2.primeiro = NULL;

    int valores1[] = {2, 4, 9,5,2};
    int valores2[] = {3, 4, 1,8,8};
    int i;
    
    // Insere elementos na lista
    for (i = 0; i < 4; i++) {
        slInsert(&lista1, &valores1[i]);
    }
    for (i = 0; i < 4; i++) {
        slInsert(&lista2, &valores2[i]);
    }
    
    printf("1 lista:");
    imprimir(&lista1);
    printf("\n");
    printf("2 lista:");
    imprimir(&lista2);
    printf("\n");

    int n = retornaNosEmL1diferenteL2(&lista1,&lista2,intCompare);
    printf("%d ",n);
    return 0;
}
