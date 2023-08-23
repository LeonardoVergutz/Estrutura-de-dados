////Programa que implementa uma lista circular////

#include <stdio.h>
#include <stdlib.h>

//Declaração da estrutura do no///

struct no{
    int numero;
    struct no *proximo;
};

//Declaração de variaveis//

struct no *cabeca;

/////Função que insere um no na lista/////

void inserir (int numero){
    //Alocaçao de memória
    struct no *novoNo = (struct no*) malloc(sizeof(sizeof(struct no)));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;

    if (cabeca ==NULL){
        cabeca = novoNo;
        novoNo -> proximo = cabeca;
    }else{
        struct no *ponteiro = cabeca;

        while (ponteiro -> proximo !=cabeca){
            ponteiro = ponteiro -> proximo;
        }

        ponteiro -> proximo = novoNo;
    }
}

//Função que imprime a lista//

void imprimir (){
    struct no *ponteiro = cabeca;
    if (ponteiro !=NULL){
        while (1){

        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;

            if (ponteiro ==cabeca){
                break;
            }
        }

    }

    printf("=================\n");
}


//Função para remover elementos//


void excluir(int numero){
    if (cabeca != NULL){
        if (cabeca -> numero == numero){
                if (cabeca-> proximo == cabeca){
                    //Caso facil, so tem um elemento na lista//
                    free(cabeca);
                    cabeca = NULL;

                }else{
                    //Caso dificil ,excluir o primeiro no da lista
                    struct no *ponteiroExcluir = cabeca;
                    cabeca = cabeca->proximo;

                    struct no *ponteiroAnterior = cabeca;

                    while (ponteiroAnterior -> proximo != ponteiroExcluir){
                        ponteiroAnterior = ponteiroAnterior-> proximo;
                    }
            ponteiroAnterior-> proximo = cabeca;
            free(ponteiroExcluir);
            }
        }else{
            //Caso dificil,excluir algum nó no meio da lista
            struct no *ponteiroAnterior = cabeca;

            while((ponteiroAnterior-> proximo != NULL)&&(ponteiroAnterior->proximo->numero!= numero)){
                ponteiroAnterior = ponteiroAnterior -> proximo;
            }

            if (ponteiroAnterior-> proximo != NULL){
                struct no *ponteiroExcluir = ponteiroAnterior ->proximo;
                ponteiroAnterior ->proximo = ponteiroExcluir -> proximo;
                free(ponteiroExcluir);
            }
        }
    }
}

//Função principal de execução do programa//

int main (){
    imprimir();

    inserir (1);
    excluir(1);
    imprimir();


    inserir (1);
    inserir (2);
    inserir (3);
    inserir (4);
    inserir (5);
    excluir (3);
    imprimir();

    excluir(2);
    excluir(5);
    excluir(4);
    imprimir();
}

