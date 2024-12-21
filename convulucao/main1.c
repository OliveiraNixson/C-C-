#include <stdio.h>

#define VT 556
#define MT 3

void convolucao(float* vetor, float* resultado){
    for(int i=0; i<VT - MT+1;i++){
        float media = (vetor[i] + vetor[i+1] + vetor[i+2])/3;        
        resultado[i] = media;
    }
}

int main(){
    FILE *file;
    float vetor[VT];
    float resultado[VT - MT + 1];

    file = fopen("c:/Users/Estudos/Documents/C/convulucao/file1.txt","r");

    if(file == NULL){
        printf("Erro \n");
        return 1;
    }

    int i = 0;
    char buffer[100]; // Tamanho máximo da linha a ser lida

    while (fgets(buffer, sizeof(buffer), file) != NULL && i < VT) {
        sscanf(buffer, "%f", &vetor[i]);
        i++;
    }

    fclose(file);

    convolucao(vetor,resultado);

    for(int i=0;i<VT - MT+1;i++){
        printf("Vetor: %0.4f ",vetor[i]);
        printf("Resultado: %0.4f\n",resultado[i]);
    }

    return 0;
}