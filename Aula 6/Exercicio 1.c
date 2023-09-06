#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaração de constantes
const int modulo = 3;

// Declaração de estruturas
struct no {
    int numero;
    struct no *proximoNo;
};

struct diretor {
    int resto;
    struct no *proximoNo;
    struct diretor *proximoDiretor;
};

// Declaração de variáveis
struct diretor *cabeca = NULL;

// Função que procura o diretor certo
struct diretor *procurarDiretor(int resto) {
    struct diretor *ponteiro = cabeca;

    // Varrendo a lista até encontrar o diretor certo ou chegar ao final
    while ((ponteiro != NULL) && (ponteiro->resto != resto)) {
        ponteiro = ponteiro->proximoDiretor;
    }

    if (ponteiro == NULL) {
        // Criar um diretor novo
        ponteiro = (struct diretor *)malloc(sizeof(struct diretor));
        ponteiro->resto = resto;
        ponteiro->proximoNo = NULL;
        ponteiro->proximoDiretor = cabeca;

        cabeca = ponteiro;
    }

    return ponteiro;
}

// Função que insere um nó na matriz esparsa
void inserir(int numero) {
    struct diretor *ponteiroDiretor = procurarDiretor(numero % modulo);

    struct no *novoNo = (struct no *)malloc(sizeof(struct no));

    novoNo->numero = numero;
    novoNo->proximoNo = ponteiroDiretor->proximoNo;

    ponteiroDiretor->proximoNo = novoNo;
}

// Função que imprime a matriz esparsa
void imprimir() {
    struct diretor *ponteiroDiretor = cabeca;

    printf("============= Matriz Esparsa ==============\n");
    while (ponteiroDiretor != NULL) {
        struct no *ponteiroNo = ponteiroDiretor->proximoNo;

        printf("%d:\t", ponteiroDiretor->resto);

        while (ponteiroNo != NULL) {
            printf("%d\t", ponteiroNo->numero);
            ponteiroNo = ponteiroNo->proximoNo;
        }

        printf("\n");
        ponteiroDiretor = ponteiroDiretor->proximoDiretor;
    }
}

//Funcao que remove um no da matriz esparsa//

void remover(int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero %modulo);

    if (ponteiroDiretor -> proximoNo!= NULL){
        if (ponteiroDiretor -> proximoNo -> numero == numero){
                //Caso facil,excluir o primeiro no da lista
            struct no *ponteiroExcluir = ponteiroDiretor -> proximoNo;
            ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
            free (ponteiroExcluir);
        }else{
            //Caso dificil,excluir algum nó no meio da lista
            struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;

            while((ponteiroAnterior-> proximoNo != NULL)&&
                  (ponteiroAnterior->proximoNo->numero!= numero)){
                ponteiroAnterior = ponteiroAnterior -> proximoNo;
            }

            if (ponteiroAnterior-> proximoNo != NULL){
                struct no *ponteiroExcluir = ponteiroAnterior ->proximoNo;
                ponteiroAnterior ->proximoNo = ponteiroExcluir -> proximoNo;
                free(ponteiroExcluir);
            }
        }
    }
}

// Função principal de execução do programa
int main() {
    int i = 0;
    time_t t;
    int numero = 0;

    srand((unsigned)time(&t));

    for (i = 0; i < 10; i++) {
        inserir(rand());
    }

    imprimir();

    printf("Digite um numero para excluir:");
    scanf("&d",&numero);

    remover(numero);

    imprimir();


}
