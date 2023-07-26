//Programa de inversão de elementos do vetor//

#include <stdio.h>

int vetororiginal[10];
int vetorinvertido[10];
int i =0;

int main(){
    //Limpeza da memoria//
    for (i=0;i<10;i++){
        vetororiginal[i]=0;
        vetorinvertido[i]=0;
    }
    for (i=0; i<10; i++){
        printf("Digite o valor correspondente a posicao %d do vetor :",i);
        scanf("%d",&vetororiginal[i]);
    }

    //Inversão do vetor//
    for (i=9; i>=0; i--){
        vetorinvertido[9-i]= vetororiginal[i];
    }

    //Impressão dos vetores//
    for (i=0; i<10; i++){
        printf("vetororiginal[%d] = %d\n",i,vetororiginal[i]);
    }

    printf("\n");

    for (i=0; i<10; i++){
        printf("vetorinvertido[%d] = %d\n",i,vetorinvertido[i]);
    }
}
