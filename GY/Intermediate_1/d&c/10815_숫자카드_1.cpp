#include <bits/stdc++.h>

using namespace std;

bool check[20000005];

int main() {
    int n, m, in;

    queue <int> s;

    scanf("%d", &n);
    vector <int> first(n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &in);
        check[in + 10000000] = true;
    }

    scanf("%d", &m);
    for(int i = 0; i<m; i++) {
        scanf("%d", &in);
        if(check[in + 10000000]) {
            s.push(1);
        } else s.push(0);
    }
    
    while(!s.empty()) {
        printf("%d ", s.front());
        s.pop();
    }
    return 0;
}