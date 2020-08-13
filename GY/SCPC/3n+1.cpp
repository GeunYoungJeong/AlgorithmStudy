#include <bits/stdc++.h>

using namespace std;

long long MIN, MAX;
bool visit[100000000];
int dp[100000000];

void f(long long n, long long cnt, int k) {
    visit[n] = true;
    
    if(n < 1) return;
    if(cnt == k + 1) {
        if(n < MIN) MIN = n;
        if(n > MAX) MAX = n;
        return;
    }
    if(!visit[n*2]) {
        f(n*2, cnt+1, k);
    }
    if(!dp[n*2]) {

    }
    if(n > 1) {
        if(((n-1) % 3 == 0) && !visit[(n-1)/3] && ((n-1) % 2 != 0)) {
            f(((n-1)/3), cnt+1, k);
        }
    }
} 

int main() {
    int t, k;
    scanf("%d", &t);

    dp[1] = 0;
    dp[2] = 1;

    for(int i = 1; i<=t; i++) {
        MIN = LONG_MAX;
        MAX = 0;
        memset(visit, false, sizeof(visit));
        scanf("%d", &k);
        f(1, 1, k);
        printf("Case #%d\n%lld %lld\n", i, MIN, MAX);
    }
    return 0;
}