#include <bits/stdc++.h>

using namespace std;

int input[1001][1001];
int dp[1001][1001];

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int main() {
    memset(dp, 0, sizeof(dp));
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            scanf("%d", &input[i][j]);
        }
    }
    dp[1][1] = input[1][1];
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            for(int k = 0; k<3; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx <= n && ny <= m) {
                    if(dp[nx][ny] < input[nx][ny] + dp[i][j]) dp[nx][ny] = input[nx][ny] + dp[i][j];
                }
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}