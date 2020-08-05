#include <bits/stdc++.h>

using namespace std;

int m = 0;
int n;

void recursive(int i, int total, vector <int> &t, vector <int> &p) {
    if(i > n) return;
    if(i == n) {
        if(total > m) {
            m = total;
        }
        return;
    }
    else {
        recursive(i+1, total, t, p);
        recursive(i+t[i], total+p[i], t, p);
    }
}

int main() {
    scanf("%d", &n);
    //���� ũ�⸦ n���� �����ϸ� ��Ÿ�� ����
    //���� �����°� ������ ����, recursive �������� vector boundary �ʰ��̱� ����
    vector <int> t(25);
    vector <int> p(25);
    for(int i = 0; i<n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }
    recursive(0, 0, t, p);
    printf("%d\n", m);
    return 0;
}