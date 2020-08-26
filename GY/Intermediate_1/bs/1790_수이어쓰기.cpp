#include <bits/stdc++.h>

using namespace std;

int solve(int num) {
    int result = 0;
    int jari = 1;
    for(int i = 1; i<=num; i*=10) {
        int j = i * 10 - 1;
        if(j >= num) j = num;
        result += (j-i+1) * jari;
        jari++;
    }
    return result;
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    if(solve(n) < k) {
        printf("-1\n");
        return 0;
    }

    int left = 1;
    int right = n;
    int mid;

    while(left <= right) {
        mid = (left + right)/2;
        int temp = solve(mid);

        if(temp == k) {
            printf("%d\n", mid%10);
            return 0;
        }
        
        if(temp < k) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    int t = solve(left) - k;
    int answer = -1;
    for(int i = 0; i<=t; i++) {
        answer = left % 10;
        left /= 10;
    }
    printf("%d\n", answer);
    return 0;
}