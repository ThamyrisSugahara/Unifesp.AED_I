/* beecrowd | 2729 Shopping List */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100
#define MAX_PALAVRAS 1001
#define TAMANHO_PALAVRA 21

// Estrutura para o nó
typedef struct listano{
    char info[TAMANHO_PALAVRA]; 
    struct listano* ant;
    struct listano* prox;
} ListaNo;

// Estrutura para a lista
typedef struct lista{
    ListaNo* prim;
    ListaNo* ult;
} Lista;

// Criar Lista
Lista* lst_cria(){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;
    return l; 
}

// Inserção no início
void lst_insere(Lista* l, char item[]){
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
    strcpy(novo->info, item); 
    novo->prox = l->prim;
    novo->ant = NULL;

    if (l->prim != NULL){
        l->prim->ant = novo;
    } else {
        l->ult = novo;
    }

    l->prim = novo;
}

// Verifica e remove as palavras repetidas
void remove_repetidos(Lista* l){
    ListaNo* atual = l->prim;
    ListaNo* proximo;
    
    while (atual != NULL) {
        proximo = atual->prox;
        while (proximo != NULL) {
            if (strcmp(atual->info, proximo->info) == 0) { // Se as palavras forem iguais
                if (proximo == l->ult) { // Se o próximo nó for o último
                    l->ult = proximo->ant;
                    if (l->ult != NULL) {
                        l->ult->prox = NULL;
                    } else {
                        l->prim = NULL; 
                    }
                } else {
                    proximo->ant->prox = proximo->prox;
                    proximo->prox->ant = proximo->ant;
                }
                ListaNo* temp = proximo;
                proximo = proximo->prox;
                free(temp);
            } else {
                proximo = proximo->prox;
            }
        }
        atual = atual->prox;
    }
}


// Ordena a lista em ordem alfabética
void lst_ordenar(Lista* l) {
    ListaNo *atual, *prox, *minimo;
    char temp[TAMANHO_PALAVRA];

    for (atual = l->prim; atual != NULL; atual = atual->prox) {
        minimo = atual;
        for (prox = atual->prox; prox != NULL; prox = prox->prox) {
            if (strcmp(minimo->info, prox->info) > 0) {
                minimo = prox;
            }
        }
        if (minimo != atual) {
            strcpy(temp, atual->info);
            strcpy(atual->info, minimo->info);
            strcpy(minimo->info, temp);
        }
    }
}



void processa_linha(Lista* l, char linha[], int max_palavras) {
    char linha_temp[MAX_PALAVRAS * TAMANHO_PALAVRA]; // Variável temporária para armazenar a linha
    strcpy(linha_temp, linha); // Copia a linha de entrada para a variável temporária

    char* token = strtok(linha_temp, " \n"); // Separa a linha em palavras usando espaços e nova linha como delimitadores
    int cont = 0; // Contador de palavras
    while (token != NULL && cont < max_palavras) {
        lst_insere(l, token); // Insere a palavra na lista
        token = strtok(NULL, " \n"); // Avança para a próxima palavra
        cont++;
    }
}


// Imprime
void lst_imprime(Lista* l){
    if (l == NULL || l->prim == NULL) {
        return;
    }
    ListaNo* p;
    for(p = l->prim; p != NULL; p = p->prox) {
        printf("%s", p->info);
        if(p->prox != NULL) // Verifica se não é o último nó
            printf(" ");
    }
    printf("\n");
}


int main(){
    int num_listas;
    scanf("%d\n", &num_listas);

    if (num_listas > MAX_N) {
        return 1; // Saímos do programa com um código de erro
    }

     for (int i = 0; i < num_listas; i++) {
        Lista* lista = lst_cria(); // Lista principal

        // Ler a lista de palavras
        char linha[MAX_PALAVRAS * TAMANHO_PALAVRA];
        fgets(linha, sizeof(linha), stdin);

        // Remover o caractere de nova linha, se presente
        if (linha[strlen(linha) - 1] == '\n')
        linha[strlen(linha) - 1] = '\0';

        processa_linha(lista, linha, MAX_PALAVRAS);


        // Remove palavras repetidas
        remove_repetidos(lista);

        lst_ordenar(lista);

        // Imprime a lista resultante
        lst_imprime(lista);

        // Liberar memória
        ListaNo* atual = lista->prim;
        ListaNo* proximo;
        while (atual != NULL) {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        free(lista);
    }

    return 0;
}