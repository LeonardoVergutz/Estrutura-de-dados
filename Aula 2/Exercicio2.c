//Problema de Ordenação Direta//
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Declaração de variavel//
int vetor [10000];
int i = 0;
int trade = 0;

//Função principal de execução do programa//

int main(){
    setlocale(LC_ALL,"Portuguese");

    //Inicialização de memoria//
    for (i = 0; i<10000;i++){
        vetor[i]= (rand() % 10000);
    }

    //Impressão do vetor desordenadamente//
    for (i = 0;i <10000;i++){
        printf("%d\n", vetor [i]);
    }

    //Ordenação dos elementos do vetor//
    trade = 1;
    while (trade){
        trade = 0;
        for (i = 0;i<9999;i++){
            if (vetor[i]>vetor[i+1]){
             int temp = vetor[i];
             vetor[i] = vetor[i+1];
             vetor[i+1]= temp;
             trade = 1;
            }
        }
    }

    //Impressão do vetor organizado//
    for (i = 0;i <10000;i++){
        printf("%d\n",vetor[i]);
    }

}



