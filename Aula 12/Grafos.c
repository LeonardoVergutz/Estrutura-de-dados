///////////
// Grafo //
///////////

#include <stdio.h>

/////////////////////////////
// Defini��o de constantes //
/////////////////////////////

const int TAMANHO = 5;

//////////////////////
// Cria��o do grafo //
//////////////////////

void criar(int grafo[TAMANHO][TAMANHO]) {
int i = 0;
int j = 0;
int amigo = 0;

// Inicializa��o do grafo //
for (i = 0; i < TAMANHO; i++) {
for (j = 0; j < TAMANHO; j++) {
grafo[i][j] = 0;
}
}

// Defini��o das conex�es //
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
// Fun��o que imprime o grafo //
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
// Fun��o que descobre o v�rtice de maior grau //
/////////////////////////////////////////////////

int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]) {
int i = 0;
int j = 0;
int contador = 0;
int maior = 0;
int vertice = 0;

// Navega��o do grafo //
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
// Fun��o principal //
//////////////////////

int main() {
int grafo[TAMANHO][TAMANHO];

criar(grafo);

imprimir(grafo);

printf("Vertice mais popular: %d\n", descobrirVerticeMaiorGrau(grafo));
}1
