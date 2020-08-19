#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    scanf("%d", &n);
    int num = n;
    vector <pair<int, int>> v;
    vector <pair<int, int>>::iterator it;
    while(num--) {
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for(it = v.begin();  it != v.end(); it++) {
        printf("%d %d\n", it -> first, it -> second);
    }
    return 0;
}