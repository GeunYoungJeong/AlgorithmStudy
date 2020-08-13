#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int input[21][21];

    int row_cnt[21];
    int col_cnt[21];
    
    char c;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin >> c;
            if(c=='H') {
                input[i][j] = 0;
            } else
            {
                input[i][j] = 1;
            }
            
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {

        }
    }

}