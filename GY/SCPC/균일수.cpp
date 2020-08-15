#include <bits/stdc++.h>

using namespace std;

int solve(int num) {
    int t = 2;
    int m, n;
    while(1) {
        bool check;
        stack <int> r;
        m = num / t;
        n = num % t;
        if(n==m) return t;
        r.push(n);
        while(m > 0) {
            n = m % t;
            m = m / t;
            if(r.top() != n) {
                check = true;
                break;
            }
            else {
                r.push(n);
            }
        }
        if(!check) return t;
        t++;
    }
    
}

int main() {
    int t, num;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &num);
        printf("Case #%d\n%d\n", i, solve(num));
    }
    return 0;
}