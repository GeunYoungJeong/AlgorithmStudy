#include <bits/stdc++.h>

using namespace std;

int room[101][101];
int cnt[101][101];
bool visit[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            scanf("%1d", &room[i][j]);
        }
    }

    queue <pair<int, int>> q;
    q.push(make_pair(1,1));
    visit[1][1] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == m && y == n) break;

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 1 && nx <=n && ny >=1 && ny <=m) {
                if(room[nx][ny] == 0 && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    cnt[nx][ny] = cnt[x][y];
                    q.push(make_pair(nx, ny));
                }
                if(room[nx][ny] == 1 && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    cnt[nx][ny] = cnt[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            printf("%d", cnt[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", cnt[n][m]);
    return 0;
}