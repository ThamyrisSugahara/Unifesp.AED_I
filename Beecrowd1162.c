#include <stdio.h> // Inclusão da biblioteca para entrada e saída padrão.

// Função para comparar dois inteiros a e b.
// Retorna a diferença a - b.
int comp(int a, int b)
{
    return a - b; // Retorna a diferença entre a e b.
}

// Função para trocar os valores de duas variáveis inteiras.
// Recebe os ponteiros para as variáveis a e b.
void swap(int *a, int *b)
{
    int aux = *a; // Armazena o valor de *a na variável auxiliar aux.
    *a = *b;      // Atribui o valor de *b a *a.
    *b = aux;     // Atribui o valor armazenado em aux a *b.
}

// Função para ordenar um vetor de inteiros usando o algoritmo de ordenação por inserção.
// Recebe o vetor V e o tamanho n do vetor.
// Retorna o número de trocas realizadas durante a ordenação.
int insertionSort(int *V, int n)
{
    int trocas = 0; // Inicializa o contador de trocas.

    // Loop para percorrer o vetor a partir do segundo elemento.
    for (int i = 1; i < n; ++i)
    {
        int j = i; // Inicializa j com o índice atual i.
        int k = j - 1; // Inicializa k com o índice anterior a j.

        // Loop para mover o elemento V[j] para a posição correta.
        while (k > -1 && comp(V[j], V[k]) < 0)
        {
            swap(&V[j], &V[k]); // Troca os elementos V[j] e V[k].
            ++trocas;           // Incrementa o contador de trocas.
            --j;                // Move j para a esquerda.
            --k;                // Move k para a esquerda.
        }
    }

    return trocas; // Retorna o número total de trocas realizadas.
}

// Função principal do programa.
int main()
{
    int N, L, vagoes[50]; // Declaração de variáveis. N: número de casos de teste, L: número de vagões, vagoes: vetor para armazenar os vagões.

    scanf("%d", &N); // Lê o número de casos de teste.

    // Loop para processar cada caso de teste.
    for (int k = 0; k < N; ++k)
    {
        scanf("%d", &L); // Lê o número de vagões para o caso de teste atual.

        // Loop para ler os valores dos vagões.
        for (int i = 0; i < L; ++i)
        {
            scanf("%d", &vagoes[i]); // Lê o valor do vagão e armazena no vetor vagoes.
        }

        // Ordena o vetor de vagões e imprime o número de trocas realizadas.
        printf("Optimal train swapping takes %d swaps.\n", insertionSort(vagoes, L));
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso.
}
