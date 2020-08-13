#include <bits/stdc++.h>

using namespace std;

int board[301][301];

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    int t, l, sx, sy, ex, ey;
    scanf("%d", &t);
    while(t--) {
        memset(board, -1, sizeof(board));
        scanf("%d %d %d %d %d", &l, &sx, &sy, &ex, &ey);

        queue <pair <int, int>> q;
        q.push(make_pair(sx, sy));
        board[sx][sy] = 0;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == ex && y == ey) break;

            for(int i = 0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < l && ny >= 0 && ny < l) {
                    if(board[nx][ny] == -1) {
                        board[nx][ny] = board[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        printf("%d\n", board[ex][ey]);
    }
    return 0;
}