#include <bits/stdc++.h>

using namespace std;

typedef struct person {
    int order;
    int age;
    string name;
} S;

bool b(S &f, S&s) {
    if(f.age == s.age) {
        return f.order < s.order;
    }
    return f.age < s.age;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector <S> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i].age >> v[i].name;
        v[i].order = i;
    }
    sort(v.begin(), v.end(), b);
    for(int i = 0; i<n; i++) {
        cout << v[i].age << " " << v[i].name << "\n";
    }    
}