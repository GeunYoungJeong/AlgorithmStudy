#include <bits/stdc++.h>

using namespace std;

int n;
int power[21][21];
int MIN = INT32_MAX;

int a[21];
int b[21];

void calculate() {
    int apower = 0;
    int bpower = 0;
    for(int i = 0; i<n/2; i++) {
        for(int j = 0; j<n/2; j++) {
            apower += power[a[i]][a[j]];
            bpower += power[b[i]][b[j]];
        }
    }
    if(MIN > abs(apower-bpower)) MIN = abs(apower-bpower);
}

void solve(int index, int anum, int bnum) {
    if(anum > n/2 || bnum > n/2) return;
    if(index == n) {
        calculate();
        return;
    }
    a[anum] = index;
    solve(index + 1, anum + 1, bnum);
    b[bnum] = index;
    solve(index+1, anum, bnum+1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &power[i][j]);
        }
    }
    solve(0,0,0);
    printf("%d\n", MIN);
    return 0;
}