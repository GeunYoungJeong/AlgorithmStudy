#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int input[1000005];
int dp[1000005];

int main() {
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        memset(input, 0, sizeof(input));
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        input[0] = 0;
        for(int i = 1; i<=n; i++) {
            scanf("%d", &input[i]);
        }
        n++;
        scanf("%d", &k);
        for(int i = 0; i<n; i++) {
            if(i >= 1) {
                if(input[i-1] + k < input[i]) {
                    dp[n-1] = -1;
                    break;
                }
            }
            for(int j = i+1; j<n; j++) {
                if(input[j] - input[i] > k) break;
                if(dp[j] == 0 && dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        printf("Case #%d\n%d\n", i, dp[n-1]);
    }
}