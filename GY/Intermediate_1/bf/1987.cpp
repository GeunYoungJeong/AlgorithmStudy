#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visit[21][21];
bool use[26];
string arr[21];
int ans = 0;
int r, c;

void solve(int x, int y, int cnt) {
    //printf("%d %d %d %c\n", x, y, cnt, arr[x][y]);
    if(ans < cnt) ans = cnt;

    for(int i = 0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if(!visit[nx][ny] && !use[arr[nx][ny]-65]) {
                use[arr[nx][ny]-65] = true;
                visit[nx][ny] = true;
                solve(nx, ny, cnt+1);
                use[arr[nx][ny]-65] = false;
                visit[nx][ny] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i<r; i++) {
        cin >> arr[i];
    }
    visit[0][0] = true;
    use[arr[0][0]-65] = true;
    vector <char> v;
    v.push_back(arr[0][0]);
    
    solve(0, 0, 1);
    
    printf("%d\n", ans);
    return 0;
}