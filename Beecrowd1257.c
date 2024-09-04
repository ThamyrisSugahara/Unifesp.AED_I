#include <stdio.h>
#include <string.h>

int main() {
    int N, L, hash;
    char frase[100];  // Assumindo que cada frase tem no máximo 100 caracteres

    scanf("%d", &N);

    for (int k = 0; k < N; ++k) {
        hash = 0;
        scanf("%d", &L);

        for (int i = 0; i < L; ++i) {
            scanf("%s", frase);

            for (int j = 0; j < strlen(frase); ++j) {
                hash += (frase[j] - 'A') + i + j;
            }
        }

        printf("%d\n", hash);
    }

    return 0;
}
