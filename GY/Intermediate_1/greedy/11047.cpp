#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    scanf("%d %d", &n, &k);
    vector <int> input;
    int num = n;
    while(num--) {
        scanf("%d", &t);
        input.push_back(t);
    }
    int cnt = 0;
    for(int i = n-1; i>=0; i--) {
        while(k >= input[i]) {
            k -= input[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}