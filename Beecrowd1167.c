#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[31];
    int value;
    struct Node *next;
    struct Node *prev;
    int removed; // Indica se o nó foi removido
} Node;

Node* createNode(char* name, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->next = newNode->prev = newNode;
    newNode->removed = 0; // Inicialmente não removido
    return newNode;
}

void insertAfter(Node* refNode, Node* newNode) {
    newNode->next = refNode->next;
    newNode->prev = refNode;
    refNode->next->prev = newNode;
    refNode->next = newNode;
}

void deleteNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->removed = 1; // Marcar como removido
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        Node *head = NULL, *tail = NULL;
        
        for (int i = 0; i < N; ++i) {
            char name[31];
            int value;
            scanf("%s %d", name, &value);
            Node* newNode = createNode(name, value);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                insertAfter(tail, newNode);
                tail = newNode;
            }
        }
        
        Node *current = head;
        while (N > 1) {
            int steps = current->value;
            Node *toDelete = current;
            for (int i = 0; i < steps; ++i) {
                current = (steps % 2 == 0) ? current->next : current->prev;
                while (current->removed) {
                    current = (steps % 2 == 0) ? current->next : current->prev;
                }
            }
            Node *nextNode = (steps % 2 == 0) ? current->next : current->prev;
            deleteNode(toDelete);
            N--;
            current = nextNode;
        }
        
        printf("Vencedor(a): %s\n", current->name);
    }
    return 0;
}

