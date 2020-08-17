#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int dx[4] = {-2, -1, 1, 2};
int dy[4] = {1, 2, 2, 1};

void solve(int i, int j, int n, int m, int num) {
    if(i<0 || i>=n || j<0 || j>=m) {
        if(ans < num) ans = num;
        return;
    }
    for(int idx = 0; idx<4; idx++) {
        solve(i+dx[idx], j+dy[idx], n, m, num+1);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int i = n-1, j = 0;
    
    while(0<=i && i<n && 0<=j && j<m) {

    }
    //solve(n-1, 0, n, m, 0);

    printf("%d\n", ans);
    return 0;
}