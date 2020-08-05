#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    char a;
    struct node * left;
    struct node * right;
}Node;

Node l[27];

void preorder(int i) {
    printf("%c", l[i].a);
    if(l[i].left != NULL) {
        preorder((l[i].left->a)-65);
    }
    if(l[i].right != NULL) {
        preorder((l[i].right->a)-65);        
    }
}

void inorder(int i) {
    if(l[i].left != NULL) {
        inorder((l[i].left->a)-65);
    }
    printf("%c", l[i].a);
    if(l[i].right != NULL) {
        inorder((l[i].right->a)-65);        
    }
}

void postorder(int i) {
    if(l[i].left != NULL) {
        postorder((l[i].left->a)-65);
    }
    if(l[i].right != NULL) {
        postorder((l[i].right->a)-65);        
    }
    printf("%c", l[i].a);
}

int main() {
    int n;
    char p, c1, c2;

    cin >> n;

    while(n--) {
        cin >> p >> c1 >> c2;
        
        l[p-65].a = p;
        if(c1 != '.') {
            l[p-65].left = &l[c1-65];
        }
        if(c2 != '.') {
            l[p-65].right = &l[c2-65];
        }
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    return 0;
}