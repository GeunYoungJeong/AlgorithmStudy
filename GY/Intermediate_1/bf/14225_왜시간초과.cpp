#include <bits/stdc++.h>

using namespace std;

int n;
int arr[21];
vector <int> check;

void solve(int idx, int temp) {
    if(idx == n) {
        if(count(check.begin(), check.end(), temp) == 0) {
            check.push_back(temp);
        }
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
    
    int i = 1;
    while(1) {
        if(count(check.begin(), check.end(), i) == 0) {
            printf("%d\n", i);
            return 0;
        }
        i++;
    }
}