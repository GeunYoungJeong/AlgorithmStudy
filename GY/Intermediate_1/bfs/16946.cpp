#include <bits/stdc++.h>

using namespace std;

int field[1001][1001];
int dist[1001][1001][2];
int cnt[1001][1001];

int n, m;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs() {
    queue <tuple<int, int, bool>> q;
    dist[1][1][0] = 1;
    dist[1][1][1] = 1;
    q.push(make_tuple(1,1, false));

    while(!q.empty()) {
        int x, y;
        bool check;
        tie(x, y, check) = q.front();
        q.pop();

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if(check) {
                    if(field[nx][ny] == 0) {
                        if(dist[nx][ny][1] == 0) {
                            dist[nx][ny][1] = dist[x][y][1] + 1;
                            q.push(make_tuple(nx, ny, true));
                        }
                    }        
                } else {
                    if(field[nx][ny] == 0) {
                        if(dist[nx][ny][0] == 0) {
                            dist[nx][ny][0] = dist[x][y][0] + 1;
                            q.push(make_tuple(nx, ny, false));
                        }
                    } else {
                        if(dist[nx][ny][1] == 0){
                            dist[nx][ny][1] = dist[x][y][0] + 1;
                            q.push(make_tuple(nx, ny, true));
                        }
                    }                     
                }
            }
        }
    }
}

int main() {
    vector<int> result;
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            scanf("%1d", &field[i][j]);
        }
    }

    bfs();
    // for(int i = 1; i<=n; i++) {
    //     for(int j = 1; j<=m; j++) {
    //         printf("%d ", dist[i][j][0]);
    //     }
    //     printf("\n");
    // }
    // for(int i = 1; i<=n; i++) {
    //     for(int j = 1; j<=m; j++) {
    //         printf("%d ", dist[i][j][1]);
    //     }
    //     printf("\n");
    // }

    if(dist[n][m][0] == 0 && dist[n][m][1] == 0) {
        printf("-1\n");
        return 0;
    }
    if(min(dist[n][m][0], dist[n][m][1]) == 0) {
        printf("%d\n", max(dist[n][m][0], dist[n][m][1]));
    } else {
        printf("%d\n", min(dist[n][m][0], dist[n][m][1]));
    }
    return 0;
}