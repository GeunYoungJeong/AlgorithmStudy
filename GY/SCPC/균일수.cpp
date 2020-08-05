#include <bits/stdc++.h>

using namespace std;

int solve(int num) {
    int mok = INT_MAX;
    int namerge;
    int b = 2;
    while (1) {
        bool check2 = false;
        int cnt = 0;
        int temp;

        while (1) {
            if (mok == 0) break;
            if (mok == INT_MAX) {
                mok = num / b;
                namerge = num % b;
            }
            else {
                namerge = mok % b;
                mok = mok / b;
            }            
            if(cnt>=1) {
                if(temp != namerge) {
                    check2 = true;
                    break;
                }
            }
            cnt++;
            temp = namerge;
        }

        if(check2) {
            b++;
            namerge = 0;
            mok = INT_MAX;   
        }
        else {
            return b;
        }
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