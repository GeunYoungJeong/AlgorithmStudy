#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int arr[1501][2001];
int p[1501][2001];
int nex[1501][2001];
int dp[1501];
int t, n, k, m, a, b;

void dfs(int curr_x, int curr_y, int dest_x, int cnt, bool state) {
    if(curr_x == dest_x) {
        if(dp[curr_y] == -1) dp[curr_y] = cnt;
        else {
            if(dp[curr_y] > cnt) dp[curr_y] = cnt;
        }
        return;
    }
    
    int next_x = nex[curr_x][curr_y];
    if(state || curr_x == 1) dfs(next_x, curr_y, dest_x, cnt, false);
    else dfs(next_x, curr_y, dest_x, cnt+1, false);

    if(!state && curr_x != 1) {
        int next_y = p[curr_x][curr_y];
        dfs(curr_x, next_y, dest_x, cnt, true);
    }
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &t);

    for(int i = 1; i<=t; i++) {
        scanf("%d %d %d", &n, &k, &m);
        memset(arr, 0, sizeof(arr));
        memset(p, 0, sizeof(p));
        memset(nex, 1, sizeof(nex));
        answer = 0;

        for(int j = 1; j<=n; j++) {
            arr[1][j] = 1;
        }

        vector <int> bef (n+1, 1);

        for(int j = 2; j<=k+1; j++) {
            scanf("%d %d", &a, &b);
            arr[j][a] = 1;
            arr[j][b] = 1;
            p[j][a] = b;
            p[j][b] = a;
            nex[bef[a]][a] = j;
            nex[bef[b]][b] = j;
            bef[a] = j;
            bef[b] = j;
        }

        for(int j = 1; j<=n; j++) {
            nex[bef[j]][j] = k+2;
        }

        for(int j = 1; j<=n; j++) {
            arr[k+2][j] = 1;
        }

        vector <pair<int, int>> p;
        int start, end;
        for(int j = 0; j<m; j++) {
            scanf("%d %d", &start, &end);
            p.push_back(make_pair(start, end));
        }

        sort(p.begin(), p.end());
        int before = 0;
        for(int j = 0; j<m; j++) {
            if(p[j].first != before) {
                memset(dp, -1, sizeof(int) * (n+1));
                before = p[j].first;        
                dfs(1, before, k+2, 0, false);
            }
            answer += dp[p[j].second];
        }
        printf("Case #%d\n%d\n", i, answer);
    }
    return 0;
}