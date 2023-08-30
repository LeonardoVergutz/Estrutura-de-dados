//Programa que implmenta uma pilha//

#include <stdio.h>
#include <stdlib.h>

//Decalração da estrutura do no//

struct no{
    int numero;
    struct no *proximo;
};

//Declaracao de variaveis//

struct no *cabeca = NULL;

//Função que insere um no na pilha//

void push(int numero){
    struct no *novoNo = (struct no*) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;
    cabeca = novoNo;
}

//Função que remove um no da pilha//

int pop(){
    int retorno = -1;

    if (cabeca != NULL){
        retorno = cabeca ->numero;
        struct no *ponteiro = cabeca;
        cabeca = cabeca -> proximo;
        free(ponteiro);
    }
    return retorno;
}

//Função principal de execucao do programa//

int main(){
  int opcao = 0;
    int numero = 0;

    while (opcao !=3){
        printf("+================+\n");
        printf("| Menu de opcoes |");
        printf("+================+\n");
        printf("|  1 - Inserir   |\n");
        printf("|  2 - Remover   |\n");
        printf("|  3 - Sair      |\n");
        printf("+================+\n");
        printf("Digite a sua opcao:");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Digite um numero :");
            scanf("%d",&numero);
            push(numero);
            break;

        case 2:
            printf("Removi o numero %d da fila\n", pop());
            break;
            }
        }
    }
