#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector <long long> v(n);
    
    for(int i = 0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    
    sort(v.begin(), v.end());

    int temp = 1, len = 0;
    long long answer = v[0];
    for(int i = 1; i<n; i++) {
        if(v[i] == v[i-1]) {
            temp++;
        }
        else {
            if(len < temp) {
                len = temp;
                answer = v[i-1];
            }
            temp = 1;
        }
    }

    if(len < temp) {
        len = temp;
        answer = v[n-1];
    }
    
    printf("%lld\n", answer);
    return 0;
}