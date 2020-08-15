#include <bits/stdc++.h>

using namespace std;

int arr[2200][2200];
int result[3];

int check(int i, int j, int size) {
    int b = arr[i][j];
    for(int s = i; s < i+size; s++) {
        for(int e = j; e < j+size; e++) {
            if(arr[s][e] != b) return -2;
            b = arr[s][e];
        }
    }
    return b;
}

void solve(int i, int j, int s) {
    int c = check(i, j, s);
    if(c == -2) {
        int size = s/3;
        for(int z = i; z<=i+size*2 ; z+=size) {
            for(int e = j; e<=j+size*2; e+=size) {
                solve(z, e, size);
            }
        }
    }
    else {
        result[c+1]++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    solve(0, 0, n);
    for(int i = 0; i<3; i++) {
        printf("%d\n", result[i]);
    } 
    return 0;
}