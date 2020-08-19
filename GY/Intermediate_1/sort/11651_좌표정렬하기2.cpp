#include <bits/stdc++.h>

using namespace std;

bool bo(pair<int, int> &f, pair<int, int> &s) {
    if(f.second == s.second) {
        return f.first < s.first;
    }
    else return f.second < s.second;
}

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
    sort(v.begin(), v.end(), bo);
    for(it = v.begin();  it != v.end(); it++) {
        printf("%d %d\n", it -> first, it -> second);
    }
    return 0;
}