//Programa preenchimento de vetor//

#include <stdio.h>

//Declara��o de variaveis//

int vetor [10];
int i = 0;

int main(){
    //Inicializa��o da memoria//
    for (i=0;i<10;i++){
        vetor[i]=0;
    }

    //Preenchimento do valor do vetor//
    for (i=0;i<10;i++){
        printf("Digite o valor da posicao %d: ",i);
        scanf("%d", &vetor[i]);
    }

    //Impress�o do vetor//
    for (i=0;i<10;i++){
            printf("vetor[%d] = %d\n ",i,vetor[i]);
    }
}
