#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10005 // máximo número de mármores, conforme especificação

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int caso = 1;
    
    while (1) {
        int N, Q;
        scanf("%d %d", &N, &Q);
        
        if (N == 0 && Q == 0) break;
        
        int marmores[MAX_N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }
        
        // Ordena os mármores
        qsort(marmores, N, sizeof(int), compara);
        
        printf("CASE# %d:\n", caso++);
        
        for (int i = 0; i < Q; i++) {
            int consulta;
            scanf("%d", &consulta);
            
            int encontrado = 0;
            int posicao = -1;
            
            // Procura o número na lista de mármores
            for (int j = 0; j < N; j++) {
                if (marmores[j] == consulta) {
                    encontrado = 1;
                    posicao = j + 1; // posição baseada em 1
                    break;
                }
            }
            
            // Imprime o resultado da consulta
            if (encontrado) {
                printf("%d found at %d\n", consulta, posicao);
            } else {
                printf("%d not found\n", consulta);
            }
        }
    }
    
    return 0;
}
