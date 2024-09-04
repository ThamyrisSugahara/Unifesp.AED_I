#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
#define ALPHABET_SIZE 26

// Função para calcular a quantidade mínima de letras a serem adicionadas para formar um palíndromo
int minLetrasAdicionadas(char sequencia[]) {
    int frequencia[ALPHABET_SIZE] = {0}; // Inicializa a frequência de cada caractere como 0
    int impares = 0; // Contador para caracteres com frequência ímpar
    
    // Calcula a frequência de cada caractere na sequência
    for (int i = 0; i < strlen(sequencia); i++) {
        frequencia[sequencia[i] - 'a']++;
    }
    
    // Conta a quantidade de caracteres com frequência ímpar
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequencia[i] % 2 != 0) {
            impares++;
        }
    }
    
    // Retorna a quantidade mínima de letras a serem adicionadas
    return (impares > 0) ? (impares - 1) : 0;
}

int main() {
    char sequencia[MAX_LENGTH];
    
    // Lê as sequências até encontrar o fim de arquivo
    while (scanf("%s", sequencia) != EOF) {
        // Calcula e imprime a quantidade mínima de letras a serem adicionadas para formar um palíndromo
        printf("%d\n", minLetrasAdicionadas(sequencia));
    }
    
    return 0;
}
