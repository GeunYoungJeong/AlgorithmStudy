#include <bits/stdc++.h>

using namespace std;

typedef struct student {
    string name;
    int k;
    int e;
    int m;
}S;

bool c(S &a, S &b) {
    if(a.k == b.k) {
        if(a.e == b.e) {
            if(a.m == b.m) {
                return a.name < b.name;
            }
            return a.m > b.m;
        }
        return a.e < b.e;
    }
    return a.k > b.k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector <S> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i].name >> v[i].k >> v[i].e >> v[i].m;
    }
    sort(v.begin(), v.end(), c);
    for(int i = 0; i<n; i++) {
        cout << v[i].name << "\n";
    }    
}