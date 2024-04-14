#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10001
#define MAX_M 10001

// Estrutura para o cliente
typedef struct {
    int items;
} Cliente;

// Estrutura para um nó da fila
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

// Função para inicializar a fila
Fila* inicializarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

// Função para enfileirar um elemento
void enfileirar(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

// Função para desenfileirar um elemento
int desenfileirar(Fila* fila) {
    if (fila->inicio == NULL) {
        return -1; // Fila vazia
    }
    No* temp = fila->inicio;
    int valor = temp->valor;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return valor;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Função para liberar a memória da fila
void liberarFila(Fila* fila) {
    while (!estaVazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Lendo os tempos de processamento de cada caixa e inicializando os tempos de término de atendimento
    int caixas[N];
    int tempos[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &caixas[i]);
        tempos[i] = 0;
    }

    // Lendo o número de itens de cada cliente
    Cliente clientes[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &clientes[i].items);
    }

    // Processando cada cliente
    Fila* fila = inicializarFila();
    for (int i = 0; i < M; i++) {
        // Encontrando o caixa que estará livre mais cedo
        int caixa = 0;
        for (int j = 1; j < N; j++) {
            if (tempos[j] < tempos[caixa]) {
                caixa = j;
            }
        }

        // Atualizando o tempo de término de atendimento no caixa escolhido
        tempos[caixa] += caixas[caixa] * clientes[i].items;
        enfileirar(fila, tempos[caixa]);
    }

    // Encontrando o maior tempo de término entre todos os caixas
    int tempo_total = desenfileirar(fila);
    while (!estaVazia(fila)) {
        int tempo = desenfileirar(fila);
        if (tempo > tempo_total) {
            tempo_total = tempo;
        }
    }

    // Imprimindo o tempo total
    printf("%d\n", tempo_total);

    // Liberando a memória da fila
    liberarFila(fila);

    return 0;
}
