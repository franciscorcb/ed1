#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//1 PROVA

/*
// 1 Calcula uma nova matriz a ser armazenada no vetor que corresponde a multiplicação da transposta da v2

int multiplicaMatrizes(int *v1,int *v2,int *v3,int n){
    if(v1!=NULL && v2!=NULL && v3!=NULL && n>0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v3[i*n+j]=0;
                for(int k=0;k<n;k++){
                    v3[i*n+j]= v1[i*n+k]*v2[j*n+k];
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}*/

//2
/*

void RemoveElementosPares(Queue *q){
    if(q != NULL && q->nElms > 0){
        int count = q->nElms;
        int i = q->front;
        int rear = -1;

        for(int j = 0; j < count; j++){
            int *val = (int *)q->item[i];
            if(*val % 2 != 0){ 
                rear = qcInCir(rear, q->maxItens);
                q->item[rear] = q->item[i];
            } else {
                free(q->item[i]);
            }
            i = qcInCir(i, q->maxItens);
        }
        q->front = 0;

        if (rear == -1) {
            q->nElms = 0;
        } else {
            q->rear = rear;
            q->nElms = rear + 1;
        }
    }
}
*/

//3
/*


int RemoveMaioresQueKey(Stack *s, void *key, int (*cmp)(void *, void *)) {
    int i, next, newRear;
    int stat;

    if (s != NULL && s->nElms > 0) {
        i = s->front;
        newRear = s->front;

        while (i != s->rear) {
            next = qcInCir(i, s->maxItens);
            stat = cmp(key, s->item[i]);

            if (!stat) {  
                s->item[newRear] = s->item[i];
                newRear = qcInCir(newRear, s->maxItens);
            } else {
                s->nElms--;  
            }

            i = next;
        }

        stat = cmp(key, s->item[i]);
        if (!stat) { 
            s->item[newRear] = s->item[i];
            newRear = qcInCir(newRear, s->maxItens);
        } else {
            s->nElms--;
        }

        s->rear = qcDecCirc(newRear, s->maxItens);
        return 1;
    }
    return 0;
}*/

/*
int verificaString(Stack *s1,char *s2,int lenght){
    char *sout;
    int stat;
    char *p;
    if(s1!=NULL){
        sout = stkCreat(lenght);
        if(sout!=NULL){
            sout = (char *)malloc(sizeof(char )*lenght);
            int i=0;
            int j=0;
            while(s2[i]!='\0'){
                while (s2[i]!=' '){
                    stkpush(sout,(void *)(&(s2[i])));
                    i++;
                }
                for(int j=0;j<i;j++){
                    p = (char *)stkpop(sout);
                    sout[j] = *p;
                }
            }
        }
    }
}*/

//2 Prova

int removeImpares(Queue *q){
    int cur, next, i;
    int *verf;
    if(q!=NULL){
        i=0;
        while(i<q->numElm){
            verf = (int *)q->elm[i];
            if(*verf %2 != 0){
                cur = q->front;
                while(cur != q->rear){
                    next = qcInc(cur,q->maxItens);
                    q->elm[cur]=q->elm[next];
                    cur =next;
                }
                q->rear = qcDec(q->rear,q->maxItens);
                q->numElms--;
            }
            else{
                i++;
                cur = qcInc(cur, q->maxItens);
            }
        }
        return true;
    }
    return false;
}