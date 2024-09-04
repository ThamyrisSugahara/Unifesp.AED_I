#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Valor;

typedef struct No {
    Valor valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarFolha() {
    return NULL;
}

No* criarArvore(Valor v, No* esq, No* dir) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = v;
    novoNo->esquerda = esq;
    novoNo->direita = dir;
    return novoNo;
}

int altura(No* no) {
    if (no == NULL) return -1;
    int alturaEsq = altura(no->esquerda);
    int alturaDir = altura(no->direita);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

No* inserir(No* no, Valor v) {
    if (no == NULL) {
        return criarArvore(v, criarFolha(), criarFolha());
    }
    if (v < no->valor) {
        no->esquerda = inserir(no->esquerda, v);
    } else {
        no->direita = inserir(no->direita, v);
    }
    return no;
}

bool pesquisar(No* no, Valor v) {
    if (no == NULL) return false;
    if (v == no->valor) return true;
    if (v < no->valor) return pesquisar(no->esquerda, v);
    return pesquisar(no->direita, v);
}

void infixa(No* no) {
    if (no == NULL) return;
    infixa(no->esquerda);
    printf("%d ", no->valor);
    infixa(no->direita);
}

void prefixa(No* no) {
    if (no == NULL) return;
    printf("%d ", no->valor);
    prefixa(no->esquerda);
    prefixa(no->direita);
}

void posfixa(No* no) {
    if (no == NULL) return;
    posfixa(no->esquerda);
    posfixa(no->direita);
    printf("%d ", no->valor);
}

typedef struct Fila {
    No** elementos;
    int tamanho;
    int capacidade;
} Fila;

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->elementos = (No**)malloc(capacidade * sizeof(No*));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

bool filaVazia(Fila* fila) {
    return fila->tamanho == 0;
}

void inserirFila(Fila* fila, No* no) {
    if (fila->tamanho == fila->capacidade) {
        fila->capacidade *= 2;
        fila->elementos = (No**)realloc(fila->elementos, fila->capacidade * sizeof(No*));
    }
    fila->elementos[fila->tamanho++] = no;
}

No* removerFila(Fila* fila) {
    if (filaVazia(fila)) return NULL;
    No* no = fila->elementos[0];
    for (int i = 1; i < fila->tamanho; i++) {
        fila->elementos[i-1] = fila->elementos[i];
    }
    fila->tamanho--;
    return no;
}

int main() {
    int c;
    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        int n;
        scanf("%d", &n);
        No* arvore = criarFolha();
        for (int j = 0; j < n; j++) {
            int valor;
            scanf("%d", &valor);
            arvore = inserir(arvore, valor);
        }

        Fila* fila = criarFila(n);
        inserirFila(fila, arvore);
        printf("Case %d:", i);

        while (!filaVazia(fila)) {
            No* no = removerFila(fila);
            printf(" %d", no->valor);
            if (no->esquerda != NULL) inserirFila(fila, no->esquerda);
            if (no->direita != NULL) inserirFila(fila, no->direita);
        }
        printf("\n");
    }

    return 0;
}
