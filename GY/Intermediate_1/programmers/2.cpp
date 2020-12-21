#include <bits/stdc++.h>

using namespace std;

vector<int> answer;

int arr[1001][1001];

void solve(int i, int j, int n, int num) {
    if(n==1) arr[i][j] = num;
    else if(n==2) {
        arr[i][j] = num;
        arr[i+1][j] = num+1;
        arr[i+1][j+1] = num+2;
    }
    else if(n>=3){
        for(int s = i; s < i+n; s++) {
            arr[s][j] = num;
            num++;
        }

        for(int s = j+1; s < j+n; s++) {
            arr[i+n-1][s] = num;
            num++;
        } 

        for(int s = 1; s < n-1; s++) {
            arr[i+n-1-s][j+n-1-s] = num;
            num++;
        }
        solve(i+2, j+1, n-3, num);
    }
    return;
}


vector<int> solution(int n) {
    memset(arr, 0, sizeof(arr));
    
    solve(0, 0, n, 1);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(arr[i][j] != 0) answer.push_back(arr[i][j]);
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;
    solution(n);
}