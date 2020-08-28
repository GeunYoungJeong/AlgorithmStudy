#include <bits/stdc++.h>

using namespace std;

unsigned long long solve(vector <unsigned int> &v, int len) {
    int s = v.size();
    unsigned long long ret = 0;
    for(int i = 0; i<s; i++) {
        ret += (v[i] / len);
    }
    return ret;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    vector <unsigned int> v(k);
    for(int i = 0; i<k; i++) {
        scanf("%d", &v[i]);
    }

    long long left = 1;
    long long right = *max_element(v.begin(), v.end());

    long long mid;
    while(left <= right) {
        mid = (left + right) / 2;
        unsigned long long temp = solve(v, mid);
        if(temp == n) break;

        if(temp < n) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    while(1) {
        mid++;
        unsigned long long a = solve(v, mid);
        if(a < n) break;
    }

    printf("%d\n", mid-1);
    return 0;
}