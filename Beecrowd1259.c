#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Função de comparação para ordenação crescente (pares)
int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função de comparação para ordenação decrescente (ímpares)
int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    int nums[MAX_SIZE];
    int even[MAX_SIZE];
    int odd[MAX_SIZE];
    int even_count = 0, odd_count = 0;

    // Leitura do número de elementos
    scanf("%d", &n);

    // Leitura dos elementos e separação em pares e ímpares
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        if (value % 2 == 0) {
            even[even_count++] = value;
        } else {
            odd[odd_count++] = value;
        }
    }

    // Ordenação dos pares em ordem crescente
    qsort(even, even_count, sizeof(int), compare_asc);

    // Ordenação dos ímpares em ordem decrescente
    qsort(odd, odd_count, sizeof(int), compare_desc);

    // Impressão dos pares
    for (int i = 0; i < even_count; i++) {
        printf("%d\n", even[i]);
    }

    // Impressão dos ímpares
    for (int i = 0; i < odd_count; i++) {
        printf("%d\n", odd[i]);
    }

    return 0;
}
