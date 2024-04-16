#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct pilhaNo{             //Estrutura para o nó
    char valor;
    struct pilhaNo* abaixo;
}pilhaNo;

typedef struct pilha{               //Estrutura para a pilha
    int tamanho;
    pilhaNo* topo;
}pilha;

void push(pilha* p, char valor){    //Empilhar
    p->tamanho += 1;
    pilhaNo* novoTopo = (pilhaNo*) malloc(sizeof(pilhaNo));

    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void pop(pilha* p){                 //Desempilhar
    if(p->tamanho > 0){
        p->tamanho -= 1;
        pilhaNo* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }
}

char top(pilha* p){
    return p->topo->valor;
}

int size(pilha* p){
    return p->tamanho;
}

int empty(pilha* p){
    return p->tamanho == 0;
}

void inicializa(pilha* p){
    p->tamanho = 0;
    p->topo = NULL;
}

void destroi(pilha* p){
    while(!empty(p)){
        pop(p);
    }
}

int precedencia(char operador){
    switch(operador){
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 2;
    }
}

int main(){
    int N, tam;
    pilha p;
    char expressao[301];

    scanf("%d\n", &N);

    for(int k = 0; k < N; ++k){
        scanf("%s\n", &expressao);

        inicializa(&p);

        tam = strlen(expressao);
        for(int i = 0; i < tam; ++i){
            if(isalpha(expressao[i]) || isdigit(expressao[i])){
                printf("%c", expressao[i]);
            }else if(expressao[i] == '(' || expressao[i] == '^'){
                push(&p, expressao[i]);
            }else if(expressao[i] == ')'){
                while(!empty(&p) && top(&p) != '('){
                    printf("%c", top(&p));
                    pop(&p);
                }

                if(!empty(&p))  pop(&p);
            }else{
                while(!empty(&p) && top(&p) != '(' && precedencia(expressao[i]) <= precedencia(top(&p))){
                    printf("%c", top(&p));
                    pop(&p);
                }

                push(&p, expressao[i]);
            }
        }

        while(!empty(&p)){
            printf("%c", top(&p));
            pop(&p);
        }
        printf("\n");
    }

    return 0;
}