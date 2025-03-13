#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _Dlnode_{
    void *data;
    struct _Dlnode_ *next;
    struct _Dlnode_ *prev
}Dlnode;

typedef struct _DlList_{
    Dlnode *first;
    Dlnode *cur;

}DlList;

int dllInsertAsFirst(DlList *l,void *data){
    Dlnode *newnode;
    if(l!=NULL){
        newnode = (DlList *)malloc(sizeof(DlList));
        if(newnode!=NULL){
            newnode ->data = data;
            newnode->next = l->first;
            newnode->prev = NULL;
            if(l->first !=NULL){
                l->first->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int dllAfterSpec(DlList *l,void *key,void *data,int(*cmp)(void*,void*)){
    Dlnode *newnode,*spec,*next;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            stat = cmp(spec->data,key);
            while(spec->next!=NULL && stat!=TRUE){
                spec =spec->next;
                stat = cmp(key,spec->data);
            }
            if(stat== TRUE){
                newnode = (Dlnode *)malloc(sizeof(Dlnode));
                if(newnode!=NULL){

                    next = spec->next;
                    newnode->data = data;
                    newnode->prev = spec;
                    newnode->next = next;

                    if(next!=NULL){
                        next->prev = newnode;
                    }
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int removeOcaraEOsVizinhos(DlList *l, void *key,int(*cmp)(void*,void*)){
    Dlnode *spec,*prev,*next,*beforePrev;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            next = spec->prev;
            prev = spec->next;
            stat = cmp(spec->data,key);
            while(spec->next !=l->first){
                spec = spec->next;
                next= spec->prev;
                prev = spec->next;
                stat = cmp(spec->data,key);
            }

            if(stat==TRUE && next->next!=NULL){
                if(prev!=NULL){
                    beforePrev = prev->prev;
                    beforePrev->next = next->next;
                    next->next->prev = beforePrev;
                }
                else{
                    l->first = next->next;
                    next->next->prev = l->first;
                }
                free(beforePrev);
                free(spec);
                free(next);
                return TRUE;
            }
        }
    }
    return FALSE;
}
