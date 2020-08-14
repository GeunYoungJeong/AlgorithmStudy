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

    int max = input[0];
    plength[0] = input[0];
    for(int i = 1; i<n; i++) {
        int temp = 0;
        for(int j = 0; j<i; j++) {
            if(input[j] < input[i] && plength[j] >= temp) {
                temp = plength[j];
            }
        }
        plength[i] = temp + input[i];
        if(max < plength[i]) max = plength[i];
    }
    printf("%d\n", max);
}