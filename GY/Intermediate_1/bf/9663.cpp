#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n, cnt = 0;
bool board[16][16];

void solve(int i, int j, int temp, bool array[16][16]) {
    if (i == n) {
        if (temp == n) {
            cnt++;
        }
        return;
    }
    if (temp > n) return;

    if (array[i][j]) {
        bool board_temp[16][16];
        copy(&array[0][0], &array[0][0] + n * n, &board_temp[0][0]);
        //가로, 세로, 대각선 false로
        for (int t = 0; t < n; t++) {
            array[i][t] = false;
            array[t][j] = false;
        }

        int min_ij = min(i,j);
        int i_temp = i - min_ij;
        int j_temp = j - min_ij;

        while (i_temp >= 0 && i_temp < n && j_temp >= 0 && j_temp < n) {
            array[i_temp][j_temp] = false;
            i_temp++;
            j_temp++;
        }

        i_temp = i - min_ij;
        j_temp = j - min_ij;

        while (i_temp >= 0 && i_temp < n && j_temp >= 0 && j_temp < n) {
            array[i_temp][j_temp] = false;
            i_temp++;
            j_temp--;
        }

        j++;
        if (j == n) {
            j = 0; i++;
        }
        solve(i, j, temp, board_temp);
        solve(i, j, temp + 1, array);
    }
    else {
        j++;
        if (j == n) {
            j = 0; i++;
        }
        solve(i, j, temp, array);
    }
}


int main() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            board[i][j] = true;
        }
    }
    scanf("%d", &n);
    solve(0, 0, 0, board);

    printf("%d\n", cnt);
    return 0;
}