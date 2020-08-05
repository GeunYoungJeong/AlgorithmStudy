#include <bits/stdc++.h>

using namespace std;

int range;
int t, n, k;

void solve(int index, int jump, int dest, int * arr) {
    if(index > dest) return;
    if(index == dest) {
        if(range > jump) range = jump;
    }
    for(int i = 1; i<=k; i++) {
        if(count(arr, arr+n, index+i) == 1) {
            solve(index+i, jump+1, arr[n-1], arr);
        }
    }
}

int main() {
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        int range = 1000000;
        int arr[100001];
        scanf("%d", &n);
        for(int i = 0; i<n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &k);
        solve(0, 0, arr[n-1], arr);
        if(range == 1000000) range = -1;
        printf("Case #%d\n%d\n", i, range);
    }
}