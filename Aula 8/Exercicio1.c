//Programa que implementa uma arvore binaria e suas respectivas navegacoes

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Declaracao de estruturas

struct no{
    int numero;
    struct no *esquerda;
    struct no *direita;
};

//Funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero){
    if (raiz == NULL){
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    }else{
        if((rand()%2)==0){
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        }else{
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;
};

//Navegacao em pre-ordem

void navegarPreOrdem(struct no *raiz){
    if(raiz != NULL){
        printf("%d\t", raiz ->numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}

//Navegar em ordem

void navegarEmOrdem(struct no *raiz){
    if(raiz != NULL){
        navegarEmOrdem(raiz -> esquerda);
        printf("%d\t", raiz ->numero);
        navegarPreOrdem(raiz -> direita);
    }
}

//Navegar pos ordem


void navegarPosOrdem(struct no *raiz){
    if(raiz != NULL){
        navegarEmOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
        printf("%d\t", raiz ->numero);
    }
}

//Funcao principal de execucao do programa

int main(){
    struct no *raiz = NULL;

    //Inicializacao da aleatoridade
    time_t t;
    srand((unsigned) time(&t));

    //Preenchimento da arvore
    int i = 0;
    for (i = 0;i<5;i++){
        raiz = inserir(raiz,i);
    }

    //Navegacoes
    printf("\n================================= PRE-ORDEM =================================\n");
    navegarPreOrdem(raiz);

    printf("\n================================= EM-ORDEM  =================================\n");
    navegarEmOrdem(raiz);

    printf("\n================================= POS-ORDEM =================================\n");
    navegarPosOrdem(raiz);
}

