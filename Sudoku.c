/* THAMYRIS NUNES SUGAHARA
   RA: 169242 
*/ 

#include <stdio.h>
#include <stdbool.h>
#define SIZE 9                                                  // Tamanho da matriz (Jogo Sudoku)

// Verificar se atende as regras do Sudoku
bool isCorrect(int matriz[SIZE][SIZE]){ 
    int i, j, k;       
    for (i = 0; i < SIZE; i++) {                                 // Verificar se cada linha e coluna contém todos os números de 1 a 9
        for (j = 1; j <= SIZE; j++) {                            
            int countRow = 0, countCol = 0;
            for (k = 0; k < SIZE; k++) {
                if (matriz[i][k] == j) {
                    countRow++;
                }
                if (matriz[k][i] == j) {
                    countCol++;
                }
            }
            if (countRow != 1 || countCol != 1) {
                return false;
            }
        }
    }

    for (int startRow = 0; startRow < SIZE; startRow += 3) {     // Verificar se cada bloco 3x3 contém todos os números de 1 a 9
        for (int startCol = 0; startCol < SIZE; startCol += 3) {
            for (int num = 1; num <= SIZE; num++) {
                int countBlock = 0;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (matriz[i + startRow][j + startCol] == num) {
                            countBlock++;
                        }
                    }
                }
                if (countBlock != 1) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int numGames, game;
    int sudokus[SIZE][SIZE];
    
    scanf("%d", &numGames);
    for (int i = 0; i < numGames; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                scanf("%d", &sudokus[j][k]);
            }
        }

        printf("Instancia %d\n", i + 1);
        if (isCorrect(sudokus)) printf("SIM\n\n");
        else printf("NAO\n\n");
    }
    return 0;
}