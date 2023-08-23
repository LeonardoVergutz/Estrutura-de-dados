/////////Lista de encadeamento duplo////////

#include <stdio.h>
#include <stdlib.h>

/////////Declaração de nó///////////////////

struct no{
    int numero;
    struct no *anterior;
    struct no *proximo;
};

//////////Declaração de variaveis////////////

struct no *cabeca = NULL;

///////// Função que insere um nó na lista///


void inserir(int numero){
    //// Alocação de memoria/////
    struct no *novoNo = (struct no*) malloc(sizeof(struct no));
    novoNo ->numero = numero;
    novoNo ->anterior = NULL;
    novoNo -> proximo = NULL;

    if (cabeca == NULL){
        //Caso facil, a lista esta vazia//
        cabeca = novoNo;
    }else{
        //Caso dificil, a lista nao esta vazia//
        struct no *ponteiro = cabeca;

        //Procura o ultimo no da lista//
        while (ponteiro -> proximo != NULL){
            ponteiro = ponteiro -> proximo;
        }

        ponteiro -> proximo = novoNo;
        novoNo -> anterior = ponteiro;
    }

}

//Função que imprime a lista//

void imprimir(){
    struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }

    printf("=================\n");
}

//Função de exclusão do programa//

void excluir (int numero){
            //Lista nao vazia//
            struct no *ponteiro = cabeca;

            while (ponteiro != NULL){
                if (ponteiro -> numero == numero){
                    if (ponteiro -> anterior == NULL){
                        //Excluir o primeiro da lista//
                        cabeca = cabeca -> proximo;
                        if(cabeca != NULL){
                            cabeca -> anterior = NULL;
                        }
                        free(ponteiro);
                        ponteiro = cabeca;
                    }else if(ponteiro ->proximo ==NULL){
                        //Excluir o ultimo da lista//
                        struct no *temp = ponteiro;
                        ponteiro = ponteiro -> anterior;
                        ponteiro -> proximo =NULL;
                        free(temp);
                    }else{
                        //Excluir um no no meio da lista//
                        struct no *temp = ponteiro;
                        ponteiro = ponteiro -> anterior;
                        temp -> anterior -> proximo = temp-> proximo;
                        temp -> proximo -> anterior = temp-> anterior;
                        free(temp);
                    }
                }
                if(ponteiro != NULL){
                    ponteiro = ponteiro ->proximo;
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



