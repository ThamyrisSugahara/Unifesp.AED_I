#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    char nome[21];
    int posicao;
    struct Node* proximo;
} Node;

// Função para criar um novo nó
Node* criarNo(char nome[], int posicao) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    strcpy(novoNo->nome, nome);
    novoNo->posicao = posicao;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir um nó na lista encadeada em ordem alfabética
void inserirEmOrdem(Node** cabeca, char nome[], int posicao) {
    Node* novoNo = criarNo(nome, posicao);
    if (*cabeca == NULL || strcmp(nome, (*cabeca)->nome) < 0) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    } else {
        Node* atual = *cabeca;
        while (atual->proximo != NULL && strcmp(nome, atual->proximo->nome) >= 0) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

// Função para liberar a memória da lista encadeada
void liberarLista(Node* cabeca) {
    Node* atual = cabeca;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Node* cabeca = NULL;

    // Lê os nomes dos alunos e suas posições e insere na lista encadeada
    for (int i = 0; i < N; i++) {
        char nome[21];
        scanf("%s", nome);
        inserirEmOrdem(&cabeca, nome, i + 1);
    }

    // Encontra o nome do aluno sorteado na posição K
    Node* atual = cabeca;
    for (int i = 1; i < K; i++) {
        atual = atual->proximo;
    }

    // Imprime o nome do aluno sorteado
    printf("%s\n", atual->nome);

    // Libera a memória alocada
    liberarLista(cabeca);

    return 0;
}
