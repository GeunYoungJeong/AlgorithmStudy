#include <bits/stdc++.h>

using namespace std;

int MAX;

void solve(int n, int temp, vector <int> &arr) {
    if(n == 2) {
        if(temp > MAX) MAX = temp;
        return;
    }

    for(int i = 2; i<n; i++) {
        int v = arr[i-1] * arr[i+1];
        vector <int> tempV = arr;
        tempV.erase(tempV.begin() + i);
        solve(n-1, temp + v, tempV);
    }
}

int main() {
    int t, n;
    vector <int> weight;
    scanf("%d", &n);
    weight.push_back(0);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &t);
        weight.push_back(t);
    }
    solve(n, 0, weight);
    
    printf("%d\n", MAX);
    return 0;
}