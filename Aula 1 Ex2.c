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
}
