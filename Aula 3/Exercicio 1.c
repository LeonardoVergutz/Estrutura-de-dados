#include <stdio.h>
#include <stdlib.h>

//////Programa de Lista de Encadeamento//////


///////Declara��o da estrutura do n�//////

struct no{
    int numero;
    struct no *proximo;
};


//Declara��o de variaves//

struct no *cabeca = NULL;

//Fun��o que insere um n� na lista//

void inserir (int numero){
    //Aloca��o do espa�o de mem�ria//
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo ->numero = numero;
    novoNo ->proximo = NULL;

    if (cabeca == NULL){
        //Caso facil, a lista esta vazia//
        cabeca= novoNo;
    }else{
        //Caso dificil,a lista n�o esta vazia//
        struct no* ponteiro = cabeca;

        while(ponteiro->proximo != NULL){
            ponteiro = ponteiro->proximo;
        }
        ponteiro -> proximo = novoNo;
    }
}

    //Fun��o que imprime os nos da lista//

void imprimir (){
    printf("=======================\n");

    struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
}

//Funcao de exclusao de um n�//
void remover(int numero){
    if (cabeca != NULL){
        if (cabeca -> numero == numero){
                //Caso facil,excluir o primeiro no da lista
            struct no *ponteiroExcluir = cabeca;
            cabeca = cabeca->proximo;
            free (ponteiroExcluir);
        }else{
            //Caso dificil,excluir algum n� no meio da lista
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


//Fun��o principal do programa//

int main(int argc, char *argv[]){
    int opcao = 0;
    int numero = 0;
    while (opcao != 4){
        printf("+==============+\n");
        printf("|Menu Principal|\n");
        printf("+==============+\n");
        printf("| 1 - Inserir  |\n");
        printf("| 2 - Remover  |\n");
        printf("| 3 - Imprimir |\n");
        printf("| 4 - Sair     |\n");
        printf("+==============+\n");
        printf("Digite a opcao:");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("Digite o numero:");
                scanf("%d",&numero);
                inserir(numero);
                break;
            case 2:
                printf("Digite o numero:");
                scanf("%d",&numero);
                remover(numero);
                break;
            case 3:
                imprimir();
                break;


        }
    }

}
