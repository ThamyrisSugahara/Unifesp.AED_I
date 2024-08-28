#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CASOS 60
#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    char cor[10];
    char tamanho;
} Camiseta;

// Função de comparação para ordenar camisetas
int comp(const void *a, const void *b) {
    const Camiseta *camisaA = (const Camiseta *)a;
    const Camiseta *camisaB = (const Camiseta *)b;

    // Comparar a cor
    int cmp = strcmp(camisaA->cor, camisaB->cor);
    if (cmp != 0) return cmp;

    // Comparar o tamanho em ordem decrescente
    if (camisaA->tamanho != camisaB->tamanho) {
        return camisaB->tamanho - camisaA->tamanho;
    }

    // Comparar o nome em ordem crescente
    return strcmp(camisaA->nome, camisaB->nome);
}

int main() {
    int n;
    int primeiroCaso = 1;

    while (scanf("%d", &n) && n != 0) {
        // Limpar buffer de entrada
        while (getchar() != '\n');

        Camiseta camisetas[MAX_CASOS];

        for (int i = 0; i < n; i++) {
            fgets(camisetas[i].nome, sizeof(camisetas[i].nome), stdin);
            camisetas[i].nome[strcspn(camisetas[i].nome, "\n")] = '\0'; // Remove o '\n'

            char linha[50];
            fgets(linha, sizeof(linha), stdin);
            sscanf(linha, "%s %c", camisetas[i].cor, &camisetas[i].tamanho);
        }

        // Ordenar camisetas usando a função de comparação
        qsort(camisetas, n, sizeof(Camiseta), comp);

        // Imprimir camisetas ordenadas
        if (!primeiroCaso) {
            printf("\n"); // Linha em branco entre casos de teste
        }
        primeiroCaso = 0;

        for (int i = 0; i < n; i++) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }

    return 0;
}
