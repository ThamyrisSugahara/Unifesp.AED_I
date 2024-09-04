#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct Node {
    int identificador;
    struct Node* proximo;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node* frente;
    Node* tras;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

// Função para enfileirar um elemento
void enfileirar(Fila* fila, int identificador) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->identificador = identificador;
    novoNo->proximo = NULL;
    if (filaVazia(fila)) {
        fila->frente = novoNo;
    } else {
        fila->tras->proximo = novoNo;
    }
    fila->tras = novoNo;
}

// Função para desenfileirar um elemento
int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        return -1; // Se a fila estiver vazia, retorna -1
    }
    int identificador = fila->frente->identificador;
    Node* temp = fila->frente;
    fila->frente = fila->frente->proximo;
    free(temp);
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    return identificador;
}

int main() {
    int N, M;
    Fila fila;
    inicializarFila(&fila);
    
    // Lendo a quantidade inicial de pessoas na fila e enfileirando-as
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int identificador;
        scanf("%d", &identificador);
        enfileirar(&fila, identificador);
    }
    
    // Lendo a quantidade de pessoas que deixaram a fila e desenfileirando-as
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int idDeixado;
        scanf("%d", &idDeixado);
        while (!filaVazia(&fila)) {
            int idAtual = desenfileirar(&fila);
            if (idAtual == idDeixado) {
                break;
            }
            enfileirar(&fila, idAtual);
        }
    }
    
    // Imprimindo o estado final da fila
    while (!filaVazia(&fila)) {
        printf("%d ", desenfileirar(&fila));
    }
    printf("\n");
    
    return 0;
}
