#include <stdio.h>      // Biblioteca padrão de entrada e saída
#include <stdlib.h>     // Biblioteca padrão com funções como malloc, free, qsort, etc.

// Estrutura para representar uma aresta do grafo
typedef struct {
    int u, v, weight;  // 'u' e 'v' são os vértices que a aresta conecta, 'weight' é o peso da aresta
} Edge;

// Função de comparação usada para ordenar as arestas pelo peso
int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;  // Converter o ponteiro genérico para o tipo Edge
    Edge *edgeB = (Edge *)b;  // Converter o ponteiro genérico para o tipo Edge
    return edgeA->weight - edgeB->weight;  // Retorna a diferença entre os pesos (ordem crescente)
}

// Função para encontrar o representante (raiz) de um conjunto em Union-Find
int find(int parent[], int i) {
    if (parent[i] == i)        // Se o próprio nó é o seu representante (raiz)
        return i;              // Retorna o próprio nó
    return find(parent, parent[i]);  // Caso contrário, busca o representante recursivamente
}

// Função para unir dois conjuntos em Union-Find
void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);  // Encontra o representante (raiz) do conjunto de 'u'
    int rootV = find(parent, v);  // Encontra o representante (raiz) do conjunto de 'v'

    // Verifica as alturas (rank) das árvores dos conjuntos para unir eficientemente
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;  // Se a árvore de 'u' é menor, 'u' se torna filho de 'v'
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;  // Se a árvore de 'v' é menor, 'v' se torna filho de 'u'
    } else {
        parent[rootV] = rootU;  // Se as árvores têm a mesma altura, 'v' se torna filho de 'u'
        rank[rootU]++;          // E a altura da árvore de 'u' é incrementada
    }
}

int main() {
    int m, n;  // 'm' é o número de junções, 'n' é o número de estradas

    // Loop para processar múltiplos casos de teste
    while (1) {
        scanf("%d %d", &m, &n);  // Lê os valores de 'm' e 'n'
        if (m == 0 && n == 0) {  // Se ambos forem zero, encerra a leitura
            break;
        }

        Edge edges[n];  // Array para armazenar as arestas do grafo
        int totalCost = 0;  // Variável para armazenar o custo total de todas as estradas

        // Lê todas as arestas e acumula o custo total
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
            totalCost += edges[i].weight;  // Soma o peso da estrada ao custo total
        }

        // Ordena as arestas pelo peso usando a função 'compare'
        qsort(edges, n, sizeof(Edge), compare);

        int parent[m], rank[m];  // Arrays para o Union-Find: 'parent' para o representante, 'rank' para a altura das árvores
        for (int i = 0; i < m; i++) {
            parent[i] = i;  // Inicialmente, cada nó é o representante de si mesmo
            rank[i] = 0;    // E as alturas das árvores são 0
        }

        int mstCost = 0;  // Variável para armazenar o custo total da Árvore Geradora Mínima (MST)
        int edgeCount = 0;  // Contador para o número de arestas na MST

        // Percorre as arestas em ordem crescente de peso
        for (int i = 0; i < n && edgeCount < m - 1; i++) {
            int u = edges[i].u;  // Vértice 'u' da aresta
            int v = edges[i].v;  // Vértice 'v' da aresta
            int weight = edges[i].weight;  // Peso da aresta

            int setU = find(parent, u);  // Encontra o representante do conjunto de 'u'
            int setV = find(parent, v);  // Encontra o representante do conjunto de 'v'

            if (setU != setV) {  // Se 'u' e 'v' estão em conjuntos diferentes, a aresta é segura para adicionar à MST
                mstCost += weight;  // Adiciona o peso da aresta ao custo da MST
                unionSets(parent, rank, setU, setV);  // Une os dois conjuntos
                edgeCount++;  // Incrementa o contador de arestas na MST
            }
        }

        int maxSavings = totalCost - mstCost;  // Calcula a economia máxima subtraindo o custo da MST do custo total
        printf("%d\n", maxSavings);  // Imprime a economia máxima para o caso de teste
    }

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
