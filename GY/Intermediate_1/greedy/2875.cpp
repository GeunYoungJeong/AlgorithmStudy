#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int team = 0;
    bool check;
    if(n == 0 || m == 0) {
        printf("0\n");
        return 0;
    }
    team = min(n/2, m);
    int girls = n - team * 2;
    int boys = m - team;
    while(girls + boys < k) {
        team--;
        girls += 2;
        boys += 1;
    }
    printf("%d\n", team);
    return 0;
}