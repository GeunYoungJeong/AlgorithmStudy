#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int parent = 0;
    int height;
    int width;
    int left = -1;
    int right = -1;
} Node;

Node LIST[10001];
bool visit[10001];
vector <int> level[10001];

int w = 1;
int h = 0;

void getwidth(int i) {
    if(LIST[i].left != -1) getwidth(LIST[i].left);
    LIST[i].width = w;
    w++;
    if(LIST[i].right != -1) getwidth(LIST[i].right);
}

void getheight(int root) {
    queue <int> q;
    q.push(root);
    visit[root] = true;
    LIST[root].height = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(LIST[x].left != -1 && !visit[LIST[x].left]) {
            int y = LIST[x].left;
            if(LIST[x].height + 1 > h) h = LIST[x].height + 1;
            LIST[y].height = LIST[x].height + 1;
            q.push(LIST[x].left);
            level[LIST[y].height].push_back(LIST[y].width);
            visit[y] = true;
        }

        if(LIST[x].right != -1 && !visit[LIST[x].right]) {
            int y = LIST[x].right;
            if(LIST[x].height + 1 > h) h = LIST[x].height + 1;
            LIST[y].height = LIST[x].height + 1;
            q.push(y);
            level[LIST[y].height].push_back(LIST[y].width);
            visit[y] = true;
        }
    }
}

int main() {
    int n, p, lc, rc;
    scanf("%d", &n);
    int num = n;
    while(num--) {
        scanf("%d %d %d", &p, &lc, &rc);
        LIST[p].left = lc;
        LIST[p].right = rc;
        if(lc != -1) LIST[lc].parent = p;
        if(rc != -1) LIST[rc].parent = p;
    }

    int root = 0;
    for(int i = 1; i<=n; i++) {
        if(LIST[i].parent == 0) {
            root = i;
            break;
        }
    }

    if(LIST[root].left == -1 && LIST[root].right == -1) {
        printf("1 1\n");
        return 0;
    }

    getwidth(root);
    getheight(root);
    
    int max_height , max_width;
    max_height = max_width = 0;

    level[1].push_back(1);
    for(int i = h; i >= 1; i--) {
        sort(level[i].begin(), level[i].end());
        int t = level[i][level[i].size()-1] - level[i][0] + 1;
        if(t >= max_width) {
            max_width = t;
            max_height = i;
        }
    }
    printf("%d %d\n", max_height, max_width);
    return 0;
}