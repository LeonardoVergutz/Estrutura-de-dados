#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declara��o da estrutura do n�
struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
    int altura;
};

// Fun��o que retorna a altura do n�
int getAlturaDoNo(struct no *raiz) {
    return (raiz == NULL) ? 0 : raiz->altura;
}

// Fun��o que retorna o maior n�mero entre dois n�meros
int getMaximoEntreDoisNumeros(int a, int b) {
    return (a > b) ? a : b;
}

// Fun��o que retorna o fator de equil�brio da �rvore
int getBalanco(struct no *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return (getAlturaDoNo(raiz->esquerda) - getAlturaDoNo(raiz->direita));
}

// Fun��o que executa a rota��o � esquerda
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

// Fun��o que executa a rota��o � direita
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

// Fun��o que insere um n�
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

// Fun��o que imprime a �rvore
void imprimir(struct no *raiz, char *indentacao) {
    if (raiz != NULL) {
        printf("%s%d\n", indentacao, raiz->numero);

        char *temp = (char *)malloc(1024 * sizeof(char));
        strcpy(temp, "...");
        strcat(temp, indentacao);

        imprimir(raiz->esquerda, temp);
        imprimir(raiz->direita, temp);
        free(temp); // Libere a mem�ria alocada para 'temp'.
    }
}

// Fun��o principal de execu��o do programa
int main() {
    struct no *raiz = NULL;
    int i = 0;

    for (i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    imprimir(raiz, "");
    return 0;
}
