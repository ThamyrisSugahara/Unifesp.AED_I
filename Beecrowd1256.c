#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        // Cria uma tabela hash de ponteiros de arrays (listas ligadas)
        int** tabela_hash = (int**)malloc(M * sizeof(int*));
        int* contador = (int*)malloc(M * sizeof(int));  // Array para contar elementos em cada índice

        // Inicializa as tabelas
        for (int i = 0; i < M; i++) {
            tabela_hash[i] = NULL;
            contador[i] = 0;
        }

        // Lê as chaves e insere na tabela
        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);

            int indice = chave % M;

            // Realoca memória para a nova chave no índice correto
            contador[indice]++;
            tabela_hash[indice] = (int*)realloc(tabela_hash[indice], contador[indice] * sizeof(int));
            tabela_hash[indice][contador[indice] - 1] = chave;
        }

        // Imprime a tabela hash
        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < contador[i]; j++) {
                printf(" %d ->", tabela_hash[i][j]);
            }
            printf(" \\\n");
        }

        // Libera a memória alocada
        for (int i = 0; i < M; i++) {
            free(tabela_hash[i]);
        }
        free(tabela_hash);
        free(contador);

        // Linha em branco entre os casos de teste
        if (N > 0) {
            printf("\n");
        }
    }

    return 0;
}
