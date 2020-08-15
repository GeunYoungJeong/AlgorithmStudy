/**
 * º°ÀÌ³ª ÂïÀ¾½Ã´Ù!
 **/

#include <bits/stdc++.h>

using namespace std;

char arr[3100][6200];

void solve(int i, int j, int s) {
    if(s==3) {
        arr[i][j] = '*';
        arr[i+1][j-1] = '*';
        arr[i+1][j+1] = '*';
        arr[i+2][j-2] = '*';
        arr[i+2][j-1] = '*';
        arr[i+2][j] = '*';
        arr[i+2][j+1] = '*';
        arr[i+2][j+2] = '*';
        return;
    }
    int size = s/2;
    solve(i, j, size);
    solve(i+size, j-size, size);
    solve(i+size, j+size, size);
}

int main() {
    memset(arr, ' ', sizeof(arr));
    int n;
    scanf("%d", &n);
    solve(0, n-1, n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<2*n; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}