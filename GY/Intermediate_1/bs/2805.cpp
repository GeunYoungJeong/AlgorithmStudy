#include <bits/stdc++.h>

using namespace std;

int n, m;

unsigned long long cal(vector <unsigned long long> &v, unsigned long long len) {
    unsigned long long ret = 0;
    for(int i = 0; i<n; i++) {
        if(v[i] > len) {
            ret += (v[i] - len);
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    vector <unsigned long long> v(n);
    unsigned long long right = 0;
    for(int i = 0; i<n; i++) {
        scanf("%lld", &v[i]);
        if(right < v[i]) right = v[i];
    }

    unsigned long long left = 1;
    unsigned long long mid = 0, ans = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        unsigned long long temp = cal(v, mid);
        if(m <= temp) {
            if(ans < mid) ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}