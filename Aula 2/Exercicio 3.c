//Programa de Busca exaustiva//
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Declaração de variavel//
int vetor [10000];
int i = 0;
int busca = 0;
int achei = 0;

//Função principal de execução do programa//

int main(){
    setlocale(LC_ALL,"Portuguese");

    //Inicialização de memoria//
    for (i = 0; i<10000;i++){
        vetor[i]= (rand() % 10000);
    }

    //Perguntar o valor a ser buscado//
    printf("Digite o valor a ser buscado:");
    scanf("%d",&busca);

    //Algoritmo de busca//
    achei = -1;
    for (i = 0; i<10000;i++){
        if (vetor[i]== busca){
            achei = i;
        }
    }
    if (achei == -1){
        printf("Valor informado não existe!! ");
    }else{
        printf("O valor foi encontrado na posição %d\n",achei);
    }


}



