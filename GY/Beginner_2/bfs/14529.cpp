#include <bits/stdc++.h>

using namespace std;

int visit[100001];

// 반례 1->2가는 경우 1이 아니라 0임에도 불구하고
// x+1을 먼저 검사하기 때문에 1로 출력
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
        if(2*x <= 100000 && visit[2*x] == 0) {
            visit[2*x] = visit[x];
            q.push(2*x);
        }
        if(x-1 >= 0 && visit[x-1] == 0) {
            visit[x-1] = visit[x] + 1;
            q.push(x-1);
        }
        if(x+1 <= 100000 && visit[x+1] == 0) {
            visit[x+1] = visit[x] + 1;
            q.push(x+1);
        }
    }
    printf("%d\n", visit[k]-1);
    return 0;
}