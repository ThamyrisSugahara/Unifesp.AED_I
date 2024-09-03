#include <stdio.h>   // Inclusão da biblioteca para entrada e saída padrão.
#include <stdlib.h>  // Inclusão da biblioteca para alocação dinâmica de memória e funções auxiliares.
#include <math.h>    // Inclusão da biblioteca para funções matemáticas, como round().

char **AlocaMatriz(int m, int n);   // Declaração da função para alocar uma matriz de caracteres.
void LiberaMatriz(char **M, int m); // Declaração da função para liberar a memória de uma matriz de caracteres.
void leNome(char **mat, int n);    // Declaração da função para ler nomes e armazená-los em uma matriz.

int main() {
    // Declaração de variáveis.
    int n, i;               // n: número de nomes, i: variável de iteração.
    double lGarrafa, lCuia; // lGarrafa: quantidade inicial, lCuia: quantidade a ser subtraída.
    char **nomes;           // Ponteiro para a matriz de nomes.

    // Entrada de dados.
    scanf("%d %lf %lf", &n, &lGarrafa, &lCuia); // Lê o número de nomes, a quantidade inicial e a quantidade a ser subtraída.
    getchar(); // Consumir o caractere de nova linha após a entrada dos números.
    nomes = AlocaMatriz(n, 13); // Aloca memória para a matriz de nomes com n linhas e 13 colunas.
    leNome(nomes, n); // Lê os nomes e os armazena na matriz.

    // Processamento
    double aux = lGarrafa; // Inicializa a variável auxiliar com a quantidade inicial.
    int cont = -1; // Inicializa o contador para o índice dos nomes.
    while(1) { // Loop infinito até que uma condição de parada seja satisfeita.
        cont++; // Incrementa o contador.
        if (aux - lCuia <= 0) { // Se a quantidade auxiliar for menor ou igual a zero, encerra o loop.
            break;
        } else { // Caso contrário, atualiza a quantidade auxiliar.
            aux = round((aux - lCuia) * 10.0) / 10.0; // Subtrai lCuia de aux e arredonda para uma casa decimal.
        }
    }
    
    // Saída
    printf("%s %.1lf\n", nomes[cont % n], aux); // Imprime o nome na posição cont % n e a quantidade restante com uma casa decimal.
    LiberaMatriz(nomes, n); // Libera a memória alocada para a matriz de nomes.
    return 0; // Fim do programa.
}

// Função para alocar uma matriz de caracteres com m linhas e n colunas.
char **AlocaMatriz(int m, int n) {
    char **M; // Ponteiro para a matriz.
    int i; // Variável de iteração.
 
    M = (char **)malloc(sizeof(char *) * m); // Aloca memória para as linhas da matriz.
    for (i = 0; i < m; i++) { // Loop para alocar memória para cada linha.
        M[i] = (char *)malloc(sizeof(char) * n); // Aloca memória para cada linha com n colunas.
    }
    return M; // Retorna o ponteiro para a matriz alocada.
}

// Função para liberar a memória de uma matriz de caracteres.
void LiberaMatriz(char **M, int m) {
    int i; // Variável de iteração.
    for (i = 0; i < m; i++) { // Loop para liberar a memória de cada linha.
        free(M[i]); // Libera a memória de cada linha.
    }
    free(M); // Libera a memória do ponteiro para as linhas.
}

// Função para ler nomes e armazená-los em uma matriz.
void leNome(char **mat, int n) {
    int i; // Variável de iteração.
    for (i = 0; i < n; i++) { // Loop para ler cada nome.
        scanf("%s", mat[i]); // Lê o nome e armazena na matriz.
    }
}
