#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20

// Função para encontrar o próximo candidato no sentido horário
int proximoHorario(int arr[], int n, int start, int step) {
    while (step--) {
        do {
            start = (start + 1) % n;
        } while (arr[start] == 0);
    }
    return start;
}

// Função para encontrar o próximo candidato no sentido anti-horário
int proximoAntiHorario(int arr[], int n, int start, int step) {
    while (step--) {
        do {
            start = (start - 1 + n) % n;
        } while (arr[start] == 0);
    }
    return start;
}

int main() {
    int N, k, m;

    while (scanf("%d %d %d", &N, &k, &m) == 3 && (N || k || m)) {
        int arr[MAX_N];
        for (int i = 0; i < N; ++i) {
            arr[i] = i + 1;
        }

        int horario = N - 1; // Inicia antes do primeiro elemento
        int antihorario = 0; // Inicia depois do último elemento
        bool firstPair = true;

        while (N > 0) {
            horario = proximoHorario(arr, MAX_N, horario, k);
            antihorario = proximoAntiHorario(arr, MAX_N, antihorario, m);

            if (!firstPair) {
                printf(", ");
            }
            firstPair = false;

            if (horario == antihorario) {
                printf("%3d", arr[horario]);
                arr[horario] = 0;
                N--;
            } else {
                printf("%3d %3d", arr[horario], arr[antihorario]);
                arr[horario] = 0;
                arr[antihorario] = 0;
                N -= 2;
            }

            if (N > 0) {
                horario = (horario + 1) % MAX_N;
                antihorario = (antihorario - 1 + MAX_N) % MAX_N;
            }
        }
        printf("\n");
    }

    return 0;
}

