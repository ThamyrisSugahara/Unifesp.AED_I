#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

// Função para contar inversões utilizando Shell Sort
long long shellSortAndCount(int arr[], int n) {
    long long inv_count = 0;
    int gap, i, j;
    int temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                inv_count++;
            }

            arr[j] = temp;
        }
    }

    return inv_count;
}

int main() {
    int N;
    int arr[MAXN];
    
    while (1) {
        if (scanf("%d", &N) != 1) {
            return 1;
        }
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            if (scanf("%d", &arr[i]) != 1) {
                return 1;
            }
        }

        // Conta o número de inversões usando Shell Sort
        long long inv_count = shellSortAndCount(arr, N);

        // Determina o vencedor com base no número de inversões
        if (inv_count % 2 == 1) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }

    return 0;
}


