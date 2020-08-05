#include <bits/stdc++.h>

using namespace std;

char board[52][52];
bool visit[52][52];
bool result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs(int i, int j, int n, int m) {
    visit[i][j] = true;
    q.push(make_pair(i, j));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); 

        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m)
            {
            }
            else
            {
                if (board[x + dx[i]][y + dy[i]] == board[x][y] && visit[x + dx[i]][y + dy[i]] == false)
                {
                    visit[x][y] = true;
                    q.push(make_pair(x + dx[i], y + dy[i]));
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i<m; i++) {
        for(int j = 0; i<n; i++) {
            scanf("%d", &board[i][j]);
        }
    }

    for(int i = 0; i<m; i++) {
        for(int j = 0; i<n; i++) {
            if(!visit[i][j]) bfs(i, j, n, m);
        }
    }

    if(result) printf("Yes\n");
    else printf("No\n");

    return 0;
}