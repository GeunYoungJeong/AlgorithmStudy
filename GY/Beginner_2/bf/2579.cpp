#include <bits/stdc++.h>

using namespace std;

int k;
char input[10];
int result[10];
bool use[10];

void solve(int index, int count) {
    if(index == k) {
        for(int i = 0; i<=k; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
        return;
    }

    if(input[index] == '<') {
        for(int i = 0; i<10; i++) {
            if(!use[i]) {
                for(int j = i+1; j<10; j++) {
                    if(!use[j]) {
                        use[i] = true;
                        use[j] = true;
                        result[index] = i;
                        result[index+1] = i;
                        solve(index+1, count);
                        use[i] = false;
                        use[j] = false;
                    }
                }
            }
        }
    } else {

    }
}

int main() {
    scanf("%d", &k);

    for(int i = 0; i<k; i++) {
        cin >> input[i];
    }
    
    solve(0,0);

}