#include <stdio.h>   // Inclusão da biblioteca para entrada e saída padrão.
#include <stdlib.h>  // Inclusão da biblioteca para alocação dinâmica de memória e funções auxiliares.

int contNum(int vet[], int tamVet, int num); // Declaração da função que conta a ocorrência de um número no vetor.
void selection(int vet[], int tamVet);      // Declaração da função de ordenação por seleção.
void copiaVetor(int vetOrig[], int vetDest[], int tamVetDest, int limInf); // Declaração da função para copiar parte de um vetor para outro.
void leVetor(int vet[], int tamVet);        // Declaração da função para ler valores para um vetor.

int main() {
    // Declaração de variáveis.
    int tamVet, rodadas;        // tamVet: tamanho do vetor, rodadas: número de iterações.
    int limInf, limSup, kMenor, guga, dabriel;  // limInf e limSup: limites do intervalo, kMenor: índice do menor número, guga e dabriel: valores para comparação.
    int *vet, *intervalo;       // Ponteiros para os vetores dinâmicos.
    int i;                     // Variável de iteração.

    // Leitura do tamanho do vetor e número de rodadas.
    scanf("%d %d", &tamVet, &rodadas);
    vet = (int*) malloc(tamVet * sizeof(int)); // Alocação dinâmica para o vetor principal.
    leVetor(vet, tamVet);        // Leitura dos valores para o vetor principal.
    
    for(i = 0; i < rodadas; i++) { // Loop para processar cada rodada.
        // Leitura dos parâmetros para a rodada.
        scanf("%d %d %d %d %d", &limInf, &limSup, &kMenor, &guga, &dabriel);

        // Processamento
        int tamIntervalo = limSup - limInf + 1;  // Cálculo do tamanho do intervalo.
        intervalo = (int*) malloc(tamIntervalo * sizeof(int)); // Alocação dinâmica para o vetor intervalo.
        copiaVetor(vet, intervalo, tamIntervalo, limInf - 1); // Cópia do intervalo do vetor principal para o vetor intervalo.

        selection(intervalo, tamIntervalo); // Ordenação do vetor intervalo.
        int menor = intervalo[kMenor - 1];   // Encontrar o k-ésimo menor valor (kMenor - 1 é o índice).
        int contKEsimo = contNum(intervalo, tamIntervalo, menor); // Contagem de ocorrências do menor valor.

        // Cálculo das diferenças.
        int difGuga = abs(contKEsimo - guga);
        int difDabri = abs(contKEsimo - dabriel);

        // Determinação do resultado.
        char result = 'E'; // Assume 'E' como valor padrão.
        if(difGuga < difDabri) { result = 'G'; }  // Se a diferença para guga é menor, result é 'G'.
        else if(difDabri < difGuga) { result = 'D'; } // Se a diferença para dabriel é menor, result é 'D'.

        // Saída dos resultados.
        printf("%d %d %c\n", menor, contKEsimo, result);
        free(intervalo); // Liberação da memória alocada para o vetor intervalo.
    }

    free(vet); // Liberação da memória alocada para o vetor principal.
    return 0; // Fim do programa.
}

// Função para contar o número de ocorrências de num no vetor.
int contNum(int vet[], int tamVet, int num) {
    int i, cont = 0; // Variáveis de iteração e contagem.
    for(i = 0; i < tamVet; i++) { // Loop para percorrer o vetor.
        if(vet[i] == num) { // Se o elemento é igual ao número procurado, incrementa o contador.
            cont++;
        }
    }
    return cont; // Retorna o total de ocorrências.
}

// Função para ordenar o vetor usando o método de seleção.
void selection(int vet[], int tamVet) {
    int i, j; // Variáveis de iteração.
    for (i = 0; i < tamVet - 1; i++) { // Loop para iterar pelo vetor.
        int min = i; // Assume que o menor valor está na posição i.
        for (j = i + 1; j < tamVet; j++) { // Loop para encontrar o menor valor no restante do vetor.
            if (vet[j] < vet[min]) {
                min = j; // Atualiza a posição do menor valor encontrado.
            }
        }
        int aux = vet[i]; // Troca o valor na posição i com o menor valor encontrado.
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

// Função para copiar uma parte do vetor original para o vetor destino.
void copiaVetor(int vetOrig[], int vetDest[], int tamVetDest, int limInf) {
    int i, j; // Variáveis de iteração.
    for(i = 0, j = limInf; i < tamVetDest; i++, j++) { // Copia os elementos do vetor original para o vetor destino.
        vetDest[i] = vetOrig[j];
    }
}

// Função para ler os valores do vetor a partir da entrada padrão.
void leVetor(int vet[], int tamVet) {
    int i; // Variável de iteração.
    for(i = 0; i < tamVet; i++) { // Loop para ler os valores do vetor.
        scanf("%d", &vet[i]);
    }
}
