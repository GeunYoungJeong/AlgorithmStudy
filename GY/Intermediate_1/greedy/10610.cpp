#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int team = 0;
    while(n + m >= k) {
        n -= 2;
        m -= 1;
        team++;
    } 
    printf("%d\n", team);
    return 0;
}