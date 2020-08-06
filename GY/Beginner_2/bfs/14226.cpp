#include <bits/stdc++.h>

using namespace std;

int cnt[1001][1001];

int main() {
    memset(cnt, -1, sizeof(cnt));
    int s;
    scanf("%d", &s);
    queue <pair<int, int>> q;
    q.push(make_pair(1,0));
    cnt[1][0] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == s) break;

        //copy
        if(cnt[x][x] == -1) {
            cnt[x][x] = cnt[x][y] + 1;
            q.push(make_pair(x, x));
        }
        if(y!=0 && x+y <= s && cnt[x+y][y] == -1) {
            q.push(make_pair(x + y, y));
            cnt[x+y][y] = cnt[x][y]+1;
        }
        if(x-1 >= 0 && cnt[x-1][y] == -1) {
            q.push(make_pair(x-1, y));
            cnt[x-1][y] = cnt[x][y] + 1;
        }
    }

    int ans;
    for(int i = 0; i<s; i++) {
        if(cnt[s][i] != -1 && ans > cnt[s][i]) {
            ans = cnt[s][i];
        }
    }

    printf("%d\n", ans);
    return 0;
}