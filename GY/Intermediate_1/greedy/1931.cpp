#include <bits/stdc++.h>

using namespace std;
    
vector <pair<int, int>> l;

bool b (pair <int, int> f, pair<int, int> s) {
    if(f.second == s.second) {
        return f.first < s.first;
    }
    return f.second < s.second;
}

int main() {
    int n, s, e;
    scanf("%d", &n);
    int num = n;
    while(num--) {
        scanf("%d %d", &s, &e);
        l.push_back(make_pair(s, e));
    }
    sort(l.begin(), l.end(), b);
    int cnt = 0;
    int end = 0;
    for(int i = 0; i<n; i++) {        
        if(l[i].first >= end) {
            cnt++;
            end = l[i].second;
        }
    }
    printf("%d\n", cnt);
    return 0;
}