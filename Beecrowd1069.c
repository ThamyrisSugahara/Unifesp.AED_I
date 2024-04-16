#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhaNo{
    char symbol;
    struct pilhaNo* abaixo;
} pilhaNo;

typedef struct pilha{
    int tamanho;
    pilhaNo* topo;
} pilha;

void push(pilha* p, char symbol){
    p->tamanho += 1;
    pilhaNo* novoTopo = (pilhaNo*)malloc(sizeof(pilhaNo));

    novoTopo->symbol = symbol;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void pop(pilha* p){
    if(p->tamanho > 0){
        p->tamanho -= 1;
        pilhaNo* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }
}

char top(pilha* p){
    return p->topo->symbol;
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

int main(){
    int N;
    char s[1001];
    scanf("%d", &N);
    int i;
    for(i = 0; i < N ; i++) {
        scanf("%s", s);
        if (strchr(s, '<') == NULL && strchr(s, '>') == NULL && strchr(s, ',') == NULL && strchr(s, '.') == NULL) {
            // Se nenhum dos símbolos especificados estiver presente na string de entrada
            return -1;
            } else {
                pilha p;
                inicializa(&p);

                int count = 0;
                char *ptr = s;
                while (*ptr != '\0') {
                    switch (*ptr) {
                        case '<':
                            push(&p, '<');
                            break;
                        case '>':
                            if (!empty(&p) && top(&p) == '<') {
                                pop(&p);
                                count++;
                            }
                            break;
                        default:
                            break;
                    }
                    ptr++;
                } 
                printf("%d\n", count); 
            }
        } 
    

    return 0;
}
