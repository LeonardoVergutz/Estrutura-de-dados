#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração da estrutura do nó
struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
    int altura;
};

// Função que retorna a altura do nó
int getAlturaDoNo(struct no *raiz) {
    return (raiz == NULL) ? 0 : raiz->altura;
}

// Função que retorna o maior número entre dois números
int getMaximoEntreDoisNumeros(int a, int b) {
    return (a > b) ? a : b;
}

// Função que retorna o fator de equilíbrio da árvore
int getBalanco(struct no *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return (getAlturaDoNo(raiz->esquerda) - getAlturaDoNo(raiz->direita));
}

// Função que executa a rotação à esquerda
struct no *rotacaoEsquerda(struct no *raiz) {
    struct no *novaRaiz = raiz->direita;
    struct no *temp = novaRaiz->esquerda;
    novaRaiz->esquerda = raiz;
    raiz->direita = temp;

    raiz->altura = 1 + getMaximoEntreDoisNumeros(getAlturaDoNo(raiz->esquerda),
                                                 getAlturaDoNo(raiz->direita));
    novaRaiz->altura = 1 + getMaximoEntreDoisNumeros(getAlturaDoNo(novaRaiz->esquerda),
                                                     getAlturaDoNo(novaRaiz->direita));

    return novaRaiz;
}

// Função que executa a rotação à direita
struct no *rotacaoDireita(struct no *raiz) {
    struct no *novaRaiz = raiz->esquerda;
    struct no *temp = novaRaiz->direita;
    novaRaiz->direita = raiz;
    raiz->esquerda = temp;

    raiz->altura = 1 + getMaximoEntreDoisNumeros(getAlturaDoNo(raiz->esquerda),
                                                getAlturaDoNo(raiz->direita));
    novaRaiz->altura = 1 + getMaximoEntreDoisNumeros(getAlturaDoNo(novaRaiz->esquerda),
                                                    getAlturaDoNo(novaRaiz->direita));

    return novaRaiz;
}

// Função que insere um nó
struct no *inserir(struct no *raiz, int numero) {
    if (raiz == NULL) {
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz->numero = numero;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        raiz->altura = 1;
    } else {
        if (raiz->numero > numero) {
            raiz->esquerda = inserir(raiz->esquerda, numero);
        } else if (raiz->numero < numero) {
            raiz->direita = inserir(raiz->direita, numero);
        }
    }

    raiz->altura = 1 + getMaximoEntreDoisNumeros(getAlturaDoNo(raiz->esquerda),
                                                 getAlturaDoNo(raiz->direita));
    int balanco = getBalanco(raiz);

    if ((balanco > 1) && (numero < raiz->esquerda->numero)) {
        raiz = rotacaoDireita(raiz);
    }

    if ((balanco < -1) && (numero > raiz->direita->numero)) {
        raiz = rotacaoEsquerda(raiz);
    }

    if ((balanco > 1) && (numero > raiz->esquerda->numero)) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        raiz = rotacaoDireita(raiz);
    }

    if ((balanco < -1) && (numero < raiz->direita->numero)) {
        raiz->direita = rotacaoDireita(raiz->direita);
        raiz = rotacaoEsquerda(raiz);
    }
    return raiz;
}

// Função que imprime a árvore
void imprimir(struct no *raiz, char *indentacao) {
    if (raiz != NULL) {
        printf("%s%d\n", indentacao, raiz->numero);

        char *temp = (char *)malloc(1024 * sizeof(char));
        strcpy(temp, "...");
        strcat(temp, indentacao);

        imprimir(raiz->esquerda, temp);
        imprimir(raiz->direita, temp);
        free(temp); // Libere a memória alocada para 'temp'.
    }
}

// Função principal de execução do programa
int main() {
    struct no *raiz = NULL;
    int i = 0;

    for (i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    imprimir(raiz, "");
    return 0;
}
