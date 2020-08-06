#include <bits/stdc++.h>

using namespace std;

int visit[100001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    queue <int> q;
    q.push(n);
    visit[n] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == k) break;
        if(x-1 >= 0 && visit[x-1] == 0) {
            visit[x-1] = visit[x] + 1;
            q.push(x-1);
        }
        if(x+1 <= 100000 && visit[x+1] == 0) {
            visit[x+1] = visit[x] + 1;
            q.push(x+1);
        }
        if(2*x <= 100000 && visit[2*x] == 0) {
            visit[2*x] = visit[x] + 1;
            q.push(2*x);
        }
    }
    printf("%d\n", visit[k]-1);
    return 0;
}