#include <bits/stdc++.h>

using namespace std;

int input[1000001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &input[i]);
    }
    vector <long long> result;
    for(int i = 0; i<n; i++) {
        auto it = lower_bound(result.begin(), result.end(), input[i]);
        if(it == result.end()) {
            result.push_back(input[i]);
        }
        else {
            *it = input[i];
        }
    }

    printf("%d\n", result.size());
    return 0;
}