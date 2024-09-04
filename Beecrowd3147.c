#include <stdio.h>
#include <stdlib.h>

typedef struct Exercito {
    int soldados;
    int lado; // 0 para lado do bem, 1 para lado do mal
    struct Exercito *prox;
} Exercito;

Exercito *criar_exercito(int soldados, int lado) {
    Exercito *novo = (Exercito *)malloc(sizeof(Exercito));
    if (novo != NULL) {
        novo->soldados = soldados;
        novo->lado = lado;
        novo->prox = NULL;
    }
    return novo;
}

void inserir_exercito(Exercito **head, Exercito *novo) {
    if (*head == NULL) {
        *head = novo;
    } else {
        Exercito *temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void liberar_exercitos(Exercito *head) {
    Exercito *temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}

int calcular_vencedor(Exercito *head) {
    int total_bem = 0, total_mal = 0;
    while (head != NULL) {
        if (head->lado == 0) {
            total_bem += head->soldados;
        } else {
            total_mal += head->soldados;
        }
        head = head->prox;
    }

    if (total_bem > total_mal) {
        return 1; // Lado do bem vence
    } else if (total_bem < total_mal) {
        return 0; // Lado do mal vence
    } else {
        return -1; // Empate
    }
}

int main() {
    int H, E, A, O, W, X;
    scanf("%d %d %d %d %d %d", &H, &E, &A, &O, &W, &X);

    Exercito *head = NULL;

    inserir_exercito(&head, criar_exercito(H, 0)); // Humanos
    inserir_exercito(&head, criar_exercito(E, 0)); // Elfos
    inserir_exercito(&head, criar_exercito(A, 0)); // Anões
    inserir_exercito(&head, criar_exercito(O, 1)); // Orcs
    inserir_exercito(&head, criar_exercito(W, 1)); // Wargs
    inserir_exercito(&head, criar_exercito(X, 0)); // Águias

    int resultado = calcular_vencedor(head);

    if (resultado == 1) {
        printf("Middle-earth is safe.\n");
    } else if (resultado == 0) {
        printf("Sauron has returned.\n");
    } else {
        printf("Bilbo will defeat the last orc or warg with Sting.\n");
    }

    liberar_exercitos(head);

    return 0;
}