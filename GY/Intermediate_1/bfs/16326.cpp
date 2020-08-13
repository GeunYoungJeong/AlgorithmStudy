#include <bits/stdc++.h>

using namespace std;

int input[21][21];
bool visit[21][21];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main( ) {
    int n;
    scanf("%d", &n);

    int location_x, location_y;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &input[i][j]);
            if(input[i][j] == 9) {
                location_x = i;
                location_y = j;
            }
        }
    }

    int size = 2;
    int eat = 0;
    int cnt = 0;
    queue <pair<int, int>> q;
    q.push(make_pair(location_x, location_y));
    visit[location_y][location_y] = true;

    while(!q.empty()) {
        cnt++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >=0 && ny <n) {
                if(!visit[nx][ny]) {
                    if(input[nx][ny] == 0 || input[nx][ny] == size) {
                        visit[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                    else if((0 < input[nx][ny]) && (input[nx][ny] < size)){
                        input[nx][ny] = 0;
                        visit[nx][ny] = true;
                        eat++;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            if(eat == size) {
                size++;
                eat = 0;
            }
        }
    }

    printf("%d", cnt);
    return 0;


}