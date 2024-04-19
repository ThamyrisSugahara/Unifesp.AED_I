#include <stdlib.h>
#include <stdio.h>

typedef struct dequeNo
{
    int valor;
    struct dequeNo *anterior, *proximo;
}dequeNo;

typedef struct deque
{
    int tamanho;
    dequeNo *frente, *tras;
}deque;

void push_front(deque *d, int valor)
{
    d->tamanho += 1;
    dequeNo *novaFrente = (dequeNo *)malloc(sizeof(dequeNo));

    novaFrente->valor = valor;
    novaFrente->proximo = d->frente;
    if (d->frente != NULL)
        d->frente->anterior = novaFrente;
    d->frente = novaFrente;
    if (d->tras == NULL)
        d->tras = d->frente;
}

void push_back(deque *d, int valor)
{
    d->tamanho += 1;
    dequeNo *novoTras = (dequeNo *)malloc(sizeof(dequeNo));

    novoTras->valor = valor;
    novoTras->anterior = d->tras;
    if (d->tras != NULL)
        d->tras->proximo = novoTras;
    d->tras = novoTras;
    if (d->frente == NULL)
        d->frente = d->tras;
}

void pop_front(deque *d)
{
    if (d->tamanho > 0)
    {
        d->tamanho -= 1;
        dequeNo *velhaFrente = d->frente;
        d->frente = d->frente->proximo;
        free(velhaFrente);
    }
}

void pop_back(deque *d)
{
    if (d->tamanho > 0)
    {
        d->tamanho -= 1;
        dequeNo *velhoTras = d->tras;
        d->tras = d->tras->anterior;
        free(velhoTras);
    }
}

int front(deque *d)
{
    return d->frente->valor;
}

int back(deque *d)
{
    return d->tras->valor;
}

int size(deque *d)
{
    return d->tamanho;
}

int empty(deque *d)
{
    return d->tamanho == 0;
}

void inicializa(deque *d)
{
    d->tamanho = 0;
    d->frente = NULL;
    d->tras = NULL;
}

void destroi(deque *d)
{
    while (!empty(d))
    {
        pop_front(d);
    }
}

int main()
{
    int n, first;
    deque cards;

    while (scanf("%d", &n))
    {
        if (!n)
            break;

        inicializa(&cards);

        for (int i = 1; i <= n; ++i)
        {
            push_back(&cards, i);
        }

        first = 1;
        printf("Discarded cards: ");
        while (size(&cards) > 1)
        {
            if (!first)
                printf(", ");
            else
                first = 0;

            printf("%d", front(&cards));

            pop_front(&cards);
            push_back(&cards, front(&cards));
            pop_front(&cards);
        }
        printf("\nRemaining card: %d\n", front(&cards));

        destroi(&cards);
    }

    return 0;
}