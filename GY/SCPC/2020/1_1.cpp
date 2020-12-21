#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, NULL);
    int t, n;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        scanf("%d", &n);
        vector <long long> a(n);
        vector <long long> b(n);

        for(int j = 0; j<n; j++) {
            scanf("%lld", &a[j]);
        }
        for(int j = 0; j<n; j++) {
            scanf("%lld", &b[j]);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        unsigned long long temp, temp1, temp2, temp3;
        unsigned long long answer;
        temp = temp1 = temp2 = temp3 = answer = 0LL;

        int start = -1, end = -1;

        for(int j = 0; j<n; j++) {
            if(a[j] != b[j]) {
                start = j;
                break;
            }
        }

        for(int j = n-1; j>=0; j--) {
            if(a[j] != b[j]) {
                end = j;
                break;
            }
        }

        if(start == -1 || end == -1 || start == end) {
            printf("Case #%d\n0\n", i);
            continue;    
        }

        for(int j = start+1; j<=end; j++) {
            temp += abs(a[j] - b[j-1]);
            temp2 += abs(a[j] - b[j]);
        }
        answer = temp; 
        if(answer > temp2) answer = temp2; 

        for(int j = start; j<=end-1; j++) {
            temp1 += abs(a[j] - b[j]);
            temp3 += abs(a[j] - b[j+1]);
        }
        if(answer > temp1) answer = temp1; 
        if(answer > temp3) answer = temp3;
        
        min(temp1, temp2, temp3, temp);
        // printf("%lld\n", temp);
        // printf("%lld\n", temp1);
        // printf("%lld\n", temp2);
        // printf("%lld\n", temp3);

        printf("Case #%d\n%lld\n", i, answer);
    }
    return 0;
}