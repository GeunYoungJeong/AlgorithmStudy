#include <bits/stdc++.h>

using namespace std;

int n, s;
int cnt = 0;
int arr[21];

void solve(int idx, int temp, int count) {
    if(idx == n) {
        if(temp == s && count != 0) {
            cnt++;
        }
        return;
    }
    solve(idx+1, temp + arr[idx], count+1);
    solve(idx+1, temp, count);
}

int main() {
    scanf("%d %d", &n, &s);
    
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    solve(0, 0, 0);
    printf("%d\n", cnt);
    return 0;
}