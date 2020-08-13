#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    vector <int> child;
    vector <int> weight;
    int diameter;
} Node;

Node l[100001];
bool visit[100001];

void dfs(int i) {
    if(visit[i]) return;
    visit[i] = true;

    int s = l[i].child.size();
    for(int j = 0; j<s; j++) {
        int y = l[i].child[j];
        if(!visit[y]) {
            l[y].diameter = l[i].diameter + l[i].weight[j];
            dfs(y);
        }
    }
}

int main() {
    int v, p, c, w;
    scanf("%d", &v);
    int num = v;
    while(num--) {
        scanf("%d", &p);
        while(1) {
            scanf("%d", &c);
            if(c == -1) break;
            scanf("%d", &w);
            l[p].child.push_back(c);
            l[p].weight.push_back(w);
        }
    }

    dfs(1);
    int max_diameter = 0;
    int max_i = 0;
    for(int i = 1; i<=v; i++) {
        if(l[i].diameter > max_diameter) {
            max_diameter = l[i].diameter;
            max_i = i;
        }
    }

    memset(visit, false, sizeof(visit));
    l[max_i].diameter = 0;

    dfs(max_i);
    
    max_diameter = 0;
    for(int i = 1; i<=v; i++) {
        if(l[i].diameter > max_diameter) {
            max_diameter = l[i].diameter;
        }
    }    
    printf("%d\n", max_diameter);
    return 0;
}