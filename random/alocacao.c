#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define FALSE -1
#define TRUE -1

/*//alocação de memoria pelo metodo tradicional
int main(){
    int **mat,l,c;
    l=4;
    c=3;
    mat = (int **)malloc(sizeof(int *)*l);
    if(mat!=NULL){
        for(int i=0;i<l;i++){
            mat[i]= (int *)malloc(sizeof(int )*c);
            if(mat[i]==NULL){
                return -1;
            }
            
        }
        int cont=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<c;j++){
                mat[i][j]=cont;
                printf("%i ",mat[i][j]);
                cont++;
            }
        }
        for(int i=0;i<l;i++){
            free(mat[i]);
        }
        free(mat);
    }
    else{
        return -1;
    }
    return 0;
}*/



//alocação de memoria em funções


/*
int imprimir(int **mat, int m, int n){
    if(mat!=NULL && m>0 && n>0){
        for(int i=0;i<m;i++){
            if(mat[i]==NULL){
                return -1;
            }
        }
        int cont=0;
        int soma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=cont;
                printf("%i  ", mat[i][j]);
                soma+= mat[i][j];
                cont++;
            }
            printf("\n");
        }
        return soma;
    }
    return FALSE;
}
int main(){
    int **vmat, l,c;
    l=5;
    c=3;
    vmat= (int **)malloc(sizeof(int *)*l);
    if(vmat!=NULL){
        for(int i=0;i<l;i++){
            vmat[i]= (int *)malloc(sizeof(int )*c);
            if(vmat[i]==NULL){
                for (int j = 0; j < i; j++) {
                    free(vmat[j]);
                }
                free(vmat);
                return FALSE;
            }
        }
        int n =imprimir(vmat,l,c);;
        printf("------------\nsoma : %i",n);
        for(int i=0;i<l;i++){
            free(vmat[i]);
        }
        free(vmat);

    }
    return 0;
}*/



//
/*
int *alocaLeMatrizArmazenada(int n, int m){
    int *vma, aux;
    vma = (int *)malloc(sizeof(int )*(n*m));
    if(vma!=NULL){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("Digite o elemento da pos vma[%i][%i]", i,j);
                scanf("%d",&aux);
                vma[i*m+j]=aux;
            }
        }
        return vma;
        free(vma);
    }
    return NULL;
}*/

/*
float SomaElmDiagonalPrincipal(int n, int m){
    float *vmat,aux;
    vmat = (float *)malloc(sizeof(int )*(n*m));
    if(vmat != NULL ){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("Digite o elemento da pos vma[%i][%i]\n", i,j);
                scanf("%.1f",&aux);
                vmat[i*m+j]=aux;
            }
        }
        float somaDprinc = 0;
        //float somaDinver = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                somaDprinc += vmat[i*m+i];
                //somaDinver += vmat[i*m+(m-1-i)];

            }
        }
        return somaDprinc;
        //return somaDinver;
        free(vmat);
    }
    return -1;
}
*/


// Soma da diagonal principal e inversa por meio de matriz


/*/
float somaDiagonalPrincipal(int n, int m){
    float **mat;
    int i,j;
    mat = (float **)malloc(sizeof(float *)*n);
    if(mat!=NULL){
        for(i=0;i<n;i++){
            mat[i]=(float *)malloc(sizeof(float )*m);
            if(mat[i]==NULL){
                for(j=i-1;j>0;j--){
                    free(mat[j]);
                }
                free(mat);
                return -1;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%.1f",&mat[i][j]);
            }
        }

        //somando diagonal principal e inversa
        float somaDprinc = 0;
        //float somaDinver = 0;
        for(i=0;i<n;i++){
            somaDprinc += mat[i][i];
            //somaDinver += mat[i][m-i-1];
        }
        for(int i=0;i<n;i++){
            free(mat[i]);
        }
        free(mat);
        return somaDprinc;
    }
    return -1;
}*/

/*
int *transposta(int *vma,int n,int m){
    int *vmb = (int *)malloc(sizeof(int )*(n*m));
    if(vmb!=NULL){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //vmb[i][j]=vma[j][i]
                vmb[i*n+j] = vmb[j*m+i]
            }
        }
    }
}*/

/*
//metodo 1
int matMulttrsnp(int *v1, int *v2, int *v3,int n){
    int i,j,k;
    if(v1!=NULL && v2!=NULL && v3!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                v3[i*n+j]=0;
                for(k=0;k<n;k++){
                    v3[i*n+j]+=v1[i*n+k]*v2[j*n+k];
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}*/

/*
//metodo 2
int matMulttrsnp(int *v1, int *v2, int *v3,int n){
    int i,j,k;
    if(v1!=NULL && v2!=NULL && v3!=NULL){
        int *v2T = (int *)malloc(sizeof(int )*n );
        if(v2T!=NULL){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    v2T[i*n+j]=v2[j*n+i];
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                v3[i*n+j]=0;
                for(k=0;k<n;k++){
                    v3[i*n+j]+=v1[i*n+k]*v2T[k*n+j];
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}*/
