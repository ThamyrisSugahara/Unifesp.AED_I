#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois inteiros, usada para ordenação
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int x[4];

    // Leitura dos quatro inteiros
    for (int i = 0; i < 4; i++) {
        scanf("%d", &x[i]);
    }

    // Ordenação dos inteiros
    qsort(x, 4, sizeof(int), compare);

    // Verificação da condição e impressão da saída
    if (x[0] * x[3] == x[1] * x[2]) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
