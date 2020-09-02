#include <bits/stdc++.h>

using namespace std;

string arr[101];
bool visit[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    int w, h;
    memset(visit, false, sizeof(visit));
    scanf("%d %d", &w, &h);
    int x_idx = -1, y_idx = -1;
    int x_dest = 0, y_dest = 0;
    for(int i = 0; i<h; i++) {
        cin >> arr[i];
        for(int j = 0; j<w; j++) {
            if(arr[i][j] == 'C') {
                if(x_idx == -1) x_idx = i, y_idx = j;
                else x_dest = i, y_dest = j;
            }
        }
    }

    //printf("%d %d %d %d\n", x_idx, y_idx, x_dest, y_dest);

    queue <tuple <pair<int, int>, int, int>> q;
    visit[x_idx][y_idx] = true;
    for(int i = 0; i<4; i++) {
        q.push(make_tuple(make_pair(x_idx + dx[i], y_idx + dy[i]), i, 0));
    }
    int answer = INT32_MAX;

    while(!q.empty()) {
        int x, y, dir, cnt;
        pair <int, int> temp;
        tie(temp, dir, cnt) = q.front();
        x = temp.first;
        y = temp.second;
        q.pop();

        printf("%d %d %d %d\n", x, y, dir, cnt);

        visit[x][y] = true;

        if(x == x_dest && y == y_dest) {
            if(answer > cnt) answer = cnt;
            continue;
        }
        
        //no mirror
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(!visit[nx][ny] && arr[nx][ny] != '*') {
                q.push(make_tuple(make_pair(nx, ny), dir, cnt));
            }
        }

        //mirror /
        if(dir == 0 || dir == 3) {
            nx = x + 1;
            ny = y - 1;
            if(dir == 0) dir = 3;
            else dir = 0;
        }
        else {
            nx = x - 1;
            ny = y + 1;
            if(dir == 1) dir = 2;
            else dir = 1;
        }
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(!visit[nx][ny] && arr[nx][ny] != '*') {
                q.push(make_tuple(make_pair(nx, ny), dir, cnt+1));
            }
        }
            
        //mirror

        if(dir == 0 || dir == 1) {
            nx = x - 1;
            ny = y - 1;
            if(dir == 0) dir = 1;
            else dir = 0;
        }
        else {
            nx = x + 1;
            ny = y + 1;
            if(dir == 2) dir = 3;
            else dir = 2;
        }
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(!visit[nx][ny] && arr[nx][ny] != '*') {
                q.push(make_tuple(make_pair(nx, ny), dir, cnt+1));
            }
        }
        // for(int i = 0; i<4; i++) {
        //     int nx = x + dx[i];
        //     int ny = y + dy[i];

        //     //no wall
        //     if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
        //         if(!visit[nx][ny] && arr[nx][ny] != '*') {
        //             q.push(make_tuple(make_pair(nx, ny), dir, cnt));
        //         }
        //     }
        // }
    }

    if(answer == INT32_MAX) {
        printf("0\n");
    }
    else {
        printf("%d\n", answer);
    }
    return 0;
}