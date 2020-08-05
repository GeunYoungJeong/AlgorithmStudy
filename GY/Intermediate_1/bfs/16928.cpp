#include <bits/stdc++.h>

using namespace std;

int dest[101];
int dist[101];

void solve() {
    queue <int> path;
    path.push(1);
    dist[1] = 0;

    while(!path.empty()) {
        int x = path.front();
        path.pop();

        for(int i = 1; i<=6; i++) {
            if(x + i <= 100 && dist[dest[x+i]] == -1) {
                dist[dest[x+i]] = dist[x] + 1;
                path.push(dest[x+i]);
            } 
        }
    }
    return;
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=100; i++) {
        dest[i] = i;
        dist[i] = -1;
    }    

    int num = n+m;
    while(num--) {
        scanf("%d %d", &a, &b);
        dest[a] = b;
    }

    solve();
    printf("%d\n", dist[100]);
    return 0;
}