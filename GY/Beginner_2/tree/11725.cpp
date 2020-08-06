#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int parent;
    vector <int> list;
}Node;

Node input[100001];
bool visit[100001];

int main() {
    int n, a, b;
    scanf("%d", &n);
    int num = n-1;
    while(num--) {
        scanf("%d %d", &a, &b);
        input[a].list.push_back(b);
        input[b].list.push_back(a);
    }

    queue <int> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        int s = input[x].list.size();
        for(int i = 0; i<s; i++) {
            if(!visit[input[x].list[i]]) {
                visit[input[x].list[i]] = true;
                q.push(input[x].list[i]);
                input[input[x].list[i]].parent = x;
            }
        }
    }

    for(int i = 2; i<=n; i++) {
        printf("%d\n", input[i].parent);
    }
    return 0;
}