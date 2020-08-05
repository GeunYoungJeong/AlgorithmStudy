#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int parent;
    bool used;
    vector <int> child;
};

int main() {
    int n,  a, b;
    scanf("%d", &n);
    
    vector <struct node> tree(n+1);

    tree[1].used = true;

    for(int i = 0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        if(tree[a].used) {
            tree[a].child.push_back(b);
            tree[b].parent = a;
            tree[b].used = true;
        } else {
            tree[b].child.push_back(a);
            tree[a].parent = b;
            tree[a].used = true;
        }
    }

    for(int i = 2; i<=n; i++) {
        printf("%d\n", tree[i].parent);
    }
    return 0;
}