#include <stdio.h>
#include <stdlib.h>

#define MAX 105

// Definição da estrutura de grafo
typedef struct {
    int x, y;  // Coordenadas do nó
    char direcao;  // Direção do movimento ('^', '>', 'v', '<')
} No;

typedef struct {
    No *nos[MAX][MAX];  // Matriz de nós
    int altura, largura;  // Dimensões do mapa
} Grafo;

// Função para inicializar o grafo
void inicializar_grafo(Grafo *g, int altura, int largura) {
    g->altura = altura;
    g->largura = largura;
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            g->nos[i][j] = NULL;
        }
    }
}

// Função para adicionar um nó ao grafo
void adicionar_no(Grafo *g, int x, int y, char direcao) {
    No *no = (No *)malloc(sizeof(No));
    no->x = x;
    no->y = y;
    no->direcao = direcao;
    g->nos[x][y] = no;
}

// Função para processar o movimento no grafo
char processar_grafo(Grafo *g) {
    int i = 0, j = 0;
    char ant = 0;

    while (1) {
        if (g->nos[i][j] == NULL) {
            return '!';
        }
        char atual = g->nos[i][j]->direcao;

        if (atual == 'x') {
            return '!';
        } else if (atual == '*') {
            return '*';
        }

        g->nos[i][j]->direcao = 'x';  // Marca como visitado

        if (atual == '^') {
            ant = '^';
            i--;
        } else if (atual == '>') {
            ant = '>';
            j++;
        } else if (atual == 'v') {
            ant = 'v';
            i++;
        } else if (atual == '<') {
            ant = '<';
            j--;
        } else if (atual == '.') {
            if (ant == '^') i--;
            else if (ant == '>') j++;
            else if (ant == 'v') i++;
            else if (ant == '<') j--;
        }

        if (i < 0 || i >= g->altura || j < 0 || j >= g->largura) {
            return '!';
        }
    }
}

int main(void) {
    Grafo g;
    int x, y;

    // Leitura das dimensões do mapa
    scanf("%d %d", &x, &y);
    inicializar_grafo(&g, y, x);

    // Leitura do mapa e criação dos nós no grafo
    for (int i = 0; i < y; ++i) {
        char linha[MAX];
        scanf("%s", linha);
        for (int j = 0; j < x; ++j) {
            adicionar_no(&g, i, j, linha[j]);
        }
    }

    // Processamento do grafo e exibição do resultado
    char resultado = processar_grafo(&g);
    printf("%c\n", resultado);

    return 0;
}
