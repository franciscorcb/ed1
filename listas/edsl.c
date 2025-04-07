#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _Slnode_{
    void *data;
    struct _Slnode_ *next;
}Slnode;

typedef struct _SlList_{
    Slnode *first;
}SlList;

int intCompare(void *a, void *b) {
    int *intA = (int *)a;
    int *intB = (int *)b;
    return (*intA == *intB);
}


int slInsert(SlList *l, void *valor){
    Slnode *newnode;
    if (l != NULL){
        newnode = (Slnode *)malloc(sizeof(Slnode));
        if (newnode != NULL){
            newnode->data = valor;         
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}


void imprimir(SlList *l){
    if (l != NULL){
        Slnode *spec = l->first;
        while (spec != NULL){
            printf("%d ", *(int *)spec->data);
            spec = spec->next;
        }
        printf("\n");
    }
}

void freeList(SlList *l) {
    if (l != NULL) {
        Slnode *current = l->first;
        Slnode *next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }

        l->first = NULL;
    }
}

int insertFirst(SlList *l,void *data){
    Slnode *newnode,*firstN;
    if(l!=NULL){
        newnode = (Slnode *)malloc(sizeof(Slnode));
        if(newnode!=NULL){
            newnode->data = data;
            firstN = l->first;
            l->first = newnode;
            if(firstN!=NULL){
                newnode->next = firstN;
            }else{
                newnode->next=NULL;
            }
            return TRUE;
        }
    }
    return FALSE;
}


int insertLast(SlList *l,void *data){
    Slnode *newnode, *last;
    if(l!=NULL){
        if(l->first!=NULL){
            newnode = (Slnode *)malloc(sizeof(Slnode));
            if(newnode!=NULL){
                newnode -> data = data;
                last = l->first;
                while(last->next!=NULL){
                    last = last->next;
                }
                last->next = newnode;
                newnode->next=NULL;
                return TRUE;
            }
        }
    }
    return FALSE;
}


int kInsert(SlList *l,int n, int *data){
    Slnode *newnode,*spec,*prev;
    int quant=1;
    int stat = FALSE;
    if(l != NULL && n>=1){
        if(l->first!=NULL){
            newnode = (Slnode *)malloc(sizeof(Slnode));
            if(newnode!=NULL){
                newnode->data = data;
                spec = l->first;
                prev = NULL;
    
                if(n==1){
                    newnode->next = l->first;
                    l->first = newnode;
                    return TRUE;
                }
    
                while(spec->next!=NULL && quant<n){
                    prev = spec;
                    spec = spec->next;
                    quant++;
                }
    
                if(quant==n){
                    newnode->next = spec;
                    if(prev!=NULL){
                        prev->next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int insertAfterSpec(SlList *l, void *key,void *data, int(*cmp)(void*,void*)){
    Slnode *newnode,*spec,*next; 
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            newnode = (Slnode *)malloc(sizeof(Slnode));
            if(newnode!=NULL){
                newnode->data = data;
                spec = l->first;
                stat = cmp(key,spec->data);
                while(spec->next!=NULL && stat != TRUE){
                    spec = spec->next;
                    stat = cmp(key,spec->data);
                }
                if(stat==TRUE){
                    next = spec->next;
                    if(next!=NULL){
                        spec->next= newnode;
                        newnode->next = next;
                    }else{
                        newnode->next = NULL;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int insertBeforeSpec(SlList *l, void *key,void *data, int(*cmp)(void*,void*)){
    Slnode *newnode, *prev, *spec;
    int stat;
    if(l!=NULL){
        newnode = (Slnode *)malloc(sizeof(Slnode));
        if(newnode!=NULL){
            prev = NULL;
            newnode->data = data;
            spec=l->first;
            stat = cmp(key,spec->data);
            while(spec->next !=NULL && stat!=TRUE){
                prev = spec;
                spec = spec->next;
                stat = cmp(key,spec->data);
            }
            if(stat==TRUE){
                newnode->next = spec;
                if(prev!=NULL){
                    prev->next = newnode;
                }else{
                    l->first = newnode;
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}
int insertInorderedList(SlList *l, void *data, int (*cmp)(void*, void*)) {
    Slnode *newnode, *spec, *prev;
    int stat;
    
    if (l != NULL) {
        newnode = (Slnode *)malloc(sizeof(Slnode));
        if (newnode != NULL) {
            newnode->data = data;
            prev = NULL;
            spec = l->first;

            if (spec == NULL) {
                newnode->next = NULL;
                l->first = newnode;
                return TRUE;
            }

            stat = cmp(data, spec->data);

            while (stat > 0 && spec->next != NULL) {
                prev = spec;
                spec = spec->next;
                stat = cmp(data, spec->data);
            }

            if (stat < 0) { 
                newnode->next = spec;
                if (prev != NULL) {
                    prev->next = newnode;
                } else {
                    l->first = newnode;
                }
            } else {
                newnode->next = spec->next;
                spec->next = newnode;
            }

            return TRUE;
        }
    }
    return FALSE;
}

void *removeFirst(SlList *l){
    Slnode *first;
    void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            first= l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}

void *sllRemoveLast(SlList *l){
    Slnode *last,*prev;
    void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            prev = NULL;
            last = l->first;
            while(last->next!=NULL){
                prev = last;
                last= last->next;
            }
            data = last->data;

            if(prev!=NULL){
                prev->next = NULL;
            }
            else{
                l->first = NULL;
            }
            free(last);
            return data;
        }
    }
    return NULL;
}


void *sllRemoveKposicao(SlList *l, int k){
    Slnode *spec,*prev,*next;
    void *data;
    int quantValores=1;

    if(l!=NULL){
        if(l->first!=NULL){
            prev = NULL;
            spec = l->first;
            next = spec->next;

            while(spec->next!=NULL && quantValores<k){
                prev = spec;
                spec =  spec->next;
                quantValores++;
            }

            if(quantValores==k && spec != NULL){
                data = spec->data;
                if(spec==l->first){
                    l->first = spec->next;
                }
                else{
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}


void *removeAfterSpec(SlList *l,void *key,int(*cmp)(void*, void*)){
    Slnode *spec,*next;
    int stat;
    void *data;
    if(l!=NULL){
        if(l->first!=NULL){

            spec = l->first;
            next = spec ->next;
            stat = cmp(key,spec->data);

            while(stat!=TRUE && spec->next!=NULL){
                spec = spec->next;
                next = spec->next;
                stat = cmp(key,spec->data);
            }

            if(stat == TRUE && next!=NULL){
                data = next->data;
                if(next->next!=NULL){
                    spec->next = next->next;
                }
                else{
                    spec->next = NULL;
                }
                free(next);
                return data;
            }
        }
    }
    return NULL;
}


void *removeBeforeSpec(SlList *l,void *key,int(*cmp)(void*,void*)){
    Slnode *spec,*prev,*beforePrev;
    void *data;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            beforePrev = NULL;
            prev = NULL;
            spec = l->first;
            stat = cmp(key,spec->data);
            while(spec !=NULL && stat != TRUE){
                beforePrev = prev;
                prev = spec;
                spec=spec->next;
                stat = cmp(key,spec->data);
            }
            if(stat==TRUE && prev !=NULL){
                data = spec->data;
                if(beforePrev!=NULL){
                    beforePrev->next = spec;
                }else{
                    l->first = spec;
                }
                free(prev);
                return data;
            }
        }
    }
    return NULL;
}


int concatenaListas(SlList *l1, SlList *l2){
    Slnode *lastL1;
    if(l1!=NULL && l2!=NULL){
        if(l1->first!=NULL && l2->first !=NULL){
            lastL1 = l1->first;
            while(lastL1->next !=NULL){
                lastL1= lastL1->next;
            }
            lastL1->next = l2->first;
            return TRUE;
        }
    }
    return FALSE;
}

int liberaNos(SlList *l){
    Slnode *spec,*next;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            while(spec!=NULL){
                next = spec->next;
                free(spec);
                spec = next;
            }
            l->first = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

int inverteLista(SlList *l){
    Slnode *prev, *spec, *next;
    if(l!=NULL){
        if(l->first!=NULL){
            prev = NULL;
            spec = l->first;
            while(spec!=NULL){
                next = spec->next;
                spec->next = prev;
                prev = spec;
                spec = next;
            }
            l->first = prev;
            return TRUE;
        }
    }
    return FALSE;
}


int interseccaoDeListas(SlList *l1,SlList *l2){
    Slnode *spec1,*spec2,*next1,*next2;
    if(l1!=NULL && l2!=NULL){
        if(l1->first!=NULL && l2->first!=NULL){
            spec1 = l1->first;
            spec2 = l2->first;
            while(spec1!=NULL && spec2 !=NULL){
                next1 = spec1->next;
                next2 = spec2->next;
                spec1->next = spec2;
                if(next1!=NULL){
                    spec2->next = next1;
                }
                spec1 = next1;
                spec2 = next2;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int retornaTamanho(SlList *l1){
    int tam=0;
    Slnode *spec;
    if(l1!=NULL){
        spec=l1->first;
        while(spec !=NULL){
            tam++;
            spec = spec->next;
        }
    }
    return tam;
}

int inSub(SlList *l1,SlList *l2,int i1,int i2, int len){
    int tamL1 = retornaTamanho(l1);
    int tamL2= retornaTamanho(l2);

    Slnode *spec1,*spec2,*prevL1,*prevL2;
    int tam1,tam2;

    if(l1!=NULL && l2!=NULL){
        if(i1>(tamL1+1) || (i2 + len -1) > tamL2 || i1<1 || i2<1){
            return FALSE;
        }
        else{
            spec1 = l1->first;
            spec2 = l2->first;
            prevL1 = NULL;
            prevL2 = NULL;

            while (tam1 < i1-1 && spec1 != NULL) {
                prevL1 = spec1;
                spec1 = spec1->next;
                tam1++;
            }

            while (tam2 < i2-1 && spec2 != NULL) {
                prevL2 = spec2;
                spec2 = spec2->next;
                tam2++;
            }

            if(spec2!=NULL){
                for(int i=0;i<len;i++){
                    Slnode *newnode = spec2;
                    spec2 = spec2->next;
                    if(prevL1==NULL){
                        newnode->next = l1->first;
                        l1->first = newnode;
                    }
                    else{
                        newnode->next = prevL1->next;
                        prevL1->next = newnode;
                    }

                    if(prevL2==NULL){
                        l2->first = spec2;
                    }
                    else{
                        prevL2->next = spec2;
                    }
                    prevL1= newnode;
                }
            }
            else{
                return FALSE;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int main() {
    SlList lista1;
    lista1.first = NULL;

    SlList lista2;
    lista2.first = NULL;


    int valores1[] = {4,3,2,1};
    int valores2[] = {8,7,6,5};
    int i;
    int tam1 = sizeof(valores1)/sizeof(int);
    int tam2 = sizeof(valores2)/sizeof(int);
    
    for (i = 0; i < tam1; i++) {
        slInsert(&lista1, &valores1[i]);
    }

    for (i = 0; i < tam2; i++) {
        slInsert(&lista2, &valores2[i]);
    }
    
    printf("1 lista:\n");
    imprimir(&lista1);

    printf("2 lista:\n");
    imprimir(&lista2);

    inSub(&lista1,&lista2,4,1,3);

    printf("Nova Lista\n");
    imprimir(&lista1);
    imprimir(&lista2);
    freeList(&lista1);
    freeList(&lista2);
    return 0;
}
