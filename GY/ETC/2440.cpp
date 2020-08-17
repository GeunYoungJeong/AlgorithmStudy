#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<n-i; j++) {
            printf(" ");
        }
        printf("*");
        if(i > 1) {
            for(int j = 0; j<2*i-3; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
}