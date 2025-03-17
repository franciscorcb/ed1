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

Tnode *removeMaior(Tnode *t){
    Tnode *aux;
    if(t!=NULL){
        if(t->right!=NULL){
            t->right = removeMaior(t->right);
            return t;
        }
        else{
            aux = t->left;
            free(t);
            return aux;
        }
    }
    return NULL;
}


Tnode *removerNosFolhas(Tnode *t){
    if(t!=NULL){
        t->left = removerNosFolhas(t->left);
        t->right = removerNosFolhas(t->right);
        if(t->right==NULL && t->left==NULL){
            free(t);
            return NULL;
        }
    }
    return t;
}


//Metodo 1, sem a função de remover Maior
Tnode *removerPorChave(Tnode *t,int key,int(*cmp)(void*,void*)){
    int stat;
    Tnode *aux;
    if(t!=NULL){
        stat = cmp(t->data,key);
        if(stat<0){
            t->left = removerPorChave(t->left,key,cmp);
            return t;
        }else if(stat>0){
            t->right = removerPorChave(t->right,key,cmp);
        }
        else{
            if(t->right==NULL && t->left==NULL){
                free(t);
                return NULL;
            }
            else if(t->right!=NULL && t->left!=NULL){
                aux = t->left;
                while(aux->right!=NULL){
                    aux = aux->right;
                }
                t->data = aux->data;
                aux->data = key;
                t->left = removerPorChave(t->left,key,cmp);
                return t;
            }
            else{
                if(t->right!=NULL){
                    aux = t->right;
                }else{
                    aux = t->left;
                }
                free(t);
                return aux;
            }
        }
    }
}


//metodo 2 com a função de remover maior
Tnode *removerKey(Tnode *t, int key,int(*cmp)(void*,void*)){
    int stat;
    Tnode *aux;
    if(t!=NULL){
        stat = cmp(t->data,key);
        if(stat<0){
            t->left = removerKey(t->left,key,cmp);
            return t;
        }
        else if(stat>0){
            t->right = removerKey(t->right,key,cmp);
            return t;
        }
        else{
            if(t->right==NULL && t->left==NULL){
                free(t);
                return NULL;
            }
            else if(t->right!=NULL && t->left!=NULL){
                aux = t->left;
                while(aux->right!=NULL){
                    aux = aux->right;
                }
                t->data = aux->data;
                t->left = removeMaior(t->left);
                return t;

            }else{
                if(t->right!=NULL){
                    aux = t->right;
                }
                else{
                    aux = t->left;
                }
                free(t);
                return aux;
            }
        }
    }
    return NULL;
}


Tnode *removerNosDeGrau1(Tnode *t){
    Tnode *aux;
    if(t!=NULL){
        t->left = removerNosDeGrau1(t->left);
        t->right = removerNosDeGrau1(t->right);

        if(t->right!=NULL && t->left==NULL){
            aux = t->right;
            free(t);
            return aux;
        }
        if(t->left!=NULL && t->right==NULL){
            aux = t->left;
            free(t);
            return aux;
        }
        return t;
    }
    return NULL;
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

    return 0;
}
