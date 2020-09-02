#include <bits/stdc++.h>

using namespace std;

int n, c;

unsigned long long cal(vector <unsigned long long> &v, unsigned long long len) {
    unsigned long long ret = 1;
    unsigned long long start = v[0];
    for(int i = 1; i<n; i++) {
        if(v[i] - start >= len) {
            ret++;
            start = v[i];
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &c);
    vector <unsigned long long> v(n);
    for(int i = 0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    unsigned long long left = 1;
    unsigned long long right = v[n-1];
    unsigned long long mid = 0, answer = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        unsigned long long temp = cal(v, mid);

        if(temp >= c) {
            if(answer < mid) answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}