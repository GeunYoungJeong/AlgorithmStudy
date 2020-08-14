#include <bits/stdc++.h>

using namespace std;

int fplength[1001] = {0, };
int bplength[1001] = {0, };
int input[1001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    int max = 1;
    fplength[0] = 1;
    bplength[n-1] = 1;
    for(int i = 1; i<n; i++) {
        int temp = 0;
        for(int j = 0; j<i; j++) {
            if(input[j] < input[i] && fplength[j] >= temp) {
                temp = fplength[j];
            }
        }
        fplength[i] = temp + 1;
    }

    for(int i = n-2; i>=0; i--) {
        int temp = 0;
        for(int j = n-1; j>i; j--) {
            if(input[j] < input[i] && bplength[j] >= temp) {
                temp = bplength[j];
            }
        }
        bplength[i] = temp + 1;
    }
    for(int i = 0; i<n; i++) {
        if(max < fplength[i] + bplength[i]) max = fplength[i] + bplength[i];
    }
    printf("%d\n", max-1);
    return 0;
}