#include <bits/stdc++.h>

using namespace std;

int num = 0;
int n, r, c, ans;

int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

void solve(int i, int j, int s) {
    if(s == 2) {
        for(int k = 0; k<4; k++) {
            if(i+dx[k] == r && j+dy[k] == c) ans = num+k;
        }
        num+=4;
        return;
    }
    else {
        solve(i, j, s/2);
        solve(i, j+s/2, s/2);
        solve(i+s/2, j, s/2);
        solve(i+s/2, j+s/2, s/2);
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    int size = pow(2, n);
    solve(0, 0, size);
    printf("%d\n", ans);
    return 0;
}