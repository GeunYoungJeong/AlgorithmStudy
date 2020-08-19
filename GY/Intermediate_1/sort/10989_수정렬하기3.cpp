#include <bits/stdc++.h>

using namespace std;

unsigned int arr[10001];

int main() {
    int n, t;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &t);
        arr[t]++;
    }
    for(int i = 0; i<=10000; i++) {
        for(int j = 0; j<arr[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}