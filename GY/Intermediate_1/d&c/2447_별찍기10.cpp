/**
 * º°ÀÌ³ª ÂïÀ¾½Ã´Ù!
 **/

#include <bits/stdc++.h>

using namespace std;

char arr[2200][2200];

void solve(int i, int j, int s) {
    if(s==1) {
        arr[i][j] = '*';
        return;
    }
    int size = s/3;
    for(int z = i; z <= i+size*2 ; z+=size) {
        for(int e = j; e <= j+size*2; e+=size) {
            if(z != i + size || e != j + size) {
                solve(z, e, size);
            }
        }
    }
}

int main() {
    memset(arr, ' ', sizeof(arr));
    int n;
    scanf("%d", &n);
    solve(0, 0, n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}