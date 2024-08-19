#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta no grafo
typedef struct {
    int origem, destino, peso;
} Aresta;

// Função de comparação para qsort, compara as arestas com base no peso
int comparaArestas(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->peso - arestaB->peso; // Retorna diferença de pesos
}

// Função para encontrar o representante do conjunto ao qual o elemento i pertence
int find(int pai[], int i) {
    if (pai[i] == i) // Se i é o próprio pai, ele é o representante do conjunto
        return i;
    return find(pai, pai[i]); // Recurre até encontrar o representante
}

// Função para unir dois conjuntos, baseando-se no rank
void unionSets(int pai[], int rank[], int x, int y) {
    int raizX = find(pai, x); // Encontra o representante do conjunto de x
    int raizY = find(pai, y); // Encontra o representante do conjunto de y

    // Compara os ranks e faz a união do menor rank com o maior
    if (rank[raizX] < rank[raizY])
        pai[raizX] = raizY; // raizY se torna pai de raizX
    else if (rank[raizX] > rank[raizY])
        pai[raizY] = raizX; // raizX se torna pai de raizY
    else {
        pai[raizY] = raizX; // Se os ranks são iguais, raizX se torna pai de raizY
        rank[raizX]++; // Aumenta o rank do novo pai
    }
}

int main() {
    int M, N;

    // Loop para processar vários casos de teste até encontrar o caso final (M = N = 0)
    while (1) {
        // Lê o número de cidades (M) e o número de rotas (N)
        scanf("%d %d", &M, &N);

        // Condição de término: se M e N forem ambos 0, o programa para
        if (M == 0 && N == 0) break;

        // Aloca memória para armazenar todas as arestas do grafo
        Aresta* arestas = (Aresta*) malloc(N * sizeof(Aresta));

        // Lê todas as arestas do grafo
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
        }

        // Ordena as arestas pelo peso (menor para maior)
        qsort(arestas, N, sizeof(Aresta), comparaArestas);

        // Arrays para armazenar os pais e os ranks dos elementos
        int* pai = (int*) malloc(M * sizeof(int));
        int* rank = (int*) malloc(M * sizeof(int));

        // Inicializa cada cidade como seu próprio pai (conjunto individual) e rank 0
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            rank[i] = 0;
        }

        int custoTotal = 0; // Inicializa o custo total da MST
        int arestasUsadas = 0; // Contador para as arestas usadas na MST

        // Itera sobre as arestas ordenadas, escolhendo as que não formam ciclos
        for (int i = 0; i < N && arestasUsadas < M - 1; i++) {
            int origem = find(pai, arestas[i].origem); // Encontra o representante do conjunto de origem
            int destino = find(pai, arestas[i].destino); // Encontra o representante do conjunto de destino

            // Se origem e destino estão em conjuntos diferentes, une-os
            if (origem != destino) {
                custoTotal += arestas[i].peso; // Adiciona o peso da aresta ao custo total
                unionSets(pai, rank, origem, destino); // Une os dois conjuntos
                arestasUsadas++; // Incrementa o contador de arestas usadas
            }
        }

        // Imprime o custo total da MST para o caso de teste atual
        printf("%d\n", custoTotal);

        // Libera a memória alocada para as arestas e para os arrays pai e rank
        free(arestas);
        free(pai);
        free(rank);
    }

    return 0;
}
