#include <bits/stdc++.h>

using namespace std;

int a_cnt, b_cnt;
string s, t;
int main() {
    cin >> s >> t;
    int slen = s.length();
    int tlen = t.length();

    while(tlen > 0) {
        if(t == s) break;
        
        if(t[tlen-1] =='A') {
            t.erase(t.end()-1);
        } else {
            t.erase(t.end()-1);
            reverse(t.begin(), t.end());
        }
        tlen--;
    }
    if(t == s) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
    return 0;
}