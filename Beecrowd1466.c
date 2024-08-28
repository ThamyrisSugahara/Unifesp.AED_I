#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define um tipo para representar o valor dos nós da árvore
typedef int Valor;

// Estrutura para representar um nó da árvore binária
typedef struct No {
    Valor valor;          // Valor armazenado no nó
    struct No* esquerda;  // Ponteiro para o nó filho à esquerda
    struct No* direita;   // Ponteiro para o nó filho à direita
} No;

// Função para criar uma folha (nó vazio)
No* criarFolha() {
    return NULL;  // Uma folha é representada por um ponteiro nulo
}

// Função para criar um novo nó na árvore
No* criarArvore(Valor v, No* esq, No* dir) {
    No* novoNo = (No*)malloc(sizeof(No));  // Aloca memória para o novo nó
    novoNo->valor = v;                     // Atribui o valor ao nó
    novoNo->esquerda = esq;                // Define o filho à esquerda
    novoNo->direita = dir;                 // Define o filho à direita
    return novoNo;                         // Retorna o nó criado
}

// Função para inserir um valor na árvore binária
No* inserir(No* no, Valor v) {
    if (no == NULL) {  // Se o nó atual é uma folha (nulo)
        return criarArvore(v, criarFolha(), criarFolha());  // Cria um novo nó com o valor
    }
    if (v < no->valor) {  // Se o valor é menor que o valor do nó atual
        no->esquerda = inserir(no->esquerda, v);  // Insere recursivamente na subárvore esquerda
    } else {  // Se o valor é maior ou igual ao valor do nó atual
        no->direita = inserir(no->direita, v);  // Insere recursivamente na subárvore direita
    }
    return no;  // Retorna o nó atualizado
}

// Estrutura para representar uma fila, usada para percorrer a árvore em largura
typedef struct Fila {
    No** elementos;   // Vetor de ponteiros para os nós da árvore
    int inicio;       // Índice de onde começa a fila
    int fim;          // Índice de onde termina a fila
    int tamanho;      // Número de elementos na fila
    int capacidade;   // Capacidade máxima da fila
} Fila;

// Função para criar uma fila com uma dada capacidade
Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));  // Aloca memória para a fila
    fila->elementos = (No**)malloc(capacidade * sizeof(No*));  // Aloca memória para os elementos da fila
    fila->inicio = fila->fim = fila->tamanho = 0;  // Inicializa os índices e tamanho
    fila->capacidade = capacidade;  // Define a capacidade da fila
    return fila;  // Retorna a fila criada
}

// Função para verificar se a fila está vazia
bool filaVazia(Fila* fila) {
    return fila->tamanho == 0;  // A fila está vazia se o tamanho for 0
}

// Função para inserir um nó na fila
void inserirFila(Fila* fila, No* no) {
    fila->elementos[fila->fim] = no;  // Insere o nó no final da fila
    fila->fim = (fila->fim + 1) % fila->capacidade;  // Atualiza o índice de fim (com comportamento circular)
    fila->tamanho++;  // Incrementa o tamanho da fila
}

// Função para remover um nó da fila
No* removerFila(Fila* fila) {
    No* no = fila->elementos[fila->inicio];  // Obtém o nó no início da fila
    fila->inicio = (fila->inicio + 1) % fila->capacidade;  // Atualiza o índice de início (com comportamento circular)
    fila->tamanho--;  // Decrementa o tamanho da fila
    return no;  // Retorna o nó removido
}

int main() {
    int c;
    scanf("%d", &c);  // Lê o número de casos de teste

    for (int i = 1; i <= c; i++) {  // Loop para processar cada caso de teste
        int n;
        scanf("%d", &n);  // Lê o número de valores que serão inseridos na árvore
        No* arvore = criarFolha();  // Inicializa a árvore como uma folha vazia
        for (int j = 0; j < n; j++) {  // Loop para inserir cada valor na árvore
            int valor;
            scanf("%d", &valor);  // Lê o valor a ser inserido
            arvore = inserir(arvore, valor);  // Insere o valor na árvore
        }

        Fila* fila = criarFila(n);  // Cria uma fila com capacidade para n elementos
        inserirFila(fila, arvore);  // Insere a árvore completa na fila

        printf("Case %d:\n", i);  // Imprime o cabeçalho para o caso de teste atual
        bool primeiro = true;  // Variável para controlar a formatação da saída

        while (!filaVazia(fila)) {  // Loop para percorrer a árvore por nível
            No* no = removerFila(fila);  // Remove o nó da fila
            if (primeiro) {  // Se for o primeiro valor da linha
                printf("%d", no->valor);  // Imprime o valor sem espaço antes
                primeiro = false;  // Marca que o primeiro valor já foi impresso
            } else {  // Para os valores subsequentes
                printf(" %d", no->valor);  // Imprime com espaço antes
            }
            if (no->esquerda != NULL) inserirFila(fila, no->esquerda);  // Insere o filho esquerdo na fila, se existir
            if (no->direita != NULL) inserirFila(fila, no->direita);  // Insere o filho direito na fila, se existir
        }

        printf("\n\n");  // Imprime uma linha em branco após cada caso de teste
    }

    return 0;  // Indica que o programa terminou corretamente
}
