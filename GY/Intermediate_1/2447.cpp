#include <bits/stdc++.h>

using namespace std;

char arr[6600][6600];
int n;

void solve(int i, int j, int size) {
    if(size == 3) {
        for(int s = i; s < i+3; s++) {
            for(int e = j; e < j+3; e++) {
                if(s == i + 1 && e == j+1) {
                }
                else{
                    arr[s][e] = '*';
                }
            }
        }
    }
    else {
        for(int s = i; s < i+size; s += (size/3)) {
            for(int e = j; e < j+size; e += (size/3)) {
                if(s == i + (size/3) && e == j+(size/3)) {
                }
                else{
                    solve(s, e, size/3);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(arr, ' ', sizeof(arr));
    solve(0, 0, n);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}