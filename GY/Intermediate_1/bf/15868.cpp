#include <bits/stdc++.h>

using namespace std;

int n, pl_count, mi_count, mu_count, di_count, MIN, MAX;
int input[12];

void solve(int idx, int temp, int pl_count, int mi_count, int mu_count, int di_count) {
    if(idx == n-1) {
        if(temp > MAX) MAX = temp;
        if(temp < MIN) MIN = temp;
        return;
    }
    if(pl_count > 0) solve(idx+1, temp + input[idx+1], pl_count-1, mi_count, mu_count, di_count);
    if(mi_count > 0) solve(idx+1, temp - input[idx+1], pl_count, mi_count-1, mu_count, di_count);
    if(mu_count > 0) solve(idx+1, temp * input[idx+1], pl_count, mi_count, mu_count-1, di_count);
    if(di_count > 0) solve(idx+1, temp / input[idx+1], pl_count, mi_count, mu_count, di_count-1);
}

int main() {
    MIN = 1000000000;
    MAX = -1000000000;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    scanf("%d %d %d %d", &pl_count, &mi_count, &mu_count, &di_count);

    solve(0, input[0], pl_count, mi_count, mu_count, di_count);

    printf("%d\n%d", MAX, MIN);
    return 0;
}