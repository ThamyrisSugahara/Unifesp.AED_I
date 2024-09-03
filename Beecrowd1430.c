#include <string.h> // Inclui a biblioteca para manipulação de strings
#include <stdio.h>  // Inclui a biblioteca para entrada e saída padrão

// Função para retornar a duração correspondente à nota musical
double duracaoNota(char nota) {
    switch (nota) {
    case 'W': // Nota Whole (inteira) - Duração de 1.0
        return 1.0;
    case 'H': // Nota Half (meia) - Duração de 0.5
        return 0.5;
    case 'Q': // Nota Quarter (quarta) - Duração de 0.25
        return 0.25;
    case 'E': // Nota Eighth (oitava) - Duração de 0.125
        return 0.125;
    case 'S': // Nota Sixteenth (dezesseis avos) - Duração de 0.0625
        return 0.0625;
    case 'T': // Nota Thirty-second (trinta e dois avos) - Duração de 0.03125
        return 0.03125;
    case 'X': // Nota Sixty-fourth (sessenta e quatro avos) - Duração de 0.015625
        return 0.015625;
    default: // Caso a nota não esteja na lista, não retorna nada
        return 0.0;
    }
}

int main() {
    int resposta;      // Variável para contar o número de seções de duração completa
    double duracao;    // Variável para acumular a duração total das notas
    char composicao[1000]; // Array para armazenar a composição musical

    // Loop para ler a composição musical até o final do arquivo (EOF)
    while (scanf("%[^\n]\n", composicao) != EOF) {
        // Verifica se a composição lida é apenas um asterisco, o que indica fim
        if (strcmp(composicao, "*") == 0)
            break;

        resposta = 0;   // Inicializa o contador de seções completas
        duracao = 0.0;  // Inicializa a duração acumulada

        // Loop para iterar sobre cada caractere na composição musical
        for (int i = 0; i < strlen(composicao); ++i) {
            // Se encontrar um '/', verifica se a duração acumulada é igual a 1.0
            if (composicao[i] == '/') {
                // Se a duração acumulada for igual a 1.0, incrementa a resposta
                if (duracao == 1.0)
                    ++resposta;
                duracao = 0.0; // Reseta a duração acumulada
            } else {
                // Se não for '/', adiciona a duração da nota atual à duração acumulada
                duracao += duracaoNota(composicao[i]);
            }
        }

        // Imprime o número de seções completas encontradas
        printf("%d\n", resposta);
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
