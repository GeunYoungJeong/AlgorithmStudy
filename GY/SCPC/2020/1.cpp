#include <bits/stdc++.h>

using namespace std;

int a[200001];
int b[200001];

int main() {
    setbuf(stdout, NULL);

    int t, n, k;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        scanf("%d %d", &n, &k);

        for(int j = 0; j<n; j++) {
            scanf("%d", &a[j]);
        }
        for(int j = 0; j<n; j++) {
            scanf("%d", &b[j]);
        }

        sort(a, a + n);
        sort(b, b + n);

        int temp = 0;
        for(int z = 0; z<k; z++) {
            if(temp < a[z] + b[k-1-z]) temp = a[z] + b[k-1-z];
        }

        printf("Case #%d\n%d\n", i, temp);
    }
    return 0;
}