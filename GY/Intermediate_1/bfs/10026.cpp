#include <bits/stdc++.h>

using namespace std;

int n, cnt, cnt2 = 0;
char arr[101][101];
bool visit[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(int i, int j) {
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
                if (arr[nx][ny] == arr[x][y]) {
                    visit[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    memset(visit, false, sizeof(visit));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'G') {
                arr[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                bfs(i, j);
                cnt2++;
            }
        }
    }

    printf("%d %d\n", cnt, cnt2);
    return 0;
}