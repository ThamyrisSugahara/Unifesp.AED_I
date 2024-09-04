#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int minLettersToAdd(char sequence[]) {
    int freq[26] = {0}; // Array para contar a frequência de cada letra
    int oddCount = 0; // Contador para contagem de letras com frequência ímpar

    // Contagem da frequência de cada letra na sequência
    for (int i = 0; i < strlen(sequence); i++) {
        freq[sequence[i] - 'a']++;
    }

    // Contagem de letras com frequência ímpar
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    // O número de letras a serem adicionadas é o máximo entre 0 e (número de letras com frequência ímpar - 1)
    return (oddCount == 0) ? 0 : oddCount - 1;
}

int main() {
    char sequence[MAX_LENGTH];

    // Loop para processar múltiplos casos de teste
    while (scanf("%s", sequence) != EOF) {
        printf("%d\n", minLettersToAdd(sequence));
    }

    return 0;
}