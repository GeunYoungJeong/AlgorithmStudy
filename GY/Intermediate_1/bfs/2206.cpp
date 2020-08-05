#include <bits/stdc++.h>

using namespace std;

int field[1001][1001];
int dist[1001][1001];
bool visit[1001][1001][2];

int n, m;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs() {
    queue <tuple<int, int, bool>> q;
    visit[1][1][0] = true;
    dist[1][1] = 0;
    q.push(make_tuple(1,1, false));

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        bool check = get<2>(q.front());
        q.pop();

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if(check) {
                    if(field[nx][ny] == 0) {
                        if(!visit[nx][ny][0]) {
                            dist[nx][ny] = dist[x][y] + 1;
                            visit[nx][ny][0] = true;
                            q.push(make_tuple(nx, ny, true));
                        }
                    }        
                } else {
                    if(field[nx][ny] == 0) {
                        if(!visit[nx][ny][0]) {
                            dist[nx][ny] = dist[x][y] + 1;
                            visit[nx][ny][0] = true;
                            q.push(make_tuple(nx, ny, false));
                        }
                    } else {
                        if(!visit[nx][ny][1]){
                            dist[nx][ny] = dist[x][y] + 1;
                            visit[nx][ny][1] = true;
                            q.push(make_tuple(nx, ny, true));
                        }
                    }                     
                }
            }
        }
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
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
    //         printf("%d", dist[i][j]);
    //     }
    //     printf("\n");
    // }
    if(dist[n][m] != -1) dist[n][m]++;
    printf("%d\n", dist[n][m]);
    return 0;
}