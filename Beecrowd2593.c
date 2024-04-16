#include <stdio.h>
#include <string.h>

#define MAX_STRING 10001
#define MAX_PALAVRA 51
#define MAX_PALAVRAS 128

void buscaPalavra(char *texto, char *palavra) {
    int posicao = -1; // Inicializa a posição como -1 (não encontrada)
    char *ptr = texto;
    
    if ((ptr = strstr(ptr, palavra)) == NULL) {
        printf("-1\n");
    } else {
       while ((ptr = strstr(ptr, palavra)) != NULL) {
        if ((ptr == texto || *(ptr - 1) == ' ') && // Verifica se é o início da palavra
            (*(ptr + strlen(palavra)) == ' ' || *(ptr + strlen(palavra)) == '\0')) { // Verifica se é o final da palavra
            if (posicao == -1) {
                posicao = ptr - texto; // Atualiza a posição se for a primeira ocorrência da palavra
            } else {
                printf(" "); // Imprime um espaço para separar as posições
            }
            printf("%d", ptr - texto); // Imprime a posição da palavra
        }
        ptr++; // Move para a próxima posição para procurar a próxima ocorrência da palavra
        }  
    }
    
    printf("\n"); // Imprime uma nova linha após a impressão das posições
}

int main() {
    char texto[MAX_STRING];
    char palavras[MAX_PALAVRAS][MAX_PALAVRA];
    int n_palavras;

    fgets(texto, MAX_STRING, stdin);
    strtok(texto, "\n");

    scanf("%d", &n_palavras);

    for (int i = 0; i < n_palavras; i++) {
        scanf("%s", palavras[i]);
    }

    for (int i = 0; i < n_palavras; i++) {
        buscaPalavra(texto, palavras[i]);
    }

    return 0;
}
