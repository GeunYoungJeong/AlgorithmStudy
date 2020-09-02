#include <bits/stdc++.h>

using namespace std;

int from[10001];
char path[10001];

void printpath(int a, int b) {
    stack <char> p;
    int cur = b;
    while(cur != a) {
        p.push(path[cur]);
        cur = from[cur];
    }
    while(!p.empty()) {
        printf("%c", p.top());
        p.pop();
    }
    printf("\n");
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        memset(from, -1, sizeof(from));
        memset(path, ' ', sizeof(path));
        scanf("%d %d", &a, &b);

        queue <int> q;
        q.push(a);

        while(!q.empty()) {
            int num = q.front();
            q.pop();

            if(num == b) {
                printpath(a, b);
                break;
            }

            //d
            if(2*num > 9999) {
                if(from[(2*num) % 10000] == -1) {
                    from[(2*num) % 10000] = num;
                    path[(2*num) % 10000] = 'D';
                    q.push((2*num) % 10000);
                }
            }
            else {
                if(from[(2*num)] == -1) {
                    from[(2*num)] = num;
                    path[(2*num)] = 'D';
                    q.push(2*num);
                }
            }

            //s
            if(num == 0) {
                if(from[9999] == -1) {
                    from[9999] = num;
                    path[9999] = 'S';
                    q.push(9999);
                }
            }
            else {
                if(from[num-1] == -1) {
                    from[num-1] = num;
                    path[num-1] = 'S';
                    q.push(num-1);
                }
            }

            //l
            int next = (num % 1000) * 10 + num / 1000;
            if(from[next] == -1) {
                from[next] = num;
                path[next] = 'L';
                q.push(next);
            }

            //r
            next = (num % 10) * 1000 + num / 10;
            if(from[next] == -1) {
                from[next] = num;
                path[next] = 'R';
                q.push(next);
            }
        }
    }
    return 0;
}