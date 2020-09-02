#include <bits/stdc++.h>

using namespace std;

int k, n;

unsigned long long solve(vector <unsigned int> &v, unsigned long long len) {
    unsigned long long ret = 0;
    for(int i = 0; i<k; i++) {
        ret += (v[i] / len);
    }
    return ret;
}

int main() {
    scanf("%d %d", &k, &n);
    vector <unsigned int> v(k);
    unsigned long long right = 0;
    for(int i = 0; i<k; i++) {
        scanf("%d", &v[i]);
        if(v[i] > right) right = v[i];
    }

    unsigned long long left = 1;
    unsigned long long mid;
    unsigned long long answer = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        unsigned long long temp = solve(v, mid);

        if(temp < n) {
            right = mid - 1;
        }
        else {
            if(mid > answer) answer = mid;
            left = mid + 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}