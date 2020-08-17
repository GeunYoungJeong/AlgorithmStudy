#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> v;

bool b(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main() {
    int n;
    scanf("%d", &n);
    bool visit[10001];
    if(n==0) {
        printf("0\n");
        return 0;
    }
    int num = n;
    while(num--) {
        int d, p;
        scanf("%d %d", &p, &d);
        v.push_back(make_pair(p, d));
    }

    sort(v.begin(), v.end(), b);

    int t = 0, answer = 0;
    for(int d = 1; d<=10000; d++) {
        bool check = false;
        for(; t<n; t++) {
            // printf("%d %d\n", d, t);
            if(v[t].second > d) {
                break;
            }
            if(!check) {
                answer += v[t].first;
                check = true;
            }
        }
    }

    // int answer = v[0].first;
    // for(int i = 1; i<n; i++) {
    //     if(v[i].second != v[i-1].second) answer += v[i].first;
    // }
    printf("%d\n", answer);
    return 0;
}