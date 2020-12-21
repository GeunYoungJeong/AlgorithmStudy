#include <bits/stdc++.h>

using namespace std;

int input[1001];
int dp[1001];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    if(n==1) {
        printf("0\n");
        return 0;
    }

    for(int i = 0; i<n-1; i++) {
        if(i!=0 && dp[i]==0) break;
        for(int j = 1; j<=input[i]; j++) {
            if(i + j < n) {
                if(dp[i+j] == 0 || dp[i+j] > dp[i] + 1) {
                    dp[i+j] = dp[i] + 1;
                }
            }
        }
    }

    // for(int i = 0; i<n; i++) {
    //     printf("%d ", dp[i]);
    // }

    if(dp[n-1] == 0) printf("-1\n");
    else printf("%d\n", dp[n-1]);
    return 0;
}