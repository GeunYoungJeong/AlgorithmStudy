#include <bits/stdc++.h>

using namespace std;

int plength[1001] = {0, };
int input[1001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    int max = 1;
    plength[0] = 1;
    for(int i = 1; i<n; i++) {
        int temp = 0;
        for(int j = 0; j<i; j++) {
            if(input[j] > input[i] && plength[j] >= temp) {
                temp = plength[j];
            }
        }
        plength[i] = temp + 1;
        if(max < plength[i]) max = plength[i];
    }
    printf("%d\n", max);
}