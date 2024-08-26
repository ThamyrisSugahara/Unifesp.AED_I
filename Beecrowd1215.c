#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 201

// Função de comparação usada para ordenar as palavras
int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char texto[MAX_WORD_LEN];
    char *palavras[MAX_WORDS];
    int total_palavras = 0;

    // Inicializa o array de palavras
    for (int i = 0; i < MAX_WORDS; i++) {
        palavras[i] = NULL;
    }

    // Lê todo o texto até o EOF
    while (scanf("%s", texto) != EOF) {
        char palavra[MAX_WORD_LEN];
        int len = 0;

        // Extrai apenas as letras da palavra, transformando em minúsculas
        for (int i = 0; texto[i]; i++) {
            if (isalpha(texto[i])) {
                palavra[len++] = tolower(texto[i]);
            } else if (len > 0) {
                palavra[len] = '\0';

                // Verifica se a palavra já foi adicionada
                int existe = 0;
                for (int j = 0; j < total_palavras; j++) {
                    if (strcmp(palavras[j], palavra) == 0) {
                        existe = 1;
                        break;
                    }
                }

                if (!existe) {
                    palavras[total_palavras] = strdup(palavra);
                    total_palavras++;
                }

                len = 0;
            }
        }

        // Caso ainda haja uma palavra sendo formada
        if (len > 0) {
            palavra[len] = '\0';

            int existe = 0;
            for (int j = 0; j < total_palavras; j++) {
                if (strcmp(palavras[j], palavra) == 0) {
                    existe = 1;
                    break;
                }
            }

            if (!existe) {
                palavras[total_palavras] = strdup(palavra);
                total_palavras++;
            }
        }
    }

    // Ordena as palavras em ordem alfabética
    qsort(palavras, total_palavras, sizeof(char *), cmp);

    // Imprime as palavras em ordem alfabética
    for (int i = 0; i < total_palavras; i++) {
        printf("%s\n", palavras[i]);
        free(palavras[i]);
    }

    return 0;
}
