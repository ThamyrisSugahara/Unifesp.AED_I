#include <stdio.h>
#include <string.h>
#define MAXN 501

int board[MAXN][MAXN];
int prefix_black[MAXN][MAXN];
int prefix_white[MAXN][MAXN];

int get_sum(int matrix[MAXN][MAXN], int x1, int y1, int x2, int y2) {
    return matrix[x2+1][y2+1] - matrix[x1][y2+1] - matrix[x2+1][y1] + matrix[x1][y1];
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    memset(board, 0, sizeof(board));
    memset(prefix_black, 0, sizeof(prefix_black));
    memset(prefix_white, 0, sizeof(prefix_white));
    for (int i = 0; i < p; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 1; 
    }
    for (int i = 0; i < p; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 2; 
    }
    // Criar matrizes prefix sum
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix_black[i][j] = prefix_black[i-1][j] + prefix_black[i][j-1] - prefix_black[i-1][j-1] + (board[i][j] == 1 ? 1 : 0);
            prefix_white[i][j] = prefix_white[i-1][j] + prefix_white[i][j-1] - prefix_white[i-1][j-1] + (board[i][j] == 2 ? 1 : 0);
        }
    }
    int black_count = 0;
    int white_count = 0;
    
    for (int size = 1; size <= n; size++) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= n - size; j++) {
                int black_sum = get_sum(prefix_black, i, j, i + size - 1, j + size - 1);
                int white_sum = get_sum(prefix_white, i, j, i + size - 1, j + size - 1);
                if (black_sum > 0 && white_sum == 0) {
                    black_count++;
                } else if (white_sum > 0 && black_sum == 0) {
                    white_count++;
                }
            }
        }
    }
    printf("%d %d\n", black_count, white_count);
    return 0;
    }