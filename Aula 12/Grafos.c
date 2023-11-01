///////////
// Grafo //
///////////

#include <stdio.h>

/////////////////////////////
// Definição de constantes //
/////////////////////////////

const int TAMANHO = 5;

//////////////////////
// Criação do grafo //
//////////////////////

void criar(int grafo[TAMANHO][TAMANHO]) {
int i = 0;
int j = 0;
int amigo = 0;

// Inicialização do grafo //
for (i = 0; i < TAMANHO; i++) {
for (j = 0; j < TAMANHO; j++) {
grafo[i][j] = 0;
}
}

// Definição das conexões //
for (i = 0; i < TAMANHO - 1; i++) {
for (j = i + 1; j < TAMANHO; j++) {
printf("Digite <1> caso %d seja amigo de %d: ", i, j);
scanf("%d", &amigo);

grafo[i][j] = amigo;
grafo[j][i] = amigo;
}
}
}

////////////////////////////////
// Função que imprime o grafo //
////////////////////////////////

void imprimir(int grafo[TAMANHO][TAMANHO]) {
int i = 0;
int j = 0;

for (i = 0; i < TAMANHO; i++) {
for (j = 0; j < TAMANHO; j++) {
printf("%d\t", grafo[i][j]);
}
printf("\n");
}
}

/////////////////////////////////////////////////
// Função que descobre o vértice de maior grau //
/////////////////////////////////////////////////

int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]) {
int i = 0;
int j = 0;
int contador = 0;
int maior = 0;
int vertice = 0;

// Navegação do grafo //
for (i = 0; i < TAMANHO - 1; i++) {
contador = 0;
for (j = i + 1; j < TAMANHO; j++) {
if (grafo[i][j]) {
contador++;
}
}
if (contador > maior) {
maior = contador;
vertice = i;
}
}

return vertice;
}

//////////////////////
// Função principal //
//////////////////////

int main() {
int grafo[TAMANHO][TAMANHO];

criar(grafo);

imprimir(grafo);

printf("Vertice mais popular: %d\n", descobrirVerticeMaiorGrau(grafo));
}1
