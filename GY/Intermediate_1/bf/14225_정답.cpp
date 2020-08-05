#include <bits/stdc++.h>

using namespace std;

int n;
int arr[21];
bool check[2000005] = {false, };

void solve(int idx, int temp) {
    if(idx == n) {
        check[temp] = true;
        return;
    }
    solve(idx+1, temp + arr[idx]);
    solve(idx+1, temp);
}

int main() {
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    solve(0, 0);
    for(int i = 1; i<2000005; i++) {
        if(!check[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
}