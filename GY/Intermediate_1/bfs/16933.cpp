#include <bits/stdc++.h>

using namespace std;

int field[1001][1001];
int dist[1001][1001][11];

int n, m, k;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
bool day = false;

void bfs() {
    queue <tuple<int, int, int>> q;
    for(int i = 0; i<=k; i++) {
        dist[1][1][i] = 1;
    }

    q.push(make_tuple(1, 1, 0));

    while(!q.empty()) {
        day = !day;
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {

                if(cnt == k) {
                    if(field[nx][ny] == 0) {
                        if(dist[nx][ny][cnt] == 0) {
                            dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
                            q.push(make_tuple(nx, ny, cnt));
                        }
                    }        
                } else if(cnt < k){
                    if(field[nx][ny] == 0) {
                        if(dist[nx][ny][cnt] == 0) {
                            dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
                            q.push(make_tuple(nx, ny, cnt));
                        }
                    } else {
                        if(day) {
                            if(dist[nx][ny][cnt+1] == 0) {
                                dist[nx][ny][cnt+1] = dist[x][y][cnt] + 1;
                                q.push(make_tuple(nx, ny, cnt+1));
                            }
                        } else {
                            bool check = false;
                            for(int i = cnt + 1; i <k; i++) {
                                if(dist[nx][ny][i] != 0) check = true;
                            }
                            if(!check) {
                                dist[x][y][cnt] = dist[x][y][cnt]+1;
                                q.push(make_tuple(x, y, cnt));
                            }
                        }
                    }                     
                }
            }
        }
    }
}

int main() {
    vector<int> result;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            scanf("%1d", &field[i][j]);
        }
    }

    bfs();

    sort(dist[n][m], dist[n][m]+k+1);

    if(dist[n][m][k] == 0) {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i<=k; i++) {
        if(dist[n][m][i] != 0) {
            printf("%d\n", dist[n][m][i]);
            return 0;
        }
    }
    return 0;
}