#include <bits/stdc++.h>

using namespace std;

vector <char> arr;
char alphabet[26];
int n;

int solve(vector <string> &v) {
    int ret = 0;
    for(int idx = 0; idx < n; idx++) {
        int len = v[idx].length();
        int jari = 1;
        int temp = 0;

        for(int i = len-1; i>=0; i--) {
            temp += (alphabet[v[idx][i]-65] * jari);
            jari *= 10;
        }
        
        ret += temp;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    vector <string> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
        int len = v[i].length();
        for(int j = 0; j<len; j++) {
            arr.push_back(v[i][j]);
        }
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int answer = 0;
    do {
        for(int i = 0; i<arr.size(); i++) {
            alphabet[arr[i]-65] = 9-i;
        }
        int temp = solve(v);
        if(answer < temp) answer = temp;
    } while(next_permutation(arr.begin(), arr.end()));

    printf("%d\n", answer);
    return 0;   
}