#include <stdio.h>  // Inclui a biblioteca para entrada e saída padrão
#include <stdlib.h> // Inclui a biblioteca para alocação dinâmica de memória

// Função de ordenação Counting Sort
void countingSort(int *V, int n, int limite) {
    // Aloca um array auxiliar para contagem dos elementos
    int *aux = (int *)malloc(limite * sizeof(int));
    int k = 0;

    // Inicializa o array auxiliar com zero
    for (int i = 0; i < limite; ++i) {
        aux[i] = 0;
    }

    // Conta a frequência de cada elemento no array V
    for (int i = 0; i < n; ++i) {
        aux[V[i]] += 1;
    }

    // Reconstrói o array V ordenado usando o array auxiliar
    for (int i = 0; i < limite; ++i) {
        for (int j = 0; j < aux[i]; ++j) {
            V[k++] = i; // Coloca o valor i no array V conforme a frequência registrada
        }
    }

    // Libera a memória alocada para o array auxiliar
    free(aux);
}

int main(void) {
    int NC, N;        // NC: número de casos de teste; N: número de elementos em cada caso de teste
    int *V;           // Ponteiro para o array de números a serem ordenados

    // Lê o número de casos de teste
    scanf("%d", &NC);

    // Loop para processar cada caso de teste
    for (int k = 0; k < NC; ++k) {
        // Lê o número de elementos para o caso de teste atual
        scanf("%d", &N);

        // Aloca memória para o array V
        V = (int *)malloc(N * sizeof(int));

        // Lê os elementos do array V
        for (int i = 0; i < N; ++i) {
            scanf("%d", &V[i]);
        }

        // Chama a função countingSort para ordenar o array V
        countingSort(V, N, 231);

        // Imprime os elementos do array ordenado
        if (N > 0) {
            printf("%d", V[0]); // Imprime o primeiro elemento sem espaço antes
        }
        for (int i = 1; i < N; ++i) {
            printf(" %d", V[i]); // Imprime os elementos restantes com um espaço antes
        }
        printf("\n"); // Imprime uma nova linha após a lista de elementos
    }

    // Libera a memória alocada para o array V
    free(V);

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
