#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int K;
        scanf("%d", &K);

        char idioma[21];
        char primeiro_idioma[21];
        int todos_iguais = 1;

        // Lê o primeiro idioma do grupo
        scanf("%s", primeiro_idioma);

        for (int i = 1; i < K; ++i) {
            scanf("%s", idioma);
            // Se algum idioma for diferente do primeiro, marcam todos_iguais como falso
            if (strcmp(idioma, primeiro_idioma) != 0) {
                todos_iguais = 0;
            }
        }

        // Se todos forem iguais, imprime o idioma, caso contrário, imprime "ingles"
        if (todos_iguais) {
            printf("%s\n", primeiro_idioma);
        } else {
            printf("ingles\n");
        }
    }

    return 0;
}
