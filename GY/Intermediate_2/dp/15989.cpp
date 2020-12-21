#include <bits/stdc++.h>

using namespace std;

int dp[10001][3];

int main() {
    int t, n;
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][2] = 1;
    for(int i = 2; i<=10000; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        if(i >= 3) dp[i][1] = dp[i-2][0] + dp[i-2][1] + dp[i-2][2];
        if(i >= 4) dp[i][1] = dp[i-3][0] + dp[i-3][1] + dp[i-3][2];
    }
    for(int i = 1; i<=10; i++) {
        printf("%d\n", dp[i][0] + dp[i][1] + dp[i][2]);
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", dp[n][0] + dp[n][1] + dp[n][2]);
    }
    return 0;
}