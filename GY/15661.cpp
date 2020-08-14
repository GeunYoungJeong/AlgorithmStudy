#include <bits/stdc++.h>

using namespace std;

int input[21][21];
int start[21];
int link[21];
int n, result;

void solve(int i, int s, int l, int sc, int lc) {
    if(i == n+2) {
        if(result > abs(sc- lc) && s > 0 && l > 0) result = abs(sc-lc);
        return;
    }
    //스타트팀으로 보낼때
    int t = 0;
    for(int k = 0; k<s; k++) {
        t += input[i][start[k]];
        t += input[start[k]][i];        
    }
    start[s] = i;
    solve(i+1, s+1, l, sc+t, lc);

    //링크팀으로 보낼때
    t = 0;
    for(int k = 0; k<l; k++) {
        t += input[i][link[k]];
        t += input[link[k]][i];
    }
    link[l] = i;
    solve(i+1, s, l+1, sc, lc+t);
}

int main() {
    result = INT16_MAX;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    solve(1, 0, 0, 0, 0);
    if(result == INT16_MAX) result = 0;
    printf("%d\n", result);
    return 0;
}