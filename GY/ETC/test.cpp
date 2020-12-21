#include <bits/stdc++.h>

using namespace std;

char arr[101][10];
int main() {
    memset(arr, ' ', sizeof(arr));
    for(int i = 0; i<=100; i++) {
        int t = log(i);
        if(0<=t && t<10) arr[i][9-t] = '*';
    }

    for(int i = 0; i<10; i++) {
        for(int j = 0; j<100; j++) {
            cout << arr[j][i];
        }
        cout << endl;
    }
    return 0;
}