//Programa criação da matriz transposta//

#include <stdio.h>

//Declaracao de variaveis//

int matriz [2][3];
int transposta [3][2];
int i = 0;
int j = 0;

// Funcao principal//

int main (){
    //Limpeza da memoria//

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            matriz[i][j] = 0;
            transposta[j][i]=0;
        }
    }

    //Introdução de valores na matriz//

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("Digite o valor para a linha %d e coluna %d da matriz:",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    //Transpondo a matriz//

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            transposta[j][i] = matriz[i][j];
        }
    }

    //Impressao das matrizes//

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d\t",transposta[i][j]);
        }
        printf("\n");
    }

}
