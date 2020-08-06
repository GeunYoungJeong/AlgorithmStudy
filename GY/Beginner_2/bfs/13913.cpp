#include <bits/stdc++.h>

using namespace std;

int visit[100001];
int from[100001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    queue <int> q;
    q.push(n);
    visit[n] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x-1 >= 0 && visit[x-1] == 0) {
            visit[x-1] = visit[x] + 1;
            from[x-1] = x;
            q.push(x-1);
        }
        if(x+1 <= 100000 && visit[x+1] == 0) {
            visit[x+1] = visit[x] + 1;
            from[x+1] = x;
            q.push(x+1);
        }
        if(2*x <= 100000 && visit[2*x] == 0) {
            visit[2*x] = visit[x] + 1;
            from[2*x] = x;
            q.push(2*x);
        }
        if(x == k) break;
    }
    printf("%d\n", visit[k]-1);
    stack <int> result;
    result.push(k);
    while(k != n) {
        result.push(from[k]);
        k = from[k];
    }
    while(!result.empty()) {
        printf("%d ", result.top());
        result.pop();
    }
    return 0;
}