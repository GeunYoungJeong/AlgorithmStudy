#include <bits/stdc++.h>

using namespace std;

int l, c;
char a[16];
vector <char> result;

void check(vector <char> res) {
    int m = 0;
    int j = 0;
    for(int i = 0; i<l; i++) {
        if(res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') {
            m++;
        }
        else j++;
    }
    if(m >= 1 && j >= 2) {
        for(int i = 0; i<l; i++) {
            printf("%c", result[i]);
        }
        printf("\n");    
    }
}

void solve(int index, int count) {
    if(index == c) {
        if(count == l) {
            check(result);
        }
        return;
    }
    result.push_back(a[index]);
    solve(index+1, count+1);
    result.pop_back();
    solve(index+1, count);
}

int main() {
    scanf("%d %d", &l, &c);
    for(int i = 0; i<c; i++) {
        cin >> a[i];
    }
    sort(a, a + c);
    solve(0, 0);
}