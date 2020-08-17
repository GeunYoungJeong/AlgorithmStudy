#include <bits/stdc++.h>

using namespace std;

long long dp[1000011] = {0,};
long long s[1000011] = {0,};

long long solve(long long t) {
    if(t==1) return 0;
    if(t==2) return 1;
    if(dp[t] == 0) {
        if(t % 2 == 0) {
            dp[t] = solve(t/2) + 1;
        }
        else {
            dp[t] = solve(t+1) + 1;
        }
    }
    return dp[t];
}

int main() {
    int t, n, a, b;
    scanf("%d", &t);
    for(int i = 2; i<=1000000; i++) {
        s[i] = s[i-1] + solve(i); 
    }
    for(int i = 1; i<=t; i++) {
        scanf("%d %d", &a, &b);
        // long long ans = 0;
        // for(int j = a; j<=b; j++) {
        //     ans += solve(j);
        // }
        printf("Case #%d\n%lld\n", i, s[b] - s[a-1]);
    }
    return 0;
}