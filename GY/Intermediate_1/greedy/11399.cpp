#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    scanf("%d", &n);
    vector <int> input;
    int num = n;
    while(num--) {
        scanf("%d", &t);
        input.push_back(t);
    }

    sort(input.begin(), input.end());

    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += input[i] * (n - i);
    }
    printf("%d\n", sum);
    return 0;

}