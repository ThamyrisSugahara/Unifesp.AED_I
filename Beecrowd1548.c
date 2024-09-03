#include <stdlib.h> // Inclui a biblioteca para alocação de memória e funções de ordenação
#include <stdio.h>  // Inclui a biblioteca para entrada e saída padrão

// Função de comparação para ordenação em ordem decrescente
int comp(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // Retorna a diferença entre os valores para ordenação decrescente
}

int main() {
    int N, M, resposta;         // Variáveis para o número de casos de teste, o tamanho do array e a resposta
    int original[1000], ordenado[1000]; // Arrays para armazenar o array original e o array ordenado

    scanf("%d", &N);  // Lê o número de casos de teste

    // Loop para processar cada caso de teste
    for (int k = 0; k < N; ++k) {
        scanf("%d", &M);  // Lê o tamanho do array para o caso de teste atual

        // Lê os elementos do array e copia para o array original e ordenado
        for (int i = 0; i < M; ++i) {
            scanf("%d", &original[i]); // Lê o elemento para o array original
            ordenado[i] = original[i]; // Copia o elemento para o array ordenado
        }

        // Ordena o array ordenado em ordem decrescente usando qsort
        qsort(ordenado, M, sizeof(int), comp);

        resposta = 0; // Inicializa o contador de elementos que permanecem na mesma posição

        // Compara os arrays original e ordenado
        for (int i = 0; i < M; ++i) {
            // Verifica se o elemento na posição i do array original é igual ao elemento na mesma posição do array ordenado
            if (original[i] == ordenado[i])
                ++resposta; // Incrementa o contador se o elemento estiver na mesma posição
        }

        printf("%d\n", resposta); // Imprime o número de elementos que permanecem na mesma posição
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
