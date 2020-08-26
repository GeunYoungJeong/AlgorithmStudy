#include <bits/stdc++.h>

using namespace std;

char arr[21][21];

int n, m, answer;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void solve(int fx, int fy, int sx, int sy, int cnt) {
    if(cnt > 10) return;

    bool state1 = false, state2 = false;
    if(fx < 0 || fx >= n || fy < 0 || fy >= m) state1 = true;
    if(sx < 0 || sx >= n || sy < 0 || sy >= m) state2 = true;

    if(state1 && state2) return;
    if(state1 || state2) {
        if(answer > cnt) answer = cnt;
        return;
    }

    for(int i = 0; i<4; i++) {
        int fnx = fx + dx[i];
        int fny = fy + dy[i];
        int snx = sx + dx[i];
        int sny = sy + dy[i];

        if(arr[fnx][fny] == '#') fnx = fx, fny = fy;
        if(arr[snx][sny] == '#') snx = sx, sny = sy;
        solve(fnx, fny, snx, sny, cnt+1);
    }
    return;
}


int main() {
    scanf("%d %d", &n, &m);

    vector <pair <int, int>> v;
    answer = INT32_MAX;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'o') v.push_back(make_pair(i, j));
        }
    }

    solve(v[0].first, v[0].second, v[1].first, v[1].second, 0);
    if(answer == INT32_MAX) answer = -1;
    printf("%d\n", answer);
    return 0;
}