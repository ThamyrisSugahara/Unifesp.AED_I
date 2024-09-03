#include <string.h> // Inclusão da biblioteca para manipulação de strings.
#include <stdlib.h> // Inclusão da biblioteca para alocação dinâmica de memória e funções auxiliares.
#include <stdio.h>  // Inclusão da biblioteca para entrada e saída padrão.

// Declaração de variáveis globais.
int tam; // Número de palavras na frase.
char palavras[100][100]; // Matriz para armazenar até 100 palavras, cada uma com até 99 caracteres.

 // Função para comparar duas strings com base em seu comprimento.
// Retorna a diferença entre o comprimento de b e o comprimento de a.
int comp(char *a, char *b)
{
    return strlen(b) - strlen(a); // Retorna a diferença de comprimento entre b e a.
}

// Função para ordenar a matriz de palavras usando o algoritmo de ordenação por inserção.
// Ordena as palavras com base no comprimento (do maior para o menor).
void insertionSort()
{
    char aux[100]; // Array auxiliar para troca de palavras.

    // Loop para percorrer o vetor a partir do segundo elemento.
    for (int i = 1; i < tam; ++i)
    {
        int j = i; // Inicializa j com o índice atual i.
        int k = j - 1; // Inicializa k com o índice anterior a j.

        // Loop para mover a palavra para a posição correta com base no comprimento.
        while (k > -1 && comp(palavras[j], palavras[k]) < 0)
        {
            strcpy(aux, palavras[j]); // Copia a palavra de palavras[j] para aux.
            strcpy(palavras[j], palavras[k]); // Copia a palavra de palavras[k] para palavras[j].
            strcpy(palavras[k], aux); // Copia a palavra armazenada em aux para palavras[k].
            --j; // Move j para a esquerda.
            --k; // Move k para a esquerda.
        }
    }
}

// Função principal do programa.
int main()
{
    int N; // Número de frases a serem processadas.
    char frase[10000], *ptr; // Array para armazenar uma frase e ponteiro para tokens.

    scanf("%d\n", &N); // Lê o número de frases a serem processadas.

    // Loop para processar cada frase.
    for (int k = 0; k < N; ++k)
    {
        scanf("%[^\n]\n", frase); // Lê uma linha inteira (frase) até uma nova linha.

        tam = 0; // Inicializa o número de palavras na frase.
        ptr = strtok(frase, " "); // Divide a frase em tokens usando o espaço como delimitador.

        // Loop para armazenar cada palavra na matriz de palavras.
        while (ptr != NULL)
        {
            strcpy(palavras[tam++], ptr); // Copia o token atual para a matriz de palavras e incrementa tam.
            ptr = strtok(NULL, " "); // Obtém o próximo token.
        }

        insertionSort(); // Ordena as palavras com base no comprimento.

        // Imprime as palavras ordenadas.
        printf("%s", palavras[0]); // Imprime a primeira palavra.
        for (int i = 1; i < tam; ++i) // Loop para imprimir as palavras restantes.
        {
            printf(" %s", palavras[i]); // Imprime a palavra atual precedida por um espaço.
        }
        printf("\n"); // Imprime uma nova linha após a lista de palavras.
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso.
}
