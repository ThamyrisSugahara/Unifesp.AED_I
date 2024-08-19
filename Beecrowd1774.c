#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta do grafo
struct Edge {
    int src, dest, weight;  // src: vértice de origem, dest: vértice de destino, weight: peso (custo) da aresta
};

// Estrutura para representar um grafo
struct Graph {
    int V, E;  // V: número de vértices (roteadores), E: número de arestas (cabos)
    struct Edge* edge;  // Um array de arestas
};

// Estrutura para representar um subconjunto para o union-find
struct Subset {
    int parent;  // Pai do subconjunto
    int rank;    // Rank do subconjunto
};

// Função para criar um grafo com V vértices e E arestas
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));  // Aloca memória para o grafo
    graph->V = V;  // Define o número de vértices
    graph->E = E;  // Define o número de arestas
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));  // Aloca memória para as arestas
    return graph;
}

// Função para encontrar o subconjunto de um elemento i (usando path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);  // Faz compressão de caminho
    return subsets[i].parent;
}

// Função para unir dois subconjuntos x e y (usando union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);  // Encontra a raiz de x
    int rootY = find(subsets, y);  // Encontra a raiz de y

    // Une os dois subconjuntos pelo rank
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Função de comparação para qsort para ordenar arestas por peso crescente
int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;  // Ordena em ordem crescente de peso
}

// Função para encontrar a Árvore Geradora Mínima usando o algoritmo de Kruskal
int kruskalMST(struct Graph* graph) {
    int V = graph->V;  // Número de vértices no grafo
    struct Edge result[V];  // Array para armazenar o resultado final (MST)
    int e = 0;  // Índice para result[]
    int i = 0;  // Índice para arestas ordenadas

    // Ordena todas as arestas por peso crescente
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Aloca memória para criar V subconjuntos
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Cria subconjuntos com um único elemento
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;  // Cada vértice é inicialmente seu próprio pai
        subsets[v].rank = 0;  // Inicialmente, o rank é 0
    }

    // Número de arestas para incluir na MST é V-1
    while (e < V - 1 && i < graph->E) {
        // Escolhe a menor aresta. Se não causa ciclo, inclui na MST
        struct Edge nextEdge = graph->edge[i++];  // Pega a próxima aresta mais barata

        int x = find(subsets, nextEdge.src - 1);  // Encontra o subconjunto do vértice de origem
        int y = find(subsets, nextEdge.dest - 1);  // Encontra o subconjunto do vértice de destino

        // Se a inclusão dessa aresta não formar um ciclo, inclua-a no resultado
        if (x != y) {
            result[e++] = nextEdge;  // Adiciona a aresta ao resultado
            Union(subsets, x, y);  // Faz a união dos subconjuntos
        }
    }

    // Calcula o peso total da MST
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
        minimumCost += result[i].weight;  // Soma o peso de todas as arestas na MST

    return minimumCost;  // Retorna o custo mínimo
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);  // Lê o número de roteadores e cabos

    struct Graph* graph = createGraph(R, C);  // Cria o grafo com R roteadores e C cabos

    for (int i = 0; i < C; i++) {
        int V, W, P;
        scanf("%d %d %d", &V, &W, &P);  // Lê a informação de cada cabo
        graph->edge[i].src = V;  // Define o vértice de origem da aresta
        graph->edge[i].dest = W;  // Define o vértice de destino da aresta
        graph->edge[i].weight = P;  // Define o peso (custo) da aresta
    }

    printf("%d\n", kruskalMST(graph));  // Calcula e imprime o custo total da MST

    return 0;
}

