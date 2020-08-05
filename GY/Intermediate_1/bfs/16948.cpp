#include <bits/stdc++.h>

using namespace std;

int dist[201][201];

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int main() {
    int n, r1, c1, r2, c2;
    scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);

    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=n; j++) {
            dist[i][j] = -1;
        }
    }

    queue <pair<int, int>> q;
    q.push(make_pair(r1, c1));
    dist[r1][c1] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(dist[nx][ny] == -1) {
                    if(nx == r2 && ny == c2) {
                        printf("%d\n", dist[x][y] + 1);
                        return 0;
                    }
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    printf("%d\n",-1);
    return 0;
}