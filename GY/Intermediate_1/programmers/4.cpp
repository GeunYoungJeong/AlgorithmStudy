#include <bits/stdc++.h>

using namespace std;

int row, col;
vector<vector<int>> cnt;

int calculate(vector<vector<int>> cnt) {
    for(int i = 0; i<row; i++) {
        int temp = 0;
        for(int j = 0; j<col; j++) {
            temp += cnt[i][j];
        }
        if(temp % 2 == 1) return 0;
    }
    return 1;
}

bool next_p() {
    if(!next_permutation(cnt[0].begin(), cnt[0].end())) {
        return false;
    }
    else {
        for(int i = 1; i<col; i++) {
            next_permutation(cnt[i].begin(), cnt[i].end());
        }
    }
    return true;
}

int solution(vector<vector<int>> a) {
    unsigned long long answer = 0;
    col = a[0].size();
    row = a.size();

    // cout << row << col << endl;

    for(int i = 0; i<col; i++) {
        vector<int> t;
        for(int j = 0; j<row; j++) {
            t.push_back(a[j][i]);
        }
        cnt.push_back(t);
    }

    for(int i = 0; i<col; i++) {
        sort(cnt[i].begin(), cnt[i].end());
    }


    do {
        
    for(int i = 0; i<col; i++) {
        for(int j = 0; j<row; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << endl;
    }
        answer += calculate(cnt);
    }
    while(next_p());

    answer %= 10000019;
    return answer;
}

int main() {
    int c, r;
    cin >> c >> r;
    vector <vector<int>> input(c, vector<int> (r));
    for(int i =0 ; i<c; i++) {
        for(int j = 0; j<r; j++) {
            cin >> input[i][j];
        }
    }
    cout << solution(input);

}