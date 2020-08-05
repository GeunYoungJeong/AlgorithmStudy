#include <bits/stdc++.h>

using namespace std;


int main() {
    int l, c;
    scanf("%d %d", &l, &c);
    vector <char> a(c);
    for(int i = 0; i<c; i++) {
        scanf("%c", &a[i]);
    }
    
    for(int i = 0; i<c; i++) {
        printf("%c\n", a[i]);
    }
}