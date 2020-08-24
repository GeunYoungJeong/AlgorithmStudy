#include <bits/stdc++.h>

using namespace std;

vector <char> arr;

int solve(string str) {
    int len = str.length();
    int temp = 0;
    int jari = 1;

    for(int i = 0; i<len; i++) {
        for(int j = 0; j<arr.size(); j++) {
            if(arr[j] == str[i]) {
                temp += (9-j) * jari;
                break;
            }
        }
        jari *= 10;
    }
    //printf("%d\n", temp);
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);
    vector <string> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
        for(int j = 0; j<v[i].length(); j++) {
            if(count(arr.begin(), arr.end(), v[i][j]) == 0) arr.push_back(v[i][j]);
        }
    }

    int answer = 0;
    do {
        int temp = 0;
        for(int i = 0; i<n; i++) {
            temp += solve(v[i]);
        }
        if(answer < temp) answer = temp;
    } while(next_permutation(arr.begin(), arr.end()));

    printf("%d\n", answer);
    return 0;   
}