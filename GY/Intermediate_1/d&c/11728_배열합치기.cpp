#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> a(n);
    vector <int> b(m);
    vector <int> result;
    for(int i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i<m; i++) {
        scanf("%d", &b[i]);
    }
    int a_idx = 0;
    int b_idx = 0;
    while(a_idx < n && b_idx < m) {
        if(a[a_idx] <= b[b_idx]) {
            result.push_back(a[a_idx]);
            a_idx++;
        }
        else {
            result.push_back(b[b_idx]);
            b_idx++;
        }
    }
    while(a_idx < n) {
        result.push_back(a[a_idx]);
        a_idx++;
    }
    while(b_idx < m) {
        result.push_back(b[b_idx]);
        b_idx++;
    }
    for(int i = 0; i<n+m; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}