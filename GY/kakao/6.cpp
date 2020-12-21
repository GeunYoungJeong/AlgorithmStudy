#include <bits/stdc++.h>

using namespace std;

bool visit[4][4];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(r, c, 0));
    visit[r][c] = true;

    while(!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();

        if(board[x][y])

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < 4 && ny>=0 && ny<4) {

            }
        }

    }
    return answer;
}