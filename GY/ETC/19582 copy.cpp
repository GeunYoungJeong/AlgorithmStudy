#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> v;

bool state;
int n, x, p;

int dp[100001];

void solve() {
    for(int i = 0; i<n; i++) {
        //�긦 ������ �� �ִ� ������ ��

        
        //�긦 ������ �� ���� ������ �� (����ʰ�)

    }
}





int main() {
    scanf("%d", &n);
    int num = n;
    while(num--) {
        scanf("%d %d", &x, &p);
        v.push_back(make_pair(x, p));
    }
    solve();
    if(state) printf("Kkeo-eok\n");
    else printf("Zzz\n");
    return 0;
}