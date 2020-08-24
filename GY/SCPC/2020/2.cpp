#include <bits/stdc++.h>

using namespace std;
int answer;

vector <int> x;
vector <int> y;

int main() {
    setbuf(stdout, NULL);

    int t, n, k;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        scanf("%d %d", &n, &k);
        int state_1 = 0;
        int state_2 = 0;
        answer = 2000000000;

        int input;
        for(int j = 0; j<n; j++) {
            scanf("%d", &input);
            x.push_back(input);
        }
        for(int j = 0; j<n; j++) {
            scanf("%d", &input);
            y.push_back(input);
        }

        sort(a, a + n);
        sort(b, b + n);

        solve(0, 0, k);

        printf("Case #%d\n%d\n", i, answer);
    }
    return 0;

}