#include <bits/stdc++.h>

using namespace std;

bool visit[10000];
bool check[10000];

void setting() {
    for(int i = 2; i<10000; i++) {
        if(!check[i]) {
            int cur = 2;
            while(i * cur < 10000) {
                check[i * cur] = true;
                cur++;
            }
        }
    }
}

int main() {
    memset(check, false, sizeof(check));
    setting();
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        memset(visit, false, sizeof(visit));
        scanf("%d %d", &a, &b);

        queue<pair<int, int>> q;
        q.push(make_pair(a, 0));
        visit[a] = true;

        while(!q.empty()) {
            int num, cnt;
            tie(num, cnt) = q.front();
            q.pop();

            if(num == b) {
                printf("%d\n", cnt);
                break;
            }

            //소수치환, 방문여부 검사 후 큐에 넣어준다
        }
    }
}