// Programa de multiplicação de matrizes//

#include <stdio.h>

int matriz [2][3];
int multi [3][2];
int resultado [2][2];
int i = 0;
int j = 0;
int k = 0;

int main(){
    //inicializando memoria//

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            matriz[i][j]= 0;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            multi[i][j]= 0;
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            resultado[i][j]= 0;
        }
    }

    //Preenchimento das matrizes//

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("Digite o valor para a linha %d e coluna %d da matriz 1:",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("Digite o valor para a linha %d e coluna %d da matriz 2:",i,j);
            scanf("%d",&multi[i][j]);
        }
    }

    //Multiplicando as matrizes//

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
           for(k=0;k<3;k++){
            resultado[i][j]+=(matriz[i][k] * multi[k][j]);
           }
        }
    }

    //Impressao dos resultados//
    printf("Matriz 1: \n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
           printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
            printf("\n");

           printf("Matriz 2: \n");

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
           printf("%d\t",multi[i][j]);
        }
        printf("\n");
    }
        printf("\n");

        printf("Matriz resultado: \n");

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
           printf("%d\t",resultado[i][j]);
        }
            printf("\n");

    }
}
