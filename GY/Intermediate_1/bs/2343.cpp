#include <bits/stdc++.h>

using namespace std;

int n, m;

int cal(vector <unsigned long long> &v, unsigned long long len) {
    int sector = 1;
    unsigned long long part = 0;
    for(int i = 0; i<n; i++) {
        part += v[i];
        if(part > len) {
            sector++;
            part = v[i];
        }
    }
    return sector;
}

int main() {
    scanf("%d %d", &n, &m);
    vector <unsigned long long> v(n);
    unsigned long long right = 0;
    unsigned long long left = 0;
    for(int i = 0; i<n; i++) {
        scanf("%lld", &v[i]);
        right += v[i];
        if(left < v[i]) left = v[i];
    }

    unsigned long long mid = 0;
    unsigned long long ans = INT32_MAX;

    while(left <= right) {
        mid = (left + right) / 2;
        int temp = cal(v, mid);
        //printf("%lld %lld %lld %d\n", left, right, mid, temp);

        if(temp <= m) {
            if(ans > mid) ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}