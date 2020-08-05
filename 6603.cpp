#include <bits/stdc++.h>

using namespace std;
    
int n;
vector <int> input;

void solve(int index, int count, deque<int> q) {
    if(index == n) {
        if(count == 6) {
            while(!q.empty()) {
                printf("%d ", q.front());
                q.pop_front();
            }
            printf("\n");
        }
        return;
    }
    q.push_back(input[index]);
    solve(index+1, count+1, q);
    q.pop_back();
    solve(index+1, count, q);
}

int main() {
    while(1) {
        input.clear();
        int t;
        scanf("%d", &n);
        if(n==0) return 0;
        for(int i = 0; i<n; i++) {
            scanf("%d", &t);
            input.push_back(t);
        }
        deque<int> q;
        solve(0, 0, q);
        printf("\n");
    }
    return 0;
}