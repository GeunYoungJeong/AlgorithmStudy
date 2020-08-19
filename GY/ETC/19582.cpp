#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> v;

bool state;
int n, x, p;

void bfs() {
    queue <tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));

    while(!q.empty()) {
        int i, m, c;
        tie(i, m, c) = q.front();
        q.pop();
        //printf("%d %d %d\n", i, m, c);

        if(c >= n-1) {
            state = true;
            return;
        }

        if(i==n) {
            if(c >= n-1) {
                state = true;
                return;
            }
        }
        else {
            q.push(make_tuple(i+1, m, c));
            if(i+1 == n) {
                if(v[i].first >= m) q.push(make_tuple(i+1, m+v[i].second, c+1));
            }
            else {
                for(int j = i+1; j<n; j++) {
                    if(v[j].first >= m) {
                        q.push(make_tuple(j, m+v[i].second, c+1));
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    int num = n;
    while(num--) {
        scanf("%d %d", &x, &p);
        v.push_back(make_pair(x, p));
    }
    bfs();
    if(state) printf("Kkeo-eok\n");
    else printf("Zzz\n");
    return 0;
}