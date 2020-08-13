#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
bool visit[1001][1001];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    queue<pair <int, int>> q;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(arr[i][j] == 1) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(!visit[nx][ny] && arr[nx][ny] != -1) {
                    arr[nx][ny] = arr[x][y] + 1;
                    visit[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int max = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(arr[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("%d\n", max-1);
    return 0;
}