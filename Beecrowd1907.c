#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct {
    int x, y;
} Ponto;

int N, M;
char matriz[MAX][MAX];
int visitado[MAX][MAX];

int dx[] = {0, 1, 0, -1};  // Movimentos: direita, baixo, esquerda, cima
int dy[] = {1, 0, -1, 0};

int dentro(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs(int x, int y) {
    // Alocando a fila dinamicamente
    Ponto *fila = (Ponto *)malloc(N * M * sizeof(Ponto));
    int inicio = 0, fim = 0;

    fila[fim++] = (Ponto){x, y};
    visitado[x][y] = 1;

    while (inicio < fim) {
        Ponto atual = fila[inicio++];

        for (int i = 0; i < 4; i++) {
            int novoX = atual.x + dx[i];
            int novoY = atual.y + dy[i];

            if (dentro(novoX, novoY) && !visitado[novoX][novoY] && matriz[novoX][novoY] == '.') {
                visitado[novoX][novoY] = 1;
                fila[fim++] = (Ponto){novoX, novoY};
            }
        }
    }

    // Liberando a memória alocada para a fila
    free(fila);
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", matriz[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matriz[i][j] == '.' && !visitado[i][j]) {
                bfs(i, j);
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
