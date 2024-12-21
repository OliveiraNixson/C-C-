#include <stdio.h>

#define MATRIZ_T 10

#define MASCARA_T 3

void convolucao2(int matriz[MATRIZ_T][MATRIZ_T],float resultado[MATRIZ_T - MASCARA_T +1][MATRIZ_T - MASCARA_T +1]){
    for(int i=1;i < MATRIZ_T - MASCARA_T+1;i++){
        for(int j=1;j< MATRIZ_T - MASCARA_T+1;j++){
            float soma=0;
            for(int k=0;k<MASCARA_T;k++){
                for(int l=0;l<MASCARA_T;l++){
                    soma += matriz[i-1+k][j-1+l];
                }
            }

            float media = soma/(MASCARA_T * MASCARA_T);
            resultado[i-1][j-1] = media;
        }
    }
}

int main(){
    FILE *file;
int matriz[MATRIZ_T][MATRIZ_T];
float resultado[MATRIZ_T - MASCARA_T +1][MATRIZ_T - MASCARA_T +1];

file  = fopen("c:/Users/Estudos/Documents/C/convulucao/file2.txt","r");
    if(file == NULL){
        printf("Erro");
        return 1;
    }

    for(int i=0;i<MATRIZ_T;i++){
        for (int j=0; j < MATRIZ_T; j++){
            fscanf(file,"%d",&matriz[i][j]);
        }
    
    }

    fclose(file);

    convolucao2(matriz,resultado);
       for(int i=0;i<MATRIZ_T-MASCARA_T+1;i++){     
            for(int j=0;j<MATRIZ_T - MASCARA_T+1;j++){
                printf("%.2f  ",resultado[i][j]);
        }
            printf("\n");
    }
    return 0;
}