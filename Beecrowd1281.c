#include <string.h> // Inclusão da biblioteca para manipulação de strings.
#include <stdio.h>  // Inclusão da biblioteca para entrada e saída padrão.

int main()
{
    int N, M, P, quantidade; // Declaração de variáveis. N: número de casos de teste, M: número de frutas disponíveis, P: número de frutas compradas, quantidade: quantidade de uma fruta comprada.
    char fruta[50], frutas[100][50]; // Array para armazenar o nome de uma fruta e uma matriz para armazenar os nomes de até 100 frutas.
    double resposta, precos[100]; // Variável para armazenar o custo total e um array para armazenar os preços das frutas.

    scanf("%d", &N); // Lê o número de casos de teste.

    // Loop para processar cada caso de teste.
    for (int k = 0; k < N; ++k)
    {
        scanf("%d", &M); // Lê o número de frutas disponíveis para o caso de teste atual.

        // Loop para ler as frutas e seus preços.
        for (int i = 0; i < M; ++i)
        {
            scanf("%s %lf\n", frutas[i], &precos[i]); // Lê o nome da fruta e seu preço, armazenando-os nos arrays correspondentes.
        }

        scanf("%d", &P); // Lê o número de frutas compradas.

        resposta = 0.0; // Inicializa a variável de resposta com 0.0 (custo total).

        // Loop para processar cada fruta comprada.
        for (int i = 0; i < P; ++i)
        {
            scanf("%s %d\n", fruta, &quantidade); // Lê o nome da fruta comprada e a quantidade.

            // Loop para encontrar o preço da fruta comprada.
            for (int j = 0; j < M; ++j)
            {
                if (strcmp(fruta, frutas[j]) == 0) // Compara o nome da fruta comprada com as frutas disponíveis.
                {
                    resposta += quantidade * precos[j]; // Adiciona o custo da fruta comprada ao total.
                    break; // Sai do loop após encontrar a fruta.
                }
            }
        }

        // Imprime o custo total formatado com duas casas decimais.
        printf("R$ %.2lf\n", resposta);
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso.
}
