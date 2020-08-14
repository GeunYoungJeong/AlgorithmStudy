#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> result(n+m);
    for(int i = 0; i<n + m; i++) {
        scanf("%d", &result[i]);
    }
    sort(result.begin(), result.end());
    for(int i = 0; i<n+m; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}