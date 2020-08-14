#include <bits/stdc++.h>

using namespace std;

int a_cnt, b_cnt;
string s, t;
bool check;

void solve(string str, int ac, int bc, int len) {
    if(ac > a_cnt || bc > b_cnt) return;
    if(len == (a_cnt + b_cnt)) {
        if(str == t) {
            check = true;
        }
        return;
    }
    string temp = str;
    reverse(temp.begin(), temp.end());
    temp.append("B");
    solve(temp, ac, bc+1, len+1);
    str.append("A");
    solve(str, ac+1, bc, len+1);
}

int main() {
    cin >> s >> t;
    int slen = s.length();
    int tlen = t.length();
    
    a_cnt = count(t.begin(), t.end(), 'A');
    b_cnt = tlen - a_cnt;
    solve(s, count(s.begin(), s.end(), 'A'), slen - count(s.begin(), s.end(), 'A'), slen);
    printf("%d\n", check);
    return 0;
}