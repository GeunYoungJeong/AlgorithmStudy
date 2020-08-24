#include <bits/stdc++.h>

using namespace std;
string s, t;
bool state;

void solve(string str) {
    if(str == s) {
        state = true;
        return;
    }

    string tem = str;

    if(str[str.size()-1] == 'A') {
        str.erase(str.end()-1);
        solve(str);
    }

    if(tem[0] == 'B') {
        reverse(tem.begin(), tem.end());
        tem.erase(tem.end()-1);
        solve(tem);        
    }

}
int main() {
    cin >> s >> t;
    solve(t);
    printf("%d\n", state);
    return 0;
}