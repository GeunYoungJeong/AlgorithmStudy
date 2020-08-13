#include <bits/stdc++.h>

using namespace std;

vector<int> check;
bool visit[100001];
vector <int> LIST[100001];

int n, a, b, s, e;
int idx = 0;

void dfs(int x) {
    if(visit[x]) return;
    visit[x] = true;
    
    idx++;
    if(idx == n) return;
    
    queue <int> order;  

    for(int y : LIST[x]) {
        if(!visit[y]) {
            order.push(y);
        }
    }
  
    int S = order.size();
    int trynum = 0;
    while(!order.empty() && trynum < S) {
        bool c = false;
        int x = order.front();
        order.pop();
        if(check[idx] == x) {
            c = true;
            dfs(x);        
        }
        if(!c) order.push(x);
        trynum++;
    }
}

int main() {
    scanf("%d", &n);

    s = e = 1;
    int num = n-1;
    while(num--) {
        scanf("%d %d", &a, &b);
        LIST[a].push_back(b);
        LIST[b].push_back(a);
    }

    num = n;
    while(num--) {
        scanf("%d", &a);
        check.push_back(a);
    }

    if(LIST[1].size() == 0 || check[0] != 1) {
        printf("0\n");
        return 0;
    }

    dfs(1);
    if(idx < n) printf("0\n");
    else printf("1\n");
    return 0;
}