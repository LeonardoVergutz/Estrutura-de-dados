//Progrma que implementa uma fila FIFO///

#include <stdio.h>
#include <stdlib.h>

//Declaração de estrutura do no ///

struct no{
    int numero;
    struct no *proximo;
};

//Declaração de variaves//

struct no *cabeca = NULL;

//Função que insere um no na fila//

void inserir (int numero){
    struct no *novoNo = (struct no*) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;
    cabeca = novoNo;
}


//Função que remove um no da fila//

int remover(){
    int retorno = -1;

    if (cabeca != NULL){
        if (cabeca -> proximo == NULL){
                //A fila so tem um no//
            retorno = cabeca -> numero;
            free(cabeca);
            cabeca = NULL;
        }else{
            //A fila tem mais de um no//
            struct no *ponteiroAnterior = cabeca;

            //Procura o penultimo no da fila//
            while (ponteiroAnterior -> proximo != NULL){
                ponteiroAnterior = ponteiroAnterior ->proximo;

            }

            retorno = ponteiroAnterior -> proximo -> numero;
            free(ponteiroAnterior -> proximo);
            ponteiroAnterior -> proximo = NULL;
        }

    }

    return retorno;
}

//Funcção que imprime a fila

void imprimir(){
    struct no *ponteiro = cabeca;

    printf("===========FILA==========");
    while(ponteiro != NULL){
        printf("==============FILA=============\n");
        printf("%d\n", ponteiro-> numero);
        ponteiro = ponteiro -> proximo;
    }
    printf("\n");
}

//Função de execução do programa//

int main (){
    int opcao = 0;
    int numero = 0;

    while (opcao !=4){
        printf("+================+\n");
        printf("| Menu de opcoes |");
        printf("+================+\n");
        printf("|  1 - Inserir   |\n");
        printf("|  2 - Remover   |\n");
        printf("|  3 - Imprimir  |\n");
        printf("|  4 - Sair      |\n");
        printf("+================+\n");
        printf("Digite a sua opcao:");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Digite um numero :");
            scanf("%d",&numero);
            inserir(numero);
            break;

        case 2:
            printf("Removi o numero %d da fila\n", remover());
            break;
        case 3:
            imprimir();
            break;

        }
    }


}
