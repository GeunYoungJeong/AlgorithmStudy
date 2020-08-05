#include <bits/stdc++.h>

using namespace std;

vector <int> station[3005];

int main() {
    int n, a, b;
    scanf("%d", &n);

    while(n--) {
        scanf("%d %d", &a, &b);
        station[a].push_back(b);
        station[b].push_back(a);
    }
    


}