#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAGONS 26

typedef struct {
    char wagons[MAX_WAGONS];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_WAGONS - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->wagons[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->wagons[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->wagons[s->top];
    }
    return '\0';
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        char input[MAX_WAGONS + 1], output[MAX_WAGONS + 1];

        for (int i = 0; i < N; i++) {
            scanf(" %c", &input[i]);
        }
        input[N] = '\0';

        for (int i = 0; i < N; i++) {
            scanf(" %c", &output[i]);
        }
        output[N] = '\0';

        Stack stack;
        initStack(&stack);

        char result[2 * MAX_WAGONS * 2 + 1];
        int resultIndex = 0;

        int inputIndex = 0, outputIndex = 0;
        int possible = 1;

        while (outputIndex < N) {
            if (!isEmpty(&stack) && peek(&stack) == output[outputIndex]) {
                pop(&stack);
                result[resultIndex++] = 'R';
                outputIndex++;
            } else if (inputIndex < N) {
                push(&stack, input[inputIndex++]);
                result[resultIndex++] = 'I';
            } else {
                possible = 0;
                break;
            }
        }

        result[resultIndex] = '\0';

        if (possible && outputIndex == N) {
            printf("%s\n", result);
        } else {
            printf("%s Impossible\n", result);
        }
    }

    return 0;
}
