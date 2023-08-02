//Programa de Busca Binaria//
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Declara��o de variavel//
int vetor [10000];
int i = 0;
int busca = 0;
int inicio = 0;
int meio = 0;
int fim = 0;

//Fun��o principal de execu��o do programa//

int main(){
    setlocale(LC_ALL,"Portuguese");

    //Inicializa��o de memoria//
    for (i = 0; i<10000;i++){
        vetor[i]= i;
    }

    //Perguntar o valor a ser buscado//
    printf("Digite o valor a ser buscado:");
    scanf("%d",&busca);

    //Algoritmo de busca//
    inicio = 0;
    fim = 9999;
    while (fim>= inicio){
        meio = ((inicio+fim)/2);
        if (busca == vetor[meio]){
            printf("O elemento informado foi encontrado na posi��o %d\n",meio);
            return 0;
        }else if(busca>vetor[meio]){
            inicio = (meio+1);
        }else{
            fim= (meio-1);
        }
    }
    printf("O valor informado n�o foi encontrado!!");
}
