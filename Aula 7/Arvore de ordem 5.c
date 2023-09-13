//Programa que implementa uma arvore de ordem 5//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de estrutura

struct no{
    int numero;
    struct no* filho1;
    struct no* filho2;
    struct no* filho3;
    struct no* filho4;
    struct no* filho5;
};

//Função que insere um no na arvore//

struct no *inserir(struct no *raiz, int numero){
    if(raiz == NULL){
        //Caso facil: a arvore esta vazia
        raiz = (struct no*) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> filho1 = NULL;
        raiz -> filho2 = NULL;
        raiz -> filho3 = NULL;
        raiz -> filho4 = NULL;
        raiz -> filho5 = NULL;
    }else{
        //Caso dificl: a arvore NAO esta vazia
        int sorteio = (rand()%5);

        if(sorteio == 0){
            raiz -> filho1 = inserir(raiz -> filho1,numero);
        }else if (sorteio = 1){
            raiz -> filho2 = inserir(raiz -> filho2, numero);
        }else if (sorteio = 2){
            raiz -> filho3 = inserir(raiz -> filho3, numero);
        }else if (sorteio = 3){
            raiz -> filho4 = inserir(raiz -> filho4, numero);
        }else if (sorteio = 4){
            raiz -> filho5 = inserir(raiz -> filho5, numero);
        }
    }
    return raiz;
};

//Função que imprime a arvore


void imprimir (struct no *raiz,char *endentacao){
    if (raiz != NULL){
    printf("%s%d\n",endentacao,raiz -> numero);

    char *temp = (char *) malloc(1024 * sizeof(char));
    strcpy(temp, "- - -");
    strcat(temp, endentacao);

    imprimir(raiz -> filho1,temp);
    imprimir(raiz -> filho2,temp);
    imprimir(raiz -> filho3,temp);
    imprimir(raiz -> filho4,temp);
    imprimir(raiz -> filho5,temp);
    }
}

//Função principal de execução do programa

int main(){
    //Inicializacao da aleatoridade
    time_t t;
    srand((unsigned) time(&t));

    //Declaracao da raiz
    struct no *raiz = NULL;

    //Declaração do endentador
    char *endentador = (char *) malloc(1024 *sizeof(char));
    strcpy (endentador, "");

    //Menu de opcoes
    int opcao = 0;

    while(opcao !=3){
        printf("+================+\n");
        printf("| Menu de opcoes |\n");
        printf("+================+\n");
        printf("| 1 - Inserir    |\n");
        printf("| 2 - Imprimir   |\n");
        printf("| 3 - Sair       |\n");
        printf("+================+\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            int numero = 0;
            printf("Digite o numero:");
            scanf("%d",&numero);
            raiz = inserir(raiz,numero);
        }else if (opcao ==2){
            imprimir(raiz,endentador);
        }


    }


}

